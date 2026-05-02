#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

// For better resolution, you can replace with RDTSC if you want.
static double seconds(void) {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec + 1e-9 * ts.tv_nsec;
}

int main(void) {
    const int stride = 128;                 // step in bytes; 128 bytes = 2 cache lines if 64B
    const int elem_size = sizeof(int);      // 4 bytes per element
    const int stride_elements = stride / elem_size;
    const int max_size_kb = 8 * 1024;       // go up to 8 MiB working set
    const int reps = 10;                    // multiple passes per size

    for (int size_kb = 1; size_kb <= max_size_kb; size_kb *= 2) {
        const int len = (size_kb * 1024) / elem_size;
        int *arr = malloc(len * sizeof(int));
        if (!arr) {
            perror("malloc");
            return 1;
        }

        // init to avoid optimizer removing the loop
        for (int i = 0; i < len; i++) {
            arr[i] = i;
        }

        double t0 = seconds();
        for (int r = 0; r < reps; r++) {
            // Example 3 style: walk every stride_elements
            for (int i = 0; i < len; i += stride_elements) {
                arr[i] *= 3;
            }
        }
        double t1 = seconds();

        double dt = t1 - t0;
        double ns_per_access = (dt * 1e9) / (reps * (len / stride_elements));

        printf("KB %4d  len %6d  dt %.3f ms  ~ %.1f ns/access\n",
               size_kb, len, dt * 1000, ns_per_access);

        free(arr);
    }

    return 0;
}
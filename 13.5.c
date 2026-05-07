#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int sum = 0;
    for (int i = 0; i < argc; i++) {
        int n = atoi(argv[i]);
        sum += n;
    }
    printf("sum = %d\n", sum);
    return 0;
}
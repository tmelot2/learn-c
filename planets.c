#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
	char planets[][8] = { "Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune", "Pluto" };
	int i,p;

	for (int i=0; i < argc; i++) {
		char *arg = argv[i];
		// printf("%p %s\n\n", argv[i], arg);

		for (int p = 0; p <= 8; p++) {
			if (strcmp(arg, planets[p]) == 0) {
				printf("%s is a planet\n", arg);
				break;
			}
		}
	}

	return 0;
}

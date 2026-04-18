#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

int main(void)
{
	srand(time(NULL));
	char EMPTY = '.';
	int x = 0;
	int y = 0;
	char maze[10][10];
	int pathIndex = 0;
	char pathLookup[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	// Init maze to empty.
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			maze[i][j] = EMPTY;
		}
	}

	int start, dir;
	maze[0][0] = pathLookup[0];
	pathIndex += 1;
	while (pathIndex < strlen(pathLookup)) {
		bool hasMatch = false;

		// Start on randomized direction, try all others before declaring stuck.
		start = rand() % 4;
		for (int i = 0; i < 4; i++) {
			dir = (start + i) % 4;
			// printf("%d, %d, pathIndex=%d ", x, y, pathIndex);

			// Up
			if (dir == 0) {
				if (y > 0 && maze[x][y-1] == EMPTY) {
					y -= 1;
					hasMatch = true;
				}
			}
			// Right
			else if (dir == 1) {
				if (x < 9 && maze[x+1][y] == EMPTY) {
					x += 1;
					hasMatch = true;
				}
			}
			// Down
			else if (dir == 2) {
				if (y < 9 && maze[x][y+1] == EMPTY) {
					y += 1;
					hasMatch = true;
				}
			}
			// Left
			else if (dir == 3) {
				if (x > 0 && maze[x-1][y] == EMPTY) {
					x -= 1;
					hasMatch = true;
				}
			}

			if (hasMatch) {
				maze[x][y] = pathLookup[pathIndex++];
				break;
			}
		}

		if (!hasMatch) {
			printf("Stuck on %c\n", pathLookup[pathIndex]);
			break;
		}
	}

	// Print result (finished or stuck).
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			printf(" %c", maze[i][j]);
		}
		printf("\n");
	}

	return 0;
}

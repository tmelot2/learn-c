#include <stdio.h>


char getCharacter(int slot) {
	if (slot == 0 || slot == 6 || slot == 3) {
		return '_';
	} else {
		return '|';
	}
}


int main(void) {
	int segments[10][7] = {
	//   0 1 2 3 4 5 6
		{1,1,1,1,1,1,0}, // 0
		{0,1,1,0,0,0,0}, // 1
		{1,1,0,1,1,0,1}, // 2
		{1,1,1,1,0,0,1}, // 3
		{0,1,1,0,0,1,1}, // 4
		{1,0,1,1,0,1,1}, // 5
		{1,0,1,1,1,1,1}, // 6
		{1,1,1,0,0,0,0}, // 7
		{1,1,1,1,1,1,1}, // 8
		{1,1,1,1,0,1,1}  // 9
	};

	char nums[] = "1234567890";

	// Each digit in number
	for (int i = 0; i < sizeof(nums); i++) {
		char c = nums[i];
		int digit = c - '0';

		// Each line in digit
		for (int j = 0; j < sizeof(nums); j++) {
			// Line 1
			if (j == 0) {
				// Left
				printf(" ");
				// Center
				if (segments[digit][0] == 1) {
					printf("_");
				}
				// Right
				printf(" ");
				printf("\n");
			}
			// Line 2
			else if (j == 1) {
				// Left
				if (segments[digit][5] == 1) {
					printf("|");
				} else {
					printf(" ");
				}
				// Center
				if (segments[digit][6] == 1) {
					printf("_");
				} else {
					printf(" ");
				}
				// Right
				if (segments[digit][1] == 1) {
					printf("|");
				} else {
					printf(" ");
				}
				printf("\n");
			} else if (j == 2) {
				// Left
				if (segments[digit][4] == 1) {
					printf("|");
				} else {
					printf(" ");
				}
				// Center
				if (segments[digit][3] == 1) {
					printf("_");
				} else {
					printf(" ");
				}
				// Right
				if (segments[digit][2] == 1) {
					printf("|");
				} else {
					printf(" ");
				}
				printf("\n");
			}
		}
	}

	return 0;
}

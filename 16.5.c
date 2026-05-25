#include <stdlib.h>
#include <stdio.h>

#define TIME24_TO_MIN(h, m) ((h) * 60 + (m))

struct flight {
	int departure;
	int arrival;
};

struct flight flight_times[] = {
	// 8:00a, 10:16a
	{ .departure = TIME24_TO_MIN(8,0), .arrival = TIME24_TO_MIN(10, 16) },
	// 9:43a, 11:52a
	{ .departure = TIME24_TO_MIN(9,43), .arrival = TIME24_TO_MIN(11, 52) },
	// 11:19a, 1:31p
	{ .departure = TIME24_TO_MIN(11,19), .arrival = TIME24_TO_MIN(13, 31) },
	// 12:47p, 3p
	{ .departure = TIME24_TO_MIN(12,47), .arrival = TIME24_TO_MIN(15, 0) },
	// 2p, 4:08p
	{ .departure = TIME24_TO_MIN(14,0), .arrival = TIME24_TO_MIN(16, 8) },
	// 3:45p, 5:55p
	{ .departure = TIME24_TO_MIN(15,45), .arrival = TIME24_TO_MIN(17, 55) },
	// 7p, 9:20p
	{ .departure = TIME24_TO_MIN(19,0), .arrival = TIME24_TO_MIN(21, 20) },
	// 9:45p, 11:58p
	{ .departure = TIME24_TO_MIN(21,45), .arrival = TIME24_TO_MIN(23, 58) },
};

void print_12h_time(int minutes) {
	char ap = 'a';
	int h12 = minutes / 60;
	if (h12 > 12) {
		h12 -= 12;
		ap = 'p';
	}
	int m12 = minutes % 60;
	printf("%d:%d %cm", h12, m12, ap);
}

int main(void) {
	int array_len = sizeof(flight_times) / sizeof(flight_times[0]);

	printf("Enter time (24h, hh:mm): ");
	int hour, min;
	scanf("%2d:%2d", &hour, &min);
	// printf("hour=%d min=%d\n", hour, min);

	// Validation
	if (hour < 0 || hour > 23) {
		printf("Hour must be between 0 & 23 (inclusive)\n");
		return 1;
	}

	if (min < 0 || min > 59) {
		printf("Minute must be between 0 & 59 (inclusive)\n");
		return 1;
	}

	// Find nearest departure time
	int min_since_midnight = hour * 60 + min;
	// printf("Your time is %d min since midnight\n", min_since_midnight);
	int closest_min = -1;
	int closest_index = 0;
	for (int i = 0; i < array_len; i++) {
		// printf("%d\n", flight_times[i].departure);
		int diff = abs(flight_times[i].departure - min_since_midnight);
		if (closest_min == -1 || diff < closest_min) {
			// printf("Found new closest %d at index %d\n", flight_times[i].departure, i);
			closest_min = diff;
			closest_index = i;
		}
	}

	// Print
	printf("You entered ");
	print_12h_time(hour * 60 + min);
	printf("\n");
	printf("Closest departure time is ");
	print_12h_time(flight_times[closest_index].departure);
	printf(", arriving at ");
	print_12h_time(flight_times[closest_index].arrival);
	printf("\n");

	return 0;
}
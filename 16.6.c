#include <stdio.h>

struct date {
	int day;
	int month;
	int year;
};

void print_date(struct date d) {
	printf("%2d/%2d/%4d", d.month, d.day, d.year);
}

// Returns 1 if date1 > date2, -1 if opposite, 0 if same
int compare_dates(struct date d1, struct date d2) {
	if (d1.year > d2.year) {
		return  1;
	} else if (d1.year < d2.year) {
		return -1;
	} else {
		if (d1.month > d2.month) {
			return 1;
		} else if (d1.month < d2.month) {
			return -1;
		} else {
			if (d1.day > d2.day) {
				return 1;
			} else if (d1.day < d2.day) {
				return -1;
			} else {
				return 0;
			}
		}
	}
}

int main(void) {
	int m1, d1, y1;
	int m2, d2, y2;

	printf("Enter first date mm/dd/yyyy: ");
	// scanf("%2d/%2d/%4d", &m1, &d1, &y1);
	m1 = 11;
	d1 = 11;
	y1 = 1111;
	struct date date1 = { .day = d1, .month = m1, .year = y1 };

	printf("Enter second date mm/dd/yyyy: ");
	// scanf("%2d/%2d/%4d", &m2, &d2, &y2);
	m2 = 11;
	d2 = 11;
	y2 = 1111;
	struct date date2 = { .day = d2, .month = m2, .year = y2 };

	printf("\n");
	print_date(date1);

	int comp = compare_dates(date1, date2);
	if (comp == 1) {
		printf(" is later than ");
	} else if (comp == -1) {
		printf(" is earlier than ");
	} else {
		printf(" is the same as ");
	}

	print_date(date2);

	return 0;
}
#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50   /* maximum number of reminders */
#define MSG_LEN 60      /* max length of reminder message */

int read_line(char str[], int n);

int main(void)
{
  // 3 for day (plus space), 3 for time (plus space)
  char reminders[MAX_REMIND][MSG_LEN+3+3];
  // Time is 2 digit hour 0-23
  char day_str[3], time_str[3], msg_str[MSG_LEN+1];
  int day, time, i, j, num_remind = 0;

  for (;;) {
    if (num_remind == MAX_REMIND) {
      printf("-- No space left --\n");
      break;
    }

    printf("Enter day, time, and reminder: ");
    fflush(stdout);

    // Parse day, end if 0.
    scanf("%2d", &day);
    if (day == 0)
      break;
    // Write day as 2 width right-aligned int into day_str.
    sprintf(day_str, "%2d", day);

    // Parse time
    scanf("%2d", &time);
    // Write time as 2 width right-aligned int into time_str.
    sprintf(time_str, "%2d", time);

    read_line(msg_str, MSG_LEN);

    // Validation
    if (day < 0 || day > 31) {
      printf("Day out of range, should be 1-31\n");
      continue;
    }
    if (time < 0 || time > 23) {
      printf("Time out of range, should be 0-23\n");
      continue;
    }

    // Sort
    for (i = 0; i < num_remind; i++)
      if (strcmp(day_str, reminders[i]) < 0)
        break;
    for (j = num_remind; j > i; j--)
      strcpy(reminders[j], reminders[j-1]);

    // Copy strings into reminders
    strcpy(reminders[i], day_str);
    strcat(reminders[i], " ");
    strcat(reminders[i], time_str);
    strcat(reminders[i], msg_str);

    num_remind++;
  }

  printf("\nDay Time Reminder\n");
  for (i = 0; i < num_remind; i++)
    printf(" %s\n", reminders[i]);

  return 0;
}

int read_line(char str[], int n)
{
  int ch, i = 0;

  while ((ch = getchar()) != '\n')
    if (i < n)
      str[i++] = ch;
  str[i] = '\0';
  return i;
}
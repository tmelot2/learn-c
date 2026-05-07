#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define NUM_PLANETS 9

void to_lower(char *s) {
    for (int i = 0; i < strlen(s); i++) {
        s[i] = tolower(s[i]);
    }
}

int main(int argc, char *argv[])
{
  char *planets[] = {"Mercury", "Venus", "Earth",
                     "Mars", "Jupiter", "Saturn",
                     "Uranus", "Neptune", "Pluto"};
  int i, j;
  char *s, *p;

  for (i = 1; i < argc; i++) {
    for (j = 0; j < NUM_PLANETS; j++) {
      s = strdup(argv[i]);
      to_lower(s);
      p = strdup(planets[j]);
      to_lower(p);

      if (strcmp(s, p) == 0) {
        printf("%s is planet %d\n", argv[i], j + 1);
        break;
      }
    }
    if (j == NUM_PLANETS)
      printf("%s is not a planet\n", argv[i]);
  }

  return 0;
}

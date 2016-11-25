// Rawan Alsaadi 10081442 
// Omar Toutounji 10169506
// Beltan Michel 10169162

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int reverse(int otherWord)
{
  if (otherWord) {
    return 0;
  } else {
    return 1;
  }
}

void capitalise(char *s)
{
  int start = 1;
  int otherWord = 1;
  for (; *s; s++) {
	// *s goes through each and every character
    if (start && otherWord) {
      *s = toupper(*s);
    }
    start = isspace(*s); // if s* is a space character then isspace returns a number > 0
    if (start) {
      otherWord = reverse(otherWord);
    }
  }
}

int main(int argc, char *argv[])
{
  FILE *fp;
  char *line = NULL;
  size_t len = 0;
  ssize_t read;
  long offset = 0L;
  int res;

  fp = fopen(argv[1], "r+");
  if (fp == NULL) {
    fprintf(stderr, "Opening file poem.txt failed\n");
    exit(EXIT_FAILURE);
  }

  while ((read = getline(&line, &len, fp)) != -1) {
    capitalise(line);
    // set position relative to start of file
    if ((res = fseek(fp, offset, SEEK_SET)) < 0) {
      fprintf(stderr, "fseek failed\n");
      exit(EXIT_FAILURE);
    }
    // printing line sets file pointer to end of line
    fprintf(fp, "%s", line);
    // get that position
    offset = ftell(fp);
  }
  fclose(fp);
  if (line) {
    free(line);
  }
  exit(EXIT_SUCCESS);
}

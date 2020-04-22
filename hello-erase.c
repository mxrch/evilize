/* Copyright (C) 2006 Peter Selinger. This file is distributed under
   the terms of the GNU General Public License. See the file COPYING
   for details. */

#include <stdio.h>
#include <unistd.h>

/* do something innocent */
int main_good(int ac, char *av[]) {
  char buf[10];
  fprintf(stdout, "Hello, world!\n");
  fprintf(stdout, "\n(press enter to quit)");
  fflush(stdout);
  fgets(buf, 10, stdin);
  return 0;
}

/* do something evil */
int main_evil(int ac, char *av[]) {
  char buf[10];
  fprintf(stdout, "This program is evil!!!\n");
  fprintf(stdout, "Erasing hard drive...");
  fflush(stdout);
  sleep(1);
  fprintf(stdout, "1Gb...");
  fflush(stdout);
  sleep(1);
  fprintf(stdout, "2Gb...");
  fflush(stdout);
  sleep(1);
  fprintf(stdout, " just kidding!\nNothing was erased.\n");
  fprintf(stdout, "\n(press enter to quit)");
  fflush(stdout);
  fgets(buf, 10, stdin);
  return 0;
}

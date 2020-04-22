/* Copyright (C) 2006 Peter Selinger. This file is distributed under
   the terms of the GNU General Public License. See the file COPYING
   for details. */

#include <string.h>
#include "crib.h"

int main_good(int ac, char *av[]);
int main_evil(int ac, char *av[]);

char *str1 = CRIB "0";
char *str2 = CRIB "1";

int main(int ac, char *av[]) {
  if (memcmp(str1, str2, 191) == 0) {
    return main_good(ac, av);
  } else {
    return main_evil(ac, av);
  }
}

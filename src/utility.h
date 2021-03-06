#include "shared.h"
#include <limits.h>
#ifndef UTILITY_H
#define UTILITY_H

/* the default line length for input / output */
#define LINELEN 80

/* the last two characters required in a string as returned from fgets */
#define EXTRACHARS 2

/* newline character required for I/O functions */
#define NEWLINE '\n'

void read_rest_of_line(void);
#endif /* ifndef UTILITY_H */

#ifndef _MENGER_
#define _MENGER_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menger(int level);
char *lvl(char *spg, int v);
char *build(char *spg, int size);
int border(char *a, char *b, int c, char *v, int e);
char *shakle(char *b, char *c, int size);

#endif

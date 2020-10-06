#include "menger.h"
/**
 * menger - a function that draws a 2D Menger Sponge.
 * @level: the level of the Menger Sponge to draw.
 */
void menger(int level)
{
int v;
char *spg;
if (level < 0)
return;
if (level == 0)
{
printf("#\n");
return;
}
spg = malloc(sizeof(char) * 3);
v = 0;
spg[0] = '#';
spg[1] = '\n';
spg[2] = '\0';
while (level > v)
{
v++;
spg = lvl(spg, v);
}
printf("%s", spg);
free(spg);
}
/**
 * lvl - a function that augumente level.
 * @spg: this is a sting. 
 * @level: The level to augument.
 * Return: a string.
 */
char *lvl(char *spg, int level)
{
double size;
size = pow((double)3, (double)level);
return (build(spg, (int)size));
}
/**
 * build- a function that returns Merge Sponge.
 * @spg: The first Merge Sponge.
 * @size: size of the Sponge.
 * Return: a string.
 */
char *build(char *spg, int size)
{
int a;    
int length; 
int t;
char *b;
char *c;
char *p;
char *l;
length = (size + 1) * (size / 3) + 1;
b = malloc(sizeof(char) * length);
c = malloc(sizeof(char) * length);
p = strdup((const char *)spg);
l = strtok(p, "\n");
a = 0;
for (t = 0; t < 3; t++)
{
a = border(b, c, a, l, t);
}
c[a] = '\n';
b[a] = '\n';
a++;
l = strtok(NULL, "\n");
while (l)
{
for (t = 0; t < 3; t++)
{
a = border(b, c, a, l, t);
}
c[a] = '\n';
b[a] = '\n';
a++;
l = strtok(NULL, "\n");
}
c[a] = '\0';
b[a] = '\0';
free(p);
free(spg);
spg = shakle(b, c, size);
free(b);
free(c);
return (spg);
}
/**
 * border - function that bulid borders and centers.
 * @b: this is a string.
 * @c: this is a string.
 * @a: this is an index.
 * @l: this is a line.
 * @t: this is an integer.
 * Return: index.
 */
int border(char *b, char *c, int a, char *l, int t)
{
int y;
y = 0;
while (l[y])
{
if (t != 1)
{
c[a] = l[y];
}
else
{
c[a] = ' ';
}
b[a] = l[y];
y++;
a++;
}
return (a);
}
/**
 * shakle - a function that concatenates.
 * @b: this is a string.
 * @c: this is a string.
 * @size: size of the Menger Sponge.
 * Return: a string.
 */
char *shakle(char *b, char *c, int size)
{
char *spg;
int length;
int y;
int a;
length = ((size + 1) * size) + 1;
spg = malloc(sizeof(char) * length);
a = 0;
for (y = 0; b[y]; y++)
{
spg[a] = b[y];
a++;
}
for (y = 0; c[y]; y++)
{
spg[a] = c[y];
a++;
}
for (y = 0; b[y]; y++)
{
spg[a] = b[y];
a++;
}
spg[a] = '\0';
return (spg);
}
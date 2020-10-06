#include "slide_line.h"
/**
 * slide_line - function that slides and merges an array of integer.
 * @line: array of integers.
 * @size: contains size elements.
 * @direction: can be LEFT or RIGHT.
 * Return: 1 or 0.
 */
int slide_line(int *line, size_t size, int direction)
{
size_t r = 0;
size_t l = 1;
size_t var1;
size_t var2;
size_t last;
size_t drap = 0;
if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
return (0);
if (direction == SLIDE_RIGHT)
{
r = size - 1;
l = size - 2;
}
for (var1 = 0; var1 < size; var1++)
{
last = l;
drap = 0;
for (var2 = var1 + 1; var2 < size; var2++)
{
if (line[r] != 0)
{
if (line[l] == line[r])
{
line[r] = line[r] * 2;
line[l] = 0;
break;
}
}
if (line[r] == 0 && line[l] != 0)
{
line[r] = line[l];
line[l] = 0;
drap = 1;
l = last;
var1--;
break;
}
if (line[l] != 0)
break;
direction == SLIDE_LEFT ? l++ : l--;
}
if (line[r] == 0)
break;
if (drap == 0)
{
if (direction == SLIDE_LEFT)
{
r++;
l = r + 1;
}
else if (direction == SLIDE_RIGHT)
{
r--;
l = r - 1;
}
}
}
return (1);
}
#!/usr/bin/python3
''' def island perimeter '''


def island_perimeter(grid):
    ''' def island_perimeter'''
    if not grid:
        return 0
    x = 0
    for y in range(len(grid)):
        for a in range(len(grid[y])):
            if grid[y][a] == 1:
                if y == 0 or grid[y - 1][a] == 0:
                    x += 1
                if a == 0 or grid[y][a - 1] == 0:
                    x += 1
                if y == len(grid) - 1 or grid[y + 1][a] == 0:
                    x += 1
                if a == len(grid[y]) - 1 or grid[y][a + 1] == 0:
                    x += 1
    return x

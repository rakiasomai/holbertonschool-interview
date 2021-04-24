#!/usr/bin/python3
'''def module'''


def pascal_triangle(n):
    '''def pascal trinagle'''

    if n <= 0:
        return []

    p = [[1]]
    if n == 1:
        return p

    for y in range(1, n):
        l = -1
        r = 0
        x = []
        for _ in range(y+1):
            val = 0
            if l > -1:
                val += p[y - 1][l]
            if r < y:
                val += p[y - 1][r]
            l += 1
            r += 1
            x.append(val)
        p.append(x)
    return p

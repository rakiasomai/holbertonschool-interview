#!/usr/bin/python3
''' Queen Module '''
import sys


def pos(a, r, c):
    '''Checks position'''
    for y in range(c):
        if a[y] is r or abs(a[y] - r) is abs(y - c):
            return False
    return True


def ver(a, c):
    '''backtracking '''
    x = len(a)
    if c is x:
        print(str([[y, a[y]] for y in range(x)]))
        return

    for r in range(x):
        if pos(a, r, c):
            a[c] = r
            ver(a, c + 1)

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)
    if sys.argv[1].isdigit() is False:
        print("N must be a number")
        sys.exit(1)
    if int(sys.argv[1]) < 4:
        print("N must be at least 4")
        sys.exit(1)

    a = [0 for c in range(int(sys.argv[1]))]
    ver(a, 0)

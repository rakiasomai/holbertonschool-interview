#!/usr/bin/python3
''' Minimum Oprations '''


def minOperations(n):
    ''' def minOperations '''
    x = 0
    y = 0
    num_h = 1
    num_y = 0

    while (num_h < n):
        if (n % num_h == 0):
            x += 1
            num_y = num_h
        elif (n % (num_h * 2) == 0 and num_h * 2 <= n):
            x += 1
            num_y = num_h
        if num_h + num_y <= n:
            y += 1
            num_h += num_y
    if num_h == n:
        return (x + y)
    return 0

#!/usr/bin/python3
''' function to make a change '''
def makeChange(coins, total):
    ''' Def make change '''
    if total <= 0:
        return 0
    changes = [total + 1] * (total + 1)
    changes[0] = 0
    for x in range(1, total + 1):
        for y in range(0, len(coins)):
            if coins[y] <= x:
                changes[x] = min(changes[x], changes[x - coins[y]] + 1)
    return -1 if changes[total] > total else changes[total]

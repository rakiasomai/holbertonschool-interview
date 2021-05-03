#!/usr/bin/python3
'''def winner module'''


def isWinner(x, nums):
    '''def is winner'''
    if not nums or x < 1:
        return None
    n = max(nums)
    search = [True for _ in range(max(n + 1, 2))]
    for y in range(2, int(pow(n, 0.5)) + 1):
        if not search[y]:
            continue
        for z in range(y * y, n + 1, y):
            search[z] = False
    search[0] = search[1] = False
    b = 0
    for y in range(len(search)):
        if search[y]:
            b += 1
        search[y] = b
    gamer_1 = 0
    for n in nums:
        gamer_1 += search[n] % 2 == 1
    if gamer_1 * 2 == len(nums):
        return None
    if gamer_1 * 2 > len(nums):
        return "Maria"
    return "Ben"

#!/usr/bin/python3
""" CanunlockAll """


def canUnlockAll(boxes):
    """ def canunlockAll """
    if len(boxes) == 0:
        return False
    if type(boxes) is not list:
        return False
    else:
        lock = len(boxes)
    open = [0]    
    for y in open:
        for i in boxes[y]:
            if i not in open:
                if i != y and i < lock and i != 0:
                    open.append(i)
    if len(open) == lock:
        return True
    else:
        return False
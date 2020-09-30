#!/usr/bin/python3
''' UTF-8 '''


def validUTF8(data):
    num_b = 0
    for y in data:
        x = 1 << 7
        if not num_b:
            while x & y:
                num_b += 1
                x >>= 1
            if not num_b:
                continue
            if num_b == 1 or num_b > 4:
                return False
        else:
            if y >> 6 != 0b10:
                return False
        num_b -= 1
    return num_b == 0

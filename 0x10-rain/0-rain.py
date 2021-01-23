#!/usr/bin/python3
''' Module for calculate rain '''


def rain(walls):
    ''' def rain '''
    left_border = 0
    right_border = 0
    min_border = 0
    high_border = len(walls) - 1

    if not walls or len(walls) < 3:
        return 0
    rain_water = 0
    while (min_border <= high_border):
        if (walls[min_border] < walls[high_border]):
            if (walls[min_border] > left_border):
                left_border = walls[min_border]
            else:
                rain_water += left_border - walls[min_border]
            min_border += 1
        else:
            if (walls[high_border] > right_border):
                right_border = walls[high_border]
            else:
                rain_water += right_border - walls[high_border]
            high_border -= 1
    return rain_water
        
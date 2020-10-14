#!/usr/bin/python3
''' comptus matrices '''
import sys


File_size = 0
y = 0
codes = ['200', '301', '400', '401', '403', '404', '405', '500']
status = {'200': 0, '301': 0,
          '400': 0, '401': 0,
          '403': 0, '404': 0,
          '405': 0, '500': 0}

try:
    for line in sys.stdin:
        list = line.split(" ")
        if len(list) > 2:
            code = list[-2]
            i = list[-1]
            if code in codes:
                status[code] += 1
            File_size += int(i)
            y += 1

        if y == 10:
            print("File size: {:d}".format(File_size))
            for x, z in sorted(status.items()):
                if z != 0:
                    print("{}: {:d}".format(x, z))
            y = 0

except Exception:
    pass
finally:
    print("File size: {}".format(File_size))
    for x, z in sorted(status.items()):
        if z != 0:
            print("{}: {}".format(x, z))

#!/usr/bin/python3
''' Matrix Module '''


def rotate_2d_matrix(matrix):
    ''' def rotate matrix '''
    tp_l = zip(*matrix[::-1])
    flex = [list(var) for var in tp_l]

    for y, x in enumerate(flex):
        matrix[y] = flex[y]

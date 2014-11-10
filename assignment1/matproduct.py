#!/usr/bin/env python
# -*- coding: utf-8 -*-

__authors__ = [
    'Jonas Gröger <jonas.groeger@gmail.com>',
    'Sebastian Haubner <seb.haubner@gmail.com>']

# Python 2/3 compatible input, see http://stackoverflow.com/a/5868543/488265
# Python 2: Rename raw_input to input
# Python 3: This will do nothing.
try:
    input = raw_input
except NameError:
    pass


class Matrix(object):
    """The representation of a 2D matrix."""

    def __init__(self, rows, cols):
        self.rows = rows
        self.cols = cols
        self.cells = [0 for _ in range(self.rows * self.cols)]

    def _assert_is_valid_index(self, row, col):
        row_inside_matrix = 0 <= row < self.rows
        column_inside_matrix = 0 <= col < self.cols
        if not all([row_inside_matrix, column_inside_matrix]):
            raise IndexError('Index row={} column={} is outside of matrix.', row, col)

    def _assert_is_multiplyable(self, other_matrix):
        if self.cols != other_matrix.rows:
            raise ValueError('The column count of the first matrix must be equal to the row count of the second.')

    def __mul__(self, other_matrix):
        self._assert_is_multiplyable(other_matrix)

        result = Matrix(self.rows, other_matrix.cols)
        for row in range(self.rows):
            for col in range(other_matrix.cols):
                tmp = result[row, col]
                for k in range(self.cols):
                    tmp_self = self[row, k]
                    temp_other = other_matrix[k, col]
                    tmp += tmp_self * temp_other
                result[row, col] = tmp

        return result

    def __str__(self):
        result = ''
        max_width = len(str(max(self.cells))) + 1
        for i in range(self.rows):
            for j in range(self.cols):
                result += ('{0: <' + str(max_width) + '}').format(self[i, j])
            result += '\n'

        return result

    # m[1,2]
    def __getitem__(self, key):
        row = key[0]
        col = key[1]
        self._assert_is_valid_index(row, col)
        return self.cells[row * self.cols + col]


    # m[1,2] = 5
    def __setitem__(self, key, value):
        row = key[0]
        col = key[1]
        self.cells[row * self.cols + col] = value


def input_int(prompt=''):
    while True:
        try:
            return int(input(prompt))
        except ValueError:
            pass


if __name__ == '__main__':
    print(('=====================================\n'
           'Input dimensions of the two matrices.\n'
           '====================================='))
    s1 = int(input_int('s1: '))
    s2 = int(input_int('s2: '))
    s3 = int(input_int('s3: '))

    A = Matrix(s1, s2)
    B = Matrix(s2, s3)

    print(('=================================\n'
           'Values of matrix one ({} values).\n'
           '================================='
          ).format(s1 * s2))

    for i in range(s1):
        for j in range(s2):
            A[i, j] = input_int()

    print(('=================================\n'
           'Values of matrix two ({} values).\n'
           '================================='
          ).format(s2 * s3))

    for i in range(s2):
        for j in range(s3):
            B[i, j] = input_int()

    print(('=======================================\n'
           'Multiplication of matrices one and two.\n'
           '======================================='
    ))

    print(A * B)

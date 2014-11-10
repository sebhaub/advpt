#!/usr/bin/env python
# -*- coding: utf-8 -*-

__authors__ = ['Jonas Gröger <jonas.groeger@gmail.com>', 'Sebastian Haubner <seb.haubner@gmail.com>']

# Python 2/3 compatible input, see http://stackoverflow.com/a/5868543/488265
# Python 2: Rename raw_input to input
# Python 3: This will do nothing.
try:
    input = raw_input
except NameError:
    pass


class Matrix(object):
    """The representation of a 2D matrix."""

    def __init__(self, rows, columns):
        self.rows = rows
        self.columns = columns
        self.cells = [0 for _ in range(self.rows * self.columns)]

    def _assert_is_valid_index(self, column, row):
        row_inside_matrix = 0 <= row < self.rows
        column_inside_matrix = 0 <= column < self.columns
        if not all([row_inside_matrix, column_inside_matrix]):
            raise IndexError('Index row={} column={} is outside of matrix.', row, column)

    def setEntry(self, i, j, val):
        self._assert_is_valid_index(i, j)
        self.cells[i * self.columns + j] = val

    def _assert_is_multiplyable(self, other_matrix):
        if self.columns != other_matrix.rows:
            raise ValueError('The column count of the first matrix must be equal to the row count of the second.')

    def getEntry(self, row, column):
        self._assert_is_valid_index(row, column)
        return self.cells[row * self.columns + column]

    def __mul__(self, other_matrix):
        self._assert_is_multiplyable(other_matrix)

        result = Matrix(self.rows, other_matrix.columns)
        for row in range(self.rows):
            for column in range(other_matrix.columns):
                tmp = result.getEntry(row, column)
                for k in range(self.columns):
                    tmp_self = self.getEntry(row, k)
                    temp_other = other_matrix.getEntry(k, column)
                    tmp += tmp_self * temp_other
                result.setEntry(row, column, tmp)

        return result

    def __str__(self):
        result = ''
        for i in range(0, self.rows):
            for j in range(0, self.columns):
                result += "[" + str(self.cells[j + i * self.columns]) + "] "
            result += ''

        return result


if __name__ == '__main__':
    s1 = int(input("Matrix A columns: "))
    s2 = int(input("Matrix A columns / Matrix B rows: "))
    s3 = int(input("Matrix B columns: "))

    A = Matrix(s1, s2)
    B = Matrix(s2, s3)

    print("Now enter all the value of of Matrix A (press return after each):")

    for i in range(0, s1):
        for j in range(0, s2):
            val = int(input())
            A.setEntry(i, j, val)

    print("---- Matrix A is ----")
    print(A)
    print("-----------------------")

    print("Now enter all the value of of Matrix B (press return after each")

    for i in range(0, s2):
        for j in range(0, s3):
            val = int(input())
            B.setEntry(i, j, val)

    print("---- Matrix B is ----")
    print(B)
    print("-----------------------")

    print("A*B =")

    C = A * B

    print(C)

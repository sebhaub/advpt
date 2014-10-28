#!/usr/bin/env python3
# -*- coding: utf-8 -*-

__authors__ = ['Jonas Gröger <jonas.groeger@gmail.com>', 'Sebastian Haubner <seb.haubner@gmail.com>']

raw_input = input


class Matrix(object):
    '''The representation of a 2D matrix.'''

    def __init__(self, rows, columns):
        self.rows = rows
        self.columns = columns
        self.cells = [0] * (self.rows * self.columns)

    def _assertIsValidIndex(self, row, column):
        row_too_low = row < 0
        row_too_high = row >= self.rows
        column_too_low = column < 0
        column_too_high = column >= self.columns

        if(any([row_too_low, row_too_high, column_too_low, column_too_high])):
            raise IndexError('Index row={} column={} is outside of matrix.', row, column)

    def setEntry(self, i, j, val):
        self._assertIsValidIndex(i, j)
        self.cells[i * self.columns + j] = val

    def getEntry(self, i, j):
        self._assertIsValidIndex(i, j)
        return self.cells[i * self.columns + j]

    def __mul__(self, other):
        if self.columns != other.rows:
            print("Diese Matrizen koennen leider nicht miteinander multipliziert werden !")
            exit(1)

        result = Matrix(self.rows, other.columns)
        for i in range(0, self.rows):
            for j in range(0, other.columns):
                tmp = result.getEntry(i, j)
                for k in range(0, self.columns):
                    tmpSelf = self.getEntry(i, k)
                    tmpOther = other.getEntry(k, j)
                    tmp += tmpSelf * tmpOther
                result.setEntry(i, j, tmp)

        return result

    def __str__(self):
        result = ''
        for i in range(0, self.rows):
            for j in range(0, self.columns):
                result += "[" + str(self.cells[j + i * self.columns]) + "] "
            result += ''

        return result

if __name__ == '__main__':
    print("Please enter s1 (the Lines of Matrix A) :")
    s1 = int(raw_input(""))
    print("Now enter s2 (the Lines of Matrix B, and the Columns of Matrix A) :")
    s2 = int(raw_input(""))
    print("and now enter s3 (the columns of Matrix B")
    s3 = int(raw_input(""))

    A = Matrix(s1, s2)
    B = Matrix(s2, s3)

    print("Now enter all the value of of Matrix A (press return after each")

    for i in range(0, s1):
        for j in range(0, s2):
            val = int(raw_input(""))
            A.setEntry(i, j, val)

    print("---- Matrix A is ----")
    print(A)
    print("-----------------------")

    print("Now enter all the value of of Matrix B (press return after each")

    for i in range(0, s2):
        for j in range(0, s3):
            val = int(raw_input(""))
            B.setEntry(i, j, val)

    print("---- Matrix B is ----")
    print(B)
    print("-----------------------")

    print("A*B =")

    C = A * B

    print(C)

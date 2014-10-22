class Matrix(object):
    def __init__(self, lines, columns):
        self.lines = lines
        self.columns = columns
        self.Values = [0] * (self.lines * self.columns)

    def setEntry(self, i, j, val):
        if i >= self.lines or j >= self.columns:
            print("Error, wrong index in setentry " + str(i) + " " + str(j))
            exit(1)
        self.Values[i * self.columns + j] = val;

    def getEntry(self, i, j):
        if i >= self.lines or j >= self.columns:
            print("Error, wrong index in setentry " + str(i) + " " + str(j))
            exit(1)
        return self.Values[i * self.columns + j];


    def __mul__(self, other):
        if self.columns != other.lines:
            print"Diese Matrizen koennen leider nicht miteinander multipliziert werden !"
            exit(1)

        result = Matrix(self.lines, other.columns)
        for i in range(0, self.lines):
            for j in range(0, other.columns):
                tmp = result.getEntry(i, j)
                for k in range(0, self.columns):
                    tmpSelf = self.getEntry(i, k)
                    tmpOther = other.getEntry(k, j)
                    tmp += tmpSelf*tmpOther
                result.setEntry(i, j, tmp)

        return result

    def printIt(self):
        for i in range(0, self.lines):
            for j in range(0, self.columns):
                print("[" + str(self.Values[j + i * self.columns]) + "] "),
            print("")


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

print ("---- Matrix A is ----")
A.printIt()
print("-----------------------")

print("Now enter all the value of of Matrix B (press return after each")

for i in range(0, s2):
    for j in range(0, s3):
        val = int(raw_input(""))
        B.setEntry(i, j, val)

print ("---- Matrix B is ----")
B.printIt()
print("-----------------------")

print ("A*B =")

C = A * B

C.printIt()





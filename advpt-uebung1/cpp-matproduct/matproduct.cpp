#include <iostream>
#include <cassert>
#include <stdio.h>
#include <string>
#include <sstream>

using namespace std;

class Matrix{
public:
	Matrix(int rows, int cols){
		assert(rows > 0 && cols > 0);
		this->rows = rows;
		this->columns = cols;
		this->cells = new int[rows*cols];
		for (int i = 0; i < rows*cols; i++){
			cells[i] = 2;
		}
	}

	~Matrix(){
		delete[] cells;
	}

	friend std::ostream& operator<<(std::ostream& os, const Matrix& obj)
	{
		for (int i = 0; i < obj.rows; i++){
			for (int j = 0; j < obj.columns; j++){
				os << obj.cells[i * obj.columns + j] + " a ";
			}
			os << "\n";
		}
		return os;
	}



private:
	int* cells;
	int rows;
	int columns;
};

int input_int() {
	std::string line;
	int val;
	while (std::getline(std::cin, line)) {
		std::stringstream ss(line);
		if (ss >> val) {
			if (ss.eof()) {
				break; // Success
			}
		}
	}
	return val;
}

int main(int argc, char **argv)
{
	int a = input_int();
	int b = input_int();

	Matrix m = Matrix(a, b);
	cout << m << endl;

	return 0;
}


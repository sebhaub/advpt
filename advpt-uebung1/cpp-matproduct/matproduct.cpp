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
		}
	
	protected:
	
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
	
	return 0;
}


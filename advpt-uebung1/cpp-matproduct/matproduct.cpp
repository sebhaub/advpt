#include <iostream>
#include <cassert>
#include <stdio.h>

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



int main(int argc, char **argv)
{
	cout << "hello world" << endl;
	
	int a, b;
	
	cin >> a;
	cin >> b;
	
	Matrix m = Matrix(a, b);
	
	return 0;
}


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
			this->cells = new int[rows*cols];
			for(int i = 0; i < rows*cols; i++){
				cells[i] = 2;
			}
		}
		
		~Matrix(){
			delete[] cells;
		}
		
		friend std::ostream& operator<<(std::ostream& os, const Matrix& obj)
		{
			for(int i = 0; i < obj.rows; i++){
				for(int j = 0; j < obj.columns; j++){
					os << obj.cells[i * obj.columns + j] + " a ";
				}
				os <<  "\n";
			}
			return os;
		}
		

			
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
	cout << m << endl;
			
	return 0;
}


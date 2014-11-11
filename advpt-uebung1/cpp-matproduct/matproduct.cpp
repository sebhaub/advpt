#include <iostream>
#include <cassert>
#include <stdio.h>
#include <string>
#include <sstream>

using std::cout;
using std::cin;
using std::streamsize;
using std::numeric_limits;
using std::endl;

class Matrix{
public:
	Matrix(int rows, int cols){
		assert(rows > 0 && cols > 0);
		this->rows = rows;
		this->columns = cols;
		this->cells = new long[rows*cols];
		for (int i = 0; i < rows*cols; i++){
			cells[i] = 0;
		}
	}

	~Matrix(){
		delete[] cells;
	}


	Matrix Matrix::operator*(const int &other) {
		Matrix result(this->rows, this->columns);
		for (unsigned int i = 0; i < this->rows; i++){
			for (unsigned int j = 0; j < this->columns; j++){
				this->cells[i*this->columns + j] *= other;
			}

		}
		return result;
	}

	Matrix Matrix::operator*(const Matrix &other) {
		assert(this->columns == other.rows);

		Matrix neu(this->rows, other.columns);

		for (unsigned int i = 0; i < this->rows; i++){
			for (unsigned int j = 0; j < other.columns; j++){
				long sum = this->cells[i*this->columns] * other.cells[j];
				for (unsigned int k = 1; k < this->columns; k++){
					sum += this->cells[i*this->rows + k] * other.cells[k*this->rows + j];
				}
				neu.cells[i*this->rows + j] = sum;
			}
		}
		return neu;
	}

	friend std::ostream& operator<<(std::ostream& stream, const Matrix &m)  {
		for (unsigned int i = 0; i < m.rows; i++){
			stream << endl;
			for (unsigned int j = 0; j < m.columns; j++){
				stream << " | " << m.cells[i*m.columns + j] << " | ";
			}
		}


		return stream;
	}

	Matrix &Matrix::operator=(const Matrix &other) {
		if (this->columns != other.columns || this->rows != other.rows){
			return *this;
		}
		else{
			for (unsigned int i = 0; i < this->rows; i++){
				for (unsigned int j = 0; j < this->columns; j++){
					this->cells[i*this->columns + j] = other.cells[i*this->columns + j];
				}
			}
			return *this;
		}
	}

	bool Matrix::operator==(const Matrix &other) {
		if (this->columns != other.columns || this->rows != other.rows){
			return false;
		}
		for (unsigned int i = 0; i < this->rows; i++){
			for (unsigned int j = 0; j < this->columns; j++){
				if (this->cells[i*this->columns + j] == other.cells[i*this->columns + j])
				{
					//fine
				}
				else { return false; }
			}
		}
		return true;
	}

	long* Matrix::operator[](int j){
		long* result;
		result = &this->cells[j*this->columns];
		return result;
	}




private:
	long* cells;
	int rows;
	int columns;
};

void getInputIntegral(long &number){
	number = 0;
	while (!(cin >> number)){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input.  Try again: ";
	}
}


int main(int argc, char **argv)
{
	long a = 0;
	long b = 0;
	getInputIntegral(a);
	getInputIntegral(b);

	Matrix m = Matrix(a, b);

	m[0][0] = 37;
	m[0][1] = 42;
	m[3][3] = 32;
	cout << m << endl;

	return 0;
}


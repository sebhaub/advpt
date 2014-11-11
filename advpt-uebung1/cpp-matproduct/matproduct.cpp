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

		Matrix result(this->rows, other.columns);

		for (unsigned int c = 0; c < this->rows; c++){
			for (unsigned int d = 0; d < other.columns; d++){
				long sum = 0;
				for (unsigned int k = 0; k < other.rows; k++){
					long tmp = this->cells[c*this->columns+k];
					sum += this->cells[c*this->columns+k] * other.cells[k*other.columns+d];
				}
				result[c][d] = sum;
			}
		}
		cout << "RESULT IS " << endl << endl << result << endl << endl;
		return result;
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
		assert(this->columns == other.columns && this->rows == other.rows);
		for (unsigned int i = 0; i < this->rows; i++){
			for (unsigned int j = 0; j < this->columns; j++){
				this->cells[i*this->columns + j] = other.cells[i*this->columns + j];
			}
		}
		return *this;
	}

	bool Matrix::operator==(const Matrix &other) {
		assert(this->columns == other.columns && this->rows == other.rows);

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
	long s1 = 0;
	long s2 = 0;
	long s3 = 0;
	long tmp = 0;

	cout << "Please enter the rows of Matrix A (s1)" << endl;
	getInputIntegral(s1);
	cout << "Please enter the columns of Matrix A (s2)" << endl;
	getInputIntegral(s2);
	cout << "Please enter the rows of Matrix B (s3)" << endl;
	getInputIntegral(s3);


	Matrix m = Matrix(s1, s2);
	Matrix m2 = Matrix(s2, s3);

	cout << "Now start entering the values of Matrix A" << endl;
	for (int i = 0; i < s1; i++){
		for (int j = 0; j < s2; j++){
			cout << "Please enter value for [" << i << "][" << j << "] --> ";
			getInputIntegral(tmp);
			m[i][j] = tmp;
		}
	}

	cout << endl << endl << "Matrix A is " << endl << "--------------" << m << endl << "----------------" << endl << endl;

	cout << "Now start entering the values of Matrix B" << endl;
	for (int i = 0; i < s2; i++){
		for (int j = 0; j < s3; j++){
			cout << "Please enter value for [" << i << "][" << j << "] --> ";
			getInputIntegral(tmp);
			m2[i][j] = tmp;
		}
	}

	cout << endl << endl << "Matrix B is " << endl << "--------------" << m2 << endl << "----------------" << endl << endl;

	Matrix b = (m*m2);
	cout << "RESULT IS " << endl << endl << endl << m << endl;


	return 0;
}


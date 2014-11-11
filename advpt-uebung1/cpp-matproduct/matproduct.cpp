#include <iostream>
#include <cassert>
#include <stdio.h>
#include <string>
#include <limits>  

using std::cout;
using std::cin;
using std::streamsize;
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


	Matrix operator*(const int &other) {
		Matrix result(this->rows, this->columns);
		for (unsigned int i = 0; i < this->rows; i++){
			for (unsigned int j = 0; j < this->columns; j++){
				this->cells[i*this->columns + j] *= other;
			}
		}
		return result;
	}

	Matrix operator*(const Matrix &other) {
		assert(this->columns == other.rows);

		Matrix result(this->rows, other.columns);

		for (unsigned int c = 0; c < this->rows; c++){
			for (unsigned int d = 0; d < other.columns; d++){
				long sum = 0;
				for (unsigned int k = 0; k < other.rows; k++){
					sum += this->cells[c*this->columns+k] * other.cells[k*other.columns+d];
				}
				result[c][d] = sum;
			}
		}
		return result;
	}

	friend std::ostream& operator<<(std::ostream& stream, const Matrix &m)  {
		for (unsigned int i = 0; i < m.rows; i++){
			for (unsigned int j = 0; j < m.columns; j++){
				stream << m.cells[i*m.columns + j] << " ";
			}
			if (i != m.rows - 1) {
				stream << endl;
			}
		}


		return stream;
	}

	Matrix &operator=(const Matrix &other) {
		assert(this->columns == other.columns && this->rows == other.rows);
		for (unsigned int i = 0; i < this->rows; i++){
			for (unsigned int j = 0; j < this->columns; j++){
				this->cells[i*this->columns + j] = other.cells[i*this->columns + j];
			}
		}
		return *this;
	}

	bool operator==(const Matrix &other) {
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

	long* operator[](int i){
		// TODO: Dont just return offset the cells but return a sublist of references
		long* result;
		result = &this->cells[i*this->columns];
		return result;
	}




private:
	long* cells;
	unsigned int rows;
	unsigned int columns;
};

void getInputIntegral(long &number){
	number = 0;
	while (!(cin >> number)){
		cin.clear();
		cin.ignore(std::numeric_limits<long>::max(), '\n');
		cout << ".";
	}
}


int main(int argc, char **argv)
{
	long s1 = 0;
	long s2 = 0;
	long s3 = 0;
	long tmp = 0;

	getInputIntegral(s1);
	getInputIntegral(s2);
	getInputIntegral(s3);


	Matrix m1 = Matrix(s1, s2);
	Matrix m2 = Matrix(s2, s3);

	for (int i = 0; i < s1; i++){
		for (int j = 0; j < s2; j++){
			getInputIntegral(tmp);
			m1[i][j] = tmp;
		}
	}

	for (int i = 0; i < s2; i++){
		for (int j = 0; j < s3; j++){
			getInputIntegral(tmp);
			m2[i][j] = tmp;
		}
	}

	Matrix m3 = (m1*m2);
	cout << m3 << endl;


	return 0;
}


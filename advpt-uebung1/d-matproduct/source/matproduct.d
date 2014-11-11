import std.stdio;
import std.getopt;
import std.c.stdlib;
import std.ascii;
import std.conv;

static bool quiet;

class Matrix {
	private int rows, cols;
	private int[] m;

	this(int rows, int cols, int[] m) {
		this.rows = rows;
		this.cols = cols;
		this.m = m;
	}

	public Matrix opBinary(string op)(Matrix other)
	{
		if(op == "*") {
			int[] m;
			m.length = this.rows * other.cols;
			Matrix result = new Matrix(this.rows, other.cols, m);

			int sum = 0;
			for(size_t c = 0; c < this.rows; ++c) {
				for(size_t d = 0; d < other.cols; ++d) {
					for(size_t k = 0; k < other.rows; ++k) {
						sum += this[c, k] * other[k, d];
					}

					result[c, d] = sum;
					sum = 0;
				}
			}
			return result;
		}
	}

	public void opIndexAssign(int value, size_t row, size_t col) {
		this.m[row * this.cols + col] = value;
	}
	
	public size_t opIndex(size_t row, size_t col) {
		return this.m[row * this.cols + col];
	}
	
	override
	public string toString() {
		string result = "";
		if(!quiet) { result ~= "The matrix looks like this:\n"; }

		for(int row = 0; row < this.rows; ++row) {
			for(int col = 0; col < this.cols; ++col) {
				result ~= to!(string)(this[row, col]);

				bool addSpace = col != this.cols - 1;
				if(addSpace) {
					result ~= " ";
				}
			}
			
			if(row != this.rows - 1) { result ~= newline; }
		}

		return result;
	}
};

static void readf_int(string s, int *obj) {	
	
	while(true) {
		try {
			readf(s, obj);
			return;
		} catch (std.conv.ConvException ex) {}
	}
}

void main(string[] args) {
	bool help;
	getopt(args,
		"quiet|q", &quiet,
		"help|h", &help);

	if(help) {
		writeln("Usage: ./matproduct_d [-q | --quiet] [-h | --help]");
		exit(0);
	}

	int s1, s2, s3;
	readf_int(" %s", &s1);
	readf_int(" %s", &s2);
	readf_int(" %s", &s3);

	int[] first, second;
	first.length = s1 * s2;
	second.length = s2 * s3;

	for(int i = 0; i < first.length; ++i) {
		readf_int(" %s", &first[i]);
	}
	for(int i = 0; i < second.length; ++i) {
		readf_int(" %s", &second[i]);
	}
	

	Matrix a = new Matrix(s1, s2, first);
	Matrix b = new Matrix(s2, s3, second);
	Matrix c = a * b;

	writeln(c.toString());
}

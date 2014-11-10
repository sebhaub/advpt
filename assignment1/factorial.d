import std.stdio;
import std.getopt;
import std.c.stdlib;
import std.bigint;

static bool quiet;
static ulong lookupTable[21] = [
	1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800,
	479001600, 6227020800, 87178291200, 1307674368000, 20922789888000,
	355687428096000,    // 17!
	6402373705728000,   // 18!
	121645100408832000, // 19!
	2432902008176640000 // 20!
];

long askUser(string prompt) {
	long number;
	
	if(!quiet) { write(prompt ~ ": "); }
		
	// Why the space before %s, read here:
	// http://ddili.org/ders/d.en/input.html
	readf(" %s", &number);
	return number;
}

BigInt factorial(ulong n) {
	if(n <= 20) {
		// The cast is nessecary because array lookups cannot be done with ulong types.
		return BigInt(lookupTable[cast(uint) n]);
	}
	
	// Use BigInt to calculate factorial
	BigInt factorial = "51090942171709440000"; // Start at 21! with multiplying
	for(ulong i = 21; i < n; ++i) {
		factorial *= i + 1;
	}
	
	return factorial;
}

void main(string[] args) {
	long n;
	bool help;
	getopt(args,
		"number|n", &n,
		"quiet|q", &quiet,
		"help|h", &help);
	
	if(help) {
		writeln("Usage: ./factorial_d -n=<number> [-q | --quiet] [-h | --help]");
		exit(0);
	}
	
	if(!n) {
		n = askUser("Please enter a number");
	}
	
	if(n < 0) {
		if(!quiet) { stderr.writefln("Error: Factorial is not defined for negative numbers."); }
		exit(-1);
	}
	
	writeln(factorial(n));
}
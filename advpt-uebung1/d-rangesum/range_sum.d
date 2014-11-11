import std.stdio;
import std.algorithm;
import std.range;
import std.getopt;
import std.c.stdlib;

static bool quiet;

int askUser(string prompt) {
	int number;
	
	if(!quiet) { write(prompt ~ ": "); }
		
	// Why the space before %s, read here:
	// http://ddili.org/ders/d.en/input.html
	readf(" %s", &number);
	return number;
}

void main(string[] args) {
	bool help;
	getopt(args,
		"quiet|q", &quiet,
		"help|h", &help);
	
	if(help) {
		writeln("Usage: ./range_sum_d [-q | --quiet] [-h | --help]");
		exit(0);
	}
	
	int start = askUser("Please enter number one");
	int stop = askUser("Please enter number two");
	
	if(start > stop) {
		swap(start, stop);
	}
	
	long sum = sum(iota(start, stop));
	
	if(quiet) {
		writeln(sum);
	} else {
		writefln("Die Summe der Zahlen von %s (inkl.) bis %s (exkl.) ist: %s.", start, stop, sum);
	}
}
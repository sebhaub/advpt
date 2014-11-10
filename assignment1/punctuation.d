import std.stdio;
import std.getopt;
import std.c.stdlib;
import std.math;
import std.ascii;
import std.range;

static bool quiet;

void main(string[] args) {
	bool help;
	getopt(args,
		"quiet|q", &quiet,
		"help|h", &help);
	
	if(help) {
		writeln("Usage: ./punctuation_d infile [-q | --quiet] [-h | --help]");
		exit(0);
	}
	
	dchar[] buf;
	while(readln(buf)) {
		foreach (c; stride(buf, 1)) {
			if(!isPunctuation(c)) {
				write(c);
			}
        }
	}
}
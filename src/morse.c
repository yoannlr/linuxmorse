#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define MAX_LINE 2048

void putmorse(char c) {
	switch(c) {
		case '\n': putchar('/'); break;
		case ' ': putchar('/'); break;
		case 't': putchar('-'); break;
		case 'e': putchar('.'); break;
		case 'm': putchar('-'); putchar('-'); break;
		case 'n': putchar('-'); putchar('.'); break;
		case 'a': putchar('.'); putchar('-'); break;
		case 'i': putchar('.'); putchar('.'); break;
		case 'o': putchar('-'); putchar('-'); putchar('-'); break;
		case 'g': putchar('-'); putchar('-'); putchar('.'); break;
		case 'k': putchar('-'); putchar('.'); putchar('-'); break;
		case 'd': putchar('-'); putchar('.'); putchar('.'); break;
		case 'w': putchar('.'); putchar('-'); putchar('-'); break;
		case 'r': putchar('.'); putchar('-'); putchar('.'); break;
		case 'u': putchar('.'); putchar('.'); putchar('-'); break;
		case 's': putchar('.'); putchar('.'); putchar('.'); break;
		case '?': putchar('-'); putchar('-'); putchar('-'); putchar('-'); break;
		case '.': putchar('-'); putchar('-'); putchar('-'); putchar('.'); break;
		case 'q': putchar('-'); putchar('-'); putchar('.'); putchar('-'); break;
		case 'z': putchar('-'); putchar('-'); putchar('.'); putchar('.'); break;
		case 'y': putchar('-'); putchar('.'); putchar('-'); putchar('-'); break;
		case 'c': putchar('-'); putchar('.'); putchar('-'); putchar('.'); break;
		case 'x': putchar('-'); putchar('.'); putchar('.'); putchar('-'); break;
		case 'b': putchar('-'); putchar('.'); putchar('.'); putchar('.'); break;
		case 'j': putchar('.'); putchar('-'); putchar('-'); putchar('-'); break;
		case 'p': putchar('.'); putchar('-'); putchar('-'); putchar('.'); break;
		case 'l': putchar('.'); putchar('-'); putchar('.'); putchar('.'); break;
		case '-': putchar('.'); putchar('.'); putchar('-'); putchar('-'); break;
		case 'f': putchar('.'); putchar('.'); putchar('-'); putchar('.'); break;
		case 'v': putchar('.'); putchar('.'); putchar('.'); putchar('-'); break;
		case 'h': putchar('.'); putchar('.'); putchar('.'); putchar('.'); break;
		case '0': putchar('-'); putchar('-'); putchar('-'); putchar('-'); putchar('-'); break;
		case '9': putchar('-'); putchar('-'); putchar('-'); putchar('-'); putchar('.'); break;
		case '8': putchar('-'); putchar('-'); putchar('-'); putchar('.'); putchar('.'); break;
		case '7': putchar('-'); putchar('-'); putchar('.'); putchar('.'); putchar('.'); break;
		case '6': putchar('-'); putchar('.'); putchar('.'); putchar('.'); putchar('.'); break;
		case '1': putchar('.'); putchar('-'); putchar('-'); putchar('-'); putchar('-'); break;
		case '2': putchar('.'); putchar('.'); putchar('-'); putchar('-'); putchar('-'); break;
		case '3': putchar('.'); putchar('.'); putchar('.'); putchar('-'); putchar('-'); break;
		case '4': putchar('.'); putchar('.'); putchar('.'); putchar('.'); putchar('-'); break;
		case '5': putchar('.'); putchar('.'); putchar('.'); putchar('.'); putchar('.'); break;
		default: fprintf(stderr, "putmorse: can't convert '%c'\n", c); break;
	}
	putchar(' ');
}

int main() {
	int nbytes;
	char* buffer = (char*) malloc(sizeof(char) * MAX_LINE);
	char* buffptr = buffer;

	while((nbytes = read(STDIN_FILENO, buffer, MAX_LINE)) > 0) {
		buffptr = buffer;
		while(*buffptr) {
			putmorse(tolower(*buffptr));
			buffptr++;
		}
	}
	putchar('\n');

	if(errno != 0) perror("Reading from stdin (read)");
}

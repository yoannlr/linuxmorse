#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_LINE 2048

void printchar(int morse) {
	switch(morse) {
		case 2: putchar('E'); break;
		case 3: putchar('T'); break;
		case 4: putchar('I'); break;
		case 6: putchar('A'); break;
		case 5: putchar('N'); break;
		case 7: putchar('M'); break;
		case 8: putchar('S'); break;
		case 12: putchar('U'); break;
		case 10: putchar('R'); break;
		case 14: putchar('W'); break;
		case 9: putchar('D'); break;
		case 13: putchar('K'); break;
		case 11: putchar('G'); break;
		case 15: putchar('O'); break;
		case 16: putchar('H'); break;
		case 24: putchar('V'); break;
		case 20: putchar('F'); break;
		case 28: putchar('-'); break;
		case 22: putchar('P'); break;
		case 30: putchar('J'); break;
		case 21: putchar('C'); break;
		case 18: putchar('L'); break;
		case 25: putchar('X'); break;
		case 17: putchar('B'); break;
		case 29: putchar('Y'); break;
		case 19: putchar('Z'); break;
		case 27: putchar('Q'); break;
		case 23: putchar('.'); break;
		case 31: putchar('?'); break;
		case 63: putchar('0'); break;
		case 47: putchar('9'); break;
		case 39: putchar('8'); break;
		case 35: putchar('7'); break;
		case 33: putchar('6'); break;
		case 62: putchar('1'); break;
		case 60: putchar('2'); break;
		case 56: putchar('3'); break;
		case 48: putchar('4'); break;
		case 32: putchar('5'); break;
		case 255: putchar(' '); break;
		default: putchar('x');
	}
}

int main() {
	int nbytes;
	char* buffer = (char*) malloc(sizeof(char) * MAX_LINE);
	int i = 0, n = 0, mc = 0;

	while((nbytes = read(STDIN_FILENO, buffer, MAX_LINE)) > 0) {
		i = 0;
		while(*(buffer + i)) {
			if(*(buffer + i) == '-') n |= 1 << mc;
			else if(*(buffer + i) == '/') {
				n = 0xFF;
			} else if(*(buffer + i) == ' ') {
				n |= 1 << mc;
				printchar(n);
				n = 0;
				mc = -1;
			}
			mc++;
			i++;
		}
	}
	putchar('\n');

	if(errno != 0) perror("Reading from stdin (read)");
}

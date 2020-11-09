all: morse unmorse
morse: src/morse.c
	gcc -Wall -o morse src/morse.c
unmorse: src/unmorse.c
	gcc -Wall -o unmorse src/unmorse.c
morseplay:
	gcc -Wall -o morseplay -lopenal -lm src/morseplay.c
clean:
	rm morse unmorse




all:
	gcc -O3 -march=native -mtune=native -lgmp -Wall main.c gm.c -o speedtest
	gcc -O3 -march=native -mtune=native -lgmp -Wall sizetest.c gm.c -o sizetest

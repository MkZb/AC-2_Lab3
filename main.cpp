#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]){
	int rez = 0;

	while ((rez = getopt(argc, argv, "ab:C::d")) != -1) {
		switch (rez) {
		case 'a': printf("found argument \"a\".\n"); break;
		case 'b': printf("found argument \"b = %s\".\n", optarg); break;
		case 'C': printf("found argument \"C = %s\".\n", optarg); break;
		case 'd': printf("found argument \"d\"\n"); break;
		case '?': printf("Error found !\n"); break;
		};
	};

	puts("123");
	system("pause");
	};
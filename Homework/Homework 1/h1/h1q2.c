/* This C program demonstrates the switch statement without using breaks. */
/* The program is tested on MS Visual C++ platform */
#include <stdio.h>
#pragma warning(disable : 4996) // Remove this line in Unix GCC environment
void main() {
	char ch;
	int f, a = 10, b = 20;
	double x;
	for (int i = 1; i <= 5; i++) {
		ch = getchar();
		printf("ch = %c\n", ch);
		switch (ch)
		{
		case '+': f = a + b; printf("f = %d\n", f); break;
		case '-': f = a - b; printf("f = %d\n", f); break;
		case '*': f = a * b; printf("f = %d\n", f); break;
		case '/': x = (double)a / (double)b; printf("f = %.2f\n", x); break;
		default: printf("invalid operator\n");

		}
		getchar();
	}
}
/* some differences that I noticed between the 2 IDE's are the the they compile their code differently , for example 
in gcc you can't intialize the sentinel value of a for loop inside the loop while in visual studio you can. another difference was
that the debugging tool for gcc is more helpful than in visual studio.*/
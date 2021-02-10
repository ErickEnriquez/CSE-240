/* This C program demonstrates the switch statement without using breaks. */
/* The program is tested on MS Visual C++ platform */
#include <stdio.h>
#pragma warning(disable : 4996) // Remove this line in Unix GCC environment
void main() {
	char ch;
	int f, a = 10, b = 20 ,i=1;
	double x;
	while(i<=5) {
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
		i++;
	}
}
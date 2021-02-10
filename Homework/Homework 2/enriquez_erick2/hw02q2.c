#include <stdio.h>

int subf(int a, int b) {
	return a - b;
}

int cubef(int a) {
	return a * a * a;
}

int minf(int a, int b) {
	if (a <= b) {
		return a;
	}
	else {
		return b;
	}
}

int oddf(int a) {
	if (a % 2 == 0) {
		return 0;
	}
	else {
		return 1;
	}
}

#define subm(a,b) (a-b)
#define cubem(a) (a*a*a)
#define minm(a,b) ((a>=b) ? b : a)
#define oddm(a) (((a % 2) == 0) ? 0 : 1)
void main()
{
	int a = 5, b = 7;

	printf("function: %d - %d = %d \n",a,b,subf(a, b));// prints subf function value 
	printf("macro: %d - %d = %d \n\n",a,b ,subm(a, b)); //prints subm macro value

	printf("function: %d - %d = %d \n",a,b, subf(a++, b--));//print subf
	printf("macro: %d - %d = %d \n\n",a,b, subm(a++, b--));//print subm

	a = 5;//reset value
	printf("function: %d cubed = %d \n", a , cubef(a));//print cubef
	printf("macro: %d cubed = %d \n\n", a , cubem(a));//print cubm

	a = 5 ;//reset value
	printf("function: %d cubed =  %d \n" , a , cubef(--a));//print cubef
	a = 5;//reset value
	printf("macro: %d cubed = %d \n\n" , a , cubem(--a));//print cubem
	
	a = 5, b = 7;// reset the values of a and b
	printf("function: min of %d and %d is %d \n",a,b, minf(a,b));//print minf
	printf("macro: min of %d and %d is %d \n\n",a,b, minm(a,b));//print minm

	printf("function: min of %d and %d is %d \n",a,b, minf(--a, --b));//print minf
	a = 5, b = 7;// reset the values of a and b
	printf("macro: min of %d and %d is %d \n\n",a,b,minm(--a, --b));//print minm

	a = 5; // reset the value of a
	printf("function:is %d odd? %d \n",a, oddf(a));//print oddf
	printf("macro: is %d odd? %d \n\n",a, oddm(a));//print oddm

	printf("function: is %d odd? %d \n",a, oddf(a++));//print oddf
	a = 5;// reset value of a
	printf("macro: is %d odd? %d \n\n",a, oddm(a++));//print oddm

}

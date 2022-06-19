#include <stdio.h>
#include "libra.h"


void addition(int a, int b)
{
	printf("Addition of  %d and  %d is: %d\n",a,b,a+b);

}


void substract(int a, int b)
{
	printf("Substraction of %d and %d is: %d\n",a,b,a-b);
}

void mul(int a, int b)
{
	printf("Multiplication of  %d and %d is: %d\n",a,b,a*b);
}

void division(int a, int b)
{
	if(b ==0)
	{
	printf("\nDivisor can't be. Please enter another value");
	scanf("%d",&b);
	}

	float x = a /b;	
	printf("Division of %d and %d is: %.2f",a,b,x);
}

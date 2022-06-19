#include <stdio.h>
#include "libra.h"
#include <stdlib.h>





int main()
{
	//Delcaration of local variable;

	int option, a, b;
	
	do
	{
		//display the multiple operations of the C basic calculator
		printf("Select an operation to perform the calculation inc C basic calculator\n");
		printf(" 1: Addition \t\t 2: Substraction \n 3: Multiplication \t\t 4: Division \n 5: Exit \n\n Please make your choice: ");
		//Accepts a numeric input to choose the operation
		scanf("%d",&option);
		
		if(option == 5)
		{
			printf("Turn off your calculator\n");
			exit(0);	
		}		
		
                //Accepts input for operation
                printf("\n Enter first number: ");
                scanf("%d",&a);
                printf("\n Enter second number: ");
                scanf("%d",&b);
		//Switch_case statement to call an operation
		
		switch(option)
		{
			case 1:
			//Add two numbers
			addition(a,b);
			break;

			case 2:
			//Substract two numbers
			substract(a,b);
			break;


			case 3:
			//Multiplication of the numbers
			mul(a,b);
			break;

			case 4:
			//Division of the numbers
			division(a,b);
			break;	
			

			default:
			printf("Something is wrong! Please check the options");
			break;		
	}		

	
		printf("\n\n<=====================================================================>\n");
	}
	while(option != 5);
	
	
	return 0;
}


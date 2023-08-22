#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "mainh.h"
#define MONTHS 12

// Above includes different libraries and variablies used around the program.

int main(int argc, char *argv[]) {
	

struct salesRecord sales[MONTHS]; //Iniitalizes an array of structures defined from the header file.
	
while(1){ //This while loops keeps the programing running while the user does not input the function "Quit".

	printTitle(); //Prints the title
	printMenu(); //Prints the menu and the list of commands.
		
	char input[5]; //Creates a string to receive the input of the user. Below grabs the user input and stores it here.
	printf("Please input command: ");
	scanf("%s", input);
	
	
	if(strcmp(input,"Show") == 0) 
		{
			show();
		}else if(strcmp(input, "Quit") == 0){ //If the user inputs 'Quit', then the program will quit.
			quit();
		}else if(strcmp(input, "Total") == 0){//If the user inputs "total", then it will use the total fuction and add the total amount of sales.
			readFile(sales);
			total(sales);
		} else if(strcmp(input, "Max") == 0){//if the user inputs "max", then the program will grab the max sales from the text file.
			readFile(sales);
			max(sales);
		}else if(strcmp(input, "Min") == 0){//If the user inputs "min", then the program will grab the minimum sales from the text file.
			readFile(sales);
			min(sales);
		}else if(strcmp(input, "Edit") == 0){//If the user inputs "Edit", then the program will edit the month sales of the month the user requested, and save it into the monthly_sales.txt file.
			readFile(sales);
			edit(sales);
			writeFile(sales);
		} else if(strcmp(input, "View") == 0){// If the user inputs "view" then the program will view a specified month the user inputed.
			readFile(sales);
			view(sales);
		} else { // if the user doesn't key in the exact wording from the menu, then this error will appear.

		
		puts("Error: Invalid Command. Please try again!\n\n");
	}
	
		
}
	return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "mainh.h"
#define MONTHS 12
#define MONTH_SIZE 4

void printTitle() //This function prints the name of the system.
	{
		printf("\n---Product Sales Management System---\n\n");
	}
	
void printMenu() //This function calls the menu and commands. Shows what commands there are and what each command does.
	{
		printf("Show - Display all sales records.\n");
		printf("View - View an amount of a specified month.\n");
		printf("Max - View the highest sales amount.\n");
		printf("Min - View the lowest sales amount.\n");
		printf("Edit - Edit an amount of a specified month.\n");
		printf("Total - Get the total of all sales.\n");
		printf("Quit - Terminate the program.\n\n");
	}
	
	
void readFile(struct salesRecord *sales) //This functino readFile reads the monthly_sales.txt file, and stores the data into an array of structures. 
{
    FILE *ptr;
    char line[LINE_SIZE]; //States char line with LINE_SIZE
    char * substring; //Char pointer substring
    int i, j;

    ptr = fopen("monthly_sales.txt", "r"); //This opens the txt file which contains the months and sales records.

    if(ptr == NULL) //if ptr is null, the file wont open, and prints the statement below.
    {
        puts("Unable to open the file.");
    }else{ //Otherwise, i equals 0, and a white loop commences, which reads through the txt file, and when finished, changes the value to 1, and ends the while loop.
        i = 0;

        while(feof(ptr) == 0)
        {
            fgets(line, LINE_SIZE, ptr);
            substring = strtok(line, "\t");
            j = 0;

            while(substring != NULL) //If it is not null, then itll go through the array and read the strings.
            {
                if(j == 0)
                {
                    strcpy(sales[i].month, substring);
                    j = 1;
                } else{
                    sales[i].amount = atof(substring);
                }

                substring = strtok(NULL, "\t");
            }
            i++;
        }
    }

    fclose(ptr); //Closes the file
}


void writeFile(struct salesRecord *sales) //This writes the array back to the text file.
{
    FILE *ptr2;
//    char line[LINE_SIZE];

    ptr2 = fopen("monthly_sales.txt", "w");

    if(ptr2 == NULL)
    {
        puts("Unable to open the file.");
    }else
    {
        for(int i = 0; i < MONTHS; i++)
        {
            fprintf(ptr2, "%s\t%.2lf\n", sales[i].month, sales[i].amount);
        }
    }

    fclose(ptr2);
}

void show() //This function reads the file, and displays all the values and months for the user.
	{
		FILE *fh; //Assigns a file pointer.
		char display;
		
		fh = fopen("monthly_sales.txt","r"); //Reads the file
		
		if(fh != NULL)
		{
			printf("File opened up successfully. Loading file...\n"); //if it works, then it'll print the file, otherwise it prints the statement below.
		} else {
			printf("Error Opening the File. \n");
		}
		
		do
		{
			display = fgetc(fh);	
			printf("%c", display);
			
		} while (display != EOF); {
			
			fclose(fh);
		}
		
		
	}
		
void view(struct salesRecord *sales){ //This function views a specified month of the user
	char viewMonth[MONTH_SIZE];
	printf("Please input your 3 letter month: "); //Asks for a 3 letter month
	scanf("%s", viewMonth);
	
	for(int i = 0; i < MONTHS; i++){ //iterates through the array and finds the specified month.
		if((strcmp(viewMonth, sales[i].month) == 0)){
			printf("The sales amount of %s: $%.2lf\n]n", sales[i].month, sales[i].amount); // prints the specified month
			break;
		}
	}
	
}

void max(struct salesRecord *sales) //This function finds the highest sale
{
	double maxSale = 0;//This variable maxSale saves the first sales value.
	
	for(int i = 0; i < MONTHS; i++){ //This for loop compares the values with the value saved in the variable, and if the highest, saves the highest value.
		if(sales[i].amount > maxSale){
			maxSale = sales[i].amount;
		}
	}
	
	printf("Max Sale: %.2lf", maxSale);
}

void min(struct salesRecord *sales) //This function finds the lowest sale
{
	double minSale = sales[0].amount; //This variable minSale saves the first sales value.
	
	for(int i = 0; i < MONTHS; i++){ //This for loop compares the values with the value saved in the variable, and if lower, saves the lowest value.
		if(minSale > sales[i].amount){
			minSale = sales[i].amount;
		}
	}
	
	printf("Min Sale: %.2lf\n\n", minSale); //prints the lowest value
}

void edit(struct salesRecord *sales){//This function edits the sales record of the specified month by the user.
	double inputNew; //This holds the new sales.
	char monthSales[MONTH_SIZE];
	
	printf("Please input the 3 letter month for the desired sales amount: "); //Asks user to input 3 letter month character and saves the month.
	scanf("%s", monthSales);
	printf("Please input the new sales amount for the month: "); //Asks ser to input new sales amount, then saves amount.
	scanf("%lf", &inputNew);
	
	for(int i = 0; i < MONTHS; i++){ //This for loop iteartes through the arrays and saves the new amount. 
		if(strcmp(monthSales, sales[i].month) == 0){ // This if statement makes sure that the month is alligned with the month in the array
			sales[i].amount = inputNew;
			printf("New Amount: $%.2lf\n\n", sales[i].amount); 
			break;
		}
	}
	
}

void total(struct salesRecord *sales) //The function "total" searches through the txt file and adds all the sales together.
{
	double totalSales = 0; //Creates a double variable that stores 0, so that when we add, the value goes up.
	
	for(int i = 0; i < MONTHS; i++){ //This for loop statement iterates through the array and adds all the values.
		totalSales = totalSales + sales[i].amount;	
	}	
	
	printf("Total sales: %.2lf\n\n", totalSales); //This statement prints the values.
}

void quit() //The function "quit" stops the while loop when the user inputs "quit".
{
	puts("Thank you and have a great day.");
	exit(0); //This statement closes the program.
}



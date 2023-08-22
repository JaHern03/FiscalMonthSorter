#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "mainh.h"
#define MONTHS 12
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	

struct salesRecord sales[MONTHS];	
	
while(1){

	printTitle();
	printMenu();
		
	char input[5];
	printf("Please input command: ");
	scanf("%s", input);
	
	
	if(strcmp(input,"Show") == 0)
		{
			show();
		}else if(strcmp(input, "Quit") == 0){
			quit();
		}else if(strcmp(input, "Total") == 0){
			readFile(sales);
			total(sales);
		} else if(strcmp(input, "Max") == 0){
			readFile(sales);
			max(sales);
		}else{
		puts("Error: Invalid Command. Please try again!\n\n");
	}
	
		
}
	return 0;
}
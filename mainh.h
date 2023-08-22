#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MONTHS 12
#define MONTH_SIZE 4
#define LINE_SIZE 50

struct salesRecord{ //Arrays of struct
	char month[MONTH_SIZE];
	double amount;
};

// ALl these lines below are function declarations, which declare the functions that are written in the function.c file.

void readFile(struct salesRecord *sales); // Declaration for readFile
void writeFile(struct salesRecord *sales); // Declaration for writeFile
void total(struct salesRecord *sales); // Declaration for total
void maxSale(struct salesRecord *sales); //Delaration for maxSale
void minSale(struct salesRecord *sales); //Declaration for minSale
void edit(struct salesRecord *sales); //Declaration for edit
void view(struct salesRecord *sales); //Declaratoin for view
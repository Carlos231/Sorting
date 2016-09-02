//test_list.c

/* (90 pts) To begin getting ready for CS 261, you will write a C program that fills and sorts a linked list of integers. Make sure your program compiles using gcc and the following list.h and test_list.c files on the ENGR server!!! You will modify test_list.c and write your own list.c implementation for all the following functions in the list.h file.
Reminder: This last assignment is not demoed for a grade. The TAs will compile, run,and grade you program based on what was submitted to TEACH. */


/******************************************************
** Program: test_list.c
** Author: Carlos Lopez-Molina
** Date: 06/03/2016
** Description: Modified files and completed functions creating a C program that fills and sorts a linked list of integers.
** Input: List of positive integers and file
** Output: new list
******************************************************/
#include "list.h"

int main (){
	char filename[20];
	struct list l;
	FILE *fileptr;
	char num[3]; //We will read positive integers 0-99 - c style string
	int value, location;
	
	printf("Enter filename: ");
	scanf("%s", filename);
	fileptr = fopen (filename,"r");
	
	//continue reading until we are at the end of the file
	while (fscanf(fileptr, "%s", num)!= EOF)
	{
		printf("number is: %d\n", atoi(num));
		push_front(&l, atoi(num)); //push to front of list
		push_back(&l, atoi(num)); //push to back of list

	}
	printf("Length of list: %d\n", length(l)); //print length of list
	print(l); //print the contents of the list
	sort_ascending(&l);//sort in ascending order
	print(l); //print the contents of the list
	sort_descending(&l); //sort in descending order
	print(l); //print the contents of the list
	
	//prompt user for the value/integer to remove from list
	printf("Enter a value/integer to remove from list: ");
	scanf("%d", &value);
	
	remove_val(&l, value); //remove specific value/integer from list
	print(l); //print the contents of the list
	
	//prompt user for item/int to add and location in list
	printf("Enter a item/int to add and the location from list: ");
	scanf("%d %d", &value, &location);
	
	insert(&l, value, location);//insert int into specific location
	print(l); //print the contents of the listt
	
	clear(&l); //clear list – no memory leaks
	
	fclose (fileptr);
	
	return 0;
}

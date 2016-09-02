/******************************************************
** Program: test_list.c
** Author: Carlos Lopez-Molina
** Date: 06/03/2016
** Description: Modified files and completed functions creating a C program that fills and sorts a linked list of integers.
** Input: List of positive integers and file
** Output: new list
******************************************************/

#include <stdio.h>
#include <stdlib.h>

struct node {
	int val;
	struct node *next;
	struct node *prev;
};

struct list {
	struct node *head;
	struct node *tail;
};

int length(struct list); //return number of nodes in list
void print(struct list); //print the values in list
void push_front(struct list *, int);//push to front of list
void push_back(struct list *, int); //push to end of list
void clear(struct list *); //remove all nodes from list
void remove_val(struct list *, int); //remove nodes w/ int as val
void sort_ascending(struct list *);
void sort_descending(struct list *);
//insert into a location in the list, start at 0 for front
void insert(struct list *, int, int);


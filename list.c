/******************************************************
 ** Program: test_list.c
 ** Author: Carlos Lopez-Molina
 ** Date: 06/03/2016
 ** Description: Modified files and completed functions creating a C program that fills and sorts a linked list of integers.
 ** Input: List of positive integers and file
 ** Output: new list
 ******************************************************/
#include "list.h"

/* struct node {
	int val;
	struct node *next; // points to next value in list of nodes
	struct node *prev; // points to previous value in list of nodes
	};

	struct list { //contains node list linked together in a chain
	struct node *head;
	struct node *tail;
	}; */

/*********************************************************************
 ** FUNCTION: length
 ** DESCRIPTION: Returns number of nodes in list
 ** PARAMETERS: struct list
 ** PRE-CONDITIONS: list of nodes
 ** POST-CONDITIONS: nothing happens to list of nodes
 ** RETURNS: sizeof(ugly)
 *********************************************************************/
int length(struct list ugly){ //return number of nodes in list
	// as seen in notes
	struct node *temp;
	int size = 0;

	temp = ugly.head;
	while (temp != NULL){ //until reach null in list - end
		//printf("Number is: %d\n ", temp->val);
		size++;
		temp = temp->next; //set to pointer to next node
	}
	free(temp);

	return size;
}

/*********************************************************************
 ** FUNCTION: print
 ** DESCRIPTION: prints the values in the list
 ** PARAMETERS: struct list
 ** PRE-CONDITIONS: list of nodes made with values inside
 ** POST-CONDITIONS: nothing happens to the list
 ** RETURNS: nothing
 *********************************************************************/
void print(struct list ugly){ //print the values in list
	//as seen in notes
	struct node *temp;

	temp = ugly.head;
	while (temp != NULL){ //print until reach NULL node
		printf("List number is: %d\n ", temp->val);
		temp = temp->next; //set temp pointer to next node
	}
	free(temp);
}

/*********************************************************************
 ** FUNCTION: push_front
 ** DESCRIPTION: push value to front of list
 ** PARAMETERS: struct list *, int num
 ** PRE-CONDITIONS: list of nodes made
 ** POST-CONDITIONS: value added to the front of this list
 ** RETURNS: nothing
 *********************************************************************/

void push_front(struct list *s, int num){ //push to front of list
	struct node *ugly = (struct node *) malloc(sizeof(struct node));
	//make sure not pointing to anything
	ugly->next = NULL;
	ugly->prev = NULL;
	ugly->val = num;

	//set prev to point to previous nodes address
	//set next to point to next address
	//head should point to next pointer for keeping track of each node in list
	if (s->head == NULL){ //if list is empty
		s->head = ugly;
	}
	else {
		ugly->next = s->head; //next point to head
		ugly->prev = ugly; //set prev to point ugly address
		s->head = ugly; //set head to point to ugly address
	}
}

/*********************************************************************
 ** FUNCTION: push_back
 ** DESCRIPTION: adds value to the end of the list
 ** PARAMETERS: struct list *, int num
 ** PRE-CONDITIONS: List of nodes made
 ** POST-CONDITIONS: value added to the end of the list
 ** RETURNS: nothing
 *********************************************************************/
void push_back(struct list *s, int num){ //push to end of s
	struct node *ugly = (struct node *) malloc(sizeof(struct node));
	ugly->next = NULL;
	ugly->prev = NULL;
	//ugly->val = num;

	if (s->tail == NULL){ //if list is empty
		s->tail = (struct node *) malloc(sizeof(struct node));
		s->tail->next = NULL;
		s->tail->val = num;
		s->head = s->tail;
	}
	ugly = s->tail;
	s->tail = (struct node *) malloc(sizeof(struct node));
	s->tail->prev = ugly;
	s->tail->val=num;
	ugly->next = s->tail;
	s->tail->next = NULL;		 
}

/*********************************************************************
 ** FUNCTION: clear
 ** DESCRIPTION: removes values from list and frees all memory
 ** PARAMETERS: struct list
 ** PRE-CONDITIONS: list of nodes made
 ** POST-CONDITIONS: list of nodes deleted
 ** RETURNS: nothing
 *********************************************************************/
void clear(struct list *s){ //remove all nodes from list
	//as seen in notes
	struct node *temp;
	temp = s->head;
	while (temp != NULL){
	//free each node in list
		s->head = temp->next;
		free(temp);
		temp = s->head;
	}
	//free(temp);
}

/*********************************************************************
 ** FUNCTION: remove_val
 ** DESCRIPTION: removes the value given from the list
 ** PARAMETERS: struct list *, int num
 ** PRE-CONDITIONS: list with values
 ** POST-CONDITIONS: list with values minus the number
 ** RETURNS: nothing
 *********************************************************************/
/* struct node {
	int val;
	struct node *next; // points to next value in list of nodes
	struct node *prev; // points to previous value in list of nodes
	};

	struct list { //contains node list linked together in a chain
	struct node *head;
	struct node *tail;
	}; */

void remove_val(struct list *ugly, int num){ //remove nodes w/ int as val
	//remove link to that value and point it to value next in list
	//free memory of that node with values position
	// 2 times to get copy
	
	//checks head
	if (ugly->head->val == num) { 
			struct node* temp = ugly->head;
			ugly->head= ugly->head->next;
			temp->next = NULL;
			temp->prev= NULL;
			free(temp);                       
	}
	//checks for tail
	else if (ugly->head == ugly->tail){
			ugly->head->prev->next = NULL;
			ugly->tail = ugly->head->prev;
	}
	//anywhere else
	else {
		struct node* temp = ugly->head;
		while (temp->next->val != num)
			temp = temp->next;

		struct node* temp2 = temp->next;
		temp->next = temp2->next;
		temp2->next->prev = temp;

		temp2->next = NULL;
		temp2->prev = NULL;
		free(temp2);      
	}
}

/*********************************************************************
 ** FUNCTION: sort_ascending
 ** DESCRIPTION: sorts values of list in ascending order
 ** PARAMETERS: struct list *
 ** PRE-CONDITIONS: list of values
 ** POST-CONDITIONS: list of values arranged in ascending order
 ** RETURNS: nothing
 *********************************************************************/
void sort_ascending(struct list *s){
	//bubble sort from notes
	printf("Ascending order: \n");
	struct node *ugly; //= (struct node *) malloc(sizeof(struct node));;
	int size = length(*s);
	int i, j, t;
	
	for(i = 0; i < size; i++){
		ugly = s->head;
		for (j=0; j < size-1; j++){
			if (ugly->val > ugly->next->val){
				t = ugly->val;
				ugly->val = ugly->next->val;
				ugly->next->val = t;
			}
			ugly = ugly->next;
		}
	}
	//free (ugly);
}

/*********************************************************************
 ** FUNCTION: sort_descending
 ** DESCRIPTION: sorts values of list in descending order
 ** PARAMETERS: struct list *
 ** PRE-CONDITIONS: list of valules
 ** POST-CONDITIONS: list of values arranged in descending order
 ** RETURNS: nothing
 *********************************************************************/
void sort_descending(struct list *s){
	//bubble sort from notes

	printf("Descending order: \n");
	struct node *ugly; //= (struct node *) malloc(sizeof(struct node));;
	int size = length(*s);
	int i, j, t;
	
	for(i = 0; i < size; i++){
		ugly = s->head;
		for (j=0; j < size-1; j++){
			if (ugly->val < ugly->next->val){
				t = ugly->val;
				ugly->val = ugly->next->val;
				ugly->next->val = t;
			}
			ugly = ugly->next;
		}
	}
	//free (ugly);
}

/*********************************************************************
 ** FUNCTION: insert
 ** DESCRIPTION: inserts a value into specific location in list
 ** PARAMETERS: struct list *, int num, int pace
 ** PRE-CONDITIONS: list of values
 ** POST-CONDITIONS: list of values with new value in place specified
 ** RETURNS: nothing
 *********************************************************************/
//insert into a location in the list, start at 0 for front
void insert(struct list *s, int num, int place){
	int i = 0;

	struct node *temp1 = (struct node *) malloc(sizeof(struct node));
	//temp1->next = NULL;
	//temp1->prev = NULL;
	temp1->val = num;

	if (place == 1){ //at first position
		temp1->next = s->head;
		s->head = temp1;
		return;
	}

	struct node *temp2 = s->head;
	for (i = 0; i < place-2; i++){
		temp2 = temp2->next;
	}
	temp1->next = temp2->next;
	temp2->next = temp1;

}

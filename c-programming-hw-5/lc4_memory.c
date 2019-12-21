
/************************************************************************/
/* File Name : lc4_memory.c		 										*/
/* Purpose   : This file implements the linked_list helper functions	*/
/* 			   to manage the LC4 memory									*/
/*             															*/
/* Author(s) : tjf and you												*/
/************************************************************************/

#include <stdio.h>
#include "lc4_memory.h"
#include <stdlib.h>
#include "lc4_loader.h"
#include "lc4_disassembler.h"

/*
 * adds a new node to linked list pointed to by head
 */
int add_to_list (row_of_memory** head, short unsigned int address, short unsigned int contents)
{

	/* allocate memory for a single node */
    row_of_memory* new_memory= malloc(sizeof(row_of_memory));
    if (new_memory == NULL){
		printf("Error: malloc fails\n.");
		return -1;
	}
	/* populate fields in newly allocated node w/ address&contents */
    new_memory->address=address;
    new_memory->contents=contents;
    new_memory->label=NULL;
    new_memory->assembly=NULL;
    new_memory->next=NULL;

	/* if head==NULL, node created is the new head of the list! */
    if(*head==NULL){*head=new_memory;}
	/* otherwise, traverse linked list until reach the right spot to insert this node */
   else{
       row_of_memory* newnode = *head;
       while(newnode->next != NULL){
            newnode = newnode->next;
        }
        newnode->next = new_memory;
       
   }
	/* insert node into the list - perform necessary "surgery" on this list */
    
	/* return 0 for success, -1 if malloc fails */

	return 0 ;
}


/*
 * search linked list by address field, returns node if found
 */
row_of_memory* search_address (row_of_memory* head, short unsigned int address )
{
	/* traverse linked list, searching each node for "address"  */
   
	/* return pointer to node in the list if item is found */

	/* return NULL if list is empty or if "address" isn't found */
    
   
       
    row_of_memory *new_memory = head;
	while (new_memory != NULL){
		if (new_memory->address == address){
			/* return pointer to node in list that matches */
			return new_memory;
		}
		new_memory = new_memory->next;
	}
	/* return NULL if list is empty or if "address" isn't found */	 
	return NULL ;
}

/*
 * search linked list by opcode field, returns node if found
 */
row_of_memory* search_opcode  (row_of_memory* head, short unsigned int opcode  )
{
	/* traverse linked list until node is found with matching opcode
	   AND "assembly" field of node is empty */

	/* return pointer to node in the list if item is found */

	/* return NULL if list is empty or if no matching nodes */
     row_of_memory* new_memory = head;
	
	while (1) {
		if (new_memory == NULL) {
			break;
		}

		if (((0b1111000000000000 & new_memory->contents) == (opcode<<12)))  {
            if(new_memory->assembly == NULL)
			break;
		}
		
		new_memory = new_memory->next;

	}

	/* return pointer to node in list that matches */
	/* return NULL if list is empty or if no matching nodes */
	 
	return new_memory;
    
    if (new_memory==NULL) return NULL;
    
  
}


void print_list (row_of_memory* head )
{
	/* make sure head isn't NULL */
    /* print out a header */
	/* traverse linked list, print contents of each node */
    if(head == NULL){
        printf("nothing here\n");
    }
    else{
            //printf("the header is %s\n",head);
            printf("Label\t\taddress\t\tcontents\t\t assembly\n"); 
             row_of_memory* node = head;
       while(node != NULL){
            printf("%s\t\t%04x\t\t%04x\t\t%s\n", node->label, node->address, node->contents, node->assembly);
            node = node->next;
       }
    }

	

}

/*
 * delete entire linked list
 */
int delete_list    (row_of_memory** head )
{
	/* delete entire list node by node */
	/* if no errors, set head = NULL upon deletion */

	/* return 0 if no error, -1 for any errors that may arise */
    
    row_of_memory* new_memory=*head;
    row_of_memory* nextptr;
    
    while( new_memory!= NULL){
  
        
        free(new_memory->assembly);
        
        free(new_memory->label);
      
        //free(node->assembly);
        
        free(new_memory);
        nextptr = new_memory -> next;
      
        new_memory = nextptr;
        *head = NULL;
	return 0 ;
    }
    
    return -1;
// 	*head = NULL;
// 	return 0 ;
}

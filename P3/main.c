/*
Kyle O'Neill
KO217135
Rahul Singh
Friday 11:30
ENTER DESCRIPTION HERE
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node{
	char text[255];
	struct node *next;
}Node;

//NODE FUNCTIONS---------------------------------------------------------------------

Node* createNode(char* text, Node* next){
	Node* nextNode = (Node*)malloc(sizeof(Node));
	if(nextNode == NULL){
		printf("Error creating a new node.\n");
		fflush(stdout);
		exit(0);
	}
	strcpy(nextNode->text, text);
	nextNode->next = next;
	return nextNode;
}
Node* connect(Node* head, char* text){
	Node* nextNode = createNode(text, head);
	head = nextNode;
	return head;
}

Node* findBefore(Node* head, int num){
	Node* current = head;
	int index = 1;
	do{
		index++;
		if(current == NULL)
			return current;
		if(index == (num-1))
			return current;
		current = current->next;
	}while(index!=(num-1));
}

Node* findNode(Node* head, int num){
	Node* current = head;
	int index = 1;
	do{
		if(current == NULL)
			return current;
		if(num==index)
			return current;
		current = current->next;
		index++;
	}while(index!=num);
}

Node* findAfter(Node* head, int num){
	Node* current = head;
	int index = 0;
	do{
		index++;
		if(current == NULL)
			return current;
		if(index == num){
			current = current->next;
			return current;
		}
		current = current->next;
	}while(index!= num);
}

void checkIfExists(Node* head, char* text){
	Node* current = head;
	if(current == NULL)
		return;
	while(strcmp(current->text, text)){
		current = current->next;
		if(current == NULL)
			break;
	}
	printf("Such text exists already");
	fflush(stdout);
}

int listLength(Node* head){
	Node* current = head;
	int index = 1;
	if(current == NULL)
		return 0;
	while(current != NULL){
		current = current->next;
		index++;
	}
	return index;
}

Node* returnTail(Node* head){
	Node* current = head;
	while(current->next != NULL){
		current = current->next;	
	}
	return current;
}

//USER COMMAND FUNCTIONS------------------------------------------------------------

//for inb, need a special case if the input number is 1. findBefore only works for 2+

void ina(Node* head, int num, char* str){
	int length = listLength(head);
	if(num > length){
		//Insert node, add text "Text inserted at the end"
	}
	Node* current = findAfter(head, num);
	if(current == NULL){
		
	}
	//insert a value in current. MUST CHECK IF SOMETHING IS IN CURRENT FIRST
}

void prn(Node* head){
	int index = 1;
	Node* current = head;
	if(current==NULL){
		printf("The list is empty");
		fflush(stdout);
	}
	while(current!= NULL){
		printf("%d %s\n", index, current->text);
		fflush(stdout);
		current = current->next;
		index++;
	}
}

//MAIN------------------------------------------------------------------------------

int main (int argc, char *argv[])
{
	Node* head = NULL;
	while(1){
		char command[4];
		int intValue;
		char stringValue[255];

		printf("Command? ");
		fflush(stdout);
		scanf("%s %d %s",command, &intValue, stringValue);

		if(!strcmp(command, "ina"))
			;//Run insert after method here
		else if(!strcmp(command, "inb"))
			;//Run insert before method here
		else if(!strcmp(command, "del"))
			;//Run delete method here
		else if(!strcmp(command, "rep"))
			;//Run replace method here
		else if(!strcmp(command, "prn"))
			;//Run prn method here
		else if(!strcmp(command, "end"))
			break;//Run end method here? Maybe just a break
	}
}
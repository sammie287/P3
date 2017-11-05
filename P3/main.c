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

Node* head = NULL;

void print(char* str){
	printf("%s\n", str);
	fflush(stdout);
}

//NODE FUNCTIONS---------------------------------------------------------------------

/*void debugS(char* str){
	printf("%s\n", str);
	fflush(stdout);
}

void debugP(Node* pointer){
	printf("%p\n", pointer);
	fflush(stdout);
}*/

Node* createNode(char* text, Node* next){
	Node* nextNode = (Node*)malloc(sizeof(Node));
	if(nextNode == NULL){
		print("Error creating a new node.");
		exit(0);
	}
	strcpy(nextNode->text, text);
	nextNode->next = next;
	return nextNode;
}

Node* findNode(int num){
	Node* current = head;
	int index = 1;
	do{
		if(current == NULL)
			return current;
		if(num == index)
			return current;
		current = current->next;
		index++;
	}while(index!=num);
}

int checkIfExists(Node* head, char* text){
	Node* current = head;
	if(current == NULL)
		return 0;
	while(strcmp(current->text, text)){
		current = current->next;
		if(current == NULL)
			return 0;
	}
	print("Such text exists already");
	return 1;
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
	if(current == NULL)
		return current;
	while(current->next != NULL){
		current = current->next;	
	}
	return current;
}

void push(Node** head, char* str){
	Node* newNode;
	newNode = malloc(sizeof(Node));
	strcpy(newNode->text, str);
	newNode->next = *head;
	*head = newNode;
}

//USER COMMAND FUNCTIONS------------------------------------------------------------

void ina(int num, char* str){
	Node* current = findNode(num);
	if(checkIfExists(head, str))
		return;
	if(current == NULL){
		Node* tail = returnTail(head);
		if(tail == NULL){
			head = createNode(str, NULL);
			print("Text inserted at the end");
			return;
		}
		Node* newTail = createNode(str, NULL);
		tail->next = newTail;
		print("Text inserted at the end");
		return;
	}
	Node* next = current->next;
	if(next == NULL){
		next = createNode(str, NULL);
		current->next = next;
		print("Ok");
		return;
	}
	Node* temp = createNode(next->text, next->next);
	strcpy(next->text, str);
	next->next = temp;
	print("Ok");
}

void inb(int num, char* str){
	Node* current = findNode(num+1);
	if(checkIfExists(head, str))
		return;
	if(current == NULL){
		if(head == NULL){
			head = createNode(str, NULL);
			print("Text inserted at the beginning");
			return;
		}
		push(&head, str);
		print("Text inserted at the beginning");
		return;
	}
	Node* temp = createNode(current->text, current->next);
	strcpy(current->text, str);
	current->next = temp;
	print("Ok");
}

void prn(){
	int index = 1;
	Node* current = head;
	if(current==NULL){
		print("The list is empty");
	}
	while(current!= NULL){
		printf("%d %s\n", index, current->text);
		fflush(stdout);
		current = current->next;
		index++;
	}
}

void del(int num){
	Node* current = findNode(num-1);
	Node* remNode = current->next;
	if(remNode == NULL){
		print("No such index");
	}
	Node* newNext = remNode->next;
	current->next = newNext;
	free(remNode);
	print("Deleted");
}

void rep(int num, char* str){
	Node* current = findNode(num);
	if(current == NULL){
		print("No such index");
		return;
	}
	strcpy(current->text, str);
	print("Replaced");
}

//MAIN------------------------------------------------------------------------------

int main (int argc, char *argv[]){
	while(1){
		char command[4];
		int intValue;
		char stringValue[255];

		printf("Command? ");
		fflush(stdout);
		scanf("%s %d %s",command, &intValue, stringValue);

		if(!strcmp(command, "ina"))
			ina(intValue, stringValue);
		else if(!strcmp(command, "inb"))
			inb(intValue, stringValue);
		else if(!strcmp(command, "del"))
			del(intValue);
		else if(!strcmp(command, "rep"))
			rep(intValue, stringValue);
		else if(!strcmp(command, "prn"))
			prn(head);
		else if(!strcmp(command, "end"))
			break;
		continue;
	}
}
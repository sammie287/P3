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

typedef struct node{ //Creates our struct node and allows us to refer to it as "Node"
	char text[255];
	struct node *next;
}Node;

Node* head = NULL; //Declares and initializes our head which will be used to access the linked list

void print(char* str){ //Custom print function to make print calls faster and to ensure I don't miss a fflush()
	printf("%s\n", str);
	fflush(stdout);
}

//NODE FUNCTIONS---------------------------------------------------------------------
//These functions support the functions specified in the program instructions

Node* createNode(char* text, Node* next){ //Creates a new node object. Takes an input of a string and a pointer to a node
	Node* nextNode = (Node*)malloc(sizeof(Node));//Allocates memory for a node and verifies that the node was created
	if(nextNode == NULL){
		print("Error creating a new node.");
		exit(0);
	}
	strcpy(nextNode->text, text);//Places the input string and pointer into our node object
	nextNode->next = next;
	return nextNode;
}

Node* findNode(int num){//An index nunber is input and a pointer to the node at that index location is returned
	if (head == NULL)//Returns null if the list is empty
		return NULL;
	Node* current = head;//Creates a new pointer, current, so we do not modify our head pointer.
						//This same initialization will be used many times in the program, for the same purpose.
	int index = 1;//index keeps track of what node we are looking at
	while(current != NULL && num != index){// Continue through the nodes until we find the num-th node, and then return it
		index++;
		current = current->next;
	}
	return current;
}

int checkIfExists(char* text){//Checks to see if the input string exists in any of our nodes. Returns true if so, false if not
	if(head == NULL)//If the list is empty, returns false
		return 0;
	Node* current = head;
	while(strcmp(current->text, text)){//Loop iterates through our list and compares the string in each node to our input string
		current = current->next;
		if(current == NULL)//If we reach the end of the list without a match, returns false
			return 0;
	}
	print("Such text exists already");//If a match is found, while loop ends and method returns true
	return 1;
}

Node* returnTail(Node* head){//Returns the tail node (the final node) of our linked list
	if(head == NULL)//If the list is empty, return null
		return NULL;
	Node* current = head;
	while(current->next != NULL){//Iterates through linked list until the final node is reached, and returns it
		current = current->next;	
	}
	return current;
}

void push(Node** head, char* str){//Creates a new head node and moves the previous head to the second index
	Node* newNode;//Declares a pointer for the new head
	newNode = malloc(sizeof(Node));//Initialize the new head
	strcpy(newNode->text, str);//Inputs the desired text field into the new head
	newNode->next = *head;//The new head points to the old head
	*head = newNode;//The head pointer is reconfigured to point to our new head
}

//USER COMMAND FUNCTIONS------------------------------------------------------------

void ina(int num, char* str){//Insert a string after a given node, determined by input int
	Node* current = findNode(num);//A new pointer is given the address of the node at our desired index location
	if(checkIfExists(str))//If the input string already exists in the list, exists the method
		return;
	if(current == NULL){//Checks if our current node is empty
		Node* tail = returnTail(head);//If so, finds our tail node
		if(tail == NULL){//If there is no tail, the list is empty
			head = createNode(str, NULL);//And a new head is created
			print("Text inserted at the end");
			return;
		}
		Node* newTail = createNode(str, NULL);//If our list is not empty, a new tail is created
		tail->next = newTail;
		print("Text inserted at the end");
		return;
	}
	Node* next = current->next;//If our current node is not empty, we create a pointer to the node after it
	if(next == NULL){//If that new node is empty, it's created and given our desired string value
		next = createNode(str, NULL);
		current->next = next;//Our current pointer is set to point to our new node
		print("Ok");
		return;
	}
	Node* temp = createNode(next->text, next->next);//If that new node is not empty, a temporary pointer is created and assigned to a new node object
													//This node object takes on the values of our "next" node
	strcpy(next->text, str);//The desired string value is placed into our "temp" node
	next->next = temp;//"Next" node is told to point to "temp" node
	print("Ok");
}

void inb(int num, char* str){//Inserts a string before a given node, determined by input int
	Node* current = findNode(num);
	if(checkIfExists(str))
		return;
	if(current == NULL){//If the node object at the desired index does not exist
		if(head == NULL){//If the node list is empty
			head = createNode(str, NULL);//A new head node is created with the desired string value
			print("Text inserted at the beginning");
			return;
		}
		push(&head, str);//If the head does exist, a new head node is created
		print("Text inserted at the beginning");
		return;
	}
	Node* temp = createNode(current->text, current->next);//A temporary pointer is made to point to a new node object,
														 //which takes the values of our "current" object
	strcpy(current->text, str);//The desired string value is put into our "current" object
	current->next = temp;//Which is then told to point to our new node object
	print("Ok");
}

void prn(){//Prints the index and current string of each node object
	if(head == NULL){//Prints if the list is empty
		print("The list is empty");
	}
	int index = 1;
	Node* current = head;
	while(current!= NULL){//Loop prints all node objects by iterating through each of them
		printf("%d %s\n", index, current->text);
		fflush(stdout);
		current = current->next;
		index++;
	}
}

int del(int num){//Delete the node at a given index. Returns true if a deletion is made, false otherwise
	if(num == 1){//Special case if the head is deleted
		if(head == NULL)//If the list is empty, return false
			return 0;
		Node* temp = head->next;//A temporary pointer points to the second node in the index
		free(head);//The head is deleted
		head = temp;//The second node in the index becomes the new head, return true
		return 1;
	}
	Node* current = findNode(num-1);//Points to the node before the one which will be deleted
	if(current == NULL)//If that node is null, no deletion occurs and return false
		return 0;
	Node* rmNode = current->next;//Points to the node which will be deleted
	if(rmNode == NULL)//If it does not exist, it cannot be deleted and false is returned
		return 0;
	current->next = rmNode->next;//The node before our deletion node is told to point to what our deletion node points to
								//This preserves the chain after a node is removed
	free(rmNode);//The node at the specified index is removed and method returns true
	return 1;
}

void rep(int num, char* str){//The node at the specified index has its string value replaced
	Node* current = findNode(num);
	if(current == NULL){//If our node doesn't exist, a replacement cannot be made
		print("No such index");
		return;
	}
	strcpy(current->text, str);//Copies the desired string value into our node
	print("Replaced");
}

//MAIN------------------------------------------------------------------------------

int main (int argc, char *argv[]){//Allows user to modify a linked list and see what it contains
	while(1){//Endless loop which only ends when 'end' command is entered by user
		char command[255];//String which holds our input command
		int intValue;//Int which holds an index value used to search through linked list
		char stringValue[255];//String which holds a value to be stored in node objects

		printf("Command? ");//Prompt user to enter command
		fflush(stdout);
		scanf("%s", command);//Saves command in command char array

		if(!strcmp(command, "ina")){//If command is 'ina', gets the index and string values and runs 'ina' method
			scanf("%d %s", &intValue, stringValue);
			ina(intValue, stringValue);
		}

		else if(!strcmp(command, "inb")){//If command is 'inb', gets the index and string values and runs 'inb' method
			scanf("%d %s", &intValue, stringValue);
			inb(intValue, stringValue);
		}

		else if(!strcmp(command, "del")){//If command is 'del', gets the index value and runs 'del' method
			scanf("%d", &intValue);
			if(del(intValue) == 1)//Method returns true if an object is deleted
				print("Deleted");//And 'Deleted' is printed
			else
				print("No such index");//If method returns false, prints that the node at index does not exist
		}

		else if(!strcmp(command, "rep")){//If command is 'rep', gets the index and string values and runs 'rep' method
			scanf("%d %s", &intValue, stringValue);
			rep(intValue, stringValue);
		}

		else if(!strcmp(command, "prn"))//If command is 'prn', runs 'prn' method
			prn(head);

		else if(!strcmp(command, "end"))//If command is 'end', Endless loop ends and program ends
			break;
	}
}
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
}node;

node* top;

int CAPACITY = 10;
int size = 0;

int push(int number) {
	if (!isFull()) {
		node* newNode;
	    newNode = malloc(sizeof(node));
	    newNode->data = number;
	    newNode->next = top;
	    top = newNode;
	    size++;
	}
    return 0;
}

int pop() {
    if (isEmpty()){
        return 1;
    }
    else {
    	top = top->next;
		size--;	
	}
}

int peek() {
	if (!isEmpty()) {
		printf("top is %d \n", top->data);	
	}
}

int display() {
    node* finger;
    finger = top;
    printf("The Items inside the Stack is: \n");
    
	while (finger != NULL) {
        printf("%d ", finger->data);
        finger = finger->next;
    }
    
    printf("\n");
    return 0;
}
int isEmpty() {
    if (top == NULL) {
        printf("There is no item left");
        return 1;
    }
    return 0;
}

int isFull() {
	if(size == CAPACITY){
		return 1;
	}
	else{
		return 0;
	}
}

int main() {
    push(1);
    push(2);
    push(3);
    push(3);
    push(3);
    push(43);
    push(553);
    push(10);
	push(7);
	push(6);
	push(3);
	push(4);
	push(5);
    display();
    pop();
    display();
    peek();
}

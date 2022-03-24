// stack using linked list
#include<stdio.h>

struct node{
	int data;
	struct node*next;
};
struct node*top = NULL;


struct node*getnewnode(int a){
	struct node*temp = (struct node*)malloc(sizeof(struct node));
	temp->data = a;
	temp->next = NULL;
	return temp;
}

void push(int a){
	struct node*temp = getnewnode(a);
	temp->next = top;
	top = temp;
}

void pop(){
	struct node*p;
	if(top==NULL)
		printf("Underflow");
	p = top;
	top = top->next;
	free(p);
}

void peek(){
	printf("%d",top->data);
}

void display(){
	struct node*temp;
	temp = top;
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp = temp->next;
	}
}

int main(){
	push(5);
	push(3);
	push(9);
	pop();
	display();
	printf("\n");
	peek();
}

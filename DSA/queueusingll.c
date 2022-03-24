//queueusingll
#include<stdio.h>

struct node{
	int data;
	struct node*next;
};
struct node*front = NULL;
struct node*rear = NULL;

struct node*getnewnode(int a){
	struct node*temp = (struct node*)malloc(sizeof(struct node));
	temp->data = a;
	temp->next = NULL;
	return temp;
}

void enqueue(int c){
	struct node*temp = getnewnode(c);
	if(front==NULL&&rear==NULL){
		front = rear = temp;
	}
	else{
		rear->next = temp;
		rear = temp;
	}
}

void dequeue(){
	struct node*temp;
	if(front==NULL&&rear==NULL)
		printf("Underflow");
	temp = front;
	front = front->next;
	free(temp);
}

void peek(){
	printf("%d",front->data);
}

void display(){
	struct node*temp;
	temp = front;
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp = temp->next;
	}
}

int main(){
	enqueue(5);
	enqueue(6);
	enqueue(7);
	enqueue(8);
	dequeue();
	display();
	printf("\n");
	peek();
}


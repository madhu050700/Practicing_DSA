// queue using array
#include<stdio.h>
#define N 5
int queue[N];
int front=-1,rear=-1;

void enqueue(int b){
	if(rear == N-1)
		printf("Overflow");
	else if(front==-1&&rear==-1){
		front++;
		rear++;
		queue[rear]=b;
	}
	else{
		rear++;
		queue[rear]=b;
	}
}

void dequeue(){
	if(front==-1&&rear==-1)
		printf("Underflow");
	front++;
}

void peek(){
	printf("%d",queue[front]);
}

void display(){
	int i;
	for(i=front;i<=rear;i++){
		printf("%d ",queue[i]);	
	}
}

int main(){
	enqueue(5);
	enqueue(6);
	enqueue(7);
	enqueue(8);
	enqueue(9);
	dequeue();
	display();
	printf("\n");
	peek();
}

// Stack implemented using array
# include<stdio.h>
# define N 10
int stack[N];
int top = -1;

void push(int a){
	if(top == N-1){
		printf("Overflow");
	}
	else{
		top++;
		stack[top]=a;
	}
}

void pop(){
	if(top==-1){
		printf("Underflow");
	}
	else{
		top--;
	}
}

void peek(){
	if(top==-1)
		printf("Stack is empty");
	printf("%d",stack[top]);
}

void display(){
	int i;
	if(top==-1)
		printf("Stack is empty");
	for(i=top;i>=0;i--){
		printf("%d ",stack[i]);
	}
}

int main(){
	push(3);
	push(5);
	push(9);
	pop();
	display();
	printf("\n");
	peek();
	
	
}

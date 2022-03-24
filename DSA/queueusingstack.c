//queue using stack
#include<stdio.h>
#define N 5
int s1[N],s2[N];
int top1=-1,top2=-1;
int count=0;

void push1(int c){
	if(top1==N-1)
		printf("Overflow");
	else{
		top1++;
		s1[top1]=c;
	}
}
int pop1(){
	if(top1==-1)
		printf("Underflow");
	return s1[top1]--;
	
}
void push2(int v){
	if(top2==N-1)
		printf("Overflow");
	top2++;
	s2[top2]=v;
}

int pop2(){
	return s2[top2--];
}

void enqueue1(int b){
	push1(b);	
	count++;
}

void dequeue1(){
	int i;
	for(i=0;i<count;i++){
		push2(pop1());
	}
	pop2();
	count--;
	for(i=0;i<count;i++){
		push1(pop2());
	}	
}

void display1(){
	int i;
	for(i=0;i<=top1;i++){
		printf("%d ",s1[i]);
	}
}


int main(){
	enqueue1(5);
	enqueue1(6);
	enqueue1(7);
	dequeue1();
	display1();

}

//stack using queue
#include<stdio.h>
#include<stdlib.h>
#define N 5
int q1[N],q2[N];
int f1=-1,r1=-1;
int f2=-1,r2=-1;
int count=0;
void enqueue1(int data){
	if(r1==N-1)
		printf("Overflow");
	else if(f1==-1&&r1==-1){
		f1++;
		r1++;
		q1[r1]=data;
	}
	else{
		r1++;
		q1[r1]=data;
	}
}

void enqueue2(int data){
	if(r2==N-1)
		printf("Overflow");
	else if(f2==-1&&r2==-1){
		f2++;
		r2++;
		q2[r2]=data;
	}
	else{
		r2++;
		q2[r2]=data;
	}
}

int dequeue1(){
	return q1[f1++];
}

int dequeue2(){
	return q2[f2++];
}
void create1(){
	f1=r1=-1;
}

void create2(){
	f2=r2=-1;
}

void push(int x){
	enqueue1(x);
	count++;
}

void pop(){
	int i;
	for(i=0;i<count-1;i++){
		enqueue2(dequeue1());
	}
	dequeue1();
	create1();
	for(i=0;i<count-1;i++){
		enqueue1(dequeue2());
	}
	create2();
}

void display(){
	int i;
	for(i=r1;i>=0;i--){
		printf("%d ",q1[i]);
	}
}

int main(){
	push(3);
	push(4);
	push(5);
	push(7);
	pop();
	display();
}




#include<stdio.h>

struct node{
	int data;
	struct node*prev;
	struct node*next;
};
struct node*head = NULL;
struct node*tail = NULL;

struct node*getnewnode(int a){
	struct node*temp = (struct node*)malloc(sizeof(struct node));
	temp->data = a;
	temp->prev = NULL;
	temp->next = NULL;
	return temp;
}

void insertatend(int a){
	struct node*temp = getnewnode(a);
	if(head == NULL){
		head =tail= temp;
	}
	else{
		struct node*p;
		p = head;
		while(p->next!=NULL){
			p = p->next;
		}
		p->next = temp;
		temp->prev = p;
		tail = tail->next;
	}
}

void display(){
	struct node*temp;
	temp = head;
	while(temp!=NULL){
		printf("%d->",temp->data);
		temp = temp->next;
	}
}
void length(){
	struct node*temp;
	int len =0;
	temp = head;
	while(temp!=NULL){
		len++;
		temp = temp->next;
	}
	printf("%d",len);
}
void insertatbegin(int b){
	struct node*temp = getnewnode(b);
	if(head == NULL){
		head = tail = temp;
	}
	else{
		temp->next = head;
		head->prev = temp;
		head = temp;
	}
}

void insertatspeci(int n, int d){
	struct node*temp = getnewnode(d);
	if(head == NULL){
		head = temp;
	}
	else{
		struct node*p;
		p = head;
		int j=1;
		while(j<n-1){
			p=p->next;
			j++;
		}
		temp->next = p->next;
		temp->prev = p;
		p->next = temp;
		temp->next->prev = temp;
	}
}

void insertaftspeci(int n,int c){
	struct node*temp = getnewnode(c);
	if(head == NULL){
		head = temp;
	}
	else{
		struct node*p;
		int j=1;
		p = head;
		while(j<n){
			p = p->next;
			j++;
		}
		temp->next = p->next;
		temp->prev = p;
		p->next = temp;
		temp->next->prev = temp;
	}
	
}
void delfb(){
	if(head == NULL){
		printf("List is empty");
	}
	else{
		struct node*p;
		p = head;
		head->next->prev = NULL;
		head = head->next;
		free(p);
	}
}

void delatend(){
	if(head == NULL){
		printf("List is empty");
	}
	else{
		struct node*p;
		p = tail;
		tail->prev->next = NULL;
		tail = tail->prev;
		free(p);
	}
}

void delatspeci(int s){
	if(head == NULL){
		printf("List is empty");
	}
	else{
		struct node*p;
		p= head;
		int j =1;
		while(j<s){
			p = p->next;
			j++;
		}
		p->prev->next = p->next;
		p->next->prev = p->prev;
		free(p);
	}
	
}

void reverse(){
	if(head == NULL){
		printf("List is empty");
	}
	else{
		struct node*currn,*nextn,*p;
		currn = nextn = head;
		while(nextn!=NULL){
			nextn = currn->next;
			currn->next = currn->prev;
			currn->prev = nextn;
			currn = nextn;
		}
		p = head;
		head = tail;
		tail = p;
	}
}



int main(){
	insertatend(3);
	insertatend(8);
	insertatend(33);
	insertatbegin(6);
	insertatbegin(77);
	insertaftspeci(3,9);
	insertatend(66);
	insertatspeci(3,10);
	delfb();
	insertaftspeci(4,999);
	delatend();
	delatspeci(4);
	display();
	reverse();
	printf("\n");
	display();
	printf("\n");
	length();
}

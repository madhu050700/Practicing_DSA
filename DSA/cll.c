#include<stdio.h>

struct node{
	int data;
	struct node*next;
};
struct node*head = NULL;
struct node*tail = NULL;

struct node*getnewnode(int a){
	struct node*temp = (struct node*)malloc(sizeof(struct node));
	temp->data = a;
	temp->next = NULL;
	return temp;
}

void insertatend(int b){
	struct node*temp = getnewnode(b);
	if(head == NULL){
		head = tail= temp;
		head->next = head;
	}
	else{
		struct node*p;
		p = head;
		while(p->next!=head){
			p=p->next;
		}
		p->next = temp;
		temp->next = head;
		tail = tail->next;
	}
}

void insertatbegin(int c){
	struct node*temp = getnewnode(c);
	if(head == NULL){
		head = tail = temp;
		head->next = head;
	}
	else{
		temp->next = head;
		head = temp;
		tail->next = temp;
	}
}

void insertatspeci(int n,int d){
	struct node*temp = getnewnode(d);
	if(head == NULL){
		head = tail = temp;
		head->next = head;
	}
	else{
		struct node*p;
		p = head;
		int j=1;
		while(j<n-1){
			p = p->next;
			j++;
		}
		temp->next = p->next;
		p->next = temp;
	}
}

void delfb(){
	if(head == NULL){
		printf("List is empty");
	}
	else{
		struct node*temp;
		temp = head;
		head = head->next;
		tail->next = head;
		free(temp);
	}
}

void delatend(){
	if(head == NULL){
		printf("List is empty");
	}
	else{
		struct node*p,*temp;
		p = head;
		temp = NULL;
		while(p->next!=head){
			temp = p;
			p = p->next;
		}
		temp->next = head;
		tail = temp;
		free(p);	
	}
}

void delatspeci(int n){
	if(head == NULL){
		printf("List is empty");
	}
	else if(n==1){
		delfb();
	}
	else{
		struct node*p,*temp;
		int j=1;
		temp = head;
		p = NULL;
		while(j<n){
			p = temp;
			temp = temp->next;
			j++;
		}
		p->next = temp->next;
		free(temp);
		
	}
}

void reverse(){
	if(head==NULL){
		printf("List is empty");
	}
	else if(head->next==head){
		printf("%d",head->data);
	}
	else{
		struct node*currnode,*prevnode,*nextnode,*p;
		currnode = head;
		nextnode = currnode->next;
		prevnode = tail;
		while(nextnode!=head){
			currnode->next = prevnode;
			prevnode = currnode;
			currnode = nextnode;
			nextnode = nextnode->next;
		}
		currnode->next = prevnode;
		p = head;
		head = tail;
		tail = p;
		
		
	}
}

void length(){
	struct node*temp;
	temp=head;
	int len =0;
	while(temp->next!=head){
		len++;
		temp = temp->next;
	}
	printf("%d",len+1);
}

void display(){
	struct node*temp;
	temp = head;
	while(temp->next!=head){
		printf("%d->",temp->data);
		temp = temp->next;
	}
	printf("%d",temp->data);
}


int main(){
	insertatend(4);
	insertatend(5);
	insertatend(7);
	insertatend(9);
	insertatbegin(6);
	insertatbegin(2);
	insertatspeci(3,3);
	delfb();
	delatend();
	delatspeci(3);
	display();
	printf("\n");
	length();
	printf("\n");
	reverse();
	display();
}


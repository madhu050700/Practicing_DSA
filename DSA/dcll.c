#include<stdio.h>

struct  node{
	int data;
	struct node*prev;
	struct node*next;
};
struct node*head=NULL;
struct node*tail=NULL;

struct node*getnewnode(int d){
	struct node*temp = (struct node*)malloc(sizeof(struct node));
	temp->data = d;
	temp->prev = NULL;
	temp->next = NULL;
	return temp;
}

void insertatend(int b){
	struct node*temp = getnewnode(b);
	if(head ==  NULL){
		head = tail = temp;
		head->prev = head;
		head->next = head;
	}
	else{
		struct node*p;
		p=head;
		while(p->next!=head){
			p = p->next;
		}
		temp->prev = p;
		temp->next = head;
		p->next = temp;
		head->prev = temp;
		tail = temp;
		
	}
}

void insertatbegin(int a){
	struct node*temp = getnewnode(a);
	if(head == NULL){
		head = tail = temp;
		head->prev = head;
		head->next = head;
	}
	else{
		temp->next = head;
		temp->prev = head->prev;
		head->prev = temp;
		head = temp;
		tail->next = temp;
	}
}

void insertatspeci(int n,int b){
	struct node*temp = getnewnode(b);
	if(head == NULL){
		head = tail=temp;
		head->prev = head;
		head->next = head;
	}
	else{
		struct node*p;
		int j=1;
		p=head;
		while(j<n-1){
			p = p->next;
			j++;	
		}
		temp->prev = p;
		temp->next = p->next;
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
		head = head->next;
		head->prev = tail;
		tail->next = head;
		free(p);
		
	}
}

void delatend(){
	if(head == NULL){
		printf("List is empty");
	}
	else{
		struct node*temp;
		temp = tail;
		tail = tail->prev;
		tail->next = head;
		head->prev = tail;
		free(temp);	
	}
}

void delatspeci(int m){
	int len = length();
	if(head == NULL){
		printf("List is empty");
	}
	else if(m==1)
		delfb();
	else if(m==len)
		delatend();
	else if(m>len||m<1)
		printf("Invalid Input");
	else{
		struct node*temp;
		temp = head;
		int j=1;
		while(j<m){
			temp = temp->next;
			j++;
		}
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		free(temp);
	}
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

int length(){
	struct node*temp;
	temp = head;
	int count=0;
	while(temp->next!=head){
		count++;
		temp = temp->next;
	}
	return count+1;
}

void reverse(){
	if(head == NULL)
		printf("List is empty");
	else if(head->next == head)
		printf("%d",head->data);
	else{
		struct node*currnode,*nextnode,*p;
		currnode=head;
		nextnode = currnode->next;
		while(nextnode!=head){
			currnode->next = currnode->prev;
			currnode->prev = nextnode;
			currnode = nextnode;
			nextnode = nextnode->next;
		}
		p = head;
		head = tail;
		tail =p;
	}
}

int main(){
	insertatend(3);
	insertatend(6);
	insertatend(7);
	insertatbegin(5);
	insertatbegin(9);
	insertatspeci(3,1);
	display();
	reverse();
	printf("\n");
	display();
}

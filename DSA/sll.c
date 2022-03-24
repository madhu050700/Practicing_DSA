# include<stdio.h>
struct node{
	int x;
	struct node*next;
};
struct node*head=NULL;
struct node*getnewnode(int d){
	
	struct node*temp = (struct node*)malloc(sizeof(struct node));
	temp->x = d;
	temp->next = NULL;
	return temp;
}
void insertatend(int a){
	struct node*temp = getnewnode(a);
	struct node*p;
	if(head == NULL){
		head = temp;
	}
	else{
		p = head;
		while(p->next!=NULL){
			p= p->next;
		}
		p->next = temp;		
	}
}
void delfn(){
	if(head == NULL){
		printf("List is empty");
	}
	else{
		struct node*temp;
		temp = head;
		head = head->next;
		free(temp);
	}
}
void delln(){
	if(head == NULL){
		printf("list is empty");
	}
	else{
		struct node*temp,*curr;
		curr = NULL;
		temp = head;
		while(temp->next!=NULL){
			curr = temp;
			temp = temp->next;
		}
		curr->next = NULL;
		free(temp);
	}
}
void delsn(int n){
	if(head == NULL){
		printf("List is empty");
	}
	else{
		struct node*temp,*curr;
		int j=1;
		curr = NULL;
		temp = head;
		while(j<n){
			curr = temp;
			temp = temp->next;
			j++;
		}
		curr->next = temp->next;
		free(temp);
	}
}
void insertafter(int i,int c){
	struct node*temp = getnewnode(c);
	int j=1;	
	if(head == NULL){
		head = temp;
	}
	else{
		struct node*p;
		p=head;
		while(j<i){
			p=p->next;
			j++;	
		}
		temp->next = p->next;
		p->next = temp;
	}
}
void insertatbegin(int b){
	struct node*temp = getnewnode(b);
	if(head == NULL){
		head = temp;	
	}
	else{
		temp->next=head;
		head = temp;
		
	}
	
}
void reverse(){
	struct node*currnode,*prevnode,*nextnode;
	prevnode = NULL;
	currnode=nextnode=head;
	while(nextnode!=NULL){
		nextnode = nextnode->next;
		currnode->next=prevnode;
		prevnode = currnode;
		currnode = nextnode;
	}
	head = prevnode;		
} 
void swap(int i,int j){
	if(head==NULL){
		printf("swap cannot be done");
	}
	else{
		struct node*p,*q;
		p=q=head;
		int st=0;
		int k=1,l=1;
		while(k<i){
			p = p->next;
			k++;
		}
		while(l<j){
			q = q->next;
			l++;
		}
		st = p->x;
		p->x = q->x;
		q->x = st;	
	}
}
void display(){
	struct node*temp;
	temp=head;
	while(temp!=NULL){
		printf("%d -> ",temp->x);
		temp = temp->next;
	}
}
void count(){
	struct node*temp;
	int len=0;
	temp = head;
	while(temp!=NULL){
		len++;
		temp = temp->next;
	}
	printf("%d",len);
}

int main(){
	insertatend(5);
	insertatend(3);
	insertatbegin(4);
	insertatend(2);
	insertafter(2,7);
	swap(2,3);
	delsn(3);
	display();
	printf("\n");
	count();
}

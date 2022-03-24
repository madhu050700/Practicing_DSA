//searching techniques.
#include<stdio.h>
#include<stdlib.h>

int Binarysearch(int A[],int n,int data){
	int low=0,high=n-1;
	while(low<=high){
		int mid = low+high/2;
		if(data<A[mid]){
			high = mid-1;
		}
		else if(data>A[mid]){
			low = mid+1;
		}
		else if(data==A[mid]){
			return mid;
		}
	}
	return -1;
}



int main(){
	int a[]={1, 2, 3, 4, 5};
	int n =sizeof(a)/sizeof(a[0]);
	int data=3;
	
	int n,a[n],data;
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	scanf("%d",&data);
	//linear searching
	printf("Enter the number to be searched:");
	scanf("%d",&b);
	for(i=0;i<n;i++){
		if(a[i]==b){
			printf("The element is found at %d",i);
			break;
		}
	}
	if(i==n)
		printf("Not found");
	int res = Binarysearch(a,n,data);
	if(res==-1)
		printf("Not found");
	else
		printf("Found %d",res);
	
}

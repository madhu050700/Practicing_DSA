#include<stdio.h>
#include<stdlib.h>
//bubblesort
/*
int main(){
	int n,i,a[n],j;
	int temp=0;
	int flag;
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%d", &a[i]);
	}
	for(i=0;i<n-1;i++){
		flag=0;
		for(j=0;j<n-i-1;j++){
			if(a[j]>a[j+1]){
				temp = a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				flag=1;
			}
		}
		if(flag==0)
			break;
	}
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
}
*/
//insertion sort
/*
int main(){
	int n,a[n],i,j;
	int temp;
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%d", &a[i]);
	}
	for(i=1;i<=n-1;i++){
		temp=a[i];
		for(j=i-1;j>=0;j--){
			if(temp<a[j]){
				a[j+1]=a[j];
			}
			else
				break;
		}
		a[j+1]=temp;
	}
	for(i=0;i<n;i++){
		printf("%d", a[i]);
	}
}
*/
//selection sort
/*
int main(){
	int n,a[n],i,j;
	int min,temp;
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%d", &a[i]);
	}
	for(i=0;i<n-1;i++){
		min = i;
		for(j=i+1;j<n;j++){
			if(a[j]<a[min])
				min=j;
		}
		temp=a[i];
		a[i]=a[min];
		a[min]=temp;
	}
	for(i=0;i<n;i++){
		printf("%d", a[i]);
	}
	
}
*/
// quick sort

int* Quicksort(int arr[],int lb,int ub){
	if(lb<ub){
		int loc = partition(arr,lb,ub);
		Quicksort(arr,lb,loc-1);
		Quicksort(arr,loc+1,ub);
	}
	return arr;
}

int partition(int arr[],int lb,int ub){
	int pivot =arr[lb];
	int l=arr[lb];
	int r=arr[ub];
	int temp,temp1;
	while(l<r){
		while(arr[l]<=pivot)
			l++;
		while(arr[r]>pivot)
			r--;
		if(l<r){
			temp=arr[l];
			arr[l]=arr[r];
			arr[r]=temp;	
		}	
	}
	temp1=arr[lb];
	arr[lb]=arr[r];
	arr[r]=temp1;
	return r;
}


int main(){
	int n,a[n],i;
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%d", &a[i]);
	}
	Quicksort(a,0,n-1);
	for(i=0;i<n;i++){
		printf("%d",a[i]);
	}	
}


// merge sort

/*
void merge(int a[],int lb,int mid,int ub){
	int i,j,k,c;
	i=lb;
	j=mid+1;
	k=lb;
	int b[100];
	while(i<=mid && j<=ub){
		if(a[i]<=a[j]){
			b[k]=a[i];
			i++;
			k++;
		}
		else {
			b[k]=a[j];
			j++;
			k++;
		}
	}
	if(i>mid){
		while(j<=ub){
			b[k]=a[j];
			j++;
			k++;
		}
	}
	else{
		while(i<=mid){
			b[k]=a[i];
			i++;
			k++;
		}
	}
	for(c=lb;c<=ub;c++){
		a[c]=b[c];
	}
}
void Mergesort(int a[],int lb,int ub){
	int mid;
	if(lb<ub){
		mid = (lb+ub)/2;
		Mergesort(a,lb,mid);
		Mergesort(a,mid+1,ub);
		merge(a,lb,mid,ub);
	}
}

int main(){
	int n,a[n],i;
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%d", &a[i]);
	}
	Mergesort(a,0,n-1);
	for(i=0;i<n;i++){
		printf("%d",a[i]);
	}
	
}
*/




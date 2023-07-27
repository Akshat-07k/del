#include<stdio.h>

int main(){

int n;
printf(" Enter NUmber of terms in array");
scanf(" %d",&n);	

	
	int arr[n];
	
	for(int i=0;i<n;i++){
		scanf(" %d",&arr[i]);
	}
	
	int sum[n+1];
	
	sum[0]=0;
	for(int i=1;i<n+1;i++){
		sum[i] = sum[i-1]+ arr[i-1];
	}
	
	
	for(int i=0;i<n;i++){
		
		printf(" %d " , arr[i]);
	
	}
	printf(" \n");
	
	
		for(int i=1;i<n+1;i++){
		
		printf(" %d " , sum[i]);
	
	}
	
return 0;
}

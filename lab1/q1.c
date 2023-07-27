#include<stdio.h>

int main(){

int n;
printf(" Enter NUmber of terms in array");
scanf(" %d",&n);	
	if(n<3)
	return 0;
	
	int arr[n];
	
	for(int i=0;i<n;i++){
		scanf(" %d",&arr[i]);
	}
	
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n;j++){
			if(arr[j] < arr[j+1])
			{
				int temp= arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				
			}
		
		}
	}
	
	
	for(int j=0;j<n;j++){
			printf(" %d " , arr[j]);
		}
	
	printf(" Second Largest and Second Smallest are : %d %d", arr[1], arr[n-2] );
return 0;
}

#include<stdio.h>

void Rotate(int arr[], int n, int initial, int final){
		int value = final+initial;
		int store;
		for(int i=initial;i<initial+final;i++){
			store= arr[i];
			arr[i]  = value;
			value = store;
		}

}
//#include<limit.h>
int main(){
	
	int n,r,i,f;
	
	scanf(" %d",&n);
	int arr[n];
	
	
	for(int i=0;i<n;i++){
		scanf(" %d",&arr[i]);
	}
	
	printf(" Enter rotating parameters : ");scanf(" %d %d",&i, &f);
	Rotate(arr,n,i,f);
	printf("\n");
	
	for(int i=0;i<n;i++){
		printf(" %d",arr[i]);
	}
	return 0;
}

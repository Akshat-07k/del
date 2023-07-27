#include<stdio.h>
//#include<limit.h>
int main(){
	
	int n;
	scanf(" %d", &n);
	int count=0,total = 0,index=0;
	int arr[n],freq[n];
	
	for(int i=0;i<n;i++){
		scanf(" %d",&arr[i]);
	}
	freq[n-1]=0;
	int max = 0;
	for(int i=0;i<n-1;i++){
	freq[i]=0;
	
		for(int j=i+1;j<n && arr[i]!=0;j++){
			if(arr[i]==arr[j]){
				arr[j]=0;
				freq[i]++;
			}
		}
		if(freq[i]!=0)
		total++;
		if(freq[i] > max){
			max= freq[i],
			index = i;
		}
	}
	
	printf("Total dups are  %d , max freq %d with %d \n" ,total,arr[index] , max+1);
	for(int i=0;i<n;i++){
	if(arr[i] !=0)
		printf(" %d %d\n",arr[i],freq[i]+1);
	}
	return 0;
}

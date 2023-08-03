#include<stdio.h>

int main(){

	FILE *p;
	p = fopen("num","w");
	printf(" Enter numbers (-1 to exit)");
	while(1){
		int temp;
		scanf(" %d",&temp);
		if(temp!= -1)
		putw(temp,p);
		else
		break;
	}
	fclose(p);
	
	p = fopen("num","r");
	printf(" Displaying The input ");
	while(1){
		int num = getw(p);
		if(num != EOF){
			printf(" %d ",num);
			while(num > 0){
				printf("%d",num%2);
				num = num/2;
			}
			printf("\n");
		}
		else
		break;
	}	
	
	fclose(p);

return 0;
}

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
	int gcd = 1;
	int num1 = getw(p);
	
		if(num1 != EOF){
			int  num2 = getw(p);
			
			if(num1 != EOF && num2 != EOF){
			
				for(int i=1;i<=num1 && i <= num2;i++){
				
					if(num1%i ==0 && num2%i==0){
					
						if(gcd < i){
							gcd = i;
						
						}
					}
				}
				
			}
			printf(" : %d \n" , gcd);
		}
		
		
		else
		break;
	}	
	
	fclose(p);

return 0;
}

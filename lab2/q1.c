#include <stdio.h>

void fun(int arr[], int *i, int num)
{
	if (num > 0)
	{
		arr[*i] = num % 2;
		*i = *i + 1;
		fun(arr, i, num / 2);
	}
	else
		return;
}
int main()
{

	FILE *p;
	p = fopen("num", "w");
	printf(" Enter numbers (-1 to exit)");
	while (1)
	{
		int temp;
		scanf(" %d", &temp);
		if (temp != -1)
			putw(temp, p);
		else
			break;
	}
	fclose(p);

	p = fopen("num", "r");
	printf(" Displaying The input ");
	while (1)
	{
		int num = getw(p);
		if (num != EOF)
		{
			printf(" %d ", num);
			// while(num > 0){
			// 	printf("%d",num%2);
			// 	num = num/2;
			// }
			int i = 0, arr[100];
			fun(arr, &i, num);

			for (int j = i - 1; j >= 0; j--)
			{
				printf("%d", arr[j]);
			}
			printf("\n");
		}
		else
			break;
	}

	fclose(p);

	return 0;
}

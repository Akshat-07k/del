#include <stdio.h>

void fun(int num1, int num2, int i, int *gcd)
{
	// printf(" -:%d:-", i);
	if (i <= num1 && i <= num2)
	{

		if (num1 % i == 0 && num2 % i == 0)
		{
			// printf("check");
			// printf(" ")
			if (*gcd < i)
			{
				// printf(" :%d: ", i);
				*gcd = i;
			}
		}
		fun(num1, num2, ++i, gcd);
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
		int gcd = 1;
		int num1 = getw(p);

		if (num1 != EOF)
		{
			int num2 = getw(p);

			if (num1 != EOF && num2 != EOF)
			{
				printf(": %d %d :", num1, num2);
				int gcd = 1;
				fun(num1, num2, 1, &gcd);
				// for (int i = 1; i <= num1 && i <= num2; i++)
				// {

				// 	if (num1 % i == 0 && num2 % i == 0)
				// 	{

				// 		if (gcd < i)
				// 		{
				// 			gcd = i;
				// 		}
				// 	}
				// }
				printf(" %d \n", gcd);
			}
		}

		else
			break;
	}

	fclose(p);

	return 0;
}

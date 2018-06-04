#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

/*
Factorial digit sum
Problem 20

n! means n × (n − 1) × ... × 3 × 2 × 1

For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.

Find the sum of the digits in the number 100!
*/

#define MAX 10000

char * multiply( char[], char[] );

int main(int argc, char const *argv[])
{

	int num = 100;
	char str[25];
    itoa(num, str, 10);
  	printf("The number 'num' is %d and the string 'str' is %s. \n" ,num, str);
    return 0;
}


char * multiply( char a[], char b[] )
{
	static char mul[MAX];
	char c[MAX];
	char temp[MAX];
	int la, lb;
	int i, j, k = 0, x = 0, y;
	long int r = 0;
	long sum = 0;
	la = strlen(a) - 1;
	lb = strlen(b) - 1;
	for (i = 0; i <= la; i++)
	{
		a[i] = a[i] - 48;
	}
	for (i = 0; i <= lb; i++)
	{
		b[i] = b[i] - 48;
	}
	for (i = lb; i >= 0; i--)
	{
		r = 0;
		for (j = la; j >= 0; j--)
		{
			temp[k++] = (b[i] * a[j] + r) % 10;
			r = (b[i] * a[j] + r) / 10;
		}
		temp[k++] = r;
		x++;
		for (y = 0; y < x; y++ )
		{
			temp[k++] = 0;
		}
	}
	k = 0;
	r = 0;
	for (i = 0; i < la + lb + 2; i++)
	{
		sum = 0;
		y = 0;
		for (j = 1; j <= lb + 1; j++)
		{
			if (i <= la + j)
			{
				sum = sum + temp[y + i];
			}
			y += j + la + 1;
		}
		c[k++] = (sum + r) % 10;
		r = (sum + r) / 10;
	}
	c[k] = r;
	j = 0;
	for (i = k - 1; i >= 0; i--)
	{
		mul[j++] = c[i] + 48;
	}
	mul[j] = '\0';
	return(mul);
}
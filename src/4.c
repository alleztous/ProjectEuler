# include <stdio.h>

/*
Largest palindrome product
Problem 4

A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
Find the largest palindrome made from the product of two 3-digit numbers.
*/

const int N = 10;
const int MAX = 998001;

int isPalindromic(int);

int main(int argc, char const *argv[])
{
	int r1 = 0;
	int r2 = r1;

	for (int i = 999; i > 99; --i)
	{
		for (int j = 999; j > 99; --j)
		{
			if (isPalindromic(i*j))
			{
				r2 = i * j;
				printf("%d * %d = %d\n", i,j,r2);
				if (r2 > r1)
				{
					r1 = r2;
				}
			}
		}
	}
	printf("%d\n", r1);
	return 0;
}

int isPalindromic(int num){
	int s[N];
	int len = 0, flag = 1;

	while(num){
		s[len++] = num % 10;
		num /= 10;
	}

	for (int i = 0; i < len; ++i){
		if (s[i] != s[len-i-1]){
			flag = 0;
			break;
		}
	}
	return flag;
}


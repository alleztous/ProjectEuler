# include <stdio.h>

/*
Sum square difference
Problem 6

The sum of the squares of the first ten natural numbers is,
12 + 22 + ... + 102 = 385
The square of the sum of the first ten natural numbers is,
(1 + 2 + ... + 10)2 = 552 = 3025
Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.
Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
*/

int ssd(int n){

	int s1 = 0, s2 = 0;

	for (int i = 1; i < n+1; ++i)
	{
		s1 += i*i;
		s2 += i;
	}

	return s2*s2 - s1;
}

int main(int argc, char const *argv[])
{
	printf("%d\n", ssd(100));
	return 0;
}


# include <stdio.h>

/*
Special Pythagorean triplet
Problem 9

A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
a2 + b2 = c2
For example, 32 + 42 = 9 + 16 = 25 = 52.
There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.
*/

int main(int argc, char const *argv[])
{

	long int a = 1, b = 1, c;

	for (a = 1; a < 500; ++a)
	{
		for (b = 1; b < 500; ++b)
		{
			c = 1000 - a - b;
			if (a*a + b*b == c*c)
			{
				printf("a= %ld, b = %ld, c = %ld\n", a,b,c);
				goto here;
			}
		}
	}
	here:;

	long int product = a * b * c;
	printf("%ld\n", product);
	return 0;
}

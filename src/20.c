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

// to be finished by myself
# define MAX_SIZE 200
char number[MAX_SIZE] = {"92842"};

int main(int argc, char const *argv[])
{
	for (int i = 0; i < MAX_SIZE; ++i)
	{
		printf("%c\n",number[i]);
	}
    return 0;
}




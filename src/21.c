#include <stdio.h>
#include <math.h>

/*
Amicable numbers
Problem 21

Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.

For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

Evaluate the sum of all the amicable numbers under 10000.
*/

# define UPPER_LIMIT 10000

int sumdivisors(int num){
	int sum = 1;
	
	for (int i = 2; i <= (int)sqrt(num); ++i)
	{
		if (num % i == 0)
		{
			if (i*i != num){
				sum += i;
				sum += num/i;
			}else{
				sum += i;
			}
		}
	}
	return sum;
}

int main(int argc, char const *argv[])
{	

	int sum = 0;
	for (int a = 2; a < UPPER_LIMIT; ++a)
	{
		int b = sumdivisors(a);
		if (a != b && a == sumdivisors(b))
		{
			printf("a = %d, b = %d \n", a, b);
			sum += a;
		}
	}

	printf("the sum of all the amicable numbers under 10000 is %d\n", sum);
    return 0;
}

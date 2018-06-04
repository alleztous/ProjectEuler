# include <stdio.h>
# include <math.h>

/*
Summation of primes
Problem 10

The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
Find the sum of all the primes below two million.
*/

int isPrime(int num){
	int flag = 1;
	if (num != 2){
		for (int i = 2; i < (int)sqrt(num) + 2; ++i)
		{
			//printf("%d\t%d\t%d\n",num,i,num % i);
			if (num % i == 0)
			{
				flag = 0;
				break;
			}
		}
	}
	return flag;
}

int main(int argc, char const *argv[])
{
	int num = 2;
	long int sum;
	while(num < 2000000){
		if (isPrime(num))
		{
			printf("%d\n", num);
			sum += num;
		}
		num ++;
	}
	printf("%ld\n",sum);
	return 0;
}


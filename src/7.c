# include <stdio.h>
# include <math.h>

/*
10001st prime
Problem 7

By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
What is the 10 001st prime number?
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

int nthPrime(int n){
	int count = 0,num = 1;

	while(count < n){
		num++;
		if(isPrime(num)){
			count++;
		}
	}
	return num;
}

int main(int argc, char const *argv[])
{
	/*
	for (int i = 2; i < 100; ++i)
	{
		if (isPrime(i))
		{
			printf("%d\n", i);
		}
	}
	*/
	printf("%d\n", nthPrime(10001));
	return 0;
}


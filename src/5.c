# include <stdio.h>

/*
Smallest multiple -- long int version
Problem 5

2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/

long int gcd(long int a, long int b){
	long int t;
	while(a % b != 0){
		t = a % b;
		a = b;
		b = t;
	}
	return b;
}

long int lcm(long int a, long int b){
	return a/gcd(a,b)*b;
}

int main(int argc, char const *argv[])
{
	long int r = 1, r1;
	for (long int i = 1; i < 21; i++)
	{
		r1 = lcm(r,i);
		printf("(%ld,%ld) = %ld\n",r,i,gcd(r,i));
		printf("(%ld,%ld) = %ld\n",r,i,r1);
		r = r1;
	}
	return 0;
}


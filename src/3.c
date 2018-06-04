# include <stdio.h>

/*
Largest prime factor
Problem 3

The prime factors of 13195 are 5, 7, 13 and 29.
What is the largest prime factor of the number 600851475143?
*/

int main(int argc, char const *argv[])
{
	int i = 1;
	long int num = 600851475143;
	while(num != 1){
		i++;
		while(num % i == 0){
			num /= i;
			//printf("%d\n",i);
		}
	}
	printf("%d\n",i);
	return 0;
}






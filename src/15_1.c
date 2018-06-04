# include <stdio.h>
# include <math.h>

/*
Lattice paths
Problem 15

The following iterative sequence is defined for the set of positive integers:

n → n/2 (n is even)
n → 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:

13 → 40 → N → 10 → 5 → 16 → 8 → 4 → 2 → 1
It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.
*/

# define N 20

long int cache[N][N] = {0};

int main(int argc, char const *argv[])
{
	for (int i = 0; i < N; ++i)
	{
		cache[0][i] = 1;
		cache[i][0] = 1;
	}

	for (int i = 1; i < N; ++i)
	{
		for (int j = 1; j < N; ++j)
		{
			cache[i][j] = cache[i-1][j] + cache[i][j-1];
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			printf("%ld ", cache[i][j]);
		}
		printf("\n");
	}
	
	printf("%ld\n", cache[N-1][N-1]);
    return 0;
}
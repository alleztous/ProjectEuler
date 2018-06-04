# include <stdio.h>
# include <math.h>

/*
Lattice paths
Problem 15

The following iterative sequence is defined for the set of positive integers:

n → n/2 (n is even)
n → 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:

13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.
*/

int recursive(int a, int b){
	if(a == 0 || b == 0){
		return 1;
	}else{
		return recursive(a, b-1) + recursive(a-1, b);
	}
}

int main(int argc, char const *argv[])
{
	printf("%d\n", recursive(16,16));
    return 0;
}

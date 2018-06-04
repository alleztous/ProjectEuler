# include <stdio.h>

/*
Lattice paths
Problem 16

The following iterative sequence is defined for the set of positive integers:

n → n/2 (n is even)
n → 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:

13 → 40 → N → 10 → 5 → 16 → 8 → 4 → 2 → 1
It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.
*/

# define size 400

int num[size] = {0};
int num1[size] = {0};

void add(int index, int t){
    int t1 = t;
    int i = index;
    while(1){
        if(num[i] + t1 > 9){
            num[i] = (num[i] + t1) % 10;
            i++;
            t1 = 1;
        }else{
            num[i] = (num[i] + t1) % 10;
            break;
        }
    }
}

int len(){
	int i = size - 1;
    while(1)
    {
    	if (num1[i] > 0)
    		break;
    	i--;
    }
    return i;
}

void printnum(){
	int i = size - 1;
    while(1)
    {
    	if (num[i] > 0)
    		break;
    	i--;
    }
    int s = 0;
    for (int j = i; j >= 0; --j)
    {
    	s = s + num[j];
    	printf("%d", num[j]);
    }
    printf("\n");
    printf("the sum of the digit is : %d\n", s);
}

int main(int argc, char const *argv[])
{
	num[0] = 2;

	for (int i = 0; i < 999; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			num1[j] = num[j];
		}
		for (int k = 0; k < len() + 1; ++k)
		{
			add(k,num1[k]);
		}
	}
	printnum();
    return 0;
}
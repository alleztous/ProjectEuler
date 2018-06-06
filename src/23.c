#include <stdio.h>
#include <math.h>

/*
Non-abundant sums
Problem 23


A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.

A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.

As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24. By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers. However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.

Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.
*/

#define MAX_SIZE 28123
int num[MAX_SIZE] = {0};
int cnt = 0;

int isabundant(int num){
    int sum = 1;
    int flag = 0;
    for (int i = 2; i <= (int)sqrt(num) ; ++i)
    {
        if(num % i == 0){
            if (i*i != num)
            {
                sum = sum + i + num/i;
            }else{
                sum = sum + i;
            }
        }
    }
    if(sum > num) flag = 1;
    if(sum < num) flag = -1;
    //printf("num = %d, sum = %d\n", num, sum);    
    return flag;
}

void initial(){
    for (int i = 2; i <= MAX_SIZE; ++i){
        if (isabundant(i) == 1)
            num[cnt++] = i;
    }
}

void print(){
    for (int i = 0; i < cnt; ++i)
    {
        printf("%d\n",num[i]);
    }
}

int isabundantsum(int i){
    int res = -1;
    int start = 0;
    int end = cnt - 1;
    while(end >= start){
        if (num[start] + num[end] > i){
            end--;
        }else if (num[start] + num[end] < i){
            start++;
        }else{
            res = 1;
            break;
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    initial();
    //print();
    printf("cnt = %d\n", cnt);
    int sum = 0;
    for (int i = 1; i <= MAX_SIZE; ++i)
    {
        if (isabundantsum(i) == -1)
        {
            sum += i;
            //printf("%d\n", i);
        }
    }
    //4179871 4179935
    printf("the total sum is %d\n", sum);
	return 0;
}


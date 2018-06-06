#include <stdio.h>
#include <math.h>

/*
 Lexicographic permutations
 Problem 24
 
 A permutation is an ordered arrangement of objects. For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4. If all of the permutations are listed numerically or alphabetically, we call it lexicographic order. The lexicographic permutations of 0, 1 and 2 are:
 
 012   021   102   120   201   210
 
 What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
 */

#define SIZE 10
int flag[SIZE];

void initial(){
    for (int i = 0; i < SIZE; ++i)
    {
        flag[i] = 1;
    }
}

int factorial(int n){
    int y = 1,i = 2;
    while(i <= n){
        y = y * (i++);
    }
    return y;
}

int choose(int put){
    int cnt = -1,index = 0;
    while(cnt != put){
        if (flag[index] == 1)
        {
            cnt++;
        }
        index++;
    }
    return index-1;
}

int main(int argc, char const *argv[])
{
    initial();
    
    int th = 1000000;
    int n = SIZE - 1;
    int put;
    
    while(n >= 0){
        put = th / factorial(n);
        th = th % factorial(n);
        if (th == 0) {
            int t = choose(put-1);
            flag[t] = 0;
            printf("%d",t);
            for (int i = SIZE-1; i >=0; i--) {
                if (flag[i] == 1) {
                    printf("%d",i);
                }
            }
            break;
        }
        int t = choose(put); // return the choosen number
        flag[t] = 0;
        n--;
        printf("%d",t);
    }
    printf("\n");
    return 0;
}

#include <stdio.h>  
#include <math.h>  


int divisor(int a)  
{  
    int i;  
    int num = 0;  
    for(i = 1; i <= sqrt(a); i++)  
    {  
        if(0 == a%i)  
            num += 2;  
        if(i*i == a)  
            num--;  
    }  
    return num;  
}  


int main()  
{  
    int i = 1;  
    int num = 0;  
    while(num <= 500)  
    {  
        i++;  
        num = divisor(i*(i+1)/2);  
    }  
    printf("%d\n",i*(i+1)/2);  
    return 0;  
}  
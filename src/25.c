#include <stdio.h>
#include <math.h>

/*
1000-digit Fibonacci number
Problem 25
 
The Fibonacci sequence is defined by the recurrence relation:

Fn = Fn−1 + Fn−2, where F1 = 1 and F2 = 1.
Hence the first 12 terms will be:

F1 = 1
F2 = 1
F3 = 2
F4 = 3
F5 = 5
F6 = 8
F7 = 13
F8 = 21
F9 = 34
F10 = 55
F11 = 89
F12 = 144
The 12th term, F12, is the first term to contain three digits.

What is the index of the first term in the Fibonacci sequence to contain 1000 digits?
*/

#define SIZE 1000

void vetSum (int vet1[],int vet2[]);

int main(){
  int n,i;
  int n1[SIZE],n2[SIZE],temp[SIZE];

  n1[0]=1;
  n2[0]=1;

  for (i=1;i<SIZE;i++){
    n1[i]=0;
    n2[i]=0;
  }

  int cnt = 2;
  
  while (1){      
    for (i=0;i<SIZE;i++)
      temp[i]=n2[i];
    vetSum(n1,n2);
    for (i=0;i<SIZE;i++)
      n1[i]=temp[i];
    cnt++;
  	if (n2[999] != 0)
  	{
  		break;
  	}
  }

  for (i=999;i>=0;i--)
    printf("%d",n2[i]);
	
  printf("\n");
  printf("cnt = %d\n",cnt);
  return 0;
}

void vetSum (int vet1[],int vet2[]){
  int i,aux,fica;
  int vai=0;
  for (i=0;i<SIZE;i++){
    aux=vet2[i]+vet1[i]+vai;
    vai = 0;
    if (aux<10)
      vet2[i]=aux;
    else {
      fica = aux % 10;
      vai = 1;
      vet2[i] = fica;
    }
  }
  return;
}


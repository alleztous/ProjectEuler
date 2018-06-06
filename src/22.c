#include <stdio.h>
#include <math.h>

/*
Names scores
Problem 22

Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.

For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.

What is the total of all the name scores in the file?
*/

#define MAX_SIZE 10000

int main(int argc, char const *argv[])
{

	FILE *f = fopen("/Users/lemuria/Documents/Code/C/ProjectEuler/data/22.txt", "r");
	char p[MAX_SIZE];
	while(1){
		int a = fscanf(f,"\"%[^\"]\",",p);
		printf("%s\n", p);
		if (a != 1)
		{
			break;
		}
	} 


	/*
	FILE *fpWrite=fopen("data.txt","w");  
    if(fpWrite==NULL)  
    {  
        return 0;  
    }  
    for(int i=0;i<10;i++)  
        fprintf(fpWrite,"%d ",i);  
    fclose(fpWrite);  
    //下面是读数据，将读到的数据存到数组a[10]中，并且打印到控制台上  
    int a[10]={0};  
    FILE *fpRead=fopen("data.txt","r");  
    if(fpRead==NULL)  
    {  
        return 0;  
    }  
    for(int i=0;i<10;i++)  
    {  
        fscanf(fpRead,"%d ",&a[i]);  
        printf("%d ",a[i]);  
    }  
    getchar();//等待  
	*/
	return 0;
}

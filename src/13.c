# include <stdio.h>
# include <math.h>

/*
Work out the first ten digits of the sum of the following one-hundred 50-digit numbers.
Problem 13

Work out the first ten digits of the sum of the following one-hundred 50-digit numbers.

*/

int num[200] = {0};

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

void printnum(){
	int i = 199;
    while(1)
    {
    	if (num[i] > 0)
    		break;
    	i--;
    }
    for (int j = i; j >= 0; --j)
    {
    	printf("%d", num[j]);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    FILE *fp = NULL;
    // open file
    fp = fopen("/Users/lemuria/Documents/Code/C/ProjectEuler/13.txt","r");

    int flag, index = 0;
    char t;

    do{
        flag = fscanf(fp,"%c",&t);
        // printf("t = %c, index = %d\n",t, index);
        if (t != '\n'){
           	add(49-index,t-'0');
           	index++;
           	if (index == 50){
           		printnum();
           	}
			index %= 50;
        }
    } while(flag == 1);

    fclose(fp);

    return 0;
}

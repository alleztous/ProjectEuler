# include <stdio.h>

/*
Maximum path sum II
Problem 67
By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.

3
7 4
2 4 6
8 5 9 3

That is, 3 + 7 + 4 + 9 = 23.

Find the maximum total from top to bottom in triangle.txt (right click and 'Save Link/Target As...'), a 15K text file containing a triangle with one-hundred rows.

NOTE: This is a much more difficult version of Problem 18. It is not possible to try every route to solve this problem, as there are 299 altogether! If you could check one trillion (1012) routes every second it would take over twenty billion years to check them all. There is an efficient algorithm to solve it. ;o)
*/

# define size 5050

int findrows(int i){
	int row = 0;
	while(1){ 
		if(i <= (row+1)*(row+2)/2 - 1)
			break;
		row++;
	}
	return row;
}

int findi(int row, int index){
	return row*(row+1)/2 + index;
}

int main(int argc, char const *argv[])
{
	int flag,cnt;
    int num[size] = {0};
	FILE *fp = NULL;

    fp = fopen("/Users/lemuria/Documents/Code/C/ProjectEuler/67.txt","r");

	do{
		flag = fscanf(fp,"%d",&num[cnt++]);
    } while(flag == 1);

    fclose(fp);

    int maxsum[size] = {0};
    maxsum[0] = num[0];

    printf("%d", maxsum[0]);
    int final = 0;
    for (int i = 1; i < size; ++i)
    {
	    int row = findrows(i);
	    int index = i - row*(row+1)/2;
	    if(index == 0){
	    	maxsum[i] = maxsum[findi(row-1,0)] + num[i]; 
			printf("\n");
	    }else if(index == row){
	    	maxsum[i] = maxsum[findi(row-1,index-1)] + num[i]; 
	    }else{
	    	int t;
	    	if(maxsum[findi(row-1,index-1)] > maxsum[findi(row-1,index)]){
	    		t = maxsum[findi(row-1,index-1)];
	    	}else{
	    		t = maxsum[findi(row-1,index)];
	    	}
	    	maxsum[i] = t + num[i];
	    }
	    printf("%d ", maxsum[i]);
	    if(row == 99 && maxsum[i] > final){
	    	final = maxsum[i];
	    }
    }
    printf("\n");
    printf("the maximum sum is %d\n", final);
    return 0;
}

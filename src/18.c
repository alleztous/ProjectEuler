# include <stdio.h>

/*
Maximum path sum I
Problem 18

By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.

3
7 4
2 4 6
8 5 9 3

That is, 3 + 7 + 4 + 9 = 23.

Find the maximum total from top to bottom of the triangle below:

75
95 64
17 47 82
18 35 87 10
20 04 82 47 65
19 01 23 75 03 34
88 02 77 73 07 63 67
99 65 04 28 06 16 70 92
41 41 26 56 83 40 80 70 33
41 48 72 33 47 32 37 16 94 29
53 71 44 65 25 43 91 52 97 51 14
70 11 33 28 77 73 17 78 39 68 17 57
91 71 52 38 17 14 91 43 58 50 27 29 48
63 66 04 68 89 53 67 30 73 16 69 87 40 31
04 62 98 27 23 09 70 98 73 93 38 53 60 04 23

NOTE: As there are only 16384 routes, it is possible to solve this problem by trying every route. However, Problem 67, is the same challenge with a triangle containing one-hundred rows; it cannot be solved by brute force, and requires a clever method! ;o)
*/

# define size 120

int findrows(int i){
	int row = 0;
	while(1){ 
		if(i <= (row+1)*(row+2)/2 - 1)
			break;
		row++;
	}
	//printf("row = %d\n",row);
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

    // open file
    fp = fopen("/Users/lemuria/Documents/Code/C/ProjectEuler/18.txt","r");

	do{
		flag = fscanf(fp,"%d",&num[cnt++]);
    } while(flag == 1);

    fclose(fp);

    //int len = sizeof(num)/sizeof(num[0]);
    int maxsum[size] = {0};
    maxsum[0] = num[0];

    /*
    maxsum[0] = num[0];
    maxsum[1] = num[0] + num[1];
    maxsum[2] = num[0] + num[2];
    maxsum[3] = maxsum[1] + num[3];
    maxsum[4] = max(maxsum[1], maxsum[2]) + num[4];
    maxsum[5] = maxsum[2] + num[5];
    maxsum[6] = maxsum[3] + num[6];
    maxsum[7] = max(maxsum[3], maxsum[4]) + num[7];
    maxsum[8] = max(maxsum[4], maxsum[5]) + num[8];
    maxsum[9] = maxsum[5] + num[9];
	*/

    // find a formular to calculate it.
    printf("%d", maxsum[0]);

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
    }
    printf("\n");
    return 0;
}

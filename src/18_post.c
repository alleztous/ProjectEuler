# include <stdio.h>
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
    fp = fopen("/Users/lemuria/Documents/Code/C/ProjectEuler/18.txt","r");
	do{
		flag = fscanf(fp,"%d",&num[cnt++]);
    } while(flag == 1);
    fclose(fp);

    int maxsum[size] = {0};
    maxsum[0] = num[0];
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
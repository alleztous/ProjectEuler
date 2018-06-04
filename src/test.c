# include <stdio.h>

int findrows(int i){
	int row = 0;
	while(1){ 
		if(i <= (row+1)*(row+2)/2 - 1)
			break;
		row++;
	}
	printf("row = %d\n",row);
	return row;
}

int findi(int row, int index){
	printf("%d\n", row*(row+1)/2 + index);
	return row*(row+1)/2 + index;
}

int main(int argc, char const *argv[])
{
	findrows(10);
	findi(2,0);
	return 0;
}






# include <stdio.h>

int leapmounthdays[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
int noleapmounthdays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

int isleap(int year){
	int flag = 0;
	if(year % 4 == 0 && year % 100 != 0){
		flag = 1;
	}
	if (year % 100 == 0 && year % 400 == 0){
		flag = 1;
	}
	return flag;
}

int main(int argc, char const *argv[])
{
	int r = 0, cnt = 0;
	for (int year = 1900; year < 2019; ++year){
		if (isleap(year)){
			for (int month = 0; month < 12; ++month)
			{
				r += leapmounthdays[month] % 7;
				if (r % 7 == 6)
				{
					cnt++;
					// need more to determine where the month+2 is bigger than 12 or not, update the year in the mean time
					printf("%d is leap year\t%02d-%02d-01 is Sundays\n",year,year,month+2);
				}
			}
		}else{
			for (int month = 0; month < 12; ++month)
			{
				r += noleapmounthdays[month] % 7;
				if (r % 7 == 6)
				{
					cnt++;
					printf("%d is not leap year\t%02d-%02d-01 is Sundays\n",year,year,month+2);
				}
			}
		}
	}

	printf("there is %d beautiful days in total \n",cnt - 2);
    return 0;
}
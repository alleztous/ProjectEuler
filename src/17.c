# include <stdio.h>

/*
Number letter counts
Problem 17

If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?

NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.
*/

/*
1 ~ 9   --> one,two,three,four,five,six,seven,eight,nine,
11 ~ 19 --> eleven,twelve,thirteen,fourteen,fifteen,sixteen,seventeen,eighteen,nineteen,
10 ~ 90 --> ten,twenty,thirty,forty,fifty,sixty,seventy,eighty,ninety
100     --> hundred
1000    --> thousand
special --> and
*/

int wordcnt_1_9[9] = {3,3,5,4,4,3,5,5,4};
int wordcnt_11_19[9] = {6,6,8,8,7,7,9,8,8};
int wordcnt_10_90[9] = {3,6,6,5,5,5,7,6,6};
int wordcnt_100 = 7;
int wordcnt_special = 3;
int wordcnt_1000 = 8;

int main(int argc, char const *argv[])
{
	int sum[1000] = {0};
	int index = 0;

	// 1~9
	for (int i = 0; i < 9; ++i)
	{
		sum[index] = wordcnt_1_9[i];
		index++;
	}
	// 11-19
	for (int i = 0; i < 9; ++i)
	{
		sum[index] = wordcnt_11_19[i];
		index++;
	}
	// 20,30,...,90
	for (int i = 0; i < 9; ++i)
	{
		sum[index] = wordcnt_10_90[i];
		index++;
	}
	// 21,22,...29, 31,32,...., ..., 91,92,...99
	for (int i = 1; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			sum[index] = wordcnt_10_90[i] + wordcnt_1_9[j];
			index++;
		}
	}
	// sum of 1 ~ 99
	int sum_1_99 = 0;
	for (int i = 0; i < 99; ++i)
	{
		sum_1_99 += sum[i];
	}

	printf("%d\n", sum_1_99);	

	// sum of 101~199, 201~299,..., 901~901
	int sum_1_999 = 0;
	for (int i = 0; i < 9; ++i)
	{
		sum_1_999 += (wordcnt_100 + wordcnt_1_9[i] + wordcnt_special) * 99 + sum_1_99 ;
	}

	// sum of 100,200,...,900
	for (int i = 0; i < 9; ++i)
	{
		sum_1_999 += wordcnt_100 + wordcnt_1_9[i];
	}

	sum_1_999 += sum_1_99;

	printf("the total sum of 1 ~ 1000 is %d\n", sum_1_999 + wordcnt_1_9[0] + wordcnt_1000);

    return 0;
}
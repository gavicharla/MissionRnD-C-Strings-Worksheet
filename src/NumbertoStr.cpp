/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>


void number_to_str(float number, char *str, int afterdecimal) {
	int temp = afterdecimal;
	while (temp--)
		number *= 10;
	int ind = 0, j = 0, x, flag = 0;
		//x is used in the process of conversion
	if (number < 0)
	{
		number *= -1;
		flag = 1;
	}
	while (number >= 1)
	{
		if (ind != afterdecimal)
		{
			x = (int)number % 10;
			str[ind] = (char)x + '0';
			number /= 10;
		}
		else
		{
			if (ind != 0)
				str[ind] = '.';
			else
				str[ind] = '\0';
		}
		ind++;

	}
	if (flag == 1)
		str[ind++] = '-';
	str[ind] = '\0';
	ind--;
	char temp1;
	for (j = 0; j < ind; j++, ind--)
	{
		temp1 = str[j];
		str[j] = str[ind];
		str[ind] = temp1;
	}
}

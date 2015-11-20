/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>
#include <malloc.h>

#define SIZE 31

char ** commonWords(char *a, char *b) {
	if (a==NULL||b==NULL)
	return NULL;
	int i = 0, j = 0, k = 0, count = 0;
	int x[10][2], y[10][2], first = 0;

	while (a[i] != '\0')//storing the lower and upper bounds of the words in the line in a 2d array
	{
		if (a[i] == ' '&&i > 0)
		{
			if (a[i - 1] != ' ')
				x[j++][1] = i - 1;
		}
		else if (i == 0 && a[i] != ' ')
			x[j][0] = i;
		else if (i > 0 && a[i] != ' ')
		{
			if (a[i - 1] == ' ')
				x[j][0] = i;
		}
		i++;
	}
	if (a[i - 1] != ' ')
		x[j++][1] = i - 1;
	i = 0;
	while (b[i] != '\0')//storing the lower and upper bounds of the words in the line in a 2d array
	{
		if (b[i] == ' '&&i > 0)
		{
			if (b[i - 1] != ' ')
				y[k++][1] = i - 1;
		}
		else if (i == 0 && b[i] != ' ')
			y[k][0] = i;
		else if (i > 0 && b[i] != ' ')
		{
			if (b[i - 1] == ' ')
				y[k][0] = i;
		}
		i++;
	}
	if (a[i - 1] != ' ')
		y[k++][1] = i - 1;
	int l = 0, m = 0, flag = 0;
	for (l = 0; l < j; l++)

	{
		flag = 0;
		for (m = 0; m < k; m++)
		{
			if (a[x[l][0]] == b[y[m][0]])
			{
				int temp1 = x[l][0];//lower bound of a word in string a
				int temp2 = y[m][0];//lower bound of a word in string b
				int temp3 = x[l][1];//upper bound of a word in string b
				int temp4 = y[m][1];//upper bound of a word in string b
				for (; temp1 <= temp3&&temp2 <= temp4; temp1++, temp2++)
					if (a[temp1] != b[temp2])//checking if the chars in the string are equal
						break;
				if (temp1 - 1 != temp3 || temp2 - 1 != temp4)//checking if the bounds are perfect and equal
					flag++;
			}
			else
				flag++;

		}
		if (flag < k)
		{
			count++;//if a common word found
		}
		else
			x[l][0] = -1;//else marking the lower bound as non matched word
	}

	l = 0, m = 0, i = 0, k = 0;
	char **s = (char **)calloc(j, j * sizeof(char *));
	for (i = 0; i<j; i++)
		s[i] = (char *)malloc(32 * sizeof(char));
	for (i = 0; i < j; i++)
	{
		if (x[i][0] != -1)
		{
			int temp1 = x[i][0];
			int temp2 = x[i][1];
			k = 0;
			while (temp1 <= temp2)
			{
				s[l][k] = a[temp1];//copying the word into the 2d string
				k++;
				temp1++;
			}
			s[l][k] = '\0';
			l++;
		}
	}

	if (count>0)
	return s;
	else return NULL;
}
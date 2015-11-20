/*
OVERVIEW: Given a string, remove all spaces in it.
E.g.: Input: "abd scd". Output: "abdscd"

INPUTS: A string.

OUTPUT: Return string after removing spaces.

ERROR CASES: Return '\0' for invalid inputs.

NOTES: Don't create new string.
*/
#include<stdio.h>
char * removeSpaces(char *str) {
	if (str==NULL)
	return '\0';
	int i = 0, j = 0,count=0;
	while (str[i] != '\0')
	{
		if (str[i] == ' '&&count==0)//checking if the first char is a space
		{
			j = i;
			count++;
			i++;
		}
		else if (count > 0&&str[i]!=' ')//if already a space occurs and present char is not a space ..copy it to the old pos
		{
			str[j] = str[i];
			j++;
			i++;
		}
		else if (str[i] == ' '&&count > 0)
		{
			i++;
		}
		else
			i++;
	}
	if (count > 0)
		str[j] = '\0';
}
/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>
void reverse(char *s, int beg, int end)
{
	
	char temp;
	for (; beg < end; beg++, end--)
	{
		temp = s[beg];
		s[beg] = s[end];
		s[end] = temp;
	}
}
void str_words_in_rev(char *input, int len)
{
	int first=0, last = len - 1;
	char temp='0';
	for (; first < last; first++, last--)
	{
		temp = input[first];
		input[first] = input[last];
		input[last] = temp;
	}
	int count = 0, i = 0, temp1=0;

	while (input[i] != '\0')
	{
		if (input[i] == ' ')
		{
			if (count == 0)
			{
				reverse(input, 0, i - 1);
				count++;
				temp1 = i + 1;
			}
			else 
			{
				reverse(input, temp1, i - 1);
				count++;
				temp1 = i + 1;
			}
		}
		i++;
	}
	reverse(input, temp1, i - 1);

}

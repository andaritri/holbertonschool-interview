#include "palindrome.h"

/**
 * is_palindrome - hecks whether or not a given
 * unsigned integer is a palindrome.
 * @n: number to be checked
 * Return: 1 if n is a palindrome, and 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	int arr[40];
	int len_num, j;
	unsigned long int num = n;

	for (len_num = 0; num != 0; len_num++)
	{
		arr[len_num] = num % 10;
		num = num / 10;
	}

	for (j = 0; j < len_num / 2; j++)
	{
		if (arr[len_num - j - 1] != arr[j])
			return (0);
	}
	return (1);
}

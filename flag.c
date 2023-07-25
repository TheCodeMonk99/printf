#include "main.h"

/**
 * get_flags - flags
 * @format: string in which to print the arguments
 * @i: take a parameter.
 * Return: lass
 */
int get_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, cui;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (cui = *i + 1; format[cui] != '\0'; cui++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[cui] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}

		if (FLAGS_CH[j] == 0)
			break;
	}

	*i = cui - 1;

	return (flags);
}

#include "main.h"

/**
 * get_width - width for printing
 * @format: string in which to print the arguments.
 * @i: index.
 * @args: lits.
 *
 * Return: width.
 */
int get_width(const char *format, int *i, va_list args)
{
	int curi;
	int width = 0;

	for (curi = *i + 1; format[curi] != '\0'; curi++)
	{
		if (is_digit(format[curi]))
		{
			width *= 10;
			width += format[curi] - '0';
		}
		else if (format[curi] == '*')
		{
			curi++;
			width = va_arg(args, int);
			break;
		}
		else
			break;
	}

	*i = curi - 1;

	return (width);
}

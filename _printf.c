#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stddef.h>
#include <stdio.h>

/**
  * _printf - produces output according to specifier if present
  * @format: string that contains specifier
  * @...: additional arguments
  *
  * Return: the no. of characters printed
  *		excluding byte used to end output
  *		strings
  */
int _printf(const char *format, ...)
{
	int i, printed_chars = 0;
	char buffer[BUFF_SIZE];
	int buff_ind = 0;
	va_list args; /*creating list argument*/

	va_start(args, format);/*starting list from format*/

	if (format == NULL)
		return (-1);

	for (i = 0; format[i] != '\0' && format; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i]; /*add character 2 buffer*/

			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			printed_chars++;/*increment printed char count*/
		}

		else if (format[i] == '%') /*if % is present*/
		{
			i++;/*move to next element in format*/

			if (format[i] == '%')
			{
				buffer[buff_ind++] = '%';/*add % into the buffer*/

				if (buff_ind == BUFF_SIZE)
					print_buffer(buffer, &buff_ind);
				printed_chars++;

			}
			if (format[i] == 'c')
			{
				int c = va_arg(args, int);/*retrieve char from args*/

				buffer[buff_ind++] = c;
				if (buff_ind == BUFF_SIZE)
					print_buffer(buffer, &buff_ind);/*add to buffer*/
				printed_chars++;/*increment count*/

			}
			if (format[i] == 's')
			{
				char *str;

				str = va_arg(args, char *);
				while (*str)
				{
					buffer[buff_ind++] = *str;
					str++;
					if (buff_ind == BUFF_SIZE)
						print_buffer(buffer, &buff_ind);
					printed_chars++;
				}

				if (buff_ind == BUFF_SIZE)
				  print_buffer(buffer, &buff_ind);
			}
			else
			{
				buffer[buff_ind++] = format[i];
				if  (buff_ind == BUFF_SIZE)
					print_buffer(buffer, &buff_ind);
				printed_chars++;
			}

		}

	}
	print_buffer(buffer, &buff_ind);
	va_end(args);
	return (printed_chars);	/* return print_chars*/
}

/**
  * print_buffer - prints buffer
  * @buffer: character array
  * @buff_ind: index of characters in array
  *
  * Return: the number of chars printed
  */
void print_buffer(char buffer[], int *buff_ind)
{
	int m = 0;

	if (*buff_ind > 0) /*check if elements present*/
	{
	/*	for (m = 0; m < *buff_ind; m++)*/
			write(1, &buffer[m], *buff_ind);
	}
	*buff_ind = 0; /*flushing buffer*/
}

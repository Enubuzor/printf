#include "main.h"
/**
* _printf - Prints formated text.
* @format: String with format of parameters.
* Return: Length of text printed.
*/
int _printf(const char *format, ...)
{
	int chr_print = 0, a = 0;
	va_list args_list;

	if (format)
	{
		va_start(args_list, format);
		while (format[chr_print])
		{
			if (format[chr_print] == '%')
			{
				chr_print++;
				if (!format[chr_print])
				{
					return (-1);
				}
				if (conv(format, &chr_print, &a, &args_list))
				{
					chr_print++;
					continue;
				}
			}
			write(1, format + chr_print++, 1);
			a++;
		}
		return (a);
	}
	return (-1);
}

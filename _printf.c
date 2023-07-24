#include "main.h"
/**
<<<<<<< HEAD
  *_printf - prints the arguments passed through to it
  *@format: the character string
  *Return: always integer
  */
int _printf(const char *format, ...)
{
	va_list all;
	int i = 0, count = 0;

	va_start(all, format);
	for (; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			write_char(format[i]);
		}
		else if (format[i + 1] == 'c')
		{
			write_char(va_arg(all, int));
			i++;
		}
		else if (format[i + 1] == '%')
		{
			write_char('%');
			i++;
		}
		else if (format[i + 1] == 's')
		{
			char *s = va_arg(all, char*);

			count = pu_ts(s);
			i++;
			count += (count - 1);
		}
			count += 1;
	va_end(all);
	}
	return (count);
}

=======
 * _printf - is a function that selects the correct function to print.
 * @format: identifier to look for.
 * Return: the length of the string.
 */
int _printf(const char * const format, ...)
{
	convert_match m[] = {
		{"%s", printf_string}, {"%c", printf_char},
		{"%%", printf_37},
		{"%i", printf_int}, {"%d", printf_dec}, {"%r", printf_srev},
		{"%R", printf_rot13}, {"%b", printf_bin}, {"%u", printf_unsigned},
		{"%o", printf_oct}, {"%x", printf_hex}, {"%X", printf_HEX},
		{"%S", printf_exclusive_string}, {"%p", printf_pointer}
	};

	va_list args;
	int i = 0, j, len = 0;

	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

Here:
	while (format[i] != '\0')
	{
		j = 13;
		while (j >= 0)
		{
			if (m[j].id[0] == format[i] && m[j].id[1] == format[i + 1])
			{
				len += m[j].f(args);
				i = i + 2;
				goto Here;
			}
			j--;
		}
		_putchar(format[i]);
		len++;
		i++;
	}
	va_end(args);
	return (len);
}
>>>>>>> 4bc65afa1d5eb25dd33aeddfbc022cb65f790689

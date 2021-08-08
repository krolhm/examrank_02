#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

int ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int ft_count(long num, int base_num)
{
	int ret = 1;
	while (num >= base_num && ++ret)
		num = num / base_num;
	return (ret);
}

void ft_putnum(long num, int base_num)
{
	char *base = "0123456789abcdef";
	if (num >= base_num)
		ft_putnum((num / base_num), base_num);
	write(1, &base[num % base_num], 1);
}

int ft_strlen(char *str)
{
	int i = 0;
	while(str[i])
		i++;
	return (i);
}

int ft_printf(const char *str, ...)
{
	va_list args;
	long num = 0;
	int i = 0, count_char = 0, k = 0, width = 0, range = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			while (str[i] >= '0' && str[i] <= '9')
				width = width * 10 + str[i++] - 48;
			if (str[i] == '.' && ++i)
				while (str[i] >= '0' && str[i] <= '9')
					range = range * 10 + str[i++] - 48;
			if (str[i] == 's')
			{
				char *argument =  va_arg(args, char *);
				if (width > 0)
				{
					if (range > 0)
						width -= range;
					else
						width -= ft_strlen(argument);
					while (width-- > 0)
						count_char += ft_putchar(' ');
				}
				if (range > 0)
					while (k < range)
						count_char += ft_putchar(argument[k++]);
				else
					while (argument[k])
						count_char += ft_putchar(argument[k++]);
			}
			else if (str[i] == 'd')
			{
				if ((num = va_arg(args, int)) < 0)
					num = -num;
				count_char += ft_count(num, 10);
				if (width > 0)
				{
					if (range > 0)
						width -= range;
					else
						width -= ft_count(num, 10);
					while (width-- > 0)
						count_char += ft_putchar(' ');
				}
				if (range > 0)
				{
					range -= ft_count(num, 10);
					while (range-- > 0)
						count_char += ft_putchar('0');
				}
				ft_putnum(num, 10);
			}
			else if (str[i] == 'x')
			{
				num = va_arg(args, unsigned int);
				count_char += ft_count(num, 16);
				if (width > 0)
				{
					if (range > 0)
						width -= range;
					else
						width -= ft_count(num, 16);
					while (width-- > 0)
						count_char += ft_putchar(' ');
				}
				if (range > 0)
				{
					range -= ft_count(num, 16);
					while (range-- > 0)
						count_char += ft_putchar('0');
				}
				ft_putnum(num, 16);
			}
		}
		else
			count_char += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (count_char);
}

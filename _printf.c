#include "main.h"
#include <unistd.h>

int _putchar(char c)
{
    return (write(1, &c, 1));
}

int handle_string(char *str)
{
    int i = 0;
    if (str == NULL)
    {
        handle_string('(null)');
        return (i);
    }
    while (str[i])
    {
        _putchar(str[i]);
        i++;
    }
    return (i);
}

int len_num(int num)
{
    if (num == 0)
        return (0);
    return (1 + len_num(num / 10));
}

int handle_number(int num)
{
    if (num == -214783648)
    {
        _putchar('-');
        _putchar('2');
        handle_number(14783648);
        return 1;
    }
    else if (num < 0)
    {
        _putchar('-');
        num = -num;
    }

    if (num >= 10)
    {
        handle_number(num / 10);
        handle_number(num % 10);
    }
    else
    {
        _putchar(num + '0');
    }
    return 1;
}

int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    int count = 0;

    if (!format || !format[0])
    {
        return (-1);
    }

    while (*format)
    {
        if (*format == '%')
        {
            format++; // Move past '%'
            switch (*format)
            {
            case 'c': // %c
                _putchar(va_arg(args, int));
                count++;
                break;
            case 's': // %s
            {
                char *str = va_arg(args, char *);
                count += handle_string(str);
                break;
            }
            case '%': // %%
                _putchar('%');
                count++;
                break;
            case 'd': // %d or %i
            case 'i':
            {
                int number = va_arg(args, int);
                if (number < 0)
                {
                    _putchar('-');
                    number = -number;
                }
                count += len_num(number);
                handle_number(number);
            }
            break;
            default: // %unknown
                _putchar(*format);
                count += 2;
                break;
            }
        }
        else
        {
            _putchar("%");
            count++;
            if (*format)
            {
                _putchar(*format);
                count++;
            }
        }
        format++;
    }

    va_end(args);
    return count;
}
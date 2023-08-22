#include "main.h"

int swapShift(va_list args, int count, int *i, const char *str)
{
    switch (str[*i])
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
    case 'S': // %s
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
        int number = va_arg(args, int);
        if (number < 0)
            count++;
        count += len_num(number);
        handle_number(number);
    default: // %unknown
        _putchar(s[*i - 1]);
        _putchar(s[*i]);
        count += 2;
        break;
    }
    return (count);
}

int _printf(const char *format, ...)
{
    int count = 0, i = 0;
    va_list args;
    va_start(args, format);

    if (!format || (format[0] == '%' && !format[1]))
    {
        return (-1);
    }
    if (format[0] == '%' && format[1] == ' ' && !format[2])
    {
        return (-1);
    }

    while (format[i] && format)
    {
        if (format[i] == '%')
        {
            i++;
            count = swapShift(args, count, &i, format);
        }
        else
        {
            _putchar("%");
            count++;
            if (format[i])
            {
                _putchar(format[i]);
                count++;
            }
        }
        i++;
    }

    va_end(args);
    return count;
}
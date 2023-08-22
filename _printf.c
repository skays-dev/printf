#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int count = 0; // To keep track of the number of characters printed

    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++; // Move past the '%'

            if (*format == 'c') // Handle character specifier
            {
                char c = va_arg(args, int);
                write(1, &c, 1);
                count++;
            }
            else if (*format == 's') // Handle string specifier
            {
                char *s = va_arg(args, char *);
                for (int i = 0; s[i] != '\0'; i++)
                {
                    write(1, &s[i], 1);
                    count++;
                }
            }
            else if (*format == '%') // Handle '%' specifier
            {
                write(1, "%", 1);
                count++;
            }
        }
        else
        {
            write(1, format, 1);
            count++;
        }

        format++;
    }

    va_end(args);
    return count;
}

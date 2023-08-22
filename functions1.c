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
        return (1);
    }
    else if (num < 0)
    {
        _putchar('-');
        num -= num;
    }

    if (num >= 10)
    {
        handle_number(num / 10);
        handle_number(num % 10);
    }
    else if (num < 10)
    {
        _putchar(num + '0');
    }
    return (1);
}
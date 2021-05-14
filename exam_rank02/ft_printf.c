#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct  s_st
{
    int width;
    int accur;
    int re;
    int point;
}               t_st;

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int  ft_strlen(char *s)
{
    int i;

    i = 0;
    while (s[i] != 0)
        i++;
    return (i);
}

void ft_list(t_st *st)
{
    st->width = 0;
    st->accur = 0;
    st->point = 0;
}

int ft_begin(t_st *st, const char *s)
{
    int i;

    i = 0;
    ft_list(st);
    while (s[i] != '\0' && s[i] != '%')
        ft_putchar(s[i++]);
    st->re += i;
    if (s[i] == '%')
        i++;
    return (i);
}

int ft_width(t_st *st, const char *s)
{
    int i;
    int res;
    int count;

    i = 0;
    res = 0;
    count = 1;
    while (s[i] >= '0' && s[i] <= '9')
    {
        res = res * count + (s[i++] - 48);
        count = 10;
    }
    st->width = res;
    return (i);
}

int ft_accur(t_st *st, const char *s)
{
    int i;
    int res;
    int count;

    i = 0;
    res = 0;
    count = 1;
    if (s[i++] != '.')
        return (0);
    st->point = 1;
    while (s[i] >= '0' && s[i] <= '9')
    {
        res = res * count + (s[i++] - 48);
        count = 10;
    }
    st->accur = res;
    return (i);
}

char	*ft_itoa(int n)
{
    char *d;
    int i;
    int count;
    int nb;

    nb = ((n > 0) ? n : -n);
    count = 1;
    i = 0;
    while (nb > 10)
    {
        nb /= 10;
        count *= 10;
    }
    d = (char *)malloc((count + 1) * sizeof(char));
    if (n < 0)
    {
        d[i++] = '-';
        n *= -1;
    }
    while (count > 0)
    {
        d[i++] = n / count + 48;
        n %= count;
        count /= 10;
    }
    d[i] = 0;
    return (d);
}

char	*ft_utoa(unsigned n)
{
    char *d;
    int i;
    int count;
    unsigned nb;

    count = 1;
    i = 0;
    nb = n;
    while (nb > 10)
    {
        nb /= 10;
        count *= 10;
    }
    d = (char *)malloc((count + 1) * sizeof(char));
    while (count > 0)
    {
        d[i++] = n / count + 48;
        n %= count;
        count /= 10;
    }
    d[i] = 0;
    return (d);
}

void	case_1(char *d, t_st *st)
{
    int i;

    i = 0;
    while (d[i] != 0)
        ft_putchar(d[i++]);
    st->re += i;
}

void	case_2(char *d, t_st *st, int len)
{
    int i;

    i = 0;
    while (i++ < (st->width - len))
        ft_putchar(' ');
    st->re += (i - 1);
    i = 0;
    while (i < len)
        ft_putchar(d[i++]);
    st->re += i;
}

void	case_3(char *d, t_st *st, int len)
{
    int i;
    int flag;

    i = 0;
    flag = ((d[i] == '-') ? 1 : 0);
    if (d[i] == '-')
        ft_putchar(d[i]);
    while (i++ < (st->accur - len + flag))
        ft_putchar('0');
    while (flag < len)
        ft_putchar(d[flag++]);
    st->re += (i - 1) + flag;
}

void	case_4(char *d, t_st *st, int len)
{
    int i;
    int flag;

    i = 0;
    flag = ((d[i] == '-') ? 1 : 0);
    while (i++ < (st->width - st->accur - flag))
        ft_putchar(' ');
    st->re += (i - 1);
    i = 0;
    if (d[i] == '-')
        ft_putchar(d[i]);
    while (i++ < (st->accur - len + flag))
        ft_putchar('0');
    while (flag < len)
        ft_putchar(d[flag++]);
    st->re += (i - 1) + flag;
}

void	cases(t_st *st, int len, char *d)
{
    if (st->width < len && st->accur < len)
        case_1(d, st);
    else if (st->width >= len && st->accur < len)
        case_2(d, st, len);
    else if (st->width < len && st->accur >= len)
        case_3(d, st, len);
    else if (st->width >= len && st->accur >= len)
        case_4(d, st, len);
}

void	case_1str(char *d, t_st *st, int len)
{
    int i;

    i = 0;
    if (!st->point)
    {
        while (i++ < (st->width - len))
            ft_putchar(' ');
        st->re += i - 1;
        i = 0;
        while (i < len)
            ft_putchar(d[i++]);
        st->re += i;
    }
    else if (st->point)
    {
        if (st->accur == 0)
        {
            while (i++ < st->width)
                ft_putchar(' ');
            st->re += i - 1;
        }
        else
        {
            while (i++ < (st->width - st->accur))
                ft_putchar(' ');
            st->re += i - 1;
            i = 0;
            while (i < st->accur)
                ft_putchar(d[i++]);
            st->re += i;
        }
    }
    i = 0;
    while (i < st->accur && st->point == 0)
        ft_putchar(d[i++]);
    st->re += i;
}

void	case_2str(char *d, t_st *st, int len)
{
    int i;
    int flag;

    i = 0;
    flag = 0;
    while (i++ < (st->width - len))
        ft_putchar(' ');
    st->re += (i - 1);
    i = 0;
    while (flag < len)
        ft_putchar(d[flag++]);
    st->re += flag;
}

void	cases_str(t_st *st, int len, char *d)
{
    if ((st->width < len && st->accur < len) || (st->width >= len && st->accur < len))
        case_1str(d, st, len);
    else if ((st->width < len && st->accur >= len) || (st->width >= len && st->accur >= len))
        case_2str(d, st, len);
}

void	proc_int(int n, t_st *st)
{
    int len;
    char *d;

    d = ft_itoa(n);
    len = ft_strlen(d);
    cases(st, len, d);
}

void	proc_str(char *d, t_st *st)
{
    int len;

    len = ft_strlen(d);
    cases_str(st, len, d);
}

char *xxx(unsigned n, char *d)
{
    if (n == 0)
        return (d + 1);
    else if (n % 16 < 10)
        *d-- = n % 16 + 48;
    else if (n % 16 >= 10)
        *d-- = n % 16 + 87;
    return (xxx(n / 16, d));
}

void	proc_x(unsigned n, t_st *st)
{
    int len;
    char *d;

    d = ft_utoa(n);
    len = ft_strlen(d);  
    d += len - 1;
    d = xxx(n, d);
    cases(st, ft_strlen(d), d);
}

int ft_type(t_st *st, const char *s, va_list ap)
{
    if (*s == 'd')
        proc_int(va_arg(ap, int), st);
    else if (*s == 's')
        proc_str(va_arg(ap, char *), st);
    else if (*s == 'x')
        proc_x(va_arg(ap, unsigned), st);
    return (1);
}

int ft_printf(const char *s, ... )
{
    va_list ap;
    t_st *st;

    va_start(ap, s);
    if (!(st = (t_st *)malloc(1 * sizeof(t_st))))
        return (0);
    st->re = 0;
    while (*s != 0)
    {
        s += ft_begin(st, s);
        if (*s == 0)
            break ;
        s += ft_width(st, s);
        s += ft_accur(st, s);
        s += ft_type(st, s, ap);
    }
    va_end(ap);
    free(st);
    return (st->re);
}

int main()
{
    printf("  ---  return: %d\n", ft_printf("Magic %10.1s is %5.d", "number", 42));
    printf("  ---  return: %d\n\n", printf("Magic %10.1s is %5.d", "number", 42));

    printf("  ---  return: %d\n", ft_printf("Hexadecimal for %d is %x", 42, 42));
    printf("  ---  return: %d\n\n", printf("Hexadecimal for %d is %x", 42, 42));

    printf("  ---  return: %d\n", ft_printf("%.7s", "toto"));
    printf("  ---  return: %d\n", printf("%.7s", "toto"));
    return 0;
}
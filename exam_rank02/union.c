#include <stdio.h>
#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_union(int argc, char **argv)
{
    int a[255];
    int i;

    i = 0;
    while (i < 255)
        a[i++] = 0;
    i = 0;
    if (argc == 3)
    {
        while (argv[1][i] != 0)
            if (!(a[argv[1][i]]))
            {
                a[argv[1][i]] = 1;
                ft_putchar(argv[1][i++]);
            }
            else
                i++;
        i = 0;
        while (argv[2][i] != 0)
            if (!(a[argv[2][i]]))
            {
                a[argv[2][i]] = 1;
                ft_putchar(argv[2][i++]);
            }
            else
                i++;
    }
    ft_putchar('\n');
}

int     main(int argc, char **argv)
{
    ft_union(argc, argv);
    return (0);
}
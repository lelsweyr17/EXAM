#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

int			ft_strlen(char *a)
{
	int i;

	i = 0;
	while (a[i] != '\0')
		i++;
	return (i);
}

char		*ft_strjoin(char *a, char *line)
{
	char *tmp;
	char *ab;
	int i;
	int len1;
	int len2;

	i = -1;
	len1 = ft_strlen(line);
	len2 = ft_strlen(a);
	ab = line;
	free(ab);
	tmp = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	while (++i < len1)
		tmp[i] = line[i];
	while (*a)
		tmp[i++] = *a++;
	tmp[i] = '\0';
	return (tmp);
}

int         get_next_line(char **line)
{
	char a[2];
	int i;

	i = 0;
	a[1] = 0;
	if (!line || read(0, a, 0) < 0)
		return(-1);
	*line = (char *)malloc(1 * sizeof(char));
	*line[0] = 0;
	while (read(0, a, 1) > 0)
	{
		if (a[0] == '\n')
		{
			a[0] = '\0';
			*line = ft_strjoin(a, *line);
			return (1);
		}
		*line = ft_strjoin(a, *line);
	}
	return (0);
}

int         main(void)
{
	int		r;
	char	*line;

	line = NULL;
	while ((r = get_next_line(&line)) > 0)
	{
		printf("%s\n", line);
		free(line);
		line = NULL;
	}
	printf("%s", line);
	free(line);
	line = NULL;
    return (0);
}
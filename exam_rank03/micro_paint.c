/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_paint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lelsweyr <lelsweyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 18:21:36 by lelsweyr          #+#    #+#             */
/*   Updated: 2021/04/01 14:45:28 by lelsweyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

typedef	struct	s_back
{
	int			width;
	int			heigth;
	char		c;
}				t_back;

typedef	struct	s_draw
{
	int			x1;
	int			y1;
	int			x2;
	int			y2;	
}				t_draw;

typedef struct	s_r
{
	char		r;
	float		x;
	float		y;
	float		width;
	float		heigth;
	char		c;
	char		**ar;
	t_back		back;
	t_draw		draw;
}				t_r;

void			func_R(t_r *elem)
{
	int i;
	int j;
	
	i = elem->draw.x1 - 1;
	j = elem->draw.y1 - 1;
	while (++i <= elem->draw.x2)
	{
		j = elem->draw.y1 - 1;
		while (++j <= elem->draw.y2)
		{
			if (i >= 0 && j >= 0 && i < elem->back.width && j < elem->back.heigth)
				elem->ar[j][i] = elem->c;
		}		
	}
}

void			func_r(t_r *elem)
{
	int i;
	int j;
	
	i = elem->draw.x1 - 1;
	j = elem->draw.y1 - 1;
	while (++i <= elem->draw.x2)
	{
		j = elem->draw.y1 - 1;
		while (++j <= elem->draw.y2)
		{
			if (i >= 0 && j >= 0 && i < elem->back.width && j < elem->back.heigth)
			{
				if ((i - elem->draw.x1) < 1 || (j - elem->draw.y1) < 1 || (elem->draw.x2 - i) < 1 || (elem->draw.y2 - j) < 1)
					elem->ar[j][i] = elem->c;
			}
		}		
	}
}

void			func_draw(t_r *elem)
{
	elem->draw.x1 = (int)elem->x;
	elem->draw.y1 = (int)elem->y;
	if ((elem->x - (int)elem->x) > 0)
		elem->draw.x1 += 1;
	if ((elem->y - (int)elem->y) > 0)
		elem->draw.y1 += 1;
	elem->draw.x2 = elem->x + elem->width;
	elem->draw.y2 = elem->y + elem->heigth;
	if ((elem->draw.x2 - (int)elem->draw.x2) > 0)
		elem->draw.x2 += 1;
	if ((elem->draw.y2 - (int)elem->draw.y2) > 0)
		elem->draw.y2 += 1;
	if (elem->draw.x2 == 0 && (elem->x + elem->width) < 0)
		elem->draw.x2 -= 1;
	if (elem->draw.y2 == 0 && (elem->y + elem->heigth) < 0)
		elem->draw.y2 -= 1;
}

void			array(t_r *elem)
{
	float i;
	float j;

	func_draw(elem);
	if (elem->r == 'R')
		func_R(elem);
	else if (elem->r == 'r')
		func_r(elem);
}

int				validate(t_r *elem)
{
	if (elem->width <= 0 || elem->heigth <= 0)
		write(1, "Error 1\n", 8);
	if (elem->r != 'r' && elem->r != 'R')
		write(1, "Error r\n", 8);
	return (0);
}

int				func_scan(FILE *fd, t_r *elem)
{
	int			i;
	char		c;

	i = 0;
	while ((i = fscanf(fd, "%c %f %f %f %f %c\n", &elem->r, &elem->x, &elem->y, &elem->width, &elem->heigth, &elem->c)) == 6)
	{
		printf("%c %f %f %f %f %c\n", elem->r, elem->x, elem->y, elem->width, elem->heigth, elem->c);
		if (validate(elem) == 1)
			return (1);
		array(elem);
	}
	if (i != -1)
		write(1, "Error elem\n", 6);
	return (0);
}

int				square(FILE *fd, t_r *elem)
{
	int			i;
	int			j;

	i = fscanf(fd, "%d %d %c\n", &elem->back.width, &elem->back.heigth, &elem->back.c);
	if (elem->back.width <= 0 || elem->back.width > 300 || elem->back.heigth <= 0 || elem->back.heigth > 300 || i != 3)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	i = -1;
	elem->ar = (char **)calloc(elem->back.heigth, sizeof(char *));
	while (++i < elem->back.heigth)
	{
		j = -1;
		elem->ar[i] = (char *)calloc(elem->back.width, sizeof(char));
		while (++j < elem->back.width)
			elem->ar[i][j] = elem->back.c;
	}
	return (0);
}

void			ft_free(t_r *elem)
{
	free(elem->ar);
	free(elem);
}

int				main(int argc, char **argv)
{
	FILE		*fd;
	t_r			*elem;
	t_back		*back;
	
	elem = (t_r *)calloc(1, sizeof(t_r));
	if (argc == 2)
	{
		fd = fopen(argv[1], "r");
		if (fd <= 0)
			return (0);
		if (square(fd, elem) == 0)
		{
			if (func_scan(fd, elem) == 1)
				return (1);
		}
	}
	int i;
	int j;
	
	i = -1;
	while (++i < elem->back.heigth)
	{
		j = -1;
		while (++j < elem->back.width)
			printf("%c", elem->ar[i][j]);
		printf("\n");
	}
	ft_free(elem);
	return (0);
}
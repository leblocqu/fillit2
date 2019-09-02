/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behaudeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 12:27:31 by behaudeg          #+#    #+#             */
/*   Updated: 2019/06/28 12:27:33 by behaudeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int			count_tetris(char *s)
{
	int i;
	int nb_tetri;

	i = 0;
	nb_tetri = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n' && (s[i + 1] == '\n' || s[i + 1] == '\0'))
			nb_tetri++;
		i++;
	}
	return (nb_tetri);
}

t_tetri		*create_tetris(t_tetri *t, char **str)
{
	int		index;
	int		nb_tetris;

	t = ft_memalloc(sizeof(t_tetri) * (g_nb_tetris + 1));
	nb_tetris = g_nb_tetris;
	index = 0;
	while (index < nb_tetris)
	{
		t[index].tetri = &str[index];
		index++;
	}
	return (t);
}

t_tetri		*create_coordd(t_tetri *t, int j, int k)
{
	int index;
	int i;

	i = -1;
	index = -1;
	while (++index < g_nb_tetris)
	{
		while (t)
		{
			while (++j < 4)
			{
				printf("index = %d\n", index);
				if (t[index].tetri[i][j] == '#')
				{
	printf("SEGFLOT\n");
					t[index].coord[k].x = j;
					t[index].coord[k].y = i;
					k++;
				}
			}
			j = -1;
		}
		i = -1;
		k = 0;
	}
	return (t);
}

t_tetri		*create_coord(t_tetri *t)
{
	int	j;
	int k;

	j = -1;
	k = 0;
	t = create_coordd(t, j, k);
	return (t);
}

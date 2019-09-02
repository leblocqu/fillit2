/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behaudeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 11:01:48 by behaudeg          #+#    #+#             */
/*   Updated: 2019/06/28 11:05:56 by behaudeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char	**fill_tab(char **tab, char *buf)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (j < count_tetris(buf))
	{
		tab[j] = (char*)malloc(sizeof(char) * 20 + 1);
		if (tab[j] == NULL)
			return (NULL);
		while (k < 20)
		{
			tab[j][k] = buf[i];
			k++;
			i++;
		}
		tab[j][20] = '\0';
		k = 0;
		j++;
		i++;
	}
	tab[j] = NULL;
	return (tab);
}

void	aff_tetri(t_tetri *t)
{
	int index;
	int i;

	index = 0;
	i = 0;
	while (index < g_nb_tetris)
	{
		while (t[index].tetri[i] != NULL)
		{
			printf("%s\n", t[index].tetri[i]);
			i++;
		}
		printf("\n");
		i = 0;
		index++;
	}
}

int		main(int argc, char **argv)
{
	char		**str;
	t_tetri		*tetriminios;

	str = NULL;
	tetriminios = NULL;
	if (argc != 2)
	{
		ft_putendl("error");
		return (-1);
	}
	if ((str = init_checker(argv[1])) == NULL)
	{
		ft_putendl("error");
		return (-1);
	}
	tetriminios = create_tetris(tetriminios, str);
	aff_tetri(tetriminios);
	tetriminios = create_coord(tetriminios);
	tetriminios = create_letter(tetriminios);
	solve(tetriminios, 2, NULL);
	return (0);
}

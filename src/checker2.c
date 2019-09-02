/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behaudeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 13:02:08 by behaudeg          #+#    #+#             */
/*   Updated: 2019/07/12 13:02:09 by behaudeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

// int		shapo(char *str)
// {
// 	int i;
// 	int n;
// 	int link;
// 	int test;

// 	link = 0;
// 	i = 0;
// 	n = 1;
// 	test = 0;
// 	if (str == NULL)
// 		return (0);
// 	int c = 0;
// 	while (str[i] != '\0')
// 	{
// 		c++;
// 		while (n % 5 != 0)
// 		{
// 			printf("val de i = %d\n", i);
// 			if (str[i] == '\n')
// 				n++;
// 			link = shapoo(i, str, test, link);
// 			i++;
// 		}
// 		if (link != 6 && link != 8)
// 		{
// 			printf("c = %d\n", c);
// 			return (0);
// 		}
// 		n++;
// 		i++;
// 		test += 21;
// 		link = 0;
// 	}
// 	return (1);
// }

// int		shapoo(int i, char *str, int test, int link)
// {
// 	if (str[i] == '#')
// 	{
// 		if (((i + 1) < 20 + test) && str[i + 1] == '#')
// 			link++;
// 		if ((i - 1) >= 0 + test && str[i - 1] == '#')
// 			link++;
// 		if (((i + 5) < 20 + test) && str[i + 5] == '#')
// 			link++;
// 		if ((i - 5) >= 0 + test && str[i - 5] == '#')
// 			link++;
// 	}
// 	return (link);
// }


int		check_line(char *s)
{
	int x;
	int y;
	int add_5;

	x = 0;
	y = 0;
	add_5 = 4;
	while (s[x] != '\0')
	{
		if (s[x] == '.' || s[x] == '#')
			y++;
		if (y > 4)
			return (0);
		if (s[x] == '\n' && x == add_5)
		{
			y = 0;
			add_5 += 5;
		}
		x++;
	}
	return (1);
}

int		check_char(char *s)
{
	int i;
	int hash;
	int point;
	int endline;

	i = 0;
	hash = 0;
	point = 0;
	endline = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '#')
			hash++;
		if (s[i] == '.')
			point++;
		if (s[i] == '\n')
			endline++;
		if (s[i] != '#' && s[i] != '.' && s[i] != '\n')
			return (0);
		i++;
	}
	if (hash != 4 || point != 12 || endline != 4)
		return (0);
	return (1);
}

// int		check_shape(char *s)
// {

// }

int				checker(char **tab)
{
	int i;

	i = 0;
	if (tab[0] == NULL)
		return (0);
	while (i < g_nb_tetris)
	{
		if (check_char(tab[i]) != 1)
			return (0);
		if (check_line(tab[i]) != 1)
			return (0);
		// if (check_shape(tab[i]) != 1)
		// 	return (0);
		i++;
	}
	return (1);
}
// int		checker(char *str)
// {
// 	int nb_tetri;

// 	nb_tetri = count_tetris(str);
// 	if (shapo(str) == 0)
// 		printf("shapo erreur\n");
// 	if (check_char(str) == 0)
// 		printf("check_char erreur\n");
// 	if (line_checker(str) == 0)
// 		printf("line_checker erreur\n");
// 	if (check_char2(str) == 0)
// 		printf("check_char2 erreur\n");
// 	return (shapo(str) == 0 || check_char(str) == 0
// 		|| line_checker(str) == 0 || check_char2(str) == 0) ? 0 : 1;
// }

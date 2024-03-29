/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: behaudeg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 14:50:03 by behaudeg          #+#    #+#             */
/*   Updated: 2019/06/25 14:50:06 by behaudeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <fcntl.h>

int g_nb_tetris;
# define BUFF_SIZE 4096

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_tetri
{
	char		lettre;
	char		**tetri;
	t_point		coord[4];
}				t_tetri;

char			**create_map(int size);
int     		try_pos(char **map, t_point point, t_tetri t, int size);
char    		**put_tetriminos(char **map, t_point point, t_tetri *t, int nb_tetris);
void	        affiche_map(char **map, int size);
char			**init_checker(char *argv);
int				line_checker(char *str);
// int				check_char(char *str);
// int				check_char2(char *str);
// int				shapo(char *str);
// int				shapoo(int i, char *str, int test, int link);
int				checker(char **tab);
int				count_tetris(char *str);
t_tetri			*create_tetris(t_tetri *t, char **str);
t_tetri			*create_coordd(t_tetri *test, int j, int k);
t_tetri			*create_coord(t_tetri *test);
t_tetri			*create_letter(t_tetri *tetri);
void			free_split(char **str_split);
void			solve(t_tetri *t, int size, char **map);
char			**fill_tab(char **tab, char *buf);
int				first_test(char *buf);
int		check_char(char *s);
int		check_line(char *s);
int		check_shape(char *s);

#endif

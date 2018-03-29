/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 09:54:07 by gavizet           #+#    #+#             */
/*   Updated: 2018/03/29 11:24:49 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct		s_lemin
{
	int				a;
	int				b;
	int				error;
	int				nb_rooms;
	int				end;
	int				start;
	int				len_tab;
	int				*next;
	int				*finish;
	int				*affichage;
	int				*aff_ants;
	int				*best_way;
	int				**sol;
	int				**links;
	long long		nb_ants;
}					t_lemin;

int					main();

int					str_is_digit(char *str);
int					digit_and_space(char *str);
int					search_for_room(t_lemin *data, int stock);

int					get_infos(t_lemin *data, t_list **room);
int					get_link(t_list **room, char *line, t_lemin *data,
					int *launch);

void				ft_lstprint(t_list **list);
void				aff_links_tab(t_lemin *data);
int					print_best_way(t_list **room, t_lemin *data);
void				print_course(t_list **room, t_lemin *data);

int					solve(t_lemin *data);
#endif

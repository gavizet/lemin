/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 15:55:16 by gavizet           #+#    #+#             */
/*   Updated: 2017/05/19 18:07:40 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static int	malloc_links(t_list **room, t_lemin *data)
{
	int			index;

	index = -1;
	ft_lstrev(room);
	if (!(data->links = (int**)ft_memalloc(sizeof(int*) *
					((data->nb_rooms + 1) * (data->nb_rooms + 1)))))
		return (1);
	while (++index < data->nb_rooms)
		if (!(data->links[index] = (int*)ft_memalloc(sizeof(int) *
						(data->nb_rooms + 1))))
			return (1);
	return (0);
}

static int	check_link(t_lemin *data, t_list *temp, char *r1, char *r2)
{
	int			index;
	int			check;

	index = 1;
	check = 0;
	while (temp)
	{
		if (!(ft_strcmp(r1, temp->content)))
		{
			data->a = index;
			check++;
		}
		if (!(ft_strcmp(r2, temp->content)))
		{
			data->b = index;
			check++;
		}
		temp = temp->next;
		index++;
	}
	ft_strdel(&r1);
	ft_strdel(&r2);
	if (check != 2 || data->a == data->b)
		return (1);
	return (0);
}

int			get_link(t_list **room, char *line, t_lemin *data, int *launch)
{
	char		*r1;
	t_list		*temp;
	static int	x = 1;

	r1 = ft_strsub(line, 0, ft_strchr(line, '-') - line);
	*launch = 1;
	if (data->links == 0)
		if (malloc_links(room, data) || data->start <= 0 || data->end <= 0)
			return (1);
	temp = *room;
	if (check_link(data, temp, r1, ft_strsub(line, ft_strlen(r1) + 1,
		(ft_strlen(line) - ft_strlen(r1)))))
		return (1);
	data->links[data->a][data->b] = x;
	data->links[data->b][data->a] = x++;
	return (0);
}

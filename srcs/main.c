/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:24:56 by gavizet           #+#    #+#             */
/*   Updated: 2017/05/14 00:12:28 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int		error(void)
{
	ft_putendl("ERROR");
	return (-1);
}

void	init_data(t_lemin *data)
{
	data->a = 0;
	data->b = 0;
	data->end = 0;
	data->start = 0;
	data->error = 0;
	data->nb_ants = 0;
	data->nb_rooms = 1;
	data->len_tab = 0;
}

int		main(void)
{
	t_lemin	data;
	t_list	*room;

	room = NULL;
	init_data(&data);
	if (get_infos(&data, &room) == -1 || data.links == 0 || data.start == 0 ||
		data.end == 0 || !solve(&data) || print_best_way(&room, &data))
		return (error());
	print_course(&room, &data);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 11:16:18 by gavizet           #+#    #+#             */
/*   Updated: 2017/05/19 18:09:04 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static int	realloc_next_level(t_lemin *data, int tour)
{
	free(data->next);
	if (!(data->next = (int*)ft_memalloc(sizeof(int) * (data->nb_rooms + 1))))
		return (1);
	data->a = -1;
	while (data->sol[tour][++data->a])
		data->next[data->a] = data->sol[tour][data->a];
	return (0);
}

static int	get_ways(t_lemin *data, int tour)
{
	int room;

	data->a = -1;
	room = 0;
	while (data->next[++data->a] > 0)
	{
		data->b = -1;
		while (++data->b < data->nb_rooms)
		{
			if (data->links[data->next[data->a]][data->b] > 0)
			{
				data->links[data->next[data->a]][data->b] *= -1;
				data->sol[tour][room] = search_for_room(data,
								data->links[data->next[data->a]][data->b]);
				if (data->links[data->next[data->a]][data->b] == data->start)
					data->finish[data->start - 1] = -1;
				data->finish[data->sol[tour][room]] = data->next[data->a];
				if (data->sol[tour][room++] == data->end - 1)
					return (1);
			}
		}
	}
	return (realloc_next_level(data, tour) == 0 ? 0 : 1);
}

static int	shorten_best_way(t_lemin *data)
{
	int	i;
	int	index_che;

	i = 0;
	index_che = 0;
	if (!(data->best_way = (int*)ft_memalloc(sizeof(int) * data->len_tab)))
		return (1);
	while (data->affichage[i] != 0)
		i++;
	while (index_che < data->len_tab && data->affichage[--i] != 0)
		data->best_way[index_che++] = data->affichage[i];
	return (0);
}

static int	get_best_way(t_lemin *data)
{
	int i;
	int	search;

	i = 0;
	search = data->end - 1;
	if (!(data->affichage = (int*)ft_memalloc(sizeof(int) *
								(data->nb_rooms + 1))))
		return (1);
	if (!data->finish)
		return (1);
	while (search != -1)
	{
		if (search != 0 && search != data->start - 1)
			data->affichage[i++] = search;
		search = data->finish[search];
		if (search == 0)
		{
			data->affichage[i++] = data->start - 1;
			break ;
		}
	}
	data->len_tab = i;
	return (shorten_best_way(data));
}

int			solve(t_lemin *data)
{
	int	tour;

	tour = -1;
	if (!(data->sol = (int**)ft_memalloc(sizeof(int*) * ((data->nb_rooms + 1) *
													(data->nb_rooms + 1)))) ||
		!(data->next = (int*)ft_memalloc(sizeof(int) * (data->nb_rooms + 1))) ||
		!(data->finish = (int*)ft_memalloc(sizeof(int) * (data->nb_rooms + 1))))
		return (1);
	while (++tour < data->nb_rooms)
		if (!(data->sol[tour] = (int*)ft_memalloc(sizeof(int) *
								(data->nb_rooms + 1))))
			return (1);
	tour = 0;
	data->next[0] = data->start - 1;
	while (data->next[0])
	{
		if (get_ways(data, tour++))
		{
			get_best_way(data);
			return (1);
		}
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 11:04:40 by gavizet           #+#    #+#             */
/*   Updated: 2017/05/13 17:57:15 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int		str_is_digit(char *str)
{
	if (!str)
		return (0);
	while (*str)
		if (!ft_isdigit(*str++))
			return (0);
	return (1);
}

int		digit_and_space(char *str)
{
	if (!str)
		return (0);
	if (*str == ' ')
		return (0);
	while (ft_isdigit(*str))
		str++;
	if (*str == ' ')
		str++;
	else
		return (0);
	if (!*str)
		return (0);
	while (ft_isdigit(*str))
		str++;
	if (*str)
		return (0);
	return (1);
}

int		search_for_room(t_lemin *data, int stock)
{
	int	room;
	int	index;

	room = 0;
	while (++room < data->nb_rooms)
	{
		index = 0;
		while (++index < data->nb_rooms)
		{
			if (data->links[room][index] == stock * -1)
			{
				data->links[room][index] *= -1;
				return (room);
			}
		}
	}
	return (0);
}

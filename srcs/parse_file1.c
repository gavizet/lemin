/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 11:04:16 by gavizet           #+#    #+#             */
/*   Updated: 2017/05/14 00:12:31 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

static int	get_room(t_list **room, char *line, t_lemin *data, int *launch)
{
	char		*temp;
	t_list		*lstmp;

	lstmp = *room;
	if (!ft_strchr(line, ' ') || line[0] == '#' ||
		*launch == 1 || line[0] == 'L' || line[0] == ' ')
		return (1);
	temp = ft_strsub(line, 0, ft_strchr(line, ' ') - line);
	line = ft_strchr(line, ' ') + 1;
	if (!lstmp && !digit_and_space(line))
		return (1);
	while (lstmp)
	{
		if ((ft_strcmp(temp, lstmp->content)) == 0 || !digit_and_space(line))
		{
			ft_strdel(&temp);
			return (1);
		}
		lstmp = lstmp->next;
	}
	ft_lstadd(room, ft_lstnew(temp, ft_strlen(temp) + 1), (data->nb_rooms)++);
	ft_strdel(&temp);
	return (0);
}

static int	get_end(t_list **room, char *line, t_lemin *data, int *launch)
{
	if (get_next_line(0, &line) > 0)
	{
		if (get_room(room, line, data, launch) == 0)
			data->end = (data->end == 0) ? data->nb_rooms : -1;
		else
			return (1);
		ft_putendl(line);
		ft_strdel(&line);
		return (0);
	}
	return (0);
}

static int	get_start_end(t_list **room, char *line, t_lemin *data, int *launch)
{
	if (ft_strcmp(line, "##start") == 0 && data->start == 0)
	{
		if (get_next_line(0, &line) > 0)
		{
			if (get_room(room, line, data, launch) == 0)
				data->start = (data->start == 0) ? data->nb_rooms : -1;
			else
				return (1);
			ft_putendl(line);
			ft_strdel(&line);
			return (0);
		}
	}
	if (ft_strcmp(line, "##end") == 0 && data->end == 0)
		if (get_end(room, line, data, launch))
			return (1);
	return (0);
}

int			get_infos(t_lemin *data, t_list **room)
{
	char		*line;
	static int	launch = 0;

	if (get_next_line(0, &line) <= 0 || !line || !(str_is_digit(line)))
		return (-1);
	data->nb_ants = (data->error == 0) ? ft_atoi(line) : 0;
	data->error = (data->nb_ants <= 0 || data->nb_ants > 2147483647) ? 1 : 0;
	ft_putendl(line);
	ft_strdel(&line);
	while (data->error == 0 && get_next_line(0, &line) > 0)
	{
		ft_putendl(line);
		if (ft_strncmp(line, "#", 1) == 0)
			data->error = get_start_end(room, line, data, &launch);
		else if (ft_strchr(line, ' '))
			data->error = get_room(room, line, data, &launch);
		else if (ft_strchr(line, '-'))
			data->error = get_link(room, line, data, &launch);
		else if (!*line)
			return (data->error);
		else
			return (data->error);
		ft_strdel(&line);
	}
	return (data->error);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gavizet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 10:40:42 by gavizet           #+#    #+#             */
/*   Updated: 2017/04/17 16:57:04 by gavizet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memalloc(size_t size)
{
	int				*tab;
	size_t			i;

	i = 0;
	if (!(tab = (int*)malloc(sizeof(int) * size)))
		return (NULL);
	while (i < size)
	{
		tab[i] = 0;
		i++;
	}
	return (tab);
}

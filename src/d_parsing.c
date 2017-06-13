/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_parsing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 15:25:09 by ataguiro          #+#    #+#             */
/*   Updated: 2017/03/23 17:40:09 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

static int	is_in_tab(int from, char *str)
{
	int	i;

	i = from - 1;
	while (lem()->room[++i])
		if (!ft_strcmp(lem()->room[i], str))
			return (1);
	return (0);
}

static void	check_dup(void)
{
	int		i;
	char	*str;

	i = -1;
	str = NULL;
	while (lem()->room[++i])
	{
		if (is_in_tab(i, str))
			error();
		str = lem()->room[i];
	}
}

void		d_parsing(void)
{
	check_dup();
}

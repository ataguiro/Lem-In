/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_parsing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 11:39:44 by ataguiro          #+#    #+#             */
/*   Updated: 2017/03/24 13:32:52 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	check_dependencies(void)
{
	if (!lem()->s_room)
		error();
	if (!lem()->e_room)
		error();
	if (!lem()->room)
		error();
	if (!lem()->tube)
		error();
	if (!lem()->ants || lem()->ants < 0 || lem()->ants > 2147483647)
		error();
	if (lem()->state == ROOM)
		error();
}

static int	is_a_room(char *str)
{
	int		i;
	t_lem	*ptr;

	ptr = lem();
	i = -1;
	while (ptr->room[++i])
	{
		if (!ft_strcmp(str, ptr->room[i]))
			return (1);
	}
	return (0);
}

static void	check_tubes(void)
{
	int		i;
	char	*a;
	char	tmp[256];
	t_lem	*ptr;

	ptr = lem();
	i = -1;
	while (ptr->tube[++i])
	{
		if (ft_strlen(ptr->tube[i]) > 250)
			error();
		ft_strcpy(tmp, ptr->tube[i]);
		a = ft_strchr(tmp, '-');
		*a = 0;
		++a;
		if (!is_a_room(a) || !is_a_room(tmp))
			error();
	}
}

void		s_parsing(void)
{
	check_dependencies();
	check_tubes();
	d_parsing();
}

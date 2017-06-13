/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 11:42:43 by ataguiro          #+#    #+#             */
/*   Updated: 2017/03/25 16:51:47 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

#define END 1
#define START 2

static inline int	index_of_room(char *room_ptr, int bonus)
{
	int	i;

	i = -1;
	if (!bonus)
		while ((*room())[++i])
			if (!ft_strcmp((*room())[i]->name, room_ptr))
				return (i);
	if (bonus == END)
		while ((*room())[++i])
			if ((*room())[i]->end == 1)
				return (i);
	if (bonus == START)
		while ((*room())[++i])
			if ((*room())[i]->start == 1)
				return (i);
	return (-1);
}

static inline void	display_color(int *ant, char *room, int end)
{
	if (end)
		ft_printf("\033[1;32mL%d\033[0m-\033[1;32m%s\033[0m ", (*ant)++, room);
	else
		ft_printf("\033[0;31mL%d\033[0m-\033[0;33m%s\033[0m ", (*ant)++, room);
}

static inline void	try_to_move(char **path)
{
	int		cur;
	int		prev;
	int		i;
	int		n;
	t_room	**ptr;

	ptr = *room();
	n = 1 + ptr[index_of_room(NULL, END)]->num_ants;
	i = ft_tablen(path);
	cur = 0;
	prev = 0;
	while (--i > 0)
	{
		cur = index_of_room(path[i], 0);
		prev = index_of_room(path[i - 1], 0);
		if ((ptr[cur]->end && ptr[prev]->num_ants)
		|| (!ptr[cur]->num_ants && ptr[prev]->num_ants))
		{
			++ptr[cur]->num_ants;
			--ptr[prev]->num_ants;
			display_color(&n, ptr[cur]->name, ptr[cur]->end);
		}
	}
	write(1, "\n", 1);
}

void				send_ants(t_arg arg)
{
	static int	c = 0;
	t_lem		*ptr;
	int			i;

	ptr = lem();
	i = -1;
	if (!arg.beta)
		while ((*room())[index_of_room(NULL, END)]->num_ants != lem()->ants)
		{
			c++;
			try_to_move(ptr->bpath[0]);
		}
	else
		while ((*room())[index_of_room(NULL, END)]->num_ants != lem()->ants)
		{
			while (ptr->bpath[++i])
				try_to_move(ptr->bpath[i]);
			i = -1;
		}
	write(1, "\n", 1);
	if (arg.c && !arg.beta)
		ft_printf("\033[1;31mNumber of moves : %d\033[0m\n", c);
}

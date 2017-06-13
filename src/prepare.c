/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 12:24:31 by ataguiro          #+#    #+#             */
/*   Updated: 2017/03/23 18:01:59 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

static int	is_not_saved(char *link, int index)
{
	int		i;

	i = -1;
	while (((*room())[index])->link[++i])
		if (!ft_strcmp(link, ((*room())[index])->link[i]))
			return (0);
	return (1);
}

static void	stock_links(char *salle, int *index)
{
	t_lem	*tmp;
	char	t[256];
	char	*ptr;
	int		i;
	int		j;

	ptr = NULL;
	tmp = lem();
	i = -1;
	j = -1;
	while (tmp->tube[++i])
	{
		ft_strcpy(t, tmp->tube[i]);
		ptr = ft_strchr(t, '-');
		*ptr = 0;
		ptr++;
		if (!ft_strcmp(salle, t) && is_not_saved(ptr, *index))
			((*room())[*index])->link[++j] = ft_strdup(ptr);
		if (!ft_strcmp(salle, ptr) && is_not_saved(t, *index))
			((*room())[*index])->link[++j] = ft_strdup(t);
	}
	((*room())[*index])->link[j + 1] = NULL;
}

static void	create_room(char *salle, int *index)
{
	(*room())[*index + 1] = NULL;
	((*room())[*index])->name = ft_strdup(salle);
	((*room())[*index])->num_ants = 0;
	if (!ft_strcmp(salle, lem()->s_room))
	{
		((*room())[*index])->start = true;
		((*room())[*index])->num_ants = lem()->ants;
	}
	if (!ft_strcmp(salle, lem()->e_room))
		((*room())[*index])->end = true;
	((*room())[*index])->link = (char **)ft_memalloc(sizeof(char *)
											* (ft_tablen(lem()->tube) + 1));
	stock_links(salle, index);
}

static void	prepare_list(int *index)
{
	int	i;

	i = -1;
	while (lem()->room[++i])
	{
		if (!((*room())[*index] = (t_room *)malloc(sizeof(t_room))))
			exit(1);
		create_room(lem()->room[i], index);
		++(*index);
	}
}

void		prepare_room(void)
{
	int	index;
	int	p;

	index = 0;
	p = -1;
	*room() = (t_room **)malloc(sizeof(t_room *) \
	* (ft_tablen(lem()->room) + 1));
	if (!(*room()))
		exit(1);
	prepare_list(&index);
}

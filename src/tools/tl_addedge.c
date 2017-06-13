/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tl_addedge.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 14:19:28 by ataguiro          #+#    #+#             */
/*   Updated: 2017/03/23 15:20:09 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"
#include "lem_in.h"

/*
**	Add an edge to the graph between src and dst
*/

static inline int	get_index(char *src)
{
	int	i;

	i = -1;
	while ((*room())[++i])
	{
		if (!ft_strcmp(src, ((*room())[i])->name))
			return (i);
	}
	return (0);
}

void				tl_addedge(t_graph *graph, char *src, char *dst)
{
	t_node	*new;
	t_node	*tmp;
	int		index;

	index = get_index(src);
	new = tl_createnode(dst);
	tmp = graph->array[index].head;
	if (!tmp)
		graph->array[index].head = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

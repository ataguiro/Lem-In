/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tl_creategraph.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 14:07:41 by ataguiro          #+#    #+#             */
/*   Updated: 2017/03/18 22:03:09 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"
#include "lem_in.h"

/*
**	Create a graph (both directed or undirected) with n vertices
*/

t_graph	*tl_creategraph(int n)
{
	t_graph		*graph;
	int			i;

	i = -1;
	graph = (t_graph *)malloc(sizeof(t_graph));
	graph->v = n;
	graph->array = (t_adjlist *)malloc(sizeof(t_adjlist) * n);
	if (!graph || !graph->array)
		error();
	while (++i < n)
	{
		((*room())[i])->marked = 0;
		graph->array[i].head = NULL;
	}
	return (graph);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tl_destroygraph.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 14:13:41 by ataguiro          #+#    #+#             */
/*   Updated: 2017/03/21 15:19:26 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"
#include "lem_in.h"

void	tl_destroygraph(t_graph *graph)
{
	int			v;
	t_node		*tmp;
	t_node		*ptr;

	if (graph)
	{
		v = -1;
		if (graph->array)
		{
			while (++v < graph->v)
			{
				ptr = graph->array[v].head;
				while (ptr)
				{
					tmp = ptr;
					ptr = ptr->next;
					free(tmp);
				}
			}
			free(graph->array);
		}
		free(graph);
	}
}

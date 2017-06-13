/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tl_displaygraph.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 14:25:04 by ataguiro          #+#    #+#             */
/*   Updated: 2017/03/24 00:21:58 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"
#include "lem_in.h"

void	tl_displaygraph(t_graph *graph)
{
	t_node		*ptr;
	int			i;

	i = -1;
	ft_printf("\n\033[1;32m:.. SHOW GRAPH ..:\033[0m");
	while (++i < graph->v)
	{
		ptr = graph->array[i].head;
		ft_printf("\n[\033[1;33m%s\033[0m] \033[1;31m--\033[0m ", \
		((*room())[i])->name);
		while (ptr)
		{
			ft_printf("[\033[1;33m%s\033[0m]", ptr->dst);
			ptr = ptr->next;
			if (ptr)
				ft_printf(" \033[1;31m--\033[0m ");
		}
	}
	ft_printf("\n\n");
}

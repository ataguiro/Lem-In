/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 15:06:15 by ataguiro          #+#    #+#             */
/*   Updated: 2017/03/24 00:17:30 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static inline void	add_links(t_graph **graph)
{
	int	i;
	int	p;

	i = -1;
	p = -1;
	while ((*room())[++i])
	{
		while (((*room())[i])->link[++p])
			tl_addedge(*graph, ((*room())[i])->name, ((*room())[i])->link[p]);
		p = -1;
	}
}

t_graph				*build_graph(t_arg arg)
{
	t_graph *graph;

	graph = tl_creategraph(ft_tablen((char **)(*room())));
	add_links(&graph);
	if (arg.s)
		tl_displaygraph(graph);
	return (graph);
}

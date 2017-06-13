/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 12:20:44 by ataguiro          #+#    #+#             */
/*   Updated: 2017/03/23 15:22:46 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPH_H
# define GRAPH_H

# define UNDIRECT 0
# define DIRECT 1

typedef struct		s_node
{
	struct s_node	*next;
	char			*dst;
}					t_node;

typedef struct		s_adjlist
{
	t_node			*head;
}					t_adjlist;

typedef struct		s_graph
{
	int				v;
	t_adjlist		*array;
}					t_graph;

/*
**	Names says it all
*/

t_node				*tl_createnode(char *v);
t_graph				*tl_creategraph(int n);
void				tl_destroygraph(t_graph *graph);
void				tl_addedge(t_graph *graph, char *src, char *dst);
void				tl_displaygraph(t_graph *graph);

#endif

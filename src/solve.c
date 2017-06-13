/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 15:38:36 by ataguiro          #+#    #+#             */
/*   Updated: 2017/03/25 17:49:26 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

#define START 1
#define END 2

static inline int	index_of_room(char *room_ptr, int bonus)
{
	int	i;

	i = -1;
	if (!bonus)
		while ((*room())[++i])
			if (!ft_strcmp((*room())[i]->name, room_ptr))
				return (i);
	if (bonus == START)
		while ((*room())[++i])
			if ((*room())[i]->start == 1)
				return (i);
	if (bonus == END)
		while ((*room())[++i])
			if ((*room())[i]->end == 1)
				return (i);
	return (-1);
}

static inline char	*get_room(int type)
{
	int	i;

	i = -1;
	while ((*room())[++i])
	{
		if (((*room())[i])->start == 1 && type == START)
			return (((*room())[i])->name);
		if (((*room())[i])->end == 1 && type == END)
			return (((*room())[i])->name);
	}
	return (NULL);
}

static inline int	try_to_save(char *start, int index, char **path)
{
	int			p;
	static int	path_index = 0;

	p = -1;
	if (path_index == LEN - 2)
		return (1);
	if (path_index == 1 && *sarg())
		return (3);
	if (!ft_strcmp(start, get_room(END)))
	{
		lem()->path[path_index] = (char **)malloc(sizeof(char *) *
													(ft_tablen(path) + 1));
		while (++p < index)
			lem()->path[path_index][p] = ft_strdup(path[p]);
		lem()->path[path_index][p] = NULL;
		++path_index;
		if (path_index == 1 && *sarg())
			return (3);
		return (1);
	}
	return (0);
}

static inline void	explore(t_graph *graph, char *start, char **path, \
																int *index)
{
	t_node			*ptr;
	static int		ret = 0;
	int				i;

	i = index_of_room(start, 0);
	if (((*room())[i])->marked)
		return ;
	ptr = graph->array[i].head;
	((*room())[i])->marked = 1;
	ft_strdel(&(path[*index]));
	path[*index] = ft_strdup(start);
	(*index)++;
	if ((ret = try_to_save(start, *index, path)))
	{
		if (ret == 3)
			return ;
	}
	else
		while (ptr)
		{
			explore(graph, ptr->dst, path, index);
			ptr = ptr->next;
		}
	(*index)--;
	((*room())[i])->marked = 0;
}

void				solve(t_graph *graph, t_arg arg)
{
	char	*start;
	char	**path;
	int		path_index;
	clock_t	t1;
	clock_t	t2;

	*sarg() = arg.f;
	t1 = clock();
	lem()->path = (char ***)ft_memalloc(sizeof(char **) * LEN);
	path_index = 0;
	path = (char **)ft_memalloc(sizeof(char *) * (graph->v + 1));
	start = get_room(START);
	explore(graph, start, path, &path_index);
	ft_tabdel(&path);
	if (!lem()->path[0])
		error();
	begin_trip(arg);
	t2 = clock();
	if (arg.c)
	{
		ft_printf("\033[1;31mTime elapsed : %d seconds.\033[0m\n", \
		(t2 - t1) / CLOCKS_PER_SEC);
	}
}

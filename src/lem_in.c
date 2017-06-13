/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 15:57:30 by ataguiro          #+#    #+#             */
/*   Updated: 2017/04/12 13:56:08 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	inits(t_arg *arg, char **av, int ac)
{
	int	i;

	(void)ac;
	i = -1;
	lem()->ants = 0;
	lem()->state = ROOM;
	lem()->allc = (char **)ft_memalloc(sizeof(char *) * LEN);
	lem()->all = (char **)ft_memalloc(sizeof(char *) * LEN);
	lem()->s_room = NULL;
	lem()->e_room = NULL;
	while (av[++i])
	{
		(!ft_strcmp(av[i], "-s")) ? arg->s = 1 : 0;
		(!ft_strcmp(av[i], "-v")) ? arg->v = 1 : 0;
		(!ft_strcmp(av[i], "-c")) ? arg->c = 1 : 0;
		(!ft_strcmp(av[i], "-b")) ? arg->b = 1 : 0;
		(!ft_strcmp(av[i], "-f")) ? arg->f = 1 : 0;
		(!ft_strcmp(av[i], "--help")) ? arg->help = 1 : 0;
		(!ft_strcmp(av[i], "--beta")) ? arg->beta = 1 : 0;
	}
}

static void	fuck_comments(void)
{
	int		i;
	int		j;
	t_lem	*ptr;

	i = -1;
	j = -1;
	ptr = lem();
	while (ptr->allc[++i])
	{
		if ((ptr->allc[i][0] == '#' && ptr->allc[i][1] != '#')
		|| (ptr->allc[i][0] == '#' && ft_strcmp(ptr->allc[i], "##start")
		&& ft_strcmp(ptr->allc[i], "##end")))
			continue ;
		lem()->all[++j] = ft_strdup(ptr->allc[i]);
	}
	lem()->all[++j] = NULL;
	lem()->size = j;
}

int			main(int ac, char **av)
{
	t_graph			*graph;
	t_arg			arg;

	arg = (t_arg){0, 0, 0, 0, 0, 0, 0};
	inits(&arg, av, ac);
	if (arg.help)
		show_help();
	get_info();
	fuck_comments();
	display_all();
	lem()->room = (char **)ft_memalloc(sizeof(char *) * lem()->size);
	lem()->tube = (char **)ft_memalloc(sizeof(char *) * lem()->size);
	parsing();
	s_parsing();
	prepare_room();
	graph = build_graph(arg);
	solve(graph, arg);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trip.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 11:08:29 by ataguiro          #+#    #+#             */
/*   Updated: 2017/03/24 21:13:32 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static inline void	save_it(int bwi)
{
	int	i;
	int	p;

	p = -1;
	i = tl_dtablen(lem()->bpath);
	lem()->bpath[i] = (char **)malloc(sizeof(char *)
										* (ft_tablen(lem()->path[bwi]) + 1));
	while (lem()->path[bwi][++p])
		lem()->bpath[i][p] = ft_strdup(lem()->path[bwi][p]);
	lem()->bpath[i][p] = NULL;
}

static inline void	choose_best_ways(int size)
{
	int	bwi;
	int	i;
	int	j;

	bwi = 0;
	i = -1;
	j = -1;
	if (tl_dtablen(lem()->bpath) == lem()->ants \
	|| tl_dtablen(lem()->bpath) == size)
		return ;
	while (++j <= size)
		if (lem()->path[j])
		{
			bwi = j;
			break ;
		}
	while (++i <= size)
	{
		if (lem()->path[i]
		&& ft_tablen(lem()->path[bwi]) > ft_tablen(lem()->path[i]))
			bwi = i;
	}
	save_it(bwi);
	ft_tabdel(&(lem()->path[bwi]));
	choose_best_ways(size);
}

static inline void	multi_path(void)
{
	int		i;
	int		j;
	t_lem	*ptr;

	ptr = lem();
	i = -1;
	j = -1;
	ft_printf("\033[1;32m.: BEST %d PATHS :.\033[0m\n", lem()->ants);
	while (ptr->bpath[++j])
	{
		while (ptr->bpath[j][++i])
		{
			ft_printf("[\033[1;33m%s\033[0m]", ptr->bpath[j][i]);
			if (ptr->bpath[j][i + 1])
				ft_printf("\033[1;31m -- \033[0m");
		}
		ft_printf("\n");
		i = -1;
	}
}

static inline void	display_best_ways(t_arg arg)
{
	int		i;
	t_lem	*ptr;

	ptr = lem();
	i = -1;
	if (arg.b)
	{
		ft_printf("\033[1;32m.: BEST PATH :.\033[0m\n");
		while (ptr->bpath[0][++i])
		{
			ft_printf("[\033[1;33m%s\033[0m]", ptr->bpath[0][i]);
			if (ptr->bpath[0][i + 1])
				ft_printf("\033[1;31m -- \033[0m");
		}
	}
	else
		multi_path();
	ft_printf("\n\n");
}

void				begin_trip(t_arg arg)
{
	int	i;

	i = tl_dtablen(lem()->path);
	lem()->bpath = (char ***)ft_memalloc(sizeof(char **) * (i + 1));
	lem()->bpath[i] = NULL;
	choose_best_ways(i);
	if (arg.v)
		display_best_ways(arg);
	send_ants(arg);
}

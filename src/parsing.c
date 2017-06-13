/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/04 16:20:05 by ataguiro          #+#    #+#             */
/*   Updated: 2017/03/25 17:10:59 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	get_room(int words, char *line)
{
	char		*tmp;
	static int	i = -1;

	if (words != 3)
		error();
	tmp = ft_strchr(line, ' ');
	*tmp = 0;
	lem()->room[++i] = ft_strdup(line);
}

static void	get_tube(int words, char *line)
{
	static int	j = -1;
	int			i;
	int			c;

	i = -1;
	c = 0;
	if (words != 2)
		error();
	while (line[++i])
		if (line[i] == '-')
			++c;
	if (c != 1)
		error();
	lem()->tube[++j] = ft_strdup(line);
}

static void	get_s_e(char *line, char *next, int *i)
{
	static int	start = 0;
	static int	end = 0;

	if (!ft_strcmp(line, "##start"))
	{
		(!next) ? error() : 0;
		get_room(ft_count_words(next, ' '), next);
		lem()->s_room = ft_strdup(next);
		*i += 2;
		start++;
	}
	if (!ft_strcmp(line, "##end"))
	{
		(!next) ? error() : 0;
		get_room(ft_count_words(next, ' '), next);
		lem()->e_room = ft_strdup(next);
		*i += 2;
		end++;
	}
	if (start > 1 || end > 1)
		error();
}

void		parsing(void)
{
	int		i;
	int		words;

	i = 1;
	lem()->ants = lem()->all[0] ? ft_atoi(lem()->all[0]) : 0;
	while (lem()->all[i])
	{
		get_s_e(lem()->all[i], lem()->all[i + 1], &i);
		if (!lem()->all[i])
			return ;
		if (lem()->all[i][0] == '#' && lem()->all[i][1] == '#')
			continue ;
		if (lem()->all[i][0] == 'L')
			return ;
		if (ft_isinstr('-', lem()->all[i]))
			lem()->state = TUBE;
		words = ft_count_words(lem()->all[i], lem()->state);
		if (lem()->state == ROOM)
			get_room(words, lem()->all[i]);
		if (lem()->state == TUBE)
			get_tube(words, lem()->all[i]);
		++i;
	}
}

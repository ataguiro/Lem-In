/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 13:17:58 by ataguiro          #+#    #+#             */
/*   Updated: 2017/03/25 15:11:54 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	exception_size(char *line)
{
	ft_printf("lem_in: near `%s': can't handle such large map\n", line);
	exit(3);
}

static int	catch_exception(char *line, int state, int p)
{
	if (!p)
		return (0);
	if (state == ROOM)
		if (ft_count_words(line, ROOM) != 3)
			return (1);
	if (state == TUBE)
		if (ft_count_words(line, TUBE) != 2)
			return (1);
	return (0);
}

void		get_info(void)
{
	char		line[LEN];
	static int	state = ROOM;
	int			p;
	int			i;

	i = -1;
	p = 0;
	while (ft_readline(line, 0) > 0)
	{
		if (i >= LEN - 1 || (ft_strlen(line) >= LEN - 1))
			exception_size(line);
		if (p && ft_strchr(line, '-'))
			state = TUBE;
		if (line[0] != '#' && catch_exception(line, state, p))
			break ;
		lem()->allc[++i] = ft_strdup(line);
		p = 1;
	}
	if (!lem()->allc[0] || !lem()->allc[0][0])
		error();
	lem()->allc[++i] = NULL;
}

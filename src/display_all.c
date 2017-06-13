/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 10:37:03 by ataguiro          #+#    #+#             */
/*   Updated: 2017/03/23 16:53:18 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	display_all(void)
{
	int		i;
	t_lem	*ptr;

	ptr = lem();
	i = -1;
	while (ptr->allc[++i])
		ft_printf("%s\n", ptr->allc[i]);
	write(1, "\n", 1);
}

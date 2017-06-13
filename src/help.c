/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 13:39:17 by ataguiro          #+#    #+#             */
/*   Updated: 2017/03/24 23:49:12 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	show_help(void)
{
	ft_printf("lem_in: usage: ./lem_in [-s] [-v] [-b] [-c] [-f] [--help] \
[--beta]\n");
	ft_printf("\n-s : show the graph generated from the map.\n");
	ft_printf("-v : verbose mode, display x best ways (x = num ants).\n");
	ft_printf("-c : display time needed for finding path and travelling.\n");
	ft_printf("-b : with -v, display the best path only.\n");
	ft_printf("-f : fast mode, searches only one way, no matter which one.\n");
	ft_printf("--beta : beta algorithm\n");
	ft_printf("--help : show this help menu.\n");
	exit(0);
}

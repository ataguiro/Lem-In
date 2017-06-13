/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 15:58:49 by ataguiro          #+#    #+#             */
/*   Updated: 2017/03/25 13:36:29 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# define ROOM ' '
# define TUBE '-'

# define LEN 40960

# include <stdbool.h>
# include <time.h>

# include "libft.h"
# include "graph.h"

typedef struct		s_room
{
	char			*name;
	char			**link;
	bool			start;
	bool			end;
	int				num_ants;
	int				marked;
}					t_room;

typedef struct		s_lem
{
	char			***path;
	char			***bpath;
	char			**allc;
	char			**all;
	char			**room;
	char			**tube;
	char			*s_room;
	char			*e_room;
	int				size;
	long			ants;
	int				state;
}					t_lem;

typedef struct		s_arg
{
	int				s;
	int				v;
	int				c;
	int				b;
	int				f;
	int				help;
	int				beta;
}					t_arg;

/*
**	Singleton lem, room
**	lem is used to create room singleton
**	room singleton is used to build the graph
*/

t_lem				*lem(void);
int					*sarg(void);
t_room				***room(void);

/*
**	Displays "ERROR" and leaves the program with exit code 0
*/

void				error(void);

/*
**	Functions related to parsing
*/

void				get_info(void);
void				parsing(void);
void				s_parsing(void);
void				d_parsing(void);
void				show_help(void);

/*
**	Building section
*/

void				display_all(void);
void				prepare_room(void);
t_graph				*build_graph(t_arg arg);

/*
**	Solving section
*/

void				solve(t_graph *graph, t_arg arg);
void				begin_trip(t_arg arg);
void				send_ants(t_arg arg);

/*
**	Tools
*/

int					tl_dtablen(char ***tab);

#endif

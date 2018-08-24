/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 06:57:00 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/24 21:39:00 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_IN_H
# define BUILT_IN_H

# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

# include "f_string.h"
# include "argv.h"
# include "s_list.h"
# include "env.h"

typedef struct	s_built_in
{
	char	*command;
	void	(*func)(t_argv);
}				t_built_in;

# define CREATE_BI(command, func)	(new_built_in(command, func))

t_list		*get_builtins(void);
bool		exec_built_in(t_argv argv);

int			validate_path(char *path);
int			print_err(int err_code);

void		bi_exit(t_argv argv);
void		bi_cd(t_argv argv);
void		bi_echo(t_argv argv);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 06:57:00 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/04 09:26:29 by wseegers         ###   ########.fr       */
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

enum			e_mode {get, init};

t_list			*builtins(enum e_mode mode);
bool			exec_built_in(t_argv argv);

int				validate_path(char *path);
int				print_err(int err_code);

void			bi_exit(t_argv argv);
void			bi_cd(t_argv argv);
void			bi_echo(t_argv argv);
void			bi_env (t_argv argv);
void			bi_setenv(t_argv argv);
void			bi_unsetenv(t_argv argv);

#endif

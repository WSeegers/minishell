/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 13:05:54 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/24 11:39:58 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <dirent.h>
# include "f_print.h"
# include "f_io.h"

# include "argv.h"
# include "env.h"
# include "built_in.h"

void	process_command(t_argv argv);
int		validate_path(char *path);
char	*validate_env_path(t_argv argv);

# define E_PDENY	(-2)
# define E_NOPATH	(-3)

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 13:05:54 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/24 20:53:19 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <dirent.h>
# include <sys/wait.h>
# include <sys/types.h>
# include "f_print.h"
# include "f_io.h"

# include "argv.h"
# include "env.h"
# include "built_in.h"

void	process_command(t_argv argv);
int		validate_path(char *path);
char	*validate_env_path(t_argv argv);

# define E_NOERR	(0)
# define E_PDENY	(1)
# define E_NOPATH	(2)

int		print_err(int err_code);

#endif

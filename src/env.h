/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 12:03:37 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/24 22:13:55 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include <stdlib.h>
# include <stdbool.h>
# include "f_print.h"
# include "f_string.h"
# include "s_list.h"
# include "f_cntl.h"

t_list	*g_environ;

struct	s_evar
{
	char *name;
	char *value;
};

typedef struct s_evar	t_evar;

bool	init_env(void);

char	*get_env(char *name);
bool	set_env(const char *name, const char *value, bool overwrite);
bool	unset_env(char *name);

bool	is_name(void *pevar, void *pchk_name);
t_evar	*get_evar(const char *name);
char	**env_char(void);
void	print_env(void);

#endif

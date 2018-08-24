/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 06:57:00 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/24 11:46:46 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILT_IN_H
# define BUILT_IN_H

# include <stdbool.h>
# include <stdlib.h>

# include "f_string.h"
# include "argv.h"
# include "s_list.h"

typedef struct	s_built_in
{
	char	*command;
	void	(*func)(t_argv);
}				t_built_in;

# define CREATE_BI(command, func)	(new_built_in(command, func))

t_list		*get_builtins(void);
bool		exec_built_in(t_argv argv);

void		bi_exit(t_argv argv);

#endif

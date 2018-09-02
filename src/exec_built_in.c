/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_built_in.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 06:55:54 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/02 21:45:36 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "built_in.h"

static bool	is_built_in(void *built_in, void *command)
{
	t_built_in	*bi;
	char		*com;

	bi = (t_built_in*)built_in;
	com = (char*)command;
	return (!f_strcmp(bi->command, com));
}

bool		exec_built_in(t_argv argv)
{
	t_built_in	*built_in;

	built_in = s_list_func_find(builtins(get), is_built_in, argv[0]);
	if (built_in)
		built_in->func(argv);
	return (built_in);
}
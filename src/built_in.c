/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 09:14:20 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/24 11:46:49 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

static t_built_in *new_built_in(char *command, void (*built_in_func)(t_argv argv))
{
	t_built_in *bi;

	bi = (t_built_in*)malloc(sizeof(t_built_in));
	bi->command = command;
	bi->func = built_in_func;
	return (bi);
}

static void		init_built_ins(t_list **built_ins)
{
	*built_ins = s_list_create(NULL); // add destroy funtion
	s_list_append(*built_ins, CREATE_BI("exit", bi_exit));
}

t_list		*get_builtins(void)
{
	static t_list *built_ins;

	if (!built_ins)
		init_built_ins(&built_ins);
	return (built_ins);
}


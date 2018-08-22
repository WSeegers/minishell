/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 14:57:06 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/22 17:05:29 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

bool	new_evar(const char *name, const char *value)
{
	t_evar *evar;

	if (!(evar = (t_evar*)malloc(sizeof(t_evar))))
		return (false);
	evar->name = f_strdup(name);
	evar->value = f_strdup(value);
	s_list_append(g_environ, evar);
	return (true);
}

bool	set_env(const char *name, const char *value, bool overwrite)
{
	t_evar	*var;
	char	*temp;

	var = get_evar(name);
	if (!var)
		return (new_evar(name, value));
	else if (overwrite)
	{
		if ((temp = f_strdup(value)))
		{
			free(var->value);
			var->value = temp;
			return (true);
		}
	}
	return (false);
}

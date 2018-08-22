/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 17:49:06 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/22 17:56:00 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

bool	unset_env(char *name)
{
	t_evar	*evar;

	if (!(evar = get_evar(name)))
		return (false);
	evar = s_list_pop(g_environ, s_list_find(g_environ, evar));
	free(evar->name);
	free(evar->value);
	free(evar);
	return (true);
}

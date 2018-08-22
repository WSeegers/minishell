/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 15:26:27 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/22 15:53:55 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

char		*get_env(char *name)
{
	t_evar *evar;

	evar = (t_evar*)s_list_func_find(g_environ, is_name, name);
	if (!evar)
		return (NULL);
	return (evar->value);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 15:37:32 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/22 17:45:40 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

static void	parse_var(const char *var)
{
	char	*value;
	char	*temp;

	temp = f_strdup(var);
	value = f_strchr(temp, '=');
	*value = '\0';
	value++;
	set_env(temp, value, true);
	free(temp);
}

static void	destroy_evar(void *pevar)
{
	t_evar	*evar;

	evar = (t_evar*)pevar;
	free(evar->name);
	free(evar->value);
	free(evar);
}

bool		init_env(void)
{
	extern char	**environ;
	char		*var;
	int			i;

	if (!(g_environ = s_list_create(destroy_evar)))
		f_eexit(0, "Malloc failed in init_env()");
	i = -1;
	while ((var = environ[++i]))
		parse_var(var);
	return (false);
}

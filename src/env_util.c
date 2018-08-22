/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 12:16:59 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/22 18:01:17 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

char	**env_char(void)
{
	char	**env;
	char	*var;
	size_t	i;
	t_evar	*evar;
	int		name_size;

	env = (char**)malloc(sizeof(char*) * (g_environ->size + 1));
	i = -1;
	while (++i < g_environ->size)
	{
		evar = (t_evar*)s_list_pop(g_environ, 0);
		name_size = f_strlen(evar->name);
		var = f_strnew(name_size + f_strlen(evar->value) + 1);
		f_strcpy(var, evar->name);
		var[name_size++] = '=';
		f_strcpy(var + name_size, evar->value);
		env[i] = var;
		s_list_append(g_environ, evar);
	}
	env[i] = NULL;
	return (env);
}

bool	is_name(void *pevar, void *pchk_name)
{
	char	*chk_name;
	t_evar	*evar;

	chk_name = (char*)pchk_name;
	evar = (t_evar*)pevar;
	return (!(f_strcmp(chk_name, evar->name)));
}

t_evar	*get_evar(const char *name)
{
	t_evar *evar;

	evar = (t_evar*)s_list_func_find(g_environ, is_name, (void*)name);
	return (evar);
}

void	print_env(void)
{
	t_evar	*evar;
	size_t	i;
	size_t	size;

	i = -1;
	size = g_environ->size;
	while (++i < size)
	{
		evar = (t_evar*)s_list_pop(g_environ, 0);
		f_printf("%s=%s\n", evar->name, evar->value);
		s_list_append(g_environ, evar);
	}
}

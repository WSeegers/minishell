/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_env_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 06:29:07 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/24 22:59:26 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*try(char *path, char *command)
{
	char *test_path;

	test_path = f_strcjoin(path, command, '/');
	if (validate_path(test_path))
	{
		free(test_path);
		test_path = NULL;
	}
	return (test_path);
}

char		*validate_env_path(t_argv argv)
{
	char	**env_path;
	char	*ret;
	char	*tmp_path;
	int		i;
	char	*path;

	if (!(path = get_env("PATH")))
		return (NULL);
	env_path = f_strsplit(path,':');
	i = -1;
	ret = NULL;
	while ((tmp_path = env_path[++i]))
	{
		if ((ret = try(tmp_path, argv[0])))
			break;
	}
	f_strarrdel(env_path);
	return (ret);
}
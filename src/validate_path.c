/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 06:27:50 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/24 20:02:42 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		validate_path(char *path)
{
	char	*slash;
	int		i;

	path = f_strdup(path);
	if (!(access(path, F_OK)) && !access(path, X_OK))
	{
		free(path);
		return (0);
	}
	i = 1;
	slash = NULL;
	while (i || (slash = f_strrchr(path, '/')))
	{
		if (slash)
			*slash = '\0';
		else if (!i)
		{
			free(path);
			return (E_PDENY);
		}
		i = 0;
	}
	free(path);
	return (E_NOPATH);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 15:04:36 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/04 09:21:20 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	find_var_end(char *arg, int offset)
{
	char	c;

	while ((c = arg[++offset]))
		if (!(f_isalnum(c) || c == '-' || c == '_'))
			break ;
	return (offset);
}

static int	join_var(char *arg, char **front, int var_start)
{
	int		var_end;
	int		var_len;
	char	*var_name;
	char	*var;
	char	*ret;

	var_end = find_var_end(arg, var_start);
	var_len = var_end - 1 - var_start;
	var_name = f_strsub(arg, var_start + 1, var_len);
	if ((var = get_env(var_name)))
	{
		ret = f_strjoin(*front, var);
		free(*front);
		*front = ret;
	}
	free(var_name);
	return (var_end);
}

static void	handle_var(char **arg, int offset)
{
	char	*front;
	char	*next;
	char	*temp;
	int		var_end;

	front = f_strsub(arg[0], 0, offset);
	var_end = join_var(arg[0], &front, offset);
	if (arg[0][var_end] && (next = f_strdup(arg[0] + var_end)))
	{
		temp = f_strjoin(front, next);
		free(front);
		free(next);
		front = temp;
	}
	free(*arg);
	*arg = front;
}

void		expand_var(t_argv argv)
{
	char		*arg;
	int			i;
	int			j;

	i = 0;
	while ((arg = argv[i]))
	{
		j = -1;
		while (arg[++j] && arg[j] != '$')
			;
		if (!arg[j])
			i++;
		else
			handle_var(argv + i, j);
	}
}

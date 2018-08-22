/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 16:26:46 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/22 08:56:54 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "argv.h"

static char	*duparg(const char *arg)
{
	char *ret;
	char *pret;
	char c;

	ret = f_strnew(f_strlen(arg));
	pret = ret;
	if ((*arg == '\"' || *arg == '\'') && (c = *arg))
		arg++;
	else
		c = '\0';
	while (*arg)
	{
		if (*arg != c)
		{
			*pret = *arg;
			pret++;
		}
		arg++;
	}
	return (ret);
}

static void	assign_argv(char *args, t_argv *pargv, int count)
{
	int		i;
	char	**argv;

	i = 0;
	argv = (char**)malloc(sizeof(char*) * (count + 1));
	argv[count] = NULL;
	argv[0] = duparg(args);
	while (++i < count)
	{
		while (*args)
			args++;
		args++;
		argv[i] = duparg(args);
	}
	*pargv = argv;
}

static int	split_line(char **pargs, const char *line)
{
	char	c;
	int		i;
	char	*args;
	int		count;

	args = f_strdup(line);
	count = 1;
	i = -1;
	while ((c = args[++i]))
		if (c == '\"' || c == '\'')
		{
			while (!(line[++i] == c))
				if (!line[i])
				{
					free(args);
					return (-1);
				}
		}
		else if (c == ' ' && ++count)
			args[i] = '\0';
	*pargs = args;
	return (count);
}

int	parse_argv(const char *line, t_argv *pargv)
{
	char	*args;
	int		count;

	count = split_line(&args, line);
	assign_argv(args, pargv, count);
	free(args);
	return (count);
}

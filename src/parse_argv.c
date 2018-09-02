/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 16:26:46 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/02 09:49:34 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "argv.h"

static char	*duparg(const char *arg)
{
	char *ret;
	char *pret;
	char c;

	while (f_isspace(*arg))
		arg++;
	ret = f_strnew(f_strlen(arg));
	pret = ret;
	c = ((*arg == '\"' || *arg == '\'')) ? *arg : '\0';
	arg += (c) ? 1 : 0;
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
		else if (f_isspace(c) && ++count)
		{
			args[i] = '\0';
			while (f_isspace(args[++i]))
				;
		}
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

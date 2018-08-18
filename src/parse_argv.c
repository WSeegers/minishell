/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 16:26:46 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/18 16:57:48 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "argv.h"

static char *parse_path(char **line)
{
	char *start;

	start = *line;
	while (**line != ' ')
		(*line)++;
	**line = '\0';
	(*line)++;
	return (start);
}


static void	assign_argv(char *args, t_argv *argv, int count)
{
	int		i;

	i = 0;
	*argv = (char**)memalloc(sizeof(char*) * count);
	argv[0] = args;
	while (++i < count)
	{
		// Need to assign argv
	}
}

static int	*split_line(char *line, t_argv *argv)
{
	char	*args;
	int		i;
	int		len;
	char	c;
	int		count;

	len = f_strlen(line);
	args = f_strnew(len);
	i = -1;
	count = 0;
	while ((c = line[++i]))
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
			line[i] = '\0';
	assign_argv(args, argv, count);
	return (count);
}

bool	parse_argv(char *line, t_argv *argv)
{

}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 15:02:54 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/03 15:03:13 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	expand_tilde(char **pline, int pos)
{
	char	*old_line;
	char	*temp;

	old_line = *pline;
	old_line[pos] = '\0';
	temp = f_strjoin(old_line, get_env("HOME"));
	*pline = f_strjoin(temp, old_line + pos + 1);
	free(old_line);
	free(temp);
}

static void	handle_open_pair(char **pline)
{
	char	*old_line;
	char	*next_line;

	old_line = *pline;
	f_printf(">");
	f_next_line(&next_line, STDIN);
	*pline = f_strcjoin(old_line, next_line, '\n');
	free(old_line);
	free(next_line);
}

void	validate_line(char **pline)
{
	char	*line;
	int		i;
	char	c;

	line = *pline;
	i = -1;
	while ((c = line[++i]))
	{
		if (c == '~' && get_env("HOME"))
			expand_tilde(pline, i);
		if (c == '\'' || c == '\"')
			while (pline[0][++i] != c)
				if (!pline[0][i])
					handle_open_pair(pline);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 21:06:01 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/04 09:31:09 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

bool	must_skip_newline(char *arg)
{
	bool skip;

	skip = false;
	if (arg[1] == 'n')
	{
		skip = true;
		if (!(arg[2] == '\0'))
			f_fprintf(STDERR, "Invalid flag\n");
	}
	else if (!(arg[1] == '\0'))
		f_fprintf(STDERR, "Invalid flag\n");
	return (skip);
}

void	bi_echo(t_argv argv)
{
	char	*str;
	bool	skip_line;
	int		i;

	i = 1;
	skip_line = false;
	if (argv[1])
	{
		if (argv[i][0] == '-')
			skip_line = must_skip_newline(argv[i++]);
		str = argv[i];
		while (str)
		{
			f_printf("%s", str = argv[i]);
			str = argv[++i];
			if (str)
				f_printf(" ");
		}
	}
	if (!skip_line)
		f_printf("\n");
}

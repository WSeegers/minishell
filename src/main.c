/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 13:05:19 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/02 10:26:12 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_basic_prompt(void)
{
	f_printf("$>");
}

int		get_command(t_argv *argv)
{
	char	*line;
	int		argc;

	argc = 0;
	f_next_line(&line, STDIN);
	if (*line)
		argc = parse_argv(line, argv);
	free(line);
	return (argc);
}

int		main(void)
{
	t_argv	argv;

	init_env();
	while (1)
	{
		print_basic_prompt();
		if (!get_command(&argv))
			continue ;
		process_command(argv); //need to free argv
		f_strarrdel(argv);
	}
}

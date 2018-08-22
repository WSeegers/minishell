/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 13:05:19 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/22 23:53:12 by wseegers         ###   ########.fr       */
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

	f_next_line(&line, STDIN);
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
		get_command(&argv);  //need to trim while space
		process_command(argv);
		//need to free argv
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 13:05:19 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/18 16:26:40 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void	print_basic_prompt(void)
{
	f_printf("$>");
}

bool	parse_argv(char *line, t_argv *argv)
{

}

bool	get_command(t_argv *argv)
{
	char	*line;
	t_argv	argv;

	f_next_line(&line, STDIN);
	f_printf("command: %s\n", line);
	parse_args(line, argv);
	free(&line);
}

int	main(void)
{
	t_argv	argv;

	print_prompt();
	get_command(&argv);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 13:05:19 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/02 21:01:49 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_basic_prompt(void)
{
	char *dir;
	char *next;

	if (!*(dir = get_env("PWD") + 1))
		dir = "root";
	else	
		while ((next = f_strchr(dir + 1, '/')))
			dir = next + 1;
	f_printf("%s $> ", dir);
}

int		get_command(t_argv *argv)
{
	char	*line;
	char	*trimmed;
	int		argc;

	argc = 0;
	f_next_line(&line, STDIN); //need to validate quotes and brackets
	if (*line)
	{
		trimmed = f_strtrim(line);
		argc = parse_argv(trimmed, argv);
		free(trimmed);
	}
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
		// for (int i = 0; argv[i]; i++)
		// 	f_printf("%d: %s\n", i, argv[i]);
		expand_var(argv);
		process_command(argv);
		f_strarrdel(argv);
	}
}

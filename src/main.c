/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 13:05:19 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/03 15:27:11 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_prompt(void)
{
	char *dir;
	char *next;
	char cwd[2048];

	while (!(dir = get_env("PWD")))
		set_env("PWD", getcwd(cwd, 2048), true);
	if (!*(dir + 1))
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
	g_state = waiting;
	f_next_line(&line, STDIN);
	g_state = processing;
	if (*line)
	{
		validate_line(&line);
		trimmed = f_strtrim(line);
		argc = parse_argv(trimmed, argv);
		free(trimmed);
	}
	free(line);
	return (argc);
}

void	handle_sig(int signo)
{
	if (signo == SIGINT)
	{
		f_printf("\n");
		if (g_state == waiting)
			print_prompt();
	}
}

int		main(void)
{
	t_argv	argv;

	init_env();
	builtins(init);
	signal(SIGINT, handle_sig);
	while (1)
	{
		print_prompt();
		if (!get_command(&argv))
			continue ;
		// for (int i = 0; argv[i]; i++)
		// 	f_printf("%d: %s\n", i, argv[i]);
		expand_var(argv);
		process_command(argv);
		f_strarrdel(argv);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 13:05:19 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/03 12:00:27 by wseegers         ###   ########.fr       */
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

int		get_command(t_argv *argv)
{
	char	*line;
	char	*trimmed;
	int		argc;

	argc = 0;
	f_next_line(&line, STDIN); //need to validate quotes and brackets
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

int		main(void)
{
	t_argv	argv;

	init_env();
	builtins(init);
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

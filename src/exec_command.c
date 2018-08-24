/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 18:08:22 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/24 11:39:15 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//debug
#include <errno.h>
#include <string.h>

static void	exec(char *path, t_argv argv)
{
	pid_t	child_pid;
	int		ret;

	//debug
	extern char **environ;

	child_pid = fork();
	ret = -42;
	if (child_pid)
	{
		wait(&ret);
	}
	else
	{
		execve(path, argv, env_char()); //env char is leaking
		f_printf("exec error: %s\n", path);
		exit(0);
	}
}

void	process_command(t_argv argv)
{
	char	*path;
	int		err;

	if (f_strchr(argv[0], '/'))
	{
		if (!(err = validate_path(argv[0])))
			exec(argv[0], argv);
		else
			f_printf("error\n"); // Print correct error message
	}
	else if (exec_built_in(argv))
		;
	else
	{
		if ((path = validate_env_path(argv)))
		{
			exec(path, argv);
			free(path);
		}	
		else
			f_printf("Command not found: %s\n", argv[0]);
	}
}

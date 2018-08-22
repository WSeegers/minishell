/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 18:08:22 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/22 23:51:43 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//debug
#include <errno.h>
#include <string.h>

void	exec(char *path, t_argv argv)
{
	pid_t	child_pid;
	int		ret;

	child_pid = fork();
	ret = -42;
	if (child_pid)
	{
		wait(&ret);
	}
	else
	{
		execve(path, argv, env_char()); //env char is leaking
		f_printf("no such file or directory\n");
		exit(0);
	}
}

int		validate_path(char *path)
{
	char	*slash;
	int		i;

	path = f_strdup(path);
	i = 1;
	slash = NULL;
	while (i || (slash = f_strrchr(path, '/')))
	{
		if (slash)
			*slash = '\0';
		if (!(i = access(path, F_OK)) && !access(path, X_OK))
		{
			free(path);
			return (0);
		}
		else if (!i)
		{
			free(path);
			return (E_PDENY);
		}
		i = 0;
	}
	free(path);
	return (E_NOPATH);
}

void	process_command(t_argv argv)
{
	//char	*path;
	int		err;

	if (f_strchr(argv[0], '/'))
	{
		if (!(err = validate_path(argv[0])))
			exec(argv[0], argv);
		else
			f_printf("error");
	}
	//else if (exec_builtin(argv))
	// 	;
	// else if (!(path = validate_path(argv[0])))
	// {
	// 	free(path);
	// }


// 	int error = validate_path(argv[0]);
// 	if (error == E_NOPATH)
// 		f_printf("nopath\n");
// 	else if (error == E_PDENY)
// 		f_printf("NONO\n");
// 	else
// 		f_printf("gotcha\n");
}

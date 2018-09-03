/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 19:44:11 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/03 14:43:46 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

static void	clean_path(char *new_path)
{
	char *last_slash;
	char *next_slash;

	last_slash = f_strchr(new_path + 1, '/');
	if (last_slash)
		while ((next_slash = f_strchr(last_slash + 1, '/')))
			last_slash = next_slash;
	if (last_slash && last_slash[1] == '.')
	{
		*last_slash = '\0';
		if (last_slash[2] == '.')
		{
			last_slash = f_strchr(new_path, '/');
			while ((next_slash = f_strchr(last_slash + 1, '/')))
				last_slash = next_slash;
			*last_slash = '\0';
		}
	}
	if (!*new_path)
	{
		*new_path = '/';
		new_path[1] = '\0';
	}
}

static void	update_cwd(char *new_path)
{
	if (print_err(validate_path(new_path)))
		;
	else
	{
		clean_path(new_path);
		chdir(new_path);
		set_env("OLDPWD", get_env("PWD"), true);
		set_env("PWD", new_path, true);
	}
}

static void	home(void)
{
	char *home;

	if ((home = get_env("HOME")))
		update_cwd(home);
	else
		f_fprintf(STDERR,
			"HOME is not set: set home with \"setenv HOME [path]\"\n");
}

void		bi_cd(t_argv argv)
{
	char *new_wd;

	if (argv[1] && argv[2])
		f_fprintf(STDERR, "Too many arguments\n");
	else if (!argv[1])
		home();
	else if (argv[1][0] == '-' && !argv[1][1])
		bi_cd((char*[3]){argv[0], get_env("OLDPWD"), NULL});
	else if (argv[1][0] == '/')
		update_cwd(argv[1]);
	else
	{
		new_wd = f_strcjoin(get_env("PWD"), argv[1], '/');
		update_cwd(new_wd);
		free(new_wd);
	}
	return ;
}

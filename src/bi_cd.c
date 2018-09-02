/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 19:44:11 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/02 21:23:51 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

static void	update_cwd(char *new_path)
{
	char *cwd;

	if (print_err(validate_path(new_path)))
			;
	else
	{
		chdir(new_path);
		cwd = getcwd(NULL, 128);
		set_env("OLDPWD", get_env("PWD"), true);
		set_env("PWD", cwd, true);
		free(cwd);
	}
}

static void home(void)
{
	char *home;

	if ((home = get_env("HOME")))
		update_cwd(home);
	else
		f_fprintf(STDERR,
			"HOME is not set: set home with \"setenv HOME [path]\"\n");

}

void	bi_cd(t_argv argv)
{
	char *cwd;
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
		cwd = getcwd(NULL, 128);
		new_wd = f_strcjoin(cwd, argv[1], '/');
		update_cwd(new_wd);
		free(new_wd);
		free(cwd);
	}
	return ;
}
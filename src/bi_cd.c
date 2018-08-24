/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers.mauws@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 19:44:11 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/24 21:39:23 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

static void	update_pwd(char *new_path)
{
	set_env("OLDPWD", get_env("PWD"), true);
	set_env("PWD", new_path, true);
	chdir(new_path);
}

void	bi_cd(t_argv argv)
{
	char *cwd;
	char *new_wd;

	if (!argv[1])
		update_pwd(get_env("HOME"));
	else
	{
		cwd = getcwd(NULL, 128);
		new_wd = f_strcjoin(cwd, argv[1], '/');
		if (print_err(validate_path(new_wd)))
			;
		else
			update_pwd(new_wd);
		free(new_wd);
		free(cwd);
	}
	return ;
}
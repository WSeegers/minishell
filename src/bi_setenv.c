/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 22:07:34 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/04 09:23:34 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

static void	show_usage(void)
{
	f_printf("setenv [key] [value]\n");
}

void		bi_setenv(t_argv argv)
{
	if (!argv[1] || !argv[2])
		show_usage();
	else
		set_env(argv[1], argv[2], true);
}

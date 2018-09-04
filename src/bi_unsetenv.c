/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 22:46:02 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/04 09:28:16 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

static void	show_usage(void)
{
	f_printf("unsetenv [key...]\n");
}

void		bi_unsetenv(t_argv argv)
{
	int i;

	if (!argv[1])
		show_usage();
	i = 0;
	while (argv[++i])
		unset_env(argv[i]);
}

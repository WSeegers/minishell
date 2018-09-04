/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 20:53:26 by wseegers          #+#    #+#             */
/*   Updated: 2018/09/04 08:45:02 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define PRINT(msg) f_fprintf(STDERR, msg)

int		print_err(int err_code)
{
	(err_code == E_NOPATH) ? PRINT("No such file or directory\n") : 0;
	(err_code == E_PDENY) ? PRINT("Permission denied\n") : 0;
	return (err_code);
}

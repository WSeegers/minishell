/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wseegers <wseegers@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 13:29:35 by wseegers          #+#    #+#             */
/*   Updated: 2018/08/22 10:45:39 by wseegers         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGV_H
# define ARGV_H

# include <stdlib.h>
# include "s_list.h"
# include "f_string.h"

typedef char	**t_argv;

int		parse_argv(const char *line, t_argv *pargv);

#endif

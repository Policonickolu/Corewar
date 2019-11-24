/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 08:36:14 by hben-yah          #+#    #+#             */
/*   Updated: 2019/11/24 09:00:00 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "libft.h"

int	parse_options(int *options, char *arg)
{
	int index;

	if (*arg == '-')
		++arg;
	while (*arg)
	{
		if ((index = ft_indexof(*arg, VM_OPTIONS)) == -1)
			return (invalid_option_error(*arg));
		*options |= 1 << index;
		if (*options & VM_OP_H)
			return (put_usage());
		++arg;
	}
	return (0);
}

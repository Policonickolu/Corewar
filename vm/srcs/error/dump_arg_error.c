/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump_arg_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 08:33:22 by hben-yah          #+#    #+#             */
/*   Updated: 2019/11/24 09:33:45 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "libft.h"

int		dump_arg_error(void)
{
	ft_putendl_fd(VM_NAME": dump number of cycles has to be a positive number",
		2);
	return (put_usage());
}

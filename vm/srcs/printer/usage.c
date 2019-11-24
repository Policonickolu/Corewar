/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 08:50:53 by hben-yah          #+#    #+#             */
/*   Updated: 2019/11/24 09:34:33 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "libft.h"

int		put_usage(void)
{
	ft_putstr_fd("Usage:  ./"VM_NAME" [-"VM_OPTIONS"] ", 2);
	ft_putstr_fd("[-dump nbr_cycles] [[-n number] champion1.cor] ...\n", 2);
	return (1);
}

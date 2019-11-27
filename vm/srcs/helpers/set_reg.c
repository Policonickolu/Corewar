/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_reg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:54:19 by hben-yah          #+#    #+#             */
/*   Updated: 2019/11/27 07:58:37 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "libft.h"

int		set_reg(t_process *ps, int reg, void *val, size_t size)
{
	if (reg < 1 || reg > REG_NUMBER)
		return (1);
	if (size > REG_SIZE)
		size = REG_SIZE;
	ft_memcpy(ps->regs + ((reg - 1) * REG_SIZE), val, size);
	return (0);
}

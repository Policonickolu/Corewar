/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_reg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:54:19 by hben-yah          #+#    #+#             */
/*   Updated: 2019/11/25 15:19:45 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "libft.h"

void	get_reg(t_process *ps, int reg, void *val, size_t size)
{
	if (reg < 1 || reg > REG_NUMBER)
		return ;
	if (size > REG_SIZE)
		size = REG_SIZE;
	ft_memcpy(val, ps->regs + ((reg - 1) * REG_SIZE), size);
}

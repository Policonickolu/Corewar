/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_reg_val.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:54:19 by hben-yah          #+#    #+#             */
/*   Updated: 2019/11/30 10:45:32 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	set_reg_val(t_process *ps, int reg, intmax_t val)
{
	if (reg < 1 || reg >= REG_NUMBER)
		reg = 0;
	ps->registers[reg] = val;
}

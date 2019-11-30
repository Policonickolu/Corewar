/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 16:52:45 by hben-yah          #+#    #+#             */
/*   Updated: 2019/11/30 11:36:22 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		operate_sub(t_vm *vm, t_process *ps)
{
	char		reg1;
	char		reg2;
	char		reg3;
	intmax_t	val;

	move_oc(ps, 1);
	reg1 = read_field(vm, ps, 1);
	reg2 = read_field(vm, ps, 1);
	reg3 = read_field(vm, ps, 1);
	val = get_reg_val(ps, reg1) - get_reg_val(ps, reg2);
	set_reg_val(ps, reg3, val);
	move_pc_past_oc(ps);
	set_carry(ps, val);
}

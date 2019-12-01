/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 16:52:45 by hben-yah          #+#    #+#             */
/*   Updated: 2019/12/01 13:40:03 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		operate_or(t_vm *vm, t_process *ps)
{
	int				param_type1;
	int				param_type2;
	intmax_t		src1;
	intmax_t		src2;
	intmax_t		dst_reg;

	move_oc(ps, 1);
	param_type1 = get_param_type(vm->field[ps->oc], 1);
	src1 = read_field(vm, ps, get_type_size(param_type1));
	if (param_type1 == REG_CODE)
		src1 = get_reg_val(ps, src1);
	else if (param_type1 == IND_CODE)
		src1 = read_field_at(vm, ps, src1, DIR_SIZE);
	param_type2 = get_param_type(vm->field[ps->oc], 2);
	src2 = read_field(vm, ps, get_type_size(param_type2));
	if (param_type2 == REG_CODE)
		src2 = get_reg_val(ps, src2);
	else if (param_type2 == IND_CODE)
		src2 = read_field_at(vm, ps, src2, DIR_SIZE);
	dst_reg = read_field(vm, ps, 1);
	src1 |= src2;
	set_reg_val(ps, dst_reg, src1);
	set_carry(ps, src1);
	move_pc_past_oc(vm, ps);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lldi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 16:52:45 by hben-yah          #+#    #+#             */
/*   Updated: 2019/12/01 13:40:08 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		operate_lldi(t_vm *vm, t_process *ps)
{
	int				param_type;
	intmax_t		v1;
	intmax_t		v2;
	char			v3;

	move_oc(ps, 1);
	param_type = get_param_type(vm->field[ps->oc], 1);
	v1 = read_field(vm, ps, param_type == REG_CODE ? 1 : 2);
	if (param_type == REG_CODE)
		v1 = get_reg_val(ps, v1);
	v2 = read_field(vm, ps, 2);
	v1 = get_rel_address(ps, v1 + v2);
	v1 = read_field_at(vm, ps, v1, DIR_SIZE);
	v3 = (char)read_field(vm, ps, 1);
	set_reg_val(ps, v3, v1);
	set_carry(ps, v1);
	move_pc_past_oc(vm, ps);
}

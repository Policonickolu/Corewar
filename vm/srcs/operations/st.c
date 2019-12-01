/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 16:52:45 by hben-yah          #+#    #+#             */
/*   Updated: 2019/12/01 13:39:59 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		operate_st(t_vm *vm, t_process *ps)
{
	int				param_type;
	intmax_t		src_reg;
	intmax_t		dst;

	move_oc(ps, 1);
	param_type = get_param_type(vm->field[ps->oc], 2);
	src_reg = read_field(vm, ps, 1);
	src_reg = get_reg_val(ps, src_reg);
	dst = (char)read_field(vm, ps, get_type_size(param_type));
	if (param_type == IND_CODE)
	{
		dst = get_rel_address(ps, dst % IDX_MOD);
		write_field_at(vm, ps, dst, src_reg);
	}
	else
		set_reg_val(ps, dst, src_reg);
	set_carry(ps, src_reg);
	move_pc_past_oc(vm, ps);
}

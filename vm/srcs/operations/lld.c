/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 16:52:45 by hben-yah          #+#    #+#             */
/*   Updated: 2019/11/30 16:12:08 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		operate_lld(t_vm *vm, t_process *ps)
{
	int				param_type;
	intmax_t		src;
	char			dst_reg;

	move_oc(ps, 1);
	param_type = get_param_type(vm->field[ps->oc], 1);
	src = read_field(vm, ps, get_type_size(param_type));
	dst_reg = (char)read_field(vm, ps, 1);
	if (param_type == IND_CODE)
		src = get_rel_address(ps, src);
	src = read_field_at(vm, ps, src, DIR_SIZE);
	set_reg_val(ps, dst_reg, src);
	set_carry(ps, src);
	move_pc_past_oc(ps);
}

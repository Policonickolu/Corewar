/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 16:52:45 by hben-yah          #+#    #+#             */
/*   Updated: 2019/11/27 09:44:52 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		operate_add(t_vm *vm, t_process *ps)
{
	int				r1;
	int				r2;
	int				r3;
	intmax_t		v1;
	intmax_t		v2;

	move_oc(ps, 1);
	read_field(vm, ps, &r1, 1);
	read_field(vm, ps, &r2, 1);
	read_field(vm, ps, &r3, 1);
	get_reg(ps, r1, &v1, sizeof(intmax_t));
	get_reg(ps, r2, &v2, sizeof(intmax_t));
	v1 += v2;
	set_reg(ps, r3, &v1, sizeof(intmax_t));	
	move_pc_past_oc(ps);
	toggle_carry(ps, v1);
}

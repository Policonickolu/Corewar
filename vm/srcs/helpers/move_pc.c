/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_pc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 17:08:49 by hben-yah          #+#    #+#             */
/*   Updated: 2019/12/03 10:52:36 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	move_pc(t_vm *vm, t_process *ps, int val)
{
	(void)vm;
	//if (vm->options & VM_OP_C)
	//	print_val(ps->pc, vm->field[ps->pc], ps->number, 0);
	ps->pc = get_rel_address(ps, val);
	//if (vm->options & VM_OP_C)
	//	print_val(ps->pc, vm->field[ps->pc], ps->number, 1);
}

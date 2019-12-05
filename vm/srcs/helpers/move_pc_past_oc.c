/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_pc_past_oc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 09:07:44 by hben-yah          #+#    #+#             */
/*   Updated: 2019/12/05 09:33:49 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	move_pc_past_oc(t_vm *vm, t_process *ps)
{
	if (vm->options & VM_OP_C)
		write_val(vm, ps->pc, ps->number, 0);
	ps->pc = ps->oc;
	if (vm->options & VM_OP_C)
		write_val(vm, ps->pc, ps->number, 1);
	move_pc(vm, ps, 1);
}

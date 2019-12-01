/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_pc_past_oc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 09:07:44 by hben-yah          #+#    #+#             */
/*   Updated: 2019/12/01 13:38:03 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	move_pc_past_oc(t_vm *vm, t_process *ps)
{
	ps->pc = ps->oc;
	move_pc(vm, ps, 1);
}

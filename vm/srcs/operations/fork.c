/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 16:52:45 by hben-yah          #+#    #+#             */
/*   Updated: 2019/12/01 13:38:16 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		operate_fork(t_vm *vm, t_process *ps)
{
	t_process		*new;
	int				at;

	at = read_field(vm, ps, 2);
	new = dup_process(vm, ps);
	insert_process(vm, new);
	move_pc(vm, new, at % IDX_MOD);
	new->sleep = 0;
	new->op = NULL;
	move_pc_past_oc(vm, ps);
}

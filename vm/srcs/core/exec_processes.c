/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_processes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 16:09:46 by hben-yah          #+#    #+#             */
/*   Updated: 2019/12/01 13:37:54 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"


t_op		*get_op_func_from_tab(int op_code)
{
	if (op_code < 1 || op_code > 16)
		return (NULL);
	return (&op_tab[op_code - 1]);
}

void		set_op_function(t_vm *vm, t_process *ps, int op_code)
{
	if (!(ps->op = get_op_func_from_tab(op_code)))
	{
		move_pc(vm, ps, 1);
		ps->sleep = 1;
	}
	else
		ps->sleep = ps->op->nb_cycles - 2;
}

void			exec_operation(t_vm *vm, t_process *process)
{
	g_op_func_tab[process->op->op_code - 1](vm, process);
	process->op = NULL;
}

void			set_next_operation(t_vm *vm, t_process *process)
{
	process->oc = process->pc;
	set_op_function(vm, process, (int)vm->field[process->pc]);
}

void			exec_processes(t_vm *vm)
{
	t_process	*process;

	process = vm->process;
	while (process)
	{
		if (!process->sleep)
		{
			if (process->op)
				exec_operation(vm, process); //add_op_to_queue
			else
				set_next_operation(vm, process);
		}
		else
			--process->sleep;
		process = process->next;
	}
	//exec_ops_queue(vm);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 15:04:15 by hben-yah          #+#    #+#             */
/*   Updated: 2019/11/25 17:45:15 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

// void		exec_ops_queue(t_vm *vm)
// {
// 	t_ps_op		*prev;

// 	while (vm->ops_queue)
// 	{
// 		prev = vm->ops_queue;
// 		vm->ops_queue = vm->ops_queue->next;
// 		prev->op(vm, prev->ps);
// 		prev->ps->op = NULL;
// 		free(prev);
// 	}
// }

// static void			setup_ops(t_operation_code *table)
// {
// 	table[454501] = &operate_live;
// 	table[1764] = &operate_ld;
// 	table[1908] = &operate_st;
// 	table[26468] = &operate_add;
// 	table[30578] = &operate_sub;
// 	table[26596] = &operate_and;
// 	table[1778] = &operate_or;
// 	table[32498] = &operate_xor;
// 	table[519920] = &operate_zjmp;
// 	table[28265] = &operate_ldi;
// 	table[30569] = &operate_sti;
// 	table[421739] = &operate_fork;
// 	table[28388] = &operate_lld;
// 	table[454249] = &operate_lldi;
// 	table[7237483] = &operate_lfork;
// 	table[26470] = &operate_aff;
// }

// static t_operation_code	get_op(long op_code)
// {
// 	static t_operation_code	table[7237484];

// 	if (op_code < 1 || op_code > 7237483)
// 		return (NULL);
// 	if (!table[1764])
// 		setup_ops(table);
// 	return (table[op_code]);
// }

// static long			hash_name(char *name)
// {
// 	long			hash;

// 	if (!name)
// 		return (0);
// 	hash = 0;
// 	while (*name)
// 	{
// 		hash = hash << 4;
// 		hash |= *name;
// 		name++;
// 	}
// 	return (hash);
// }

void				save_op(t_vm *vm, t_process *ps, int op_code)
{
	t_op			*seek;

	seek = op_tab;
	while (seek->op_code && seek->op_code != op_code)
		seek++;
	ft_putendl2("opé : ", seek->name);
	if (!(ps->op = ht_get(vm->operations, seek->name)))
	{
		move_pc(ps, 1);
		ps->sleep_cycles = 1;
	}
	else
		ps->sleep_cycles = seek->nb_cycles - 2;
}

// void		exec_process(t_vm *vm, t_process *ps)
// {
// 	ps->pc_tmp = ps->pc;
// 	save_op(vm, ps, (int)vm->field[ps->pc]);
// }

// void			add_op_to_queue(t_vm *vm, t_process *ps)
// {
// 	t_ps_op		*op;

// 	if (!ps->op)
// 		return ;
// 	if (!(op = (t_ps_op*)ft_memalloc(sizeof(t_ps_op))))
// 		error_exit(vm, "Malloc failed, op creation.");
// 	op->ps = ps;
// 	op->op = ps->op;
// 	op->next = vm->ops_queue;
// 	vm->ops_queue = op;
// }

void			exec_operation(t_vm *vm, t_process *process)
{
	process->op(vm, process);
}

void			get_next_operation(t_vm *vm, t_process *process)
{
	process->pc_tmp = process->pc;
	save_op(vm, process, (int)vm->field[process->pc]);
}

void			exec_processes(t_vm *vm)
{
	t_process	*process;

	process = vm->process;
	while (process)
	{
		if (!process->sleep_cycles)
		{
			if (process->op)
				exec_operation(vm, process); //add_op_to_queue
			else
				get_next_operation(vm, process);
		}
		else
			--process->sleep_cycles;
		process = process->next;
	}
	//exec_ops_queue(vm);
}

void	run_vm(t_vm *vm)
{
	init_processes(vm);
	while (vm->cycle_to_die > 0 && vm->process)
	{
		exec_processes(vm);
		// if (vm->total_cycle == CYCLE_TO_DIE)
		// 	vm->cycle = 0;
		if (vm->cycle == vm->cycle_to_die)
		{
			//check_processes(vm);
			++vm->check;
			if (vm->check == MAX_CHECKS || vm->live_calls >= NBR_LIVE)
			{
				vm->check = 0;
				vm->cycle_to_die -= CYCLE_DELTA;
			}
			vm->cycle = 0;
			vm->live_calls = 0;
		}
		//dump
		++vm->cycle;
		++vm->total_cycle;
	}
}

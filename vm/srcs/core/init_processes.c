/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_processes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 15:57:40 by hben-yah          #+#    #+#             */
/*   Updated: 2019/11/30 10:47:53 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "vm.h"
#include "libft.h"

void	init_process(t_vm *vm, t_champ *champ, size_t pc)
{
	t_process	*process;

	if (!(process = (t_process*)ft_memalloc(sizeof(t_process))))
		vm_exit(vm, "error malloc, init process");
	process->name = champ->header.prog_name;
	process->number = champ->number;
	//process->r[get_r(1)] = process->number; // FAIRE UNE FONCTION QUI ECRIT DANS UN REGISTRE DE PLUSIEURS CASES !!!
	set_reg_val(process, 1, process->number);
	process->pc = pc;
	process->next = vm->process;
	process->id = ++vm->n_process;
	vm->process = process;
	ft_memcpy(vm->field + pc, champ->prog, champ->header.prog_size);
}

void	init_processes(t_vm *vm)
{
	t_champ		*champ;
	size_t		gap;
	size_t		pc;

	pc = 0;
	gap = MEM_SIZE / vm->n_champ;
	champ = vm->champ;
	while (champ)
	{
		init_process(vm, champ, pc);
		pc += gap;
		champ = champ->next;
	}
}

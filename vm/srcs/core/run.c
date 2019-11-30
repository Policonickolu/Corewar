/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 15:04:15 by hben-yah          #+#    #+#             */
/*   Updated: 2019/11/30 11:27:53 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	run_vm(t_vm *vm)
{
	init_processes(vm);
	while (vm->cycles_to_die > 0 && vm->process)
	{
		exec_processes(vm);
		// if (vm->total_cycles == CYCLE_TO_DIE)
		// 	vm->cycles = 0;
		if (vm->cycles == vm->cycles_to_die)
		{
			check_processes(vm);
			++vm->checks;
			if (vm->checks == MAX_CHECKS || vm->lives >= NBR_LIVE)
			{
				vm->checks = 0;
				vm->cycles_to_die -= CYCLE_DELTA;
			}
			vm->cycles = 0;
			vm->lives = 0;
		}
		display_field(vm);
		++vm->cycles;
		++vm->total_cycles;
	}
}

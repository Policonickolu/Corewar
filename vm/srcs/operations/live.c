/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 16:52:45 by hben-yah          #+#    #+#             */
/*   Updated: 2019/12/05 11:09:24 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		operate_live(t_vm *vm, t_process *ps)
{
	int			number;
	t_champ		*champ;

	number = (int)read_field(vm, ps, DIR_SIZE);
	if ((champ = get_champ(vm, number)))
	{
		++ps->lives;
		++vm->lives;
		vm->last_name = champ->header.prog_name;
		vm->last_live = number;
		if (vm->options & VM_OP_C)
		{
			wprintw(vm->display.out, "Le joueur %s (%d) est vivant !\n", vm->last_name, vm->last_live);
			wrefresh(vm->display.out);
		}
		else
		{
			ft_putstr("Le joueur ");
			ft_putstr(vm->last_name);
			ft_putstrnbr(" (", vm->last_live, ") est vivant !\n");
		}
	}
	move_pc_past_oc(vm, ps);
}

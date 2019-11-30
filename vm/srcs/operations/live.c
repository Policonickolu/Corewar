/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 16:52:45 by hben-yah          #+#    #+#             */
/*   Updated: 2019/11/30 11:35:32 by hben-yah         ###   ########.fr       */
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
		ft_putstr("Le joueur ");
		ft_putstr(vm->last_name);
		ft_putstrnbr(" (", vm->last_live, ") est vivant !\n");
	}
	move_pc_past_oc(ps);
}

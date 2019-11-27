/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 16:52:45 by hben-yah          #+#    #+#             */
/*   Updated: 2019/11/27 09:16:41 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		operate_live(t_vm *vm, t_process *ps)
{
	int		number;
	t_champ	*champ;

	read_field(vm, ps, &number, DIR_SIZE);
	if ((champ = get_champ(vm, number)))
	{
		++ps->live_calls;
		++vm->live_calls;
		vm->last_live = number;
		vm->last_name = champ->header.prog_name;
		ft_putstr("Le joueur ");
		ft_putstr(vm->last_name);
		ft_putstrnbr(" (", vm->last_live, ") est vivant !\n");
	}
	move_pc_past_oc(ps);
}

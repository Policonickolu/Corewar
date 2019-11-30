/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 16:52:45 by hben-yah          #+#    #+#             */
/*   Updated: 2019/11/30 16:23:11 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		operate_aff(t_vm *vm, t_process *ps)
{
	char			reg;
	intmax_t		val;

	move_oc(ps, 2);
	reg = (char)read_field(vm, ps, 1);
	val = get_reg_val(ps, reg);
	// if (vm->aff)// || vm->affd || vm->affx || vm->affx2)
	// {
		ft_printf(CYAN);
		ft_printf("Aff r%-2d [", reg);
		//if (vm->aff)
			ft_printf("%C", val % 256);
		// else if (vm->affd)
		// 	ft_printf("%d", val);
		// else if (vm->affx)
		// 	ft_printf("%x", val);
		// else if (vm->affx2)
		// 	ft_printf("%X", val);
		ft_printf("]\n");
		ft_printf(RESET);
	//}
	move_pc_past_oc(ps);
}

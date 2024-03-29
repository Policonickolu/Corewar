/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 08:45:35 by hben-yah          #+#    #+#             */
/*   Updated: 2019/12/05 11:29:13 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	reset_display(t_vm *vm)
{
	if (vm->options & VM_OP_C)
	{
		wgetch(vm->display.out);
		delwin(vm->display.game);
		delwin(vm->display.out);
		endwin();
	}
}

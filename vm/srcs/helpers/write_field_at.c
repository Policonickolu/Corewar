/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_field_at.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 08:44:47 by hben-yah          #+#    #+#             */
/*   Updated: 2019/12/05 09:12:48 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	write_field_at(t_vm *vm, t_process *ps, intmax_t i, intmax_t val)
{
	int			size;
	int			addr;

	size = DIR_SIZE;
	while (size--)
	{
		addr = get_rel_address(ps, i++);
		vm->field[addr] = (val >> (size * 8)) & 0xFF;
		if (vm->options & VM_OP_C)
			write_val(vm, addr, ps->number, 0);
	}
}

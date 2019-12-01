/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_field_at.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 08:44:47 by hben-yah          #+#    #+#             */
/*   Updated: 2019/12/01 16:03:38 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

char	*g_base_2 = "0123456789abcdef";

void	print_val(int addr, unsigned char val, int number, int rev)
{
	int		x;
	int		y;

	x = FIELD_OFFSET_X + (addr * 3 % FIELD_WIDTH);
	y = FIELD_OFFSET_Y + (addr * 3 / FIELD_WIDTH);
	
	if (rev)
	{
		mvaddch(y, x++, g_base_2[val / 16] | A_REVERSE | COLOR_PAIR(((number - 1) % 7) + 1));
		mvaddch(y, x++, g_base_2[val % 16] | A_REVERSE | COLOR_PAIR(((number - 1) % 7) + 1));
	}
	else
	{
		mvaddch(y, x++, g_base_2[val / 16] | COLOR_PAIR(((number - 1) % 7) + 1));
		mvaddch(y, x++, g_base_2[val % 16] | COLOR_PAIR(((number - 1) % 7) + 1));
	}
	refresh();
	usleep(50000);
}

void	write_field_at(t_vm *vm, t_process *ps, intmax_t i, intmax_t val)
{
	int			size;
	int			addr;

	size = DIR_SIZE;
	while (size--)
	{
		addr = get_rel_address(ps, i++);
		vm->field[addr] = (val >> (size * 8)) & 0xFF;
		if (vm->options & VM_OP_G)
			print_val(addr, (unsigned char)vm->field[addr], ps->number, 0);
	}
}

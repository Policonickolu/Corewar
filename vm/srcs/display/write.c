/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 08:47:02 by hben-yah          #+#    #+#             */
/*   Updated: 2019/12/05 09:20:33 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	write_val(t_vm *vm, int addr, int number, int rev)
{
	int		x;
	int		y;
	unsigned char val;

	x = FIELD_OFFSET_X + (addr * 3 % FIELD_WIDTH);
	y = FIELD_OFFSET_Y + (addr * 3 / FIELD_WIDTH);
	val = (unsigned char)vm->field[addr];
	if (rev)
	{
		mvwaddch(vm->display.game, y, x++, g_base[val / 16] | A_REVERSE | COLOR_PAIR(((number - 1) % 7) + 1));
		mvwaddch(vm->display.game, y, x++, g_base[val % 16] | A_REVERSE | COLOR_PAIR(((number - 1) % 7) + 1));
	}
	else
	{
		mvwaddch(vm->display.game, y, x++, g_base[val / 16] | COLOR_PAIR(((number - 1) % 7) + 1));
		mvwaddch(vm->display.game, y, x++, g_base[val % 16] | COLOR_PAIR(((number - 1) % 7) + 1));
	}
	wrefresh(vm->display.game);
	usleep(vm->display.speed);
}

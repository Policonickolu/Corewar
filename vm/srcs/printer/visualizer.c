/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 10:40:42 by hben-yah          #+#    #+#             */
/*   Updated: 2019/12/01 13:17:41 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

char	*g_base = "0123456789abcdef";

void	visu_write_prog(t_vm *vm, t_champ *champ, int pc)
{
	size_t	i;
	int		x;
	int		y;

	x = FIELD_OFFSET_X + (pc * 3 % FIELD_WIDTH);
	y = FIELD_OFFSET_Y + (pc * 3 / FIELD_WIDTH);
	i = 0;
	while (i < champ->header.prog_size)
	{
		mvaddch(y, x++, g_base[(unsigned char)vm->field[pc + i] / 16] | COLOR_PAIR(((champ->number - 1) % 7) + 1));
		mvaddch(y, x++, g_base[(unsigned char)vm->field[pc + i] % 16] | COLOR_PAIR(((champ->number - 1) % 7) + 1));
		mvaddch(y, x++, ' ');
		if (x >= FIELD_OFFSET_X + FIELD_WIDTH)
		{
			++y;
			x = FIELD_OFFSET_X;
		}
		++i;
	}
}

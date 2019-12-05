/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   programs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 10:34:53 by hben-yah          #+#    #+#             */
/*   Updated: 2019/12/05 09:05:32 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	display_programs(t_vm *vm, t_champ *champ, int pc)
{
	size_t	i;
	int		yx[2];

	if (vm->options & VM_OP_C)
	{
		yx[0] = FIELD_OFFSET_Y + (pc * 3 / FIELD_WIDTH);
		yx[1] = FIELD_OFFSET_X + (pc * 3 % FIELD_WIDTH);
		i = 0;
		while (i < champ->header.prog_size)
		{
			mvwaddch(vm->display.game, yx[0], yx[1]++,
				g_base[(unsigned char)vm->field[pc + i] / 16]
				| COLOR_PAIR(((champ->number - 1) % 7) + 1));
			mvwaddch(vm->display.game, yx[0], yx[1]++,
				g_base[(unsigned char)vm->field[pc + i] % 16]
				| COLOR_PAIR(((champ->number - 1) % 7) + 1));
			if (++yx[1] >= FIELD_OFFSET_X + FIELD_WIDTH)
			{
				++yx[0];
				yx[1] = FIELD_OFFSET_X;
			}
			++i;
		}
	}
	wrefresh(vm->display.game);
}

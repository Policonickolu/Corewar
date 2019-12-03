/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   programs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 10:34:53 by hben-yah          #+#    #+#             */
/*   Updated: 2019/12/03 11:58:41 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	display_programs(t_vm *vm, t_champ *champ, int pc)
{
	size_t	i;
	int		x;
	int		y;

	if (vm->options & VM_OP_C)
	{
		x = pc * 3 % FIELD_WIDTH;
		y = pc * 3 / FIELD_WIDTH;
		i = 0;
		while (i < champ->header.prog_size)
		{
			mvwaddch(vm->game, y, x++, g_base[(unsigned char)vm->field[pc + i] / 16]
				| COLOR_PAIR(((champ->number - 1) % 7) + 1));
			mvwaddch(vm->game, y, x++, g_base[(unsigned char)vm->field[pc + i] % 16]
				| COLOR_PAIR(((champ->number - 1) % 7) + 1));
			mvwaddch(vm->game, y, x++, ' ');
			if (x >= FIELD_WIDTH)
			{
				++y;
				x = 0;
			}
			++i;
		}
	}
}

// void	display_programs(t_vm *vm, t_champ *champ, int pc)
// {
// 	size_t	i;
// 	int		x;
// 	int		y;

// 	if (vm->options & VM_OP_C)
// 	{
// 		x = FIELD_OFFSET_X + (pc * 3 % FIELD_WIDTH);
// 		y = FIELD_OFFSET_Y + (pc * 3 / FIELD_WIDTH);
// 		i = 0;
// 		while (i < champ->header.prog_size)
// 		{
// 			mvaddch(y, x++, g_base[(unsigned char)vm->field[pc + i] / 16]
// 				| COLOR_PAIR(((champ->number - 1) % 7) + 1));
// 			mvaddch(y, x++, g_base[(unsigned char)vm->field[pc + i] % 16]
// 				| COLOR_PAIR(((champ->number - 1) % 7) + 1));
// 			mvaddch(y, x++, ' ');
// 			if (x >= FIELD_OFFSET_X + FIELD_WIDTH)
// 			{
// 				++y;
// 				x = FIELD_OFFSET_X;
// 			}
// 			++i;
// 		}
// 	}
// }

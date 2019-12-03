/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 08:45:30 by hben-yah          #+#    #+#             */
/*   Updated: 2019/12/03 12:20:13 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			draw_rectangle(int y1, int x1, int y2, int x2)
{
    mvhline(y1, x1, 0, x2-x1);
    mvhline(y2, x1, 0, x2-x1);
    mvvline(y1, x1, 0, y2-y1);
    mvvline(y1, x2, 0, y2-y1);
    mvaddch(y1, x1, ACS_ULCORNER);
    mvaddch(y2, x1, ACS_LLCORNER);
    mvaddch(y1, x2, ACS_URCORNER);
    mvaddch(y2, x2, ACS_LRCORNER);
}

void			display_boxes(t_vm *vm)
{
	vm->grid_height = MEM_SIZE / FIELD_WIDTH * 3;
	// draw_rectangle(FIELD_OFFSET_Y + vm->grid_height + 1, LEG_OFFSET_X - 2,
	// 	FIELD_OFFSET_Y + LEG_HEIGHT + vm->grid_height + 1,
	// 	LEG_OFFSET_X + LEG_WIDTH + 4);
	// draw_rectangle(VERB_OFFSET_Y - 1, VERB_OFFSET_X - 2,
	// 	VERB_OFFSET_Y + vm->grid_height + 1,
	// 	VERB_OFFSET_X + VERB_WIDTH);
	// draw_rectangle(INFO_OFFSET_Y - 1, INFO_OFFSET_X - 2,
	// 	INFO_OFFSET_Y + vm->grid_height + 1,
	// 	INFO_OFFSET_X + INFO_WIDTH);
	// draw_rectangle(FIELD_OFFSET_Y - 1, FIELD_OFFSET_X - 2,
	// 	FIELD_OFFSET_Y + vm->grid_height + 1,
	// 	FIELD_OFFSET_X + FIELD_WIDTH);
}

void			display_numbers(t_vm *vm)
{
	int i;
	int x;
	int y;

	x = FIELD_OFFSET_X;
	y = FIELD_OFFSET_Y - 2;
	i = 0;
	while (i < FIELD_WIDTH / 3)
	{
		mvwaddch(vm->game, y, x++, '0' + (i / 10 % 10));
		mvwaddch(vm->game, y, x++, '0' + (i++ % 10));
		mvwaddch(vm->game, y, x++, ' ');
	}
	y += 2;
	i = 0;
	while (i < (MEM_SIZE / FIELD_WIDTH * 3) + 1)
	{	
		x = FIELD_OFFSET_X - 5;
		mvwaddch(vm->game, y, x++, '0' + (i / 10 % 10));
		mvwaddch(vm->game, y++, x, '0' + (i++ % 10));
	}
}

static void		init_colors(void)
{
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_CYAN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(6, COLOR_GREEN, COLOR_BLACK);
	init_pair(7, COLOR_WHITE, COLOR_BLACK);
}

void			init_display(t_vm *vm)
{
	if (vm->options & VM_OP_C)
	{
		initscr();
		cbreak();
		noecho();
		clear();
		start_color();
		init_colors();
		vm->game = newwin(LINES, FIELD_WIDTH + INFO_WIDTH, 0, 0);
		vm->out = newwin(LINES, VERB_WIDTH, 0, VERB_OFFSET_X);
		scrollok(vm->out, TRUE);
		display_numbers(vm);
		display_boxes(vm);
	}
}

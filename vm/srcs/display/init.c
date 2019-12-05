/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 08:45:30 by hben-yah          #+#    #+#             */
/*   Updated: 2019/12/05 11:54:03 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void			display_boxes(t_vm *vm)
{
	int x[6];
	int y[6];
	
	y[0] = FIELD_OFFSET_Y - 1;
	y[1] = FIELD_OFFSET_Y + (MEM_SIZE / 192 * 3) + 1;
	x[0] = FIELD_OFFSET_X - 2;
	x[1] = FIELD_OFFSET_X + FIELD_WIDTH + 1;
	x[2] = FIELD_OFFSET_X + FIELD_WIDTH + INFO_WIDTH + 1;
    mvwhline(vm->display.game, y[0], x[0], 0, x[2]-x[0]);
    mvwhline(vm->display.game, y[1], x[0], 0, x[2]-x[0]);
    mvwvline(vm->display.game, y[0], x[0], 0, y[1]-y[0]);
    mvwvline(vm->display.game, y[0], x[1], 0, y[1]-y[0]);
    mvwvline(vm->display.game, y[0], x[2], 0, y[1]-y[0]);
	mvwaddch(vm->display.game, y[0], x[0], ACS_ULCORNER);
	mvwaddch(vm->display.game, y[0], x[1], ACS_URCORNER);
	mvwaddch(vm->display.game, y[0], x[2], ACS_URCORNER);
	mvwaddch(vm->display.game, y[1], x[0], ACS_LLCORNER);
	mvwaddch(vm->display.game, y[1], x[1], ACS_LRCORNER);
	mvwaddch(vm->display.game, y[1], x[2], ACS_LRCORNER);
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
		mvwaddch(vm->display.game, y, x++, '0' + (i / 10 % 10));
		mvwaddch(vm->display.game, y, x++, '0' + (i++ % 10));
		mvwaddch(vm->display.game, y, x++, ' ');
	}
	y += 2;
	i = 0;
	while (i < (MEM_SIZE / FIELD_WIDTH * 3) + 1)
	{	
		x = FIELD_OFFSET_X - 5;
		mvwaddch(vm->display.game, y, x++, '0' + (i / 10 % 10));
		mvwaddch(vm->display.game, y++, x, '0' + (i++ % 10));
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
		getmaxyx(stdscr, vm->display.height, vm->display.width);
		vm->display.game = newwin(vm->display.height, W_GAME_WIDTH, 0, 0);
		vm->display.out = newwin(vm->display.height, vm->display.width - W_GAME_WIDTH, 0, W_GAME_WIDTH);
		scrollok(vm->display.out, TRUE);
		display_numbers(vm);
		display_boxes(vm);
		
		mvwprintw(vm->display.game, INFO_OFFSET_Y + 30, INFO_OFFSET_X + 1, "CYCLE DELTA    %d", CYCLE_DELTA);
		vm->display.speed = 10000;
		
		keypad(vm->display.out, TRUE);
		curs_set(0);
		wrefresh(vm->display.game);
		wmove(vm->display.out, 0, 0);
	}
}

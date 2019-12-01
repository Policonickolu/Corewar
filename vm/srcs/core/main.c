/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 08:13:53 by hben-yah          #+#    #+#             */
/*   Updated: 2019/12/01 15:33:39 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "libft.h"

// int		set_operations(t_vm *vm)
// {
// 	if (!(vm->operations = ht_new(CW_HASHTAB_SIZE)))
// 		return (1);
// 	if (ht_add(vm->operations, "live", (void *)&operate_live, sizeof(&operate_live))
// 		|| ht_add(vm->operations, "ld", (void *)&operate_ld, sizeof(&operate_ld))
// 		|| ht_add(vm->operations, "st", (void *)&operate_st, sizeof(&operate_st))
// 		|| ht_add(vm->operations, "add", (void *)&operate_add, sizeof(&operate_add))
// 		|| ht_add(vm->operations, "sub", (void *)&operate_sub, sizeof(&operate_sub))
// 		|| ht_add(vm->operations, "and", (void *)&operate_and, sizeof(&operate_and))
// 		|| ht_add(vm->operations, "or", (void *)&operate_or, sizeof(&operate_or))
// 		|| ht_add(vm->operations, "xor", (void *)&operate_xor, sizeof(&operate_xor))
// 		|| ht_add(vm->operations, "zjmp", (void *)&operate_zjmp, sizeof(&operate_zjmp))
// 		|| ht_add(vm->operations, "ldi", (void *)&operate_ldi, sizeof(&operate_ldi))
// 		|| ht_add(vm->operations, "sti", (void *)&operate_sti, sizeof(&operate_sti))
// 		|| ht_add(vm->operations, "fork", (void *)&operate_fork, sizeof(&operate_fork))
// 		|| ht_add(vm->operations, "lld", (void *)&operate_lld, sizeof(&operate_lld))
// 		|| ht_add(vm->operations, "lldi", (void *)&operate_lldi, sizeof(&operate_lldi))
// 		|| ht_add(vm->operations, "lfork", (void *)&operate_lfork, sizeof(&operate_lfork))
// 		|| ht_add(vm->operations, "aff", (void *)&operate_aff, sizeof(&operate_aff)))
// 	{
// 		ht_tabdel(&vm->operations, NULL);
// 		return (1);
// 	}
// 	return (0);
// }

void rectangle(int y1, int x1, int y2, int x2)
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

void	init_field(void)
{
	int i;
	int x;
	int y;

	rectangle(FIELD_OFFSET_Y - 1, FIELD_OFFSET_X - 2,
		FIELD_OFFSET_Y + (MEM_SIZE / FIELD_WIDTH * 3) + 1, FIELD_OFFSET_X + (FIELD_WIDTH));
	rectangle(INFO_OFFSET_Y - 1, INFO_OFFSET_X - 2,
		INFO_OFFSET_Y + (MEM_SIZE / FIELD_WIDTH * 3) + 1, INFO_OFFSET_X + (INFO_WIDTH));
	x = FIELD_OFFSET_X;
	y = FIELD_OFFSET_Y - 2;
	i = 0;
	while (i < FIELD_WIDTH / 3)
	{
		mvaddch(y, x++, '0' + (i / 10 % 10));
		mvaddch(y, x++, '0' + (i++ % 10));
		mvaddch(y, x++, ' ');
	}
	y += 2;
	i = 0;
	while (i < (MEM_SIZE / FIELD_WIDTH * 3) + 1)
	{	
		x = FIELD_OFFSET_X - 5;
		mvaddch(y, x++, '0' + (i / 10 % 10));
		mvaddch(y++, x, '0' + (i++ % 10));
	}
}

void	init_visualizer(void)
{
	initscr();
	cbreak();
	noecho();
	clear();
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_CYAN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(6, COLOR_GREEN, COLOR_BLACK);
	init_pair(7, COLOR_WHITE, COLOR_BLACK);
	init_field();
}

void	reset_visualizer(void)
{
	getch();
	endwin();
}

int		main(int ac, char **av)
{
	t_vm	vm;
	int		ret;

	ft_bzero(&vm, sizeof(t_vm));
	vm.ac = --ac;
	vm.av = ++av;
	// if (set_operations(&vm))
	// 	return (1);
	if (!(ret = handle_arguments(&vm, ac, av)))
	{
		if (vm.options & VM_OP_G)
			init_visualizer();
		vm.cycles = 1;
		vm.total_cycles = 1;
		vm.cycles_to_die = CYCLE_TO_DIE;
		if (!(ret = read_champions(&vm)))
		{
			run_vm(&vm);
			//print_results(vm);
		}
		//print_champion(&vm);
		if (vm.options & VM_OP_G)
			reset_visualizer();
	}
	del_vm(&vm);
	return (ret);
}

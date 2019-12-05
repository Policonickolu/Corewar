/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 09:24:30 by hben-yah          #+#    #+#             */
/*   Updated: 2019/12/05 11:48:09 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	get_processes_lives_and_number(t_vm *vm, int number, int *count, int *lives)
{

	t_process 	*ps;

	ps = vm->process;
	*count = 0;
	*lives = 0;
	while (ps)
	{
		if (ps->number == number)
		{
			++*count;
			*lives += ps->lives;
		}
		ps = ps->next;
	}
}

void	display_players(t_vm *vm)
{
	t_champ *champ;
	int i;
	int lives;
	int count;

	champ = vm->champ;
	i = 10;
	while (champ)
	{
		mvwaddch(vm->display.game, INFO_OFFSET_Y + i++, INFO_OFFSET_X + 1, ' ' | A_REVERSE | COLOR_PAIR(((champ->number - 1) % 7) + 1));
		wprintw(vm->display.game, " Joueur %d (%s)", champ->number, champ->header.prog_name);
		get_processes_lives_and_number(vm, champ->number, &count, &lives);
		mvwprintw(vm->display.game, INFO_OFFSET_Y + i++, INFO_OFFSET_X + 1, "    Processus %d", count);
		if (vm->lives)
			mvwprintw(vm->display.game, INFO_OFFSET_Y + i++, INFO_OFFSET_X + 1, "    Lives     %d (%3.0f %%)", lives, (double)lives / (double)vm->lives * 100);
		else
			mvwprintw(vm->display.game, INFO_OFFSET_Y + i++, INFO_OFFSET_X + 1, "    Lives     %d           ", lives);

		champ = champ->next;
		++i;
	}

}

void	display_infos(t_vm *vm)
{
	mvwprintw(vm->display.game, INFO_OFFSET_Y + 1, INFO_OFFSET_X + 1, "Vitesse       %8d", vm->display.speed);
	mvwprintw(vm->display.game, INFO_OFFSET_Y + 2, INFO_OFFSET_X + 1, "Cycles        %8d", vm->cycles);
	mvwprintw(vm->display.game, INFO_OFFSET_Y + 3, INFO_OFFSET_X + 1, "Cycles to die %8d", vm->cycles_to_die);
	mvwprintw(vm->display.game, INFO_OFFSET_Y + 4, INFO_OFFSET_X + 1, "Total Cycles  %8d", vm->total_cycles);
	mvwprintw(vm->display.game, INFO_OFFSET_Y + 5, INFO_OFFSET_X + 1, "Lives         %8d (%d pour dec. CTD)", vm->lives, NBR_LIVE);
	mvwprintw(vm->display.game, INFO_OFFSET_Y + 6, INFO_OFFSET_X + 1, "Verifications %8d (%d pour dec. CTD)", vm->checks, MAX_CHECKS);
	mvwprintw(vm->display.game, INFO_OFFSET_Y + 7, INFO_OFFSET_X + 1, "Processus     %8d", vm->n_process);
	if (vm->last_name)
		mvwprintw(vm->display.game, INFO_OFFSET_Y + 8, INFO_OFFSET_X + 1, "Dernier live      %s", vm->last_name);
	display_players(vm);
	wrefresh(vm->display.game);
}
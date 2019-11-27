/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_field.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 09:46:42 by hben-yah          #+#    #+#             */
/*   Updated: 2019/11/27 11:13:56 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int			match_pc(t_vm *vm, int i)
{
	t_process		*ps;

	ps = vm->process;
	while (ps)
	{
		if (i == ps->pc)
			return (ps->id);
		ps = ps->next;
	}
	return (0);
}

static void			print_line(t_vm *vm, char *bytes, int pane, int byte_width)
{
	int				j;
	int				k;
	int				ps_id;

	j = 0;
	ft_printf("%s%.8x  %s", B_BLUE, pane, RESET);
	while (j++ < byte_width)
	{
		k = 0;
		while (k++ < 8 && !(ps_id = 0) && ft_printf(BLUE))
		{
			if (pane >= MEM_SIZE)
				return ;
			if ((ps_id = match_pc(vm, pane)))
			{
				(ps_id == 1) ? ft_printf(B_RED) : 0;
				(ps_id == 2) ? ft_printf(B_GREEN) : 0;
				(ps_id == 3) ? ft_printf(B_CYAN) : 0;
				(ps_id == 4) ? ft_printf(B_YELLOW) : 0;
			}
			ft_printf("%.2x %s", (unsigned char)bytes[pane++], RESET);
		}
		ft_putchar(' ');
	}
	ft_putchar('\n');
}

static void			print_player_info(t_process *ps)
{
	ft_printf("Joueur %d (%s) ", ps->number, ps->name);
	ft_printf("%s ", (ps->live_calls) ? "déclaré vivant" : "manquant");
	ft_printf("et restera en sommeil pendant (cycles) %-20d\n", ps->sleep_cycles);
	ft_printf(RESET);
}

static void			print_cycle_info(t_vm *vm)
{
	t_process		*ps;
	int				player_num;

	player_num = 0;
	ft_printf("CYCLE NUMBER[%6d]   ", vm->total_cycle);
	ft_printf("CYCLE[%6d]   ", vm->cycle);
	ft_printf("CYCLE_TO_DIE[%6d]   ", vm->cycle_to_die);
	ft_printf("CHECKS[%6d]\n\n", vm->check);
	while (player_num++ < MAX_PLAYERS && (ps = vm->process))
	{
		while (ps)
		{
			if (ps->id == player_num)
			{
				(ps->id == 1) ? ft_printf(B_RED) : 0;
				(ps->id == 2) ? ft_printf(B_GREEN) : 0;
				(ps->id == 3) ? ft_printf(B_CYAN) : 0;
				(ps->id == 4) ? ft_printf(B_YELLOW) : 0;
				print_player_info(ps);
				break ;
			}
			ps = ps->next;
		}
	}
}

void				dump_memory(t_vm *vm, int byte_width, int exit_flag)
{
	char			*bytes;
	int				pane;

	bytes = vm->field;
	pane = 0;
	while (pane < MEM_SIZE)
	{
		print_line(vm, bytes, pane, byte_width);
		pane += (byte_width * 8);
	}
	if (exit_flag)
	{
		del_vm(vm);
		exit(0);
	}
	print_cycle_info(vm);
}

void		display_field(t_vm *vm)
{
	if (vm->dump == vm->total_cycle)
		dump_memory(vm, 4, 1);
	if (vm->options & VM_OP_D)
	{
		// if (!(vm->total_cycle % 20))
		// 	ft_printf(CLEAR);
		ft_printf(CUR_RESET);
		dump_memory(vm, 8, 0);
		usleep(10000);
	}
	//exit(0);
}

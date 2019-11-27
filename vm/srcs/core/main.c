/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 08:13:53 by hben-yah          #+#    #+#             */
/*   Updated: 2019/11/27 10:24:19 by hben-yah         ###   ########.fr       */
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
		vm.cycle = 1;
		vm.total_cycle = 1;
		vm.cycle_to_die = CYCLE_TO_DIE;
		if (!(ret = read_champions(&vm)))
		{
			run_vm(&vm);
			//print_results(vm);
		}
		//print_champion(&vm);
	}
	del_vm(&vm);
	return (ret);
}

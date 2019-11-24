/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 08:13:53 by hben-yah          #+#    #+#             */
/*   Updated: 2019/11/24 15:09:38 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "libft.h"

int		main(int ac, char **av)
{
	t_vm	vm;
	int		ret;

	ft_bzero(&vm, sizeof(t_vm));
	vm.ac = --ac;
	vm.av = ++av;
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

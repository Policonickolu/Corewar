/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 08:13:53 by hben-yah          #+#    #+#             */
/*   Updated: 2019/12/05 08:45:27 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "libft.h"

char	*g_base = "0123456789abcdef";

int		main(int ac, char **av)
{
	t_vm	vm;
	int		ret;

	ft_bzero(&vm, sizeof(t_vm));
	vm.ac = --ac;
	vm.av = ++av;
	if (!(ret = handle_arguments(&vm, ac, av)))
	{
		vm.cycles = 1;
		vm.total_cycles = 1;
		vm.cycles_to_die = CYCLE_TO_DIE;
		if (!(ret = read_champions(&vm)))
		{
			init_display(&vm);			
			run_vm(&vm);
			reset_display(&vm);
		}
	}
	del_vm(&vm);
	return (ret);
}

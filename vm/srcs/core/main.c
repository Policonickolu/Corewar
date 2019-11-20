/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 08:13:53 by hben-yah          #+#    #+#             */
/*   Updated: 2019/11/20 09:24:26 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		main(int ac, char **av)
{
	t_vm	vm;

	vm->ac = ac;
	vm->av = av;
	if (parse_options(&vm, ac, av))
		return (1);
	parse(&vm);
	run_vm(&vm);
	free_vm(&vm);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 09:14:14 by hben-yah          #+#    #+#             */
/*   Updated: 2019/12/03 11:04:40 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	put_dead_process(t_vm *vm, int number)
{
	wprintw(vm->out, "Le processus %d n'a plus donné signe de vie\n", number);
}

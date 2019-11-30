/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 15:20:11 by hben-yah          #+#    #+#             */
/*   Updated: 2019/11/30 15:32:11 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "libft.h"

t_process		*dup_process(t_vm *vm, t_process *src)
{
	t_process *new;

	if (!(new = (t_process*)malloc(sizeof(t_process))))
		vm_exit(vm, "malloc error: process dup");
	ft_memcpy(new, src, sizeof(t_process));
	return (new);
}

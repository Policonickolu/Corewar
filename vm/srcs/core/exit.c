/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 11:29:30 by hben-yah          #+#    #+#             */
/*   Updated: 2019/11/24 12:16:28 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "vm.h"
#include "libft.h"

void	vm_exit(t_vm *vm, char *mes)
{
	ft_putendl2(VM_NAME": ", mes);
	del_vm(vm);
	exit(1);
}
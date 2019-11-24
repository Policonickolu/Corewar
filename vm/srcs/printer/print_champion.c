/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_champion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 12:41:31 by hben-yah          #+#    #+#             */
/*   Updated: 2019/11/24 12:59:08 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "libft.h"

void		print_champion(t_vm *vm)
{
	t_champ *champ;

	champ = vm->champ;
	while (champ)
	{
		ft_putendl("---------------");
		ft_putendl2("file : ", champ->file);
		ft_putendl2("name : ", champ->header.prog_name);
		ft_putstrnbr("number : ", champ->number, "\n");
		ft_putstrnbr("magic : ", champ->header.magic, "\n");
		ft_putstrnbr("size : ", champ->header.prog_size, "\n");
		ft_putendl2("comment : ", champ->header.comment);
		ft_putendl2("program : ", (char *)champ->prog);
		ft_putendl("");
		champ = champ->next;
	}
}

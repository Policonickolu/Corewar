/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 09:05:49 by hben-yah          #+#    #+#             */
/*   Updated: 2019/11/27 11:35:23 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "vm.h"

void	del_process(t_process **process)
{
	t_process *todel;

	if (process && *process)
	{
		todel = *process;
		*process = (*process)->next;
		free(todel->file);
		free(todel);
	}
}

void	del_process_lst(t_process **lst)
{
	if (lst)
		while (*lst)
			del_process(lst);
}

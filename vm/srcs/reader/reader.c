/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 12:10:07 by hben-yah          #+#    #+#             */
/*   Updated: 2019/11/24 15:03:42 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "vm.h"
#include "libft.h"

int	check_magic(unsigned int magic)
{
	int				m;
	unsigned char 	*m1;
	unsigned char 	*m2;

	m = COREWAR_EXEC_MAGIC;
	m1 = (unsigned char*)&magic;
	m2 =  (unsigned char*)&m;

	return (!(m1[0] == m2[3]
			&& m1[1] == m2[2]
			&& m1[2] == m2[1]
			&& m1[3] == m2[0]));
}

int read_champion(t_champ *champ)
{
	int		fd;

	if ((fd = open(champ->file, O_RDONLY)) < 0)
		return (file_not_found_error());
	if (read(fd, &champ->header, sizeof(header_t))
		< (int)sizeof(header_t) || check_magic(champ->header.magic))
	{
		close(fd);
		return (invalid_file_error());
	}
	if (champ->header.prog_size < CHAMP_MAX_SIZE)
	{
		close(fd);
		return (champion_size_too_big());
	}
	if (read(fd, &champ->prog, champ->header.prog_size)
		< (int)champ->header.prog_size)
	{
		close(fd);
		return (invalid_file_error());
	}
	close(fd);
	return (0);
}

int read_champions(t_vm *vm)
{
	t_champ *champ;

	champ = vm->champ;
	while (champ)
	{
		if (read_champion(champ))
			return (1);
		champ = champ->next;
	}
	return (0);
}

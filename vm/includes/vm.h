/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 08:09:19 by hben-yah          #+#    #+#             */
/*   Updated: 2019/11/20 09:27:28 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include <stdlib.h>
# include "libft.h"

/*
** Defines
*/

# define VM_NAME		"corewar"

# define VM_OPTIONS		"h"
# define VM_OP_H		1

# define STR_EXPAND(tok) #tok
# define STR(tok) STR_EXPAND(tok)

/*
** Structures
*/

typedef struct			s_vm
{
	char				**argv;
	int					argc;

	int					options;

	//int					dump;
	//int					debug;

	int					aff;
	int					affd;
	int					affx;
	int					affx2;

	int					cycle;
	int					tot_cycle;
	int					cycle_to_die;
	
	int					checkups;
	
	int					live_calls;
	int					last_live;
	
	char				*last_name;

	char				field[MEM_SIZE];
	
	t_name				*name;

	t_champ				*champ;
	t_process			*process;
	
	t_ps_op				*ops_queue;
}						t_vm;

/*
** Prototypes
*/

# include "prototypes.h"

#endif

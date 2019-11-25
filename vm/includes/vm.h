/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 08:09:19 by hben-yah          #+#    #+#             */
/*   Updated: 2019/11/25 17:20:24 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

#include <stdlib.h>
# include "op.h"
# include "libft.h"

/*
** Defines
*/

# define VM_NAME				"Corewar"

# define VM_OPTIONS				"h"
# define VM_OP_H				1

# define STR_EXPAND(tok) #tok
# define STR(tok) STR_EXPAND(tok)

# define CW_HASHTAB_SIZE		64

/*
** Structures
*/

typedef struct			s_champ
{
	int				number;
	char			*file;

	header_t		header;
	unsigned char	prog[CHAMP_MAX_SIZE];

	struct s_champ	*next;
}						t_champ;

typedef struct			s_process
{
	int					id;
	char				*name;
	int					number;

	unsigned char		regs[REG_NUMBER * REG_SIZE];
	int					pc;
	int					pc_tmp;
	char				carry;


	int					live_calls;
	int					sleep_cycles;

	void				(*op)();

	struct s_process	*next;
}						t_process;


typedef struct			s_vm
{
	char				**av;
	int					ac;

	int					options;
	int					dump;
	//int				debug;

	// int					aff;
	// int					affd;
	// int					affx;
	// int					affx2;

	int					cycle;
	int					total_cycle;
	int					cycle_to_die;
	int					check;
	
	int					live_calls;
	int					last_live;
	
	char				*last_name;

	char				field[MEM_SIZE];
	
	//t_name				*name;

	int					n_champ;
	t_champ				*champ;

	int					n_process;
	t_process			*process;
	
	t_hashtab			*operations;

	//t_ps_op				*ops_queue;
}						t_vm;

typedef struct			s_op
{
	char				*name;
	int					params_quantity;
	int					param_type[4];
	int					op_code;
	int					nb_cycles;
	char				*description;
	int					has_pcode;
	int					has_idx;
}						t_op;

extern t_op				op_tab[17];

typedef void			(*t_operation_code)(t_vm *vm, t_process *ps);

/*
** Prototypes
*/

# include "prototypes.h"

#endif

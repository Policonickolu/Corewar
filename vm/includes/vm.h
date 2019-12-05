/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 08:09:19 by hben-yah          #+#    #+#             */
/*   Updated: 2019/12/05 09:16:34 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include <stdlib.h>
# include <stdint.h>
# include <curses.h>
# include "op.h"
# include "libft.h"

/*
** Defines
*/

# define VM_NAME				"Corewar"

# define VM_OPTIONS				"hdavc"
# define VM_OP_H				1	// helper
# define VM_OP_D				2	// debug
# define VM_OP_A				4	// aff
# define VM_OP_V				8	// verbose
# define VM_OP_C				16	// visu ncurse

# define STR_EXPAND(tok) #tok
# define STR(tok) STR_EXPAND(tok)

# define CW_HASHTAB_SIZE		64

/*
** Display
*/

# define FIELD_WIDTH		192
# define FIELD_OFFSET_X		5
# define FIELD_OFFSET_Y		5

# define INFO_WIDTH			50
# define INFO_OFFSET_X		FIELD_OFFSET_X + FIELD_WIDTH + 2
# define INFO_OFFSET_Y		5

# define W_GAME_WIDTH		251


/*
** Colors
*/

# define SIZE_OF_BUFF	64
# define CLEAR			"\x1b[H\x1b[2J"
# define CUR_RESET		"\x1b[H\x1b[?25l"
# define SHOW_CURSOR	"\x1b[?12;25h"
# define B_RED			"\x1b[1m\x1b[31m"
# define B_GREEN		"\x1b[1m\x1b[32m"
# define B_YELLOW		"\x1b[1m\x1b[33m"
# define B_BLUE			"\x1b[1m\x1b[34m"
# define B_PINK			"\x1b[1m\x1b[35m"
# define B_CYAN    		"\x1b[1m\x1b[36m"
# define B_WHITE   		"\x1b[1m\x1b[37m"
# define RED			"\x1b[31m"
# define GREEN			"\x1b[32m"
# define YELLOW			"\x1b[33m"
# define BLUE			"\x1b[34m"
# define PINK			"\x1b[35m"
# define CYAN    		"\x1b[36m"
# define WHITE   		"\x1b[37m"
# define RESET   		"\x1b[0m"


/*
** Structures
*/

typedef struct			s_op
{
	char				*name;
	int					params_quantity;
	int					param_type[4];
	int					op_code;
	int					nb_cycles;
	char				*description;
	int					has_ocp;
	int					has_idx;
}						t_op;

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
	int					number;
	char				*name;

	intmax_t			registers[REG_NUMBER];
	int					pc; // program counter
	int					oc; // operation counter
	char				carry;


	int					lives;
	int					sleep;

	t_op				*op;

	struct s_process	*next;
}						t_process;

typedef struct			s_display
{
	int					height;
	int					width;
	int					speed;
	WINDOW				*game;
	WINDOW				*out;
}						t_display;


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

	int					cycles;
	int					total_cycles;
	int					cycles_to_die;
	int					checks;
	
	int					lives;
	int					last_live;
	char				*last_name;

	char				field[MEM_SIZE];
	
	//t_name				*name;

	int					n_champ;
	t_champ				*champ;

	int					n_process;
	t_process			*process;
	
	//t_hashtab			*operations;

	//t_ps_op			*ops_queue;
	t_display			display;
}						t_vm;

extern t_op				op_tab[17];
extern void				(*g_op_func_tab[17])(t_vm *, t_process *);
extern char				*g_base;

typedef void			(*t_operation_code)(t_vm *vm, t_process *ps);

/*
** Prototypes
*/

# include "prototypes.h"

#endif

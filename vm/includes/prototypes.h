/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 11:34:46 by hben-yah          #+#    #+#             */
/*   Updated: 2019/12/05 11:34:46 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

/*
** Prototypes
*/


int				check_champion_number(t_vm *vm, int number);
int				parse_champion(t_vm *vm, int number, char *file);
void			champ_lst_rev(t_champ **alst);
int				check_vm(t_vm *vm);
int				handle_arguments(t_vm *vm, int ac, char **av);
int				parse_options(int *options, char *arg);
int				parse_arguments(t_vm *vm, int ac, char **av);
void			check_processes(t_vm *vm);
t_op			*get_op_func_from_tab(int op_code);
void			set_op_function(t_vm *vm, t_process *ps, int op_code);
void			exec_operation(t_vm *vm, t_process *process);
void			set_next_operation(t_vm *vm, t_process *process);
void			exec_processes(t_vm *vm);
void			vm_exit(t_vm *vm, char *mes);
void			init_process(t_vm *vm, t_champ *champ, size_t pc);
void			init_processes(t_vm *vm);
int				main(int ac, char **av);
void			run_vm(t_vm *vm);
void			del_champ(t_champ **champ);
void			del_champ_lst(t_champ **lst);
void			del_process(t_process **process);
void			del_process_lst(t_process **lst);
void			del_vm(t_vm *vm);
void			get_processes_lives_and_number(t_vm *vm, int number, int *count, int *lives);
void			display_players(t_vm *vm);
void			display_infos(t_vm *vm);
void			display_boxes(t_vm *vm);
void			display_numbers(t_vm *vm);
void			init_display(t_vm *vm);
void			put_dead_process(t_vm *vm, int number);
void			display_programs(t_vm *vm, t_champ *champ, int pc);
void			reset_display(t_vm *vm);
void			write_val(t_vm *vm, int addr, int number, int rev);
int				no_champion_error(void);
int				too_many_champions_error(void);
int				missing_champion_error(void);
int				champion_size_too_big(void);
int				dump_arg_error(void);
int				file_not_found_error(void);
int				invalid_file_error(void);
int				invalid_option_error(char arg);
int				already_attributed_number_error(void);
int				n_arg_error(void);
t_process			*dup_process(t_vm *vm, t_process *src);
t_champ			*get_champ(t_vm *vm, int number);
int				get_param_type(unsigned char ocp, int param);
intmax_t			get_reg_val(t_process *ps, int reg);
int				get_rel_address(t_process *ps, int move);
int				get_type_size(int type);
void			insert_process(t_vm *vm, t_process *new);
void			move_oc(t_process *ps, int val);
void			move_pc(t_vm *vm, t_process *ps, int val);
void			move_pc_past_oc(t_vm *vm, t_process *ps);
intmax_t			read_field(t_vm *vm, t_process *ps, size_t size);
intmax_t			read_field_at(t_vm *vm, t_process *ps, intmax_t i, size_t size);
void			set_carry(t_process *ps, intmax_t value);
void			set_reg_val(t_process *ps, int reg, intmax_t val);
void			write_field_at(t_vm *vm, t_process *ps, intmax_t i, intmax_t val);
void			operate_add(t_vm *vm, t_process *ps);
void			operate_aff(t_vm *vm, t_process *ps);
void			operate_and(t_vm *vm, t_process *ps);
void			operate_fork(t_vm *vm, t_process *ps);
void			operate_ld(t_vm *vm, t_process *ps);
void			operate_ldi(t_vm *vm, t_process *ps);
void			operate_lfork(t_vm *vm, t_process *ps);
void			operate_live(t_vm *vm, t_process *ps);
void			operate_lld(t_vm *vm, t_process *ps);
void			operate_lldi(t_vm *vm, t_process *ps);
void			operate_or(t_vm *vm, t_process *ps);
void			operate_st(t_vm *vm, t_process *ps);
void			operate_sti(t_vm *vm, t_process *ps);
void			operate_sub(t_vm *vm, t_process *ps);
void			operate_xor(t_vm *vm, t_process *ps);
void			operate_zjmp(t_vm *vm, t_process *ps);
void			dump_memory(t_vm *vm, int byte_width, int exit_flag);
void			display_field(t_vm *vm);
void			print_champion(t_vm *vm);
int				put_usage(void);
int				check_numbers(header_t *header);
int		read_champion(t_champ *champ);
int		read_champions(t_vm *vm);

#endif

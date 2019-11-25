/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 17:45:34 by hben-yah          #+#    #+#             */
/*   Updated: 2019/11/25 17:45:34 by hben-yah         ###   ########.fr       */
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
void			vm_exit(t_vm *vm, char *mes);
void			init_process(t_vm *vm, t_champ *champ, size_t pc);
void			init_processes(t_vm *vm);
int				set_operations(t_vm *vm);
int				main(int ac, char **av);
void			save_op(t_vm *vm, t_process *ps, int op_code);
void			exec_operation(t_vm *vm, t_process *process);
void			get_next_operation(t_vm *vm, t_process *process);
void			exec_processes(t_vm *vm);
void			run_vm(t_vm *vm);
void			del_champ(t_champ **champ);
void			del_champ_lst(t_champ **lst);
void			del_vm(t_vm *vm);
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
int				get_new_address(t_process *ps, int modify);
void			get_reg(t_process *ps, int reg, void *val, size_t size);
void			move_pc(t_process *ps, int val);
void			set_reg(t_process *ps, int reg, void *val, size_t size);
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
void			print_champion(t_vm *vm);
int				put_usage(void);
int				check_numbers(header_t *header);
int	 read_champion(t_champ *champ);
int	 read_champions(t_vm *vm);

#endif

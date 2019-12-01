# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/01 15:24:07 by hben-yah          #+#    #+#              #
#    Updated: 2019/12/01 15:24:07 by hben-yah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	corewar

COMP			=	clang
FLAG			=	-Wall -Wextra -Werror
FLAGDEV         =   -g3

# Sources paths
FILES_C			=   \
					arguments/champion.c \
					arguments/handler.c \
					arguments/options.c \
					arguments/parser.c \
					core/check_processes.c \
					core/exec_processes.c \
					core/exit.c \
					core/init_processes.c \
					core/main.c \
					core/run.c \
					del/del_champ.c \
					del/del_process.c \
					del/del_vm.c \
					error/champions_error.c \
					error/dump_arg_error.c \
					error/file_not_found_error.c \
					error/invalid_file_error.c \
					error/invalid_option_error.c \
					error/number_error.c \
					helpers/dup_process.c \
					helpers/get_champ.c \
					helpers/get_param_type.c \
					helpers/get_reg_val.c \
					helpers/get_rel_address.c \
					helpers/get_type_size.c \
					helpers/insert_process.c \
					helpers/move_oc.c \
					helpers/move_pc.c \
					helpers/move_pc_past_oc.c \
					helpers/read_field.c \
					helpers/read_field_at.c \
					helpers/set_carry.c \
					helpers/set_reg_val.c \
					helpers/write_field_at.c \
					operations/add.c \
					operations/aff.c \
					operations/and.c \
					operations/fork.c \
					operations/ld.c \
					operations/ldi.c \
					operations/lfork.c \
					operations/live.c \
					operations/lld.c \
					operations/lldi.c \
					operations/op.c \
					operations/or.c \
					operations/st.c \
					operations/sti.c \
					operations/sub.c \
					operations/xor.c \
					operations/zjmp.c \
					printer/display_field.c \
					printer/print_champion.c \
					printer/usage.c \
					printer/visualizer.c \
					reader/reader.c
FILES_O			=	$(FILES_C:.c=.o)
FILES_H			=	\
					prototypes.h \
					vm.h

#Directories
SRCS_SD			= 	\
					arguments \
					core \
					del \
					error \
					helpers \
					operations \
					printer \
					reader
SRCS_D			=	./srcs/
OBJS_D			=   ./objs/
INCL_D 			=	./includes/

# Paths
SRCS			= 	$(addprefix $(SRCS_D), $(FILES_C))
OBJS			=	$(addprefix $(OBJS_D), $(FILES_O))
INCL			=	$(addprefix $(INCL_D), $(FILES_H))

# Libft
LFT_D			=	../libft/
LFT_P			=	$(addprefix $(LFT_D), libft.a)
LFT_I			=	../libft/includes/
LFT_L			=	../libft
LFT_H			=	\
					ft_defines.h \
					ft_printf.h \
					ft_prototypes.h \
					ft_structs.h \
					libft.h


# Ncurses
CUR				=	-lncurses

# Op
OP_D			=	../op

# Rules

all				:	$(NAME)

dev				:	debug $(NAME)


$(NAME)			:	$(LFT_P) $(OBJS)
					@echo "\nAssemblage et création de l'exécutable $(NAME)"
					@$(COMP) $(FLAG) $(OBJS) $(LFT_P) $(CUR) -o $(NAME)
					@echo "Terminé"

$(LFT_P)		:	force
					@echo "Vérification de la librairie Libft"
					@make -C $(LFT_D)

$(OBJS_D)%.o	:	$(SRCS_D)%.c $(addprefix $(LFT_I), $(LFT_H)) $(INCL)
					@echo -e "\033[2K\c"
					@echo "\rCréation de l'objet $@\c"
					@mkdir -p $(addprefix $(OBJS_D), $(SRCS_SD))
					@$(COMP) $(FLAG) -I $(LFT_I) -I $(INCL_D) -I $(OP_D) -o $@ -c $<

clean			:
					@make -C $(LFT_D) clean
					@echo "Nettoyage des objets $(OBJS_D)"
					@rm -rf $(OBJS_D)

fclean			:
					@make -C $(LFT_D) fclean
					@echo "Nettoyage des objets $(OBJS_D)"
					@rm -rf $(OBJS_D)
					@echo "Nettoyage de l'exécutable $(NAME)"
					@rm -f $(NAME)

re				:	fclean all

debug			:	force
					@$(eval FLAG = $(FLAG) $(FLAGDEV))

force			:
					@true

.PHONY			:	all clean fclean re force debug dev

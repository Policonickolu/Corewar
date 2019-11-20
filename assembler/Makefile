# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/20 15:37:51 by hben-yah          #+#    #+#              #
#    Updated: 2019/07/20 15:37:51 by hben-yah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	lem-in

COMP			=	clang
FLAG			=	-Wall -Wextra -Werror
FLAGDEV         =   -g3

# Sources paths
FILES_C			=   \
					boolean.c \
					checker.c \
					command.c \
					distance.c \
					error.c \
					graph.c \
					lemin.c \
					options.c \
					parser.c \
					pathfinder.c \
					reset.c \
					room.c \
					solver.c \
					steps.c \
					walk.c
FILES_O			=	$(FILES_C:.c=.o)
FILES_H			=	\
					lemin.h \
					prototypes.h
SRCS_D			=	./srcs/
OBJS_D			=   ./objs/
INCL_D 			=	./includes/

# Paths
SRCS			= 	$(addprefix $(SRCS_D), $(FILES_C))
OBJS			=	$(addprefix $(OBJS_D), $(FILES_O))
INCL			=	$(addprefix $(INCL_D), $(FILES_H))

# Libft
LFT_D			=	./libft/
LFT_P			=	$(addprefix $(LFT_D), libft.a)
LFT_I			=	./libft/includes/
LFT_L			=	./libft
LFT_H			=	\
					ft_defines.h \
					ft_printf.h \
					ft_prototypes.h \
					ft_structs.h \
					libft.h


# Rules

all				:	$(NAME)

dev				:	debug $(NAME)

redev			:	fclean debug $(NAME)

$(NAME)			:	$(LFT_P) $(OBJS)
					@echo "\nAssemblage et création de l'exécutable $(NAME)"
					@$(COMP) $(FLAG) $(OBJS) $(LFT_P) -o $(NAME)
					@echo "Terminé"

$(LFT_P)		:	force
					@echo "Vérification de la librairie Libft"
					@make -C $(LFT_D)

$(OBJS_D)%.o	:	$(SRCS_D)%.c $(addprefix $(LFT_I), $(LFT_H)) $(INCL)
					@echo -e "\033[2K\c"
					@echo "\rCréation de l'objet $@\c"
					@mkdir -p $(OBJS_D)
					@$(COMP) $(FLAG) -I $(LFT_I) -I $(INCL_D) -o $@ -c $<

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

.PHONY			:	all clean fclean re force debug dev redev

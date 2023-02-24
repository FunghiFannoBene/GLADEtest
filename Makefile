# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shhuang <shhuang@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/17 01:45:36 by shhuang           #+#    #+#              #
#    Updated: 2023/01/17 02:17:17 by shhuang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= get_next_line.a

bonus	= get_next_line.c\
get_next_line_utils.c\

BONUS	= $(bonus:.c=.o)

CC	= clang

RM	= rm -f

CFLAGS	= -Wall -Wextra -Werror -D BUFFER_SIZE=10000

all:	$(NAME)

$(NAME):	$(BONUS)
			ar rcs $(NAME) $(BONUS)

bonus:
$(NAME):	$(BONUS)
		ar rcs $(NAME) $(BONUS)

clean:
			$(RM) $(BONUS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
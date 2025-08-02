CC = cc
CFLAGS = -Wall -Wextra -Werror -MMD -MP -I./include

OBJ_DIR = ./obj
SRC_DIR = ./srcs
HEADER_DIR = ./include

SRC =									\
	$(SRC_DIR)/check_args.c				\
	$(SRC_DIR)/clean_data.c				\
	$(SRC_DIR)/ft_atoi.c				\
	$(SRC_DIR)/init_philo.c				\
	$(SRC_DIR)/monitor_routine.c		\
	$(SRC_DIR)/monitor_thread.c			\
	$(SRC_DIR)/philo_actions.c			\
	$(SRC_DIR)/philo_routine.c			\
	$(SRC_DIR)/philo_threads.c			\
	$(SRC_DIR)/philo.c					\
	$(SRC_DIR)/printf_mutex.c			\
	$(SRC_DIR)/stop_simulation.c		\
	$(SRC_DIR)/time.c					\

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
DEP = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.d)

NAME = philo

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c Makefile
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

-include $(DEP)

clean:
	rm -rf $(OBJ_DIR)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re

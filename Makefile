# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: hyilmaz <hyilmaz@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2022/04/07 13:15:46 by hyilmaz       #+#    #+#                  #
#    Updated: 2022/04/07 14:05:55 by hyilmaz       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# Compilation configuration parameters
CC = gcc
CFLAGS = -Wall -Wextra -Werror
CRITERION_INCLUDE_PATH = /Users/hyilmaz/.brew/include


# Unit test files
TEST_FILES = 	test/test_utils.c \
				philo/utils/ft_isdigit.c \
				philo/utils/ft_isspace.c \
				philo/utils/skip_chr_func_pointer.c \
				philo/utils/skip_chr.c \
				philo/utils/skip_plus_and_minus_signs.c \
				philo/utils/atoi_with_int_overflow_check.c \
				test/test_input_validation.c \
				philo/input_validation.c

# Test object files
TEST_OBJ_DIR = test_obj
TEST_OBJ_FILES = $(TEST_FILES:%.c=$(TEST_OBJ_DIR)/%.o)

# Program names
TEST_NAME = test_philo

# SRC_DIR = philo
# SRC = input_validation.c
# OBJ = $(SRC:%.c=$(SRC_DIR)/%.o)

# Test build
test: $(TEST_OBJ_DIR) $(TEST_NAME)

test_run: test
	@./$(TEST_NAME)

$(TEST_OBJ_DIR):
	mkdir -p $@

$(TEST_NAME): $(TEST_OBJ_FILES)
	$(CC) $(CFLAGS) -I$(CRITERION_INCLUDE_PATH) -lcriterion $^ -o $@

$(TEST_OBJ_FILES): $(TEST_OBJ_DIR)/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(TEST_OBJ_DIR)

fclean: clean
	rm -rf $(TEST_NAME)

.PHONY: test test_run clean fclean
	
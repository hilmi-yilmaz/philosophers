# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: hyilmaz <hyilmaz@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2022/04/07 13:15:46 by hyilmaz       #+#    #+#                  #
#    Updated: 2022/08/10 16:07:09 by hyilmaz       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

# Compilation configuration parameters
CC = gcc
CFLAGS = -Wall -Wextra -Werror -pthread -fsanitize=thread -g
# CRITERION_INCLUDE_PATH = /Users/hyilmaz/.brew/include
CRITERION_INCLUDE_PATH = /opt/homebrew/Cellar/criterion/2.4.1/include
CRITERION_LIB_PATH= /opt/homebrew/Cellar/criterion/2.4.1/lib


# Header files
HEADER_FILES = 	src/input_validation.h \
				src/set_data.h \
				src/mutexes.h \
				src/timing.h \
				src/utils/utils.h

# Source files
SRC_FILES = src/main.c \
			src/input_validation.c \
			src/set_data.c \
			src/mutexes.c \
			src/timing.c \
			src/utils/ft_isdigit.c \
			src/utils/ft_isspace.c \
			src/utils/skip_chr_func_pointer.c \
			src/utils/skip_chr.c \
			src/utils/skip_plus_and_minus_signs.c \
			src/utils/atoi_with_int_overflow_check.c \
			src/utils/ft_bzero.c \
			src/utils/ft_memset.c \
			src/utils/ft_calloc.c


# Unit test files
TEST_FILES = 	test/test_utils.c \
				src/utils/ft_isdigit.c \
				src/utils/ft_isspace.c \
				src/utils/skip_chr_func_pointer.c \
				src/utils/skip_chr.c \
				src/utils/skip_plus_and_minus_signs.c \
				src/utils/atoi_with_int_overflow_check.c \
				src/utils/ft_bzero.c \
				src/utils/ft_memset.c \
				src/utils/ft_calloc.c \
				test/test_input_validation.c \
				src/input_validation.c \
				test/test_set_data.c \
				src/set_data.c \
				test/test_timing.c \
				test/test_add_timeval.c \
				src/timing.c


# Release object files
RELEASE_OBJ_DIR = release_obj
RELEASE_OBJ_FILES = $(SRC_FILES:%.c=$(RELEASE_OBJ_DIR)/%.o)

# Test object files
TEST_OBJ_DIR = test_obj
TEST_OBJ_FILES = $(TEST_FILES:%.c=$(TEST_OBJ_DIR)/%.o)

# Program names
NAME = philo
TEST_NAME = test_philo

# Default (release) build
all: $(RELEASE_OBJ_DIR) $(NAME)

run: all
	@./$(NAME) 4 60 20 20 4

$(RELEASE_OBJ_DIR):
	mkdir -p $@

$(NAME): $(RELEASE_OBJ_FILES)
	$(CC) $(CFLAGS) $^ -o $@

$(RELEASE_OBJ_FILES): $(RELEASE_OBJ_DIR)/%.o : %.c $(HEADER_FILES)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

# Test build
test: $(TEST_OBJ_DIR) $(TEST_NAME)

test_run: test
	@./$(TEST_NAME)

$(TEST_OBJ_DIR):
	mkdir -p $@

$(TEST_NAME): $(TEST_OBJ_FILES)
	$(CC) $(CFLAGS) -I$(CRITERION_INCLUDE_PATH) -L$(CRITERION_LIB_PATH) -lcriterion $^ -o $@

$(TEST_OBJ_FILES): $(TEST_OBJ_DIR)/%.o: %.c $(HEADER_FILES)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(CRITERION_INCLUDE_PATH) -c $< -o $@

clean:
	rm -rf $(TEST_OBJ_DIR) $(RELEASE_OBJ_DIR)

fclean: clean
	rm -rf $(NAME) $(TEST_NAME)

.PHONY: test test_run clean fclean
	
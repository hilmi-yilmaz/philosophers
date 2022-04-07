/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_utils.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 12:57:58 by hyilmaz       #+#    #+#                 */
/*   Updated: 2022/04/07 14:01:47 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_UTILS_H
# define TEST_UTILS_H

/* System headers */
# include <stdarg.h>
# include <stdlib.h>
# include <string.h>

/* User defined headers */

/* Function prototypes */
char	**create_argv(int amount_arguments, ...);
void	free_argv(char **argv);

#endif
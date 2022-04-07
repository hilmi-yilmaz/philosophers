/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 13:38:37 by hyilmaz       #+#    #+#                 */
/*   Updated: 2022/04/07 13:53:11 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

/* System headers */
# include <stdbool.h>
# include <limits.h>
# include <stdlib.h>

/* User defined header */

/* Macros */
# define SUCCES 0
# define FAILURE 1

/* Data structures */
typedef struct s_atoi
{
	int	result;
	int	minus;
	int	*err;
}				t_atoi;

/* Function prototypes */
int		ft_isspace(int c);
bool	ft_isdigit(int c);
int		skip_chr(char *str, int c);
int		skip_chr_func_pointer(char *str, int (func)(int));
int		skip_plus_and_minus_signs(const char *num_str, int *minus, int *err);
int		atoi_with_int_overflow_check(const char *num_str, int *err);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 13:38:37 by hyilmaz       #+#    #+#                 */
/*   Updated: 2022/04/11 13:22:10 by hyilmaz       ########   odam.nl         */
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

typedef struct s_dclist
{
	void			*content;
	bool			is_last;
	struct s_dclist	*next;
	struct s_dclist	*previous;
}				t_dclist;

/* Function prototypes */
int			ft_isspace(int c);
bool		ft_isdigit(int c);
int			skip_chr(char *str, int c);
int			skip_chr_func_pointer(char *str, int (func)(int));
int			skip_plus_and_minus_signs(const char *num_str, int *minus, int *err);
int			atoi_with_int_overflow_check(const char *num_str, int *err);
void		*ft_calloc(size_t count, size_t size);
void		*ft_memset(void *s, int c, size_t n);
void		ft_bzero(void *s, size_t n);
t_dclist 	*create_dc_list(void *content);
void		dc_list_add_back(t_dclist **dclist, t_dclist *new_element);
void		delete_element(t_dclist *dclist, void (*del)(void *));
void		clear_entire_list(t_dclist **dclist, void (*del)(void *));

#endif
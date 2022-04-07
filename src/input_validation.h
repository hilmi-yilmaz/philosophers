/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_validation.h                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/06 16:45:55 by hyilmaz       #+#    #+#                 */
/*   Updated: 2022/04/07 15:47:13 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_VALIDATION_H
# define INPUT_VALIDATION_H

/* System headers */
# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>

/* User defined headers */
# include "utils/utils.h"

/* Function prototypes */
bool	validate_input(int argc, char *argv[]);

#endif
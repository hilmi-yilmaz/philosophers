/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/06 16:38:47 by hyilmaz       #+#    #+#                 */
/*   Updated: 2022/04/11 12:18:16 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* System headers */
#include <stdio.h>
#include <string.h>

/* User defined headers */
#include "input_validation.h"
#include "set_data.h"
#include "data_structs.h"
#include "utils/utils.h"

int	main(int argc, char *argv[])
{
	t_data	data;
	
	if (!validate_input(argc, argv + 1))
		return (1);
	ft_memset(&data, 0, sizeof(t_data));
	set_data(argv + 1, &data);
	return (0);
}
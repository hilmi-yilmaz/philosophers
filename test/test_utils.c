/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_utils.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 12:57:36 by hyilmaz       #+#    #+#                 */
/*   Updated: 2022/04/07 13:36:31 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "test_utils.h"

char	**create_argv(int amount_arguments, ...)
{
	int				i;
	char			**argv;
	char			*tmp;
	unsigned int	len;
	va_list			args;
	
	i = 0;
	argv = calloc(amount_arguments + 1, sizeof(*argv));
	va_start(args, amount_arguments);
	while (i < amount_arguments)
	{
		tmp = va_arg(args, char *);
		len = strlen(tmp);
		argv[i] = calloc(len + 1, sizeof(*argv[i]));
		memcpy(argv[i], tmp, len + 1);
		i++;
	}
	va_end(args);
	return (argv);
}

void	free_argv(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}
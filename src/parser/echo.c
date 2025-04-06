/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 13:58:23 by lkhoury           #+#    #+#             */
/*   Updated: 2025/04/06 20:48:19 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// void    echo(char *argv)
// {
//     ft_putstr_fd(argv, 1);
//     if (argv && ft_strcmp(argv, "-n") == 1)
//         printf("\n");
// }

int	check_n_option(const char *arg)
{
	int i = 0;

	if (!arg || arg[i] != '-' || arg[i + 1] != 'n')
		return (0);
	i += 2;
	while (arg[i])
	{
		if (arg[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

void	echo(t_tree_node *echo_node)
{
	t_tree_node *arg = echo_node->right;
	int newline = 0;
	int printed = 0;

	while (arg && arg->token == WORD && check_n_option(arg->data))
	{
		newline = 1;
		arg = arg->right;
	}
	while (arg && arg->token == WORD)
	{
		printf("%s", arg->data);
		printed = 1;
		if (arg->right && arg->right->token == WORD)
			printf(" ");
		arg = arg->right;
	}
	if (!newline || !printed)
		printf("\n");
}


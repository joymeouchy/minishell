/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeouchy <jmeouchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:46:19 by lkhoury           #+#    #+#             */
/*   Updated: 2025/01/23 13:08:24 by jmeouchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

char	*command_line_input(void)
{
	char	*input;

	input = readline("Minishell$ ");
	return (input);
}

int	main(void)
{
	t_list	*list;

	while (1)
	{
		list = input_to_list(command_line_input());
		print_list(list);
		if (list)
		{
			if (check_and_remove_quotes(list) == 1)
			{
				free(list);
				continue ;
			}
			else
			{
				printf("after removing quotes\n");
				print_list(list);
			}
		}
		if (list)
			free_list(list);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeouchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:46:19 by lkhoury           #+#    #+#             */
/*   Updated: 2025/02/08 20:15:32 by jmeouchy         ###   ########.fr       */
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
		if (!list || !list->head)
			continue;
		print_list(list);
		printf("\n\n");
		printf("size of the list %d\n",list->list_size);
		expand_list(list);
		// printf("\nafter expand\n");
		// print_list(list);
		check_and_remove_quotes(list);
		// printf("\nafter quotes\n");
		// print_list(list);
		shunting_yard(list);
		if (list)
			free_list(list);
	}
	return (0);
}

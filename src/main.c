/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeouchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:46:19 by lkhoury           #+#    #+#             */
/*   Updated: 2025/02/17 13:31:21 by jmeouchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

char	*command_line_input(void)
{
	char	*input;

	input = readline("Minishell$ ");
	return (input);
}

int	main(int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	t_list	*list;
	t_envp *env;
	t_stack *stack;
	
	env = get_split_path(envp);
	while (1)
	{
		list = input_to_list(command_line_input());
		if (!list || !list->head)
			continue;;
		print_list(list);
		// printf("\n");
		expand_list(list);
		// // printf("\nafter expand\n");
		// // print_list(list);
		// // printf("\n");
		check_and_remove_quotes(list);
		// // printf("\nafter quotes\n");
		// // print_list(list);
		tokenize(list, env);
		stack = shunting_yard(list);
		print_stack(stack);
		if (list)
			free_list(list);
		// if (stack)
		// 	free_stack(stack);
	}
	free(env);
	return (0);
}

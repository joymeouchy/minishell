/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeouchy <jmeouchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:46:19 by lkhoury           #+#    #+#             */
/*   Updated: 2025/04/24 10:01:54 by jmeouchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*command_line_input(void)
{
	char	*input;

	input = readline("Minishell$ ");
	if (input && *input)
		add_history(input);
	return (input);
}

void	parsing_main(t_envp *env)
{
	t_list	*list;
	t_stack *stack;
	t_tree *tree;

	list = input_to_list(command_line_input());
	if (!list)
	{
		write(1, "exit", 5);
		exit(1);
	}
	if (!list->head)
		return ;
	expand_list(list);
	// printf("\nafter expand\n");
	// print_list(list);
	// printf("\n");
	check_and_remove_quotes(list);
	tokenize(list, env);
	// printf("\nafter tokenization\n");
	// print_list(list);
	stack = shunting_yard(list);
	print_stack(stack);
	// env_getter(envp);
	// printf("\n\n\n\n");
	tree = stack_to_tree(stack);
	// export();
	// unset(tree);
	// printf("\n\n\n\n");
	printf("tree:\n");
	print_inorder(tree->root);
	// // printf("testing echo:\n");
	// // echo(tree->root);
	if (list)
		free_list(list);
	if (stack)
		free_stack(stack);
}

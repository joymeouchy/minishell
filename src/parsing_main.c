/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeouchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:46:19 by lkhoury           #+#    #+#             */
/*   Updated: 2025/04/19 01:02:56 by jmeouchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

// int exit_status;

// char	*command_line_input(void)
// {
// 	char	*input;

// 	input = readline("Minishell$ ");
// 	if (input && *input)
// 		add_history(input);
// 	return (input);
// }

// int	main(int argc, char **argv, char **envp)
// {
// 	(void)argc;
// 	(void)argv;
// 	t_list	*list;
// 	t_envp *env;
// 	t_stack *stack;
// 	t_tree *tree;
	
// 	env = get_split_path(envp);
// 	while (1)
// 	{
// 		list = input_to_list(command_line_input());
// 		if (!list || !list->head)
// 			continue;;
// 		// print_list(list);
// 		// printf("\n");
// 		expand_list(list);
// 		// printf("\nafter expand\n");
// 		// print_list(list);
// 		// printf("\n");
// 		check_and_remove_quotes(list);
// 		// printf("\nafter quotes\n");
// 		// print_list(list);
// 		tokenize(list, env);
// 		stack = shunting_yard(list);
// 		print_stack(stack);
// 		// env_getter(envp);
// 		printf("\n\n\n\n");
// 		tree = stack_to_tree(stack);
// 		// export();
// 		printf("tree:\n");
// 		print_inorder(tree->root);
// 		// printf("testing echo:\n");
// 		// echo(tree->root);
// 		if (list)
// 			free_list(list);
// 		if (stack)
// 			free_stack(stack);
// 	}
// 	free(env);
// 	return (0);
// }
#include <errno.h>
void myhandler(int sigtype)
{
	if(sigtype == 2)
	{
		write(1,"\n",1);
	}
	if(sigtype == 3)
		printf("control backslash baby");
}
int main ()
{
    struct sigaction action;



    (action).sa_handler = myhandler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    if (sigaction(SIGINT, &action, NULL) || sigaction(SIGQUIT, &action, NULL))
        printf("hiiiiiiiiiiiiiiiiiiiiii");
    while(1)
    {
		readline("Minishell$ ");
    }
	return (0);
}

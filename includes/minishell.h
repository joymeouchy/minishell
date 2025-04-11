/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeouchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 08:12:20 by jmeouchy          #+#    #+#             */
/*   Updated: 2025/04/11 14:10:01 by jmeouchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H


# include "../libft/libft.h"
# include "structures.h"
# include <stdio.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <stdbool.h>

///parser.c///

void    one_element_input_to_list(char *input, t_list *list, int *start, int *i);
void    two_element_input_to_list(char *input, t_list *list, int *start, int *i);
int split_redirections(char *input, t_list *list, int start, int *i);
int split_symbols(char *input, t_list *list, int start, int *i);
int double_quotes_to_node(char *input, t_list *list, int start, int *i);
int single_quotes_to_node(char *input, t_list *list, int start, int *i);
t_list  *input_to_list(char *input);
int pwd(void);

///remove_quotes.c///

void	skip_quotes_in_string(int *count_quotes, char *string, int *i, int quotes_ascii);
int     check_if_quotes_balanced(char *string);
int     check_if_contains_quotes(char *string);
void	remove_quotes_from_substring(char *string, char **copy_string, int *i, int quotes_ascii);
void	remove_quotes_from_string(char *string);
int     check_and_remove_quotes(t_list *list);

///expand.c///
void expand_list(t_list *list);

///utils.c///
char	*append_char_to_string(char *src, char c);

///shunting_yard.c//
t_stack *shunting_yard(t_list *list);


////tokenization.c//
void	tokenize(t_list *list, t_envp *envp);
int     ft_strcmp(char *s1, char *s2);
//get_env.c
t_envp *get_split_path(char **envp);
void  env_getter(char **env_p);

///main.c///
char	*command_line_input(void);
t_tree	*stack_to_tree(t_stack *stack);
void	print_inorder(t_tree_node *node);
void	echo(t_tree_node *echo_node);
void myhandler(int sigtype);

#endif
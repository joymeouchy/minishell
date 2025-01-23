/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeouchy <jmeouchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 08:12:20 by jmeouchy          #+#    #+#             */
/*   Updated: 2025/01/23 10:48:21 by jmeouchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include "structures.h"
# include <stdio.h>
# include <readline/history.h>
# include <readline/readline.h>

///parser.c///

void    one_element_input_to_list(char *input, t_list *list, int *start, int *i);
void    two_element_input_to_list(char *input, t_list *list, int *start, int *i);
int split_redirections(char *input, t_list *list, int start, int *i);
int split_symbols(char *input, t_list *list, int start, int *i);
int double_quotes_to_node(char *input, t_list *list, int start, int *i);
int single_quotes_to_node(char *input, t_list *list, int start, int *i);
t_list  *input_to_list(char *input);


///remove_quotes.c///

void	skip_quotes_in_string(int *count_quotes, char *string, int *i, int quotes_ascii);
int     check_if_quotes_balanced(char *string);
int     check_if_contains_quotes(char *string);
char	*append_char_to_string(char *src, char c);
void	remove_quotes_from_substring(char *string, char **copy_string, int *i, int quotes_ascii);
void	remove_quotes_from_string(char *string);
int     check_and_remove_quotes(t_list *list);

///expand.c///

///main.c///
char	*command_line_input(void);

#endif
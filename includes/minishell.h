/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeouchy <jmeouchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 08:12:20 by jmeouchy          #+#    #+#             */
/*   Updated: 2025/01/17 10:30:59 by jmeouchy         ###   ########.fr       */
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

// void	one_element_input_to_list(char *input, t_list *list, int *start, int *i);
// void	two_element_input_to_list(char *input, t_list *list, int *start, int *i);
// int	split_redirections(char *input, t_list *list, int start, int *i);
// int	split_symbols(char *input, t_list *list, int start, int *i);
// int	double_quotes_to_node(char *input, t_list *list, int start, int *i);
// int	single_quotes_to_node(char *input, t_list *list, int start, int *i);
t_list	*input_to_list(char *input);


///token.c//
void	tokenize(t_list *list);

#endif
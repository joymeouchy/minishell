/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 08:12:20 by jmeouchy          #+#    #+#             */
/*   Updated: 2025/01/21 12:25:35 by root             ###   ########.fr       */
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

t_list	*input_to_list(char *input);
char	*command_line_input();
char *get_variable_value(const char *var, int last_exit_status);
char *expand_token(const char *token, int last_exit_status);
void expand_list(t_list *list, int last_exit_status);
int main(void);
int find_dollar(char *str);
char *extract_variable_name(char *str);

#endif
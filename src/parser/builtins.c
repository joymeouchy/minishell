/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhoury <lkhoury@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 13:58:23 by lkhoury           #+#    #+#             */
/*   Updated: 2025/02/07 15:51:02 by lkhoury          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// void    echo(char *argv)
// {
//     int newline;

//     newline = 1;

//     if (argv && ft_strcmp(argv, "-n") == 0)
//     {
//         newline = 0;
//     }
//         ft_putstr_fd(argv, 1);
//         if (argv[i + 1])
//             printf(" ");
    
//     if (newline)
//         printf("\n");
// }


void    echo(char *argv)
{
    ft_putstr_fd(argv, 1);
    if (argv && ft_strcmp(argv, "-n") == 1)
        printf("\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeouchy <jmeouchy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:30:41 by lkhoury           #+#    #+#             */
/*   Updated: 2025/04/23 18:22:53 by jmeouchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void myhandler(int sigtype)
{
	if(sigtype == 2)
	{
        write(1, "\n", 1);
        rl_replace_line("",1);
        rl_on_new_line();
        rl_redisplay();
	}
}
void signal_init()
{    
    if (signal(SIGINT, myhandler) == SIG_ERR || signal(SIGQUIT, SIG_IGN) == SIG_ERR)
    {
        write(1, "error\n", 1);
        exit(1);
    }
}

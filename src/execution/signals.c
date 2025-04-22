/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeouchy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:30:41 by lkhoury           #+#    #+#             */
/*   Updated: 2025/04/19 00:35:08 by jmeouchy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void myhandler(int sigtype)
{
    printf("got signal%dd\n", sigtype);
}
int main ()
{
    struct sigaction action;
    int n, p[2];
    char buf[1000];

    pipe(p);
    (action).sa_handler = myhandler();
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    if (sigaction(SIGINT, &action, NULL) || sigaction(SIGQUIT, &action, NULL) || sigaction(SIGTERM, &action, NULL))
        printf("hiiiiiiiiiiiiiiiiiiiiii");
    while(1)
    {
        n = read(p[0], buf, 1000);
        printf("read returned %d, errno = %d\n", n, errno);
    }
	return (0);
}

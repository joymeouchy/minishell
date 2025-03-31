/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 20:25:19 by root              #+#    #+#             */
/*   Updated: 2025/03/31 20:26:22 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/structures.h"

int handle_redir(t_redir *redirection, int redir_count)
{
    int fd;
    int i;
    char *delimiter;
    char *line;
    size_t len;
    ssize_t read_len;
    int temp_fd;

    i = 0;
    while(i < redir_count)
    {
        if(redirection[i].token == 3)
        {
            fd = open(redirection[i].file, O_RDONLY);
            if (fd == -1)
            {
                perror("Error opening input file");
                return (1);
            }
            if (dup2(fd, 0) == -1)
            {
                perror("Error redirecting input");
                return (1);
            }
            close(fd);
        }
        else if (redirection[i].token == 4)
        {
            fd = open(redirection[i].file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
            if (fd == -1)
            {
                perror("Error opening output file");
                return (1);
            }
            if (dup2(fd, 1) == -1)
            {
                perror("Error redirecting output");
                return (1);
            }
            close(fd);
        }
        else if (redirection[i].token == 6)
        {
            fd = open(redirection[i].file, O_WRONLY | O_CREAT | O_APPEND, 0644);
            if (fd == -1)
            {
                perror("Error opening output file for append");
                return 1;
            }
            if (dup2(fd, 1) == -1)
            {
                perror("Error redirecting output");
                return (1);
            }
            close(fd);
        }
        else if (redirection[i].token == 5)
        {
            delimiter = redirection[i].file;
            line = NULL;
            len = 0;
            temp_fd = open("heredoc_temp.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
            if (temp_fd == -1)
            {
                perror("Error creating temporary file for heredoc");
                return (1);
            }
        }
        i++;
    }
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_prompt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irivero- <irivero-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:30:36 by irivero-          #+#    #+#             */
/*   Updated: 2023/12/13 12:09:04 by irivero-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	**g_envp = NULL;
int		g_exit_status = 0;

/* generates and prints a command prompt to the standard output*/
void	generate_prompt(void)
{
	char	current_path[123];
	/*char		*cwd_buffer;

	//current_path = NULL;
	//cwd_buffer = NULL;
	if (current_path)
		free(current_path);
	cwd_buffer = getcwd(NULL, 0);
	if (cwd_buffer != NULL)
	{
		current_path = ft_strdup(cwd_buffer);
		free(cwd_buffer);
	}*/
	//set_signal();
	ft_putstr_fd("\033[1;32m", 1);
	ft_putstr_fd("our shell: ", 1);
	ft_putstr_fd("\033[0m", 1);
	ft_putstr_fd("\033[1;34m", 1);
	ft_putstr_fd(getcwd(current_path, 123), 1);
	//ft_putstr_fd(current_path,1);
	ft_putstr_fd("\033[0m", 1);
	ft_putstr_fd("$ ", 1);

	//ree(current_path);
}

/* reads a line from standard input and appends it to the content of line
it uses a loop to keep reading util the end of input.
it returns the value of ret.*/
int		get_line(char **line)
{
	int		ret;
	char	*input;
	char	*temp;

	*line = ft_strdup("");
	while (1)
	{
		ret = get_next_line(0, &input);
		temp = ft_strjoin(*line, input);
		free(*line);
		free(input);
		*line = temp;
		if (ret == 0)
		{
			ft_putstr_fd("	\b\b", 1);
			if (ft_strlen(*line) != 0)
				continue;
			ft_putstr_fd("exit\n", 1);
		}
		break ;
	}
	return (ret);
}


/* reads from standard input into the buffer
int		read_from_stdin(char **buf)
{
	int 	bytes_read;
	size_t	size;

	size = 1024;
	bytes_read = 0;
	*buf = ft_strnew(size);
	if (!buf)
		return (-1);
	bytes_read = read(0, *buf, size);
	if (bytes_read == 0)
	{
		free(*buf);
		return (-1);
	}
	else if (bytes_read < 0)
	{
		free(*buf);
		return (-1);
	}
	return (bytes_read);
}
*/
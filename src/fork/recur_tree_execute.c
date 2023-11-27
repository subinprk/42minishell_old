/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recur_tree_execute.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subpark <subpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:27:27 by subpark           #+#    #+#             */
/*   Updated: 2023/11/27 17:46:38 by subpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	execute_pipe(t_cmd *node, char **envp)
{
	pid_t	pid;
	int		fd[2];
	int		pipefd[2];
	int		type;

}

void	execute_simple_cmd(t_cmd *node, char **envp)
{
	pid_t	pid;
	int		fd[2];
	int		pipefd[2];
	int		type;

}

void	execute_simple_redirect(t_cmd *node, char **envp)
{
	pid_t	pid;
	int		fd[2];
	int		pipefd[2];
	int		type;

	type = redirect_type(node->left_child);
	if (type == REL_TYPE_L)
		//////////stopped here
}

void	execute_tree(t_cmd *node, char **envp)
{
	if (node->node_type == NODE_CMD || node->node_type == NODE_REDIRECTS)
		return ;
	else if (node->node_type == NODE_PIPE)
		execute_pipe(node, envp);
	else if (node->node_type == NODE_SIMPLE_CMD)
		execute_simple_cmd(node, envp);
	else if (node->node_type == NODE_SIMPLE_REDIRECT)
		execute_simple_redirect(node, envp);
}

void	search_tree(t_cmd *node, char **envp)
{
	execute_tree(node, envp);
	if ((node->left_child != NODE_RED_TYPE ||
		node->left_child != NODE_FILE_PATH) && node->left_child)
		search_tree(node->left_child, envp);
	if ((node->right_child != NODE_FILE_NAME ||
		node->right_child != NODE_ARGV) && node->right_child)
		search_tree(node->right_child, envp);
}
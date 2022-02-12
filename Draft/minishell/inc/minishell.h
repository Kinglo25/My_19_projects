/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:20:14 by lmajerus          #+#    #+#             */
/*   Updated: 2022/02/11 17:03:58 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define ECHO 1
# define CD 2
# define PWD 3
# define EXPORT 4
# define UNSET 5
# define ENV 6
# define EXIT 7
# define BIN 8
# define REDIR_IN 9
# define REDIR_OUT 10
# define RD_LIMIT 11
# define REDIR_IN_APD 12
# define PIPES 13
# define DOLLAR 14

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <time.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_cmd
{
	int		type;
	char	*input;
	int		pipe[2];
	void	*next;
	void	*prev;
}				t_cmd;

typedef struct s_minishell
{
	int			bool_redir_in;
	int			bool_redir_out;
	int			bool_pipe;
	char		*user_input;
	char		**env;
	t_cmd		*cmd;
}				t_minishell;

#endif

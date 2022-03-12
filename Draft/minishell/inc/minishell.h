/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:20:14 by lmajerus          #+#    #+#             */
/*   Updated: 2022/03/01 11:25:38 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <time.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <sys/stat.h>
# include <termios.h>
# include <errno.h>
# include <fcntl.h>
# include <limits.h>

typedef enum e_type
{
	TOKEN_SPACE,
	TOKEN_PIPE,
	TOKEN_REDIR_IN,
	TOKEN_REDIR_OUT,
	TOKEN_LAST
}			t_type;

typedef struct s_operations
{
	const char		*op;
	int				size;
	t_token_type	type;
}				t_operations;

typedef struct s_token
{
	char			*content;
	int				size;
	t_type			type;
	struct s_token	*next;
}				t_token;

typedef struct s_list
{
	void			*data;
	struct s_list	*next;
}				t_list;
typedef struct s_redirection
{
	char	*name;
	int		flag;
	t_list	*heredoc;
}				t_redirection;

typedef struct s_cmd
{
	char			*cmd;
	int				argc;
	char			**argv;
	t_redirection	out;
	t_redirection	in;
}				t_cmd;

typedef struct s_mini
{
	t_cmd			*cmds;
	int				cmd_count;
	int				exit_status;
	char			**envp;
	char			*line;
	struct termios	termios_p;
}				t_mini;

// parser_utils.c

char		*ft_strdup(const char *s);
void		*ft_memcpy(void *dest, const void *src, size_t n);
size_t		ft_strlen(const char *s);


#endif

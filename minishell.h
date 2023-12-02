/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:47:10 by julberna          #+#    #+#             */
/*   Updated: 2023/11/14 15:19:07 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "./libft/libft.h"

typedef struct s_flags
{
	char			*flag;
	struct s_flags	*next;
}				t_flags;

typedef struct s_args
{
	char			*arg;
	struct s_args	*next;	
}				t_args;

typedef struct s_cmd
{
	char			*cmd;
	t_flags			*flags;
	t_args			*args;
	char			*in;
	char			*out;
	char			*err;
	struct s_cmd	*prev;
	struct s_cmd	*next;
}				t_cmd;

#endif

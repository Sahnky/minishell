/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julberna <julberna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:47:27 by julberna          #+#    #+#             */
/*   Updated: 2023/12/02 20:14:27 by julberna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	char	*buffer;

	while (42)
	{
		buffer = readline("mini~* ");
		if (ft_strlen(buffer) > 0)
			add_history(buffer);
	}
}

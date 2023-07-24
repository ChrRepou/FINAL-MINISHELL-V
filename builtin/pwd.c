/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apaghera <apaghera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 19:10:29 by apaghera          #+#    #+#             */
/*   Updated: 2023/07/24 18:56:53 by apaghera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parse.h"

int	build_pwd(t_cmds *cmds)
{
	char	*pwd;
	char	*check_format;	

	check_format = escape_quote(cmds[0].cmds[0]);
	if (!ft_strncmp(check_format, "pwd", 4))
	{
		free(check_format);
		pwd = getcwd(NULL, 0);
		if (!pwd)
			return (perror(pwd), 0);
		if (cmds[0].data.pipe_out != -1)
			ft_putendl_fd(pwd, cmds[0].data.pipe_out);
		else
			ft_putendl_fd(pwd, 1);
		free(pwd);	
		return (1);
	}
	free(check_format);
	return (0);
}

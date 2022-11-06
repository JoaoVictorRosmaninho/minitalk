/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jv <jv@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 20:01:41 by jv                #+#    #+#             */
/*   Updated: 2022/11/06 20:02:30 by jv               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H 

# include <unistd.h>
# include <sys/types.h>
# include <signal.h>
# include "../libft/libft.h"

# define BUFFSIZE 1024

void	show_message(const char *msg);
#endif

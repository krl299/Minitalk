/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:26:50 by cmoran-l          #+#    #+#             */
/*   Updated: 2023/01/19 17:03:04 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include	"libft/libft.h"
# include	<signal.h>
/* Funtions */
void	ft_send_msg(char *str, int pid);
void	ft_send_byte(unsigned char c, int pid);
void	ft_handler(int pid, siginfo_t *si, void *unused);
void	ft_handler2(int pid);
#endif

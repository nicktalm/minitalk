/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntalmon <ntalmon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:25:35 by ntalmon           #+#    #+#             */
/*   Updated: 2024/02/14 15:48:29 by ntalmon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGES_H
# define MESSAGES_H

# define M_ERROR "\n\033[0;91mError!\033[0m"
# define M_MESSAGE "\033[38;5;214mAdd the server PID and a string.\033[0m"
# define M_EXAMPLE "\033[0;92mExample:\033[0m"
# define M_EXAMPLE2 "./client [PID]123456 [Message]Hello\n"

# define M_START "\n\033[0;94mMessages sent by the client:\n\033[0m"
# define M_PID "\033[0;96m\nPID : %d\033[0m"

# define M_SERVER "\033[1;31m\nWrong number of arguments\033[0m"
# define M_SERVER2 "\033[38;5;214mInput must look like this:\033[0m ./server\n"

#endif
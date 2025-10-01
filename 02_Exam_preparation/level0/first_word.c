/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 14:41:21 by marapovi          #+#    #+#             */
/*   Updated: 2025/10/01 14:16:10 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main (int ac, char **av)
{
    if (ac != 2)
        return (write(1,"\n", 1), 1);

    int i = 0;
    char *str = av[1];

    while (str[i] && (str[i] == 32 || str[i] == 9))
        i++;
    while (str[i] && str[i] != 32 && str[i] != 9)
    {   
        write (1, &str[i], 1);
        i++;
    }
    write (1, "\n", 1);
    return (0);
}

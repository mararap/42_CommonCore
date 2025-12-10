/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rip.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: netrunner <netrunner@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 21:48:53 by netrunner         #+#    #+#             */
/*   Updated: 2025/10/08 22:18:01 by netrunner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int ft_strlen(char *s)
{
    int i = 0;
    while (s[i])
        i++;
    return i;
}

int is_balanced(char *str, int len)
{
    int balance = 0;
    int i = 0;
    
    while (i < len)
    {
        if (str[i] == '(')
            balance++;
        else if (str[i] == ')')
        {
            balance--;
            if (balance < 0)
                return 0;
        }
        i++;
    }
    return (balance == 0);
}

void backtrack(char *str, int *min_removals, int index, int current_removals, int mode)
{
    if (mode == 0 && current_removals > *min_removals)
        return;
    if (is_balanced(str, ft_strlen(str)))
    {
        if (mode == 0)
        {
            if (current_removals < *min_removals)
                *min_removals = current_removals;
        }
        else if (mode == 1 && current_removals == *min_removals)
        {
            write(1, str, ft_strlen(str));
            write(1, "\n", 1);
        }
        return;
    }
    int i = index;
    while (str[i])
    {
        if (str[i] == '(' || str[i] == ')')
        {
            char saved = str[i];
            str[i] = ' ';
            backtrack(str, min_removals, i + 1, current_removals + 1, mode);
            str[i] = saved;
        }
        i++;
    }
}


int main(int argc, char **argv)
{
    if (argc != 2 || argv[1][0] == '\0')
        return 1;
    int i = 0;
    while (argv[1][i])
    {
        if (argv[1][i] != '(' && argv[1][i] != ')')
            return 1;
        i++;
    }
    int min_removals = ft_strlen(argv[1]);
	backtrack(argv[1], &min_removals, 0, 0, 0); // zuerst min finden
	backtrack(argv[1], &min_removals, 0, 0, 1); // dann Lösungen ausgeben

    return 0;
}

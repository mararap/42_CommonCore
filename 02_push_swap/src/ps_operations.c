/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 16:46:02 by marapovi          #+#    #+#             */
/*   Updated: 2025/10/26 19:04:24 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

ps_swap(t_stack *stack, char stack_name)
{
    int temp;
    
    temp = stack->value[0];
    stack->value[0] = stack->value[1];
    stack->value[1] = temp;
    write(1, "s", 1);
    write(1, &stack_name, 1);
    write(1, "\n", 1);    
}
ps_push(t_stack *from, t_stack *to, char to_stack_name)
{
    int i;
    int j;
    while (to->size > 0)
    {
        to->value[to->size] = to->value[to->size - 1];
        to->size++;
    }
    to->value[0] = from->value[0];
    to->size--;
    // Implementation of push operation
}
ps_rotate()
{
    // Implementation of rotate operation
}
ps_rrotate()
{
    // Implementation of reverse rotate operation
}
ps_double_swap()
{
    // Implementation of double swap operation
}
ps_double_rotate()
{
    // Implementation of double rotate operation
}
ps_double_rrotate()
{
    // Implementation of double reverse rotate operation
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marapovi <marapovi@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 16:38:35 by marapovi          #+#    #+#             */
/*   Updated: 2026/05/03 18:17:53 by marapovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef pthread_mutex_t t_fork_lock;
typedef struct s_philo t_philo;
typedef struct s_dinner t_dinner;

struct					s_philo
{
	int					id;
	pthread_t			tid;
	long long			last_meal_time;
	int					meal_count;
	pthread_mutex_t		meal_count_lock;
	pthread_mutex_t		last_meal_time_lock;
	t_fork_lock			*left;
	t_fork_lock			*right;
	t_dinner			*dinner;
};

struct					s_dinner
{
	int					philo_count;
	long long			time_to_die;
	long long			time_to_eat;
	long long			time_to_sleep;
	long long			start_time;
}



#endif // !PHILO_H

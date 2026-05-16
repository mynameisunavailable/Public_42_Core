/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_struct_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 12:41:45 by yunguo            #+#    #+#             */
/*   Updated: 2026/03/20 12:41:45 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_STRUCT_BONUS_H
# define PHILO_STRUCT_BONUS_H

typedef int				t_bool;
# define TRUE 1
# define FALSE 0

struct s_philo
{
	int				indx;
	atomic_llong	t_lastmeal;
	atomic_int		nmealsdone;
	int				cpid;
	sem_t			*meal_l;
	char			meal_l_name[36];
	struct s_philo	*prev;
	struct s_philo	*next;
	struct s_stats	*stat;
};

typedef struct s_philo	t_philo;

// struct s_cpstk
// {
// 	t_bool			phil;
// 	int				indx;
// 	pthread_mutex_t	lock;
// 	struct s_philo	*prev;
// 	struct s_philo	*next;
// 	struct s_cpstk	*left;
// 	struct s_cpstk	*rigt;
// };

// typedef struct s_cpstk	t_cpstk;

struct s_stats
{
	int				n_phil;
	long long		t_tdie;
	long long		t_teat;
	long long		t_tslp;
	int				n_maxm;
	atomic_llong	starve;
	long long		tstart;
	sem_t			*p_lock;
	sem_t			*ticket;
	sem_t			*cpstks;
};

typedef struct s_stats	t_stats;

#endif
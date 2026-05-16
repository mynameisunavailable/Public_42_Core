/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 17:37:51 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/27 17:37:51 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_STRUCT_H
# define PHILO_STRUCT_H

typedef int				t_bool;
# define TRUE 1
# define FALSE 0

struct	s_philo
{
	t_bool			phil;
	int				indx;
	atomic_llong	t_lastmeal;
	atomic_int		nmealsdone;
	pthread_t		thrd;
	pthread_mutex_t	meal_l;
	struct s_philo	*prev;
	struct s_philo	*next;
	struct s_cpstk	*left;
	struct s_cpstk	*rigt;
	struct s_stats	*stat;
};

typedef struct s_philo	t_philo;

struct	s_cpstk
{
	t_bool			phil;
	int				indx;
	pthread_mutex_t	lock;
	struct s_philo	*prev;
	struct s_philo	*next;
	struct s_cpstk	*left;
	struct s_cpstk	*rigt;
};

typedef struct s_cpstk	t_cpstk;

struct	s_stats
{
	int				n_phil;
	long long		t_tdie;
	long long		t_teat;
	long long		t_tslp;
	int				n_maxm;
	atomic_llong	starve;
	atomic_int		ploser;
	atomic_llong	tstart;
	pthread_mutex_t	p_lock;
};

typedef struct s_stats	t_stats;

#endif
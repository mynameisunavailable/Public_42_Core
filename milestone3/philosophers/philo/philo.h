/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 23:22:45 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/26 23:22:45 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdatomic.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>
# include <unistd.h>
# include "philo_struct.h"

//ft_num_conv_str.c
int			ft_atoi(char *str);

//ft_put_err.c
void		ft_puterr(char *str);
int			ft_puterr_no(char *msg, int err);

//ft_string_vi.c
size_t		ft_strlen(const char *str);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_str_is_num(char *str);
int			ft_str_is_int(char *str);

//philo_thread.c
int			create_philo_threads(t_philo *philo);
void		clean_philo_upto(t_philo *philo, int indx);
void		cleanup_philo_threads(t_philo *philo);

//philo_thread_est.c
int			philo_est_odd_eat(t_philo *philo);
void		*philo_est_odd(void *arg);
int			philo_est_even_eat(t_philo *philo);
void		*philo_est_even(void *arg);

//philo_time.c
long long	time_now(void);
void		philo_syncstart(long long tstart);
void		state_usleep(long long usec, t_stats *stat);
long long	smart_sleep(t_philo *philo, int offset);

//philo_v.c
t_bool		int_is_odd(int n);
t_bool		all_full(t_philo *philo);

//philo_main.c
void		state_message(int indx, char *msg, t_philo *philo);
void		safe_unlock(t_cpstk *left, t_cpstk *rigt);
int			run_sim(t_philo *philo, t_stats *stats);

//t_cpstk_new.c
t_cpstk		*t_cpstk_new(int indx);
t_philo		*t_cpstk_pushnext(t_philo **head, int indx);

//t_philo_new.c
t_philo		*t_philo_new(int indx, t_stats *stats);
t_philo		*t_philo_pushnext(t_philo **head, int indx, t_stats *stats);
t_philo		*t_philo_pushprev(t_philo **head, int indx, t_stats *stats);

//philo_init.c
int			arguments_isvalid(int argc, char **argv);
int			philo_arg_isinvalid(char *arg);
int			init_t_stats(int argc, char **argv, t_stats *stats);
int			initialise_table(int argc, char **argv, t_philo **philo,
				t_stats *stats);

//ft_safefree.c
void		ft_safefree(void **ptr);
void		free_philocpstk(t_philo *head);

//debug_print.c
void		print_philo(t_philo *head);
void		print_cpstk(t_cpstk *head);
void		print_philocpstk(t_philo *head);

#endif
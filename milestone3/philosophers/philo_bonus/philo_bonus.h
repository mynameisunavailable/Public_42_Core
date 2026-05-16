/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 12:41:53 by yunguo            #+#    #+#             */
/*   Updated: 2026/03/20 12:41:53 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <limits.h>
# include <fcntl.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdatomic.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include "philo_struct_bonus.h"

//ft_put_err.c
void		ft_puterr(char *str);
int			ft_puterr_no(char *msg, int err);
void		state_message(int indx, char *msg, t_philo *philo);

//ft_safefree.c
void		ft_safefree(void **ptr);
void		safe_close_semaphore(t_stats *stats);
void		unlink_semaphore(void);
void		free_philo(t_philo *head);
void		destroy_philo_forks(t_philo *philo);

//ft_num_conv_str.c
int			ft_atoi(char *str);
void		ft_reverse_string(char *string, char *reverse_string, int length);
char		*ft_itoa_fast(int n, char *dest);
char		*ft_strcpy(char *dest, char *src);
char		*ft_strcat(char *dest, char *src);

//ft_string_vi.c
size_t		ft_strlen(const char *str);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_str_is_num(char *str);
int			ft_str_is_int(char *str);

//philo_main.c
void		check_completion(t_philo *philo);

//philo_est.c
void		*check_starve(void *arg);
void		philo_est_single(t_philo *philo);
void		return_ticket_and_cpstks_dcheck(t_philo *philo);
void		philo_est_odd(t_philo *philo);
void		philo_est_even(t_philo *philo);

//philo_init.c
int			arguments_isvalid(int argc, char **argv);
int			philo_arg_isinvalid(char *arg);
int			init_t_stats_sem(t_stats *stats);
int			init_t_stats(int argc, char **argv, t_stats *stats);
int			initialise_table(int argc, char **argv, t_philo **philo,
				t_stats *stats);

//philo_time.c
long long	time_now(void);
void		philo_syncstart(long long tstart);
void		state_usleep(long long usec, t_stats *stat);
long long	smart_sleep(t_philo *philo, int offset);

//philo_v.c
t_bool		int_is_odd(int n);

//t_philo_new.c
t_philo		*t_philo_new(int indx, t_stats *stats);
t_philo		*t_philo_pushnext(t_philo **head, int indx, t_stats *stats);
t_philo		*t_philo_pushprev(t_philo **head, int indx, t_stats *stats);

#endif
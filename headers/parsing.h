/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakinen <rmakinen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:35:07 by yoonslee          #+#    #+#             */
/*   Updated: 2023/08/22 09:50:28 by rmakinen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "minishell.h"

# include <stdlib.h>
# include <signal.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <term.h>

typedef struct s_data
{
	struct s_env		*env;
	struct termios		old_tio;
	struct termios		new_tio;
	struct sigaction	sa;
	char				**args;
	int					start;
	int					end;
	int					s_quotes;
	int					d_quotes;
	char				*out;
	int					i;
	int					j;
	int					k;
	int					struct_count;
}	t_data;

/*conctenate.c*/
void	delete_quotes2(char *str, int index, int size, t_data *ms);
void	delete_quotes(char *str, int index, int size, t_data *ms);
char	**concatenate(char **str, t_data *ms);
int		extend_expand_quote_check2(t_data *ms, char **str);

/*expand_env_utils.c*/
int		check_quote_cases(t_data **ms, char c);
char	**realloc_stack(char **str, int count);

/*expand_env.c*/
char	*expand_var(t_data *ms, char *str, int start);
char	*find_env(t_data *ms, char *var, int var_size);
void	realloc_var(t_data *ms, char *str, char *var, int size);
char	**expand_quote_check(t_data *ms, char **str);

/*parser_special.c*/
char	*special_expand(t_data *ms, char *str);
int		count_size(char *str, char *var, char *new);
int		space_newline(char *str);
int		break_in_expand_quote(char *str, t_data *ms);
int		find_index(char *str, char c);

/*parser_utils.c*/
void	quotes_init(t_data *ms);
void	free_str_array(char **str);
void	ms_init(t_data *ms);
void	realloc_var2(t_data *ms, int leftover, int size, char *str);
char	*expand_var_init(t_data *ms, char *str, int start);

#endif

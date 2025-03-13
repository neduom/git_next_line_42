/* ************************************************************************** */
/*																			*/
/*														:::		::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*													+:+ +:+			+:+	 */
/*   By: mel-moud <mel-moud@student.42.fr>			+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+			*/
/*   Created: 2024/12/15 13:35:28 by mel-moud			#+#	#+#			 */
/*   Updated: 2024/12/20 15:03:07 by mel-moud         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s1);
char	*get_next_line(int fd);

#endif

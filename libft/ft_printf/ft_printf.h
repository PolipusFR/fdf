/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsabatie <lsabatie@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 14:23:48 by lsabatie          #+#    #+#             */
/*   Updated: 2023/07/20 03:30:29 by lsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <stdint.h>

# define FT_PRINTF_H

int		ft_printf(const char *format, ...);
int		pf_putchar(int c);
int		pf_putstr(char *str);
int		pf_putnbr(int nb);
int		pf_putnbr_unsigned(unsigned int nb);
int		pf_putptr(unsigned long long ptr);
int		pf_puthex(unsigned int nb, const char format);
int		pf_toupper(int c);
int		pf_itoa(int nb);
int		pf_itoa_unsigned(unsigned int nb);
char	*pf_reverse(char *str, int len_str);
int		pf_print_string(char *string, int size);
int		check(void);
int		pf_negative_itoa(int nb);

#endif
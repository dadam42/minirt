/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damouyal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:53:20 by damouyal          #+#    #+#             */
/*   Updated: 2019/10/12 11:19:56 by damouyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void		skip_spaces(const char **str)
{
	while (**str == '\t' || **str == '\n' || **str == '\v' || **str == '\f' ||
			**str == '\r' || **str == ' ')
		(*str)++;
}

static int		get_sign(const char **str)
{
	if (**str == '-' || **str == '+')
	{
		(*str)++;
		if (*(*str - 1) == '-')
			return (-1);
	}
	return (1);
}

static int		get_next_digit(const char **str)
{
	int ret;

	if (**str >= '0' && **str <= '9')
	{
		ret = **str - '0';
		(*str)++;
		return (ret);
	}
	return (-1);
}

int				ft_atoi(const char *str)
{
	int sign;
	int ret;
	int digit;

	skip_spaces(&str);
	sign = get_sign(&str);
	ret = 0;
	while ((digit = get_next_digit(&str)) >= 0)
	{
		ret = 10 * ret - digit;
	}
	return ((-sign) * ret);
}

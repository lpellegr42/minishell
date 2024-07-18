//#include "minishell.h"
#include "../../includes/minishell.h"

char	*ft_strdup(char *s)
{
	char	*cpy;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	cpy = (char *)malloc(len * sizeof(char) + 1);
	i = 0;
	if (cpy == NULL)
		return (NULL);
	else
	{
		while (s[i])
		{
			cpy[i] = s[i];
			i++;
		}
		cpy[i] = '\0';
	}
	return (cpy);
}

int	ft_nbrlen(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len = len + 1;
		n = n * (-1);
	}
	while (n > 0)
	{
		n = n / 10;
		len ++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		len;

	len = ft_nbrlen(n);
	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = n * (-1);
		i++;
	}
	while (len-- > i)
	{
		str[len] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}

#include "../includes/minishell.h"

int	ft_len(char *str, int i)
{
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char    *ft_strjoin(char *s1, char *s2)
{
        char    *newstr;
        int             i;
        int             j;

        newstr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
        if (newstr == NULL)
                return (NULL);
        i = 0;
        j = 0;
        while (s1[i])
        {
                newstr[i] = s1[j];
                i++;
                j++;
        }
        j = 0;
        while (s2[j])
        {
                newstr[i] = s2[j];
                i++;
                j++;
        }
        newstr[i] = '\0';
        return (newstr);
}
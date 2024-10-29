#include <unistd.h>
#include <stdlib.h>

int	check_input(int argc, char *argv[])
{
	int	verdict;

	verdict = 0;
	(void) argv;
	if (argc != 2)
		verdict = 1;
	if (verdict != 0)
		write(1, "\n", 1);
	return (verdict);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_strdup(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

void	ft_permute(char *str, int i_char, int strlen, char **perms, int *i_perm)
{
	char	tmp_char;

	if (i_char == strlen - 1)
	{
		perms[*i_perm] = malloc(sizeof(char) * (strlen + 1));
		ft_strdup(perms[*i_perm], str);
		(*i_perm)++;
		return ;
	}
	for (int j = i_char; j < strlen; j++)
	{
		tmp_char = str[i_char];
		str[i_char] = str[j];
		str[j] = tmp_char;
		ft_permute(str, i_char + 1, strlen, perms, i_perm);
		tmp_char = str[i_char];
		str[i_char] = str[j];
		str[j] = tmp_char;
	}
}

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	if (!str1 || !str2)
		return (0);
	while (str1[i] == str2[i])
		i++;
	return (str1[i] - str2[i]);
}


void	ft_bubble_sort(char **perms, int n_perms, int sorted)
{
	char	*tmp_str;

	for (int i = 0; i < n_perms - 1; i++)
	{
		if (ft_strcmp(perms[i], perms[i + 1]) > 0)
		{
			tmp_str = perms[i];
			perms[i] = perms[i + 1];
			perms[i + 1] = tmp_str;
			sorted = -1;
		}
	}
	if (sorted == 1)
		return ;
	ft_bubble_sort(perms, n_perms, 1);
}

int	main(int argc, char *argv[])
{
	int		i_perm;
	int		n_perms;
	int		strlen;
	char	**perms;

	if (check_input(argc, argv) != 0)
		return (1);

	strlen = ft_strlen(argv[1]);
	n_perms = 1;
	for (int i = 1; i <= strlen; i++)
		n_perms *= i;
	perms = malloc(sizeof(char *) * n_perms);
	i_perm = 0;
	ft_permute(argv[1], 0, strlen, perms, &i_perm);
	ft_bubble_sort(perms, n_perms, 1);
	for (int i = 0; i < n_perms; i++)
	{
		write(1, perms[i], strlen);
		write(1, "\n", 1);
		free(perms[i]);
	}
	free(perms);
}

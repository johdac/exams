#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	check_input(int argc)
{
	int	verdict;

	verdict = 0;
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

void ft_swap(char* x, char* y)
{
	char temp = *x;
	*x = *y;
	*y = temp;
}

void ft_reverse(char* str, int start, int end)
{
	while (start < end) {
		ft_swap(&str[start], &str[end]);
		start++;
		end--;
	}
}

int	ft_permute(char *str, int n)
{
	// Start at the second to last character
	int i = n - 2;
	// Find the rightmost character that is smaller than its next character
	while (i >= 0 && str[i] > str[i + 1])
		i--;
	// If no such character is found, we are at the last permutation, send stop signal
	if (i < 0)
		return 0;
	// Find the smallest character on right of 'i' and larger than str[i]
	int j = n - 1;
	while (str[j] < str[i])
		j--;
	// Swap characters at i and j
	ft_swap(&str[i], &str[j]);
	// Reverse the sequence from i+1 to end to get the next permutation
	ft_reverse(str, i + 1, n - 1);
	return 1;
}

int	main(int argc, char *argv[])
{
	if (check_input(argc) != 0)
		return (1);
	puts(argv[1]);
	while (ft_permute(argv[1], ft_strlen(argv[1])))
		puts(argv[1]);
}

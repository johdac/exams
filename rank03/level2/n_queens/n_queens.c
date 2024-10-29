#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_print_solution(char board[999][999], int n)
{
	for (int col = 0; col < n; col++)
		for (int row = 0; row < n; row++)
			if (board[row][col] == 'q')
				printf(" %i", row);
	printf("\n");
}

void	ft_setup_board(char board[999][999], int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			board[i][j] = '.';
}

void	ft_debug_print_board(char board[999][999], int n)
{
	printf("\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j < (n - 1))
				printf("%c ", board[i][j]);
			else
				printf("%c", board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int	ft_placement_possible(char board[999][999], int n, int col, int row)
{
	int	tmp_row;
	int	tmp_col;

	//check orthogonal left
	for (tmp_col = col; tmp_col >= 0; tmp_col--)
		if (board[tmp_col][row] == 'q')
			return (0);
	//check diagonal top left
	tmp_col = col;
	tmp_row = row;
	while (tmp_col >= 0 && tmp_row >= 0)
	{
		if (board[tmp_col][tmp_row] == 'q')
			return (0);
		tmp_col--;
		tmp_row--;
	}
	//check diagonal bottom left;
	tmp_col = col;
	tmp_row = row;
	while (tmp_col >= 0 && tmp_row < n)
	{
		if (board[tmp_col][tmp_row] == 'q')
			return (0);
		tmp_col--;
		tmp_row++;
	}
	return (1);
}


void	ft_put_queens(char board[999][999], int n, int col, int row)
{
	if (col >= n)
	{
		ft_debug_print_board(board, n); // disable debug printing for exam
		ft_print_solution(board, n);
	}
	while (row < n)
	{
		if (ft_placement_possible(board, n, col, row) == 1)
		{
			board[col][row] = 'q';
			ft_put_queens(board, n, col + 1, 0);
		}
		board[col][row] = '.';
		row++;
	}
}

int	main(int argc, char *argv[])
{
	int		n;
	char	board[999][999] = {0};

	if (argc != 2)
		return (printf("\n"), 1);
	n = atoi(argv[1]);
	ft_setup_board(board, n);
	ft_debug_print_board(board, n); // disable debug printing for exam
	ft_put_queens(board, n, 0, 0);
}

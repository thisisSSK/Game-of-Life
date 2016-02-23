#include "board.h"


int** allocate_empty_board(int x, int y) {
	
	int** board = calloc(x, sizeof(int *));
	for (int row = 0; row < x; row++) {
		board[row] = calloc(y, sizeof(int));
	}
	return board;
}

Board* initialize_board_struct(int x, int y, int initial_cells) {
	Board* board_struct = calloc(1,sizeof(Board));
	board_struct->size_x = x;
	board_struct->size_y = y;
	board_struct->initial_cells = initial_cells;
	board_struct->board = allocate_empty_board(x,y);
	return board_struct;
}

void initialize_board(Board *board) {
	int cells_on_board = 0;
	srand ( time(NULL) );
	while (cells_on_board < board->initial_cells) {
		int x_to_place_cell = rand() % (board->size_x-1);
		int y_to_place_cell = rand() % (board->size_y-1);
		if (board->board[x_to_place_cell][y_to_place_cell] != 0) {
			continue;
		}
		else {
			board->board[x_to_place_cell][y_to_place_cell] = 1;
			cells_on_board += 1;
		}
	}
}

void update_board_state(Board *board_struct) {
	int** board = board_struct->board;
	for (int r = 0; r < board_struct->size_x; r++) {
		for (int c = 0; c < board_struct->size_y; c++) {
			// printf("-------- (%d,%d) -------- \n", r, c);
			int num_neighbor_cells = get_num_neighbors(r, c, board_struct);
			// printf("Number of Neighbors for %d,%d = %d\n", r,c,num_neighbor_cells);
			if (num_neighbor_cells <3) {
				
				if (board[r][c] == 1) {
					board[r][c] = 3;
				}
				else if (board[r][c] == 0) {
					board[r][c] = 0;
				}
			}
			else {
				if (board[r][c] == 0) {
					board[r][c] = 4;
				}
				else if (board[r][c] == 1) {
					board[r][c] = 1;
				}	
			}
			// printf("---------------------------\n");
				
		}
	}
	update_board_state_final(board_struct);
}
void update_board_state_final(Board *board_struct) {
	int** board = board_struct->board;
	for (int r = 0; r < board_struct->size_x; r++) {
		for (int c = 0; c < board_struct->size_y; c++) {
			if (board[r][c] == 3) {
				board[r][c] = 0;
			}
			else if (board[r][c] == 4) {
				board[r][c] = 1;
			}
		}
	}
}

int get_num_neighbors(int r, int c, Board *board_struct) {
	int num_neighbor_cells = 0;
	if (board_struct->board[r][c] == 1) {
		num_neighbor_cells -= 1;
	}
	for (int i = r-1; i <= r+1; i++) {
		if (i < 0) {
			continue;
		}
		else if (i >= board_struct->size_x) {
			break;
		}
		else {
			for (int j = c-1; j <= c+1; j++) {
				if (j < 0) {
					continue;
				}	
				else if (j >= board_struct->size_y) {
					break;
				}
				else if (board_struct->board[i][j] == 1 || board_struct->board[i][j] == 3) {
					// printf("1 found. %d,%d=%d\n",i,j, board_struct->board[i][j]);
					num_neighbor_cells += 1;
				}
				else {
					// printf("%d,%d=%d\n",i,j, board_struct->board[i][j]);
				}
			}
		}	
	}	
	return num_neighbor_cells;
}

void print_board(Board *board) {
	for(int i = 0; i < board->size_x; i++) {
		printf("\t");
		for (int j = 0; j < board->size_y; j++) {
			printf("%d",board->board[i][j]);
			if (j == board->size_y-1) {
				printf("\n");
			}
		}
	}
}

void free_board(Board *board) {
	if (board != NULL) {
		for (int row = 0; row < board->size_y; row++) {
			if (board->board[row] != NULL)
				free(board->board[row]);
		}
		if (board->board != NULL) {
			free(board->board);	
		}
		
		free(board);
	}
}
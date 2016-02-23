#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#ifndef ALIVE_TO_DEAD 
#define ALIVE_TO_DEAD 3
#endif
#ifndef DEAD_TO_ALIVE
#define DEAD_TO_ALIVE 4
#endif


typedef struct {
	int size_x;
	int size_y;
	int initial_cells;
	int current_cells;
	int** board;

}Board;

int** allocate_empty_board(int , int );
Board* initialize_board_struct(int , int , int);
void initialize_board(Board *);
void print_board(Board *);
void free_board(Board *);
void update_board_state(Board *);
int get_num_neighbors(int,int, Board *);
void update_board_state_final(Board *);
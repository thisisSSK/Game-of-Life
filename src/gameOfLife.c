
/**
 *
 * argv[1] = Width of Field
 * argv[2] = Height of Field
 * argv[3] = # of initial cells
 * 
 */

#include "gameOfLife.h"
#include "board.h"

int main(int argc, char** argv) {

	check_input_count(argc);

	int x = parse_param(argv[1]);
	int y = parse_param(argv[2]);
	int initial_cells = parse_param(argv[3]);

	Board* board_struct = initialize_board_struct(x, y, initial_cells);
	initialize_board(board_struct);
	printf("------ Initial Board ------\n");
	print_board(board_struct);
	printf("------ ------------- ------\n");

	for (int i = 0; i < 5; i ++) {
		printf("------ Step %d ------\n", i + 1);
		update_board_state(board_struct);
		print_board(board_struct);
	}


	free_board(board_struct);

}



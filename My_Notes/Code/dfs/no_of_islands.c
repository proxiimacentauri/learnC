// Program to count islands in boolean 2D matrix
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define ROW 5
#define COL 5

int isSafe(int Surface[][COL], int curr_row, int curr_col, bool visited[][COL])
{
	// Current row and col number is in range
    if((curr_row >=0 && curr_row < ROW) && (curr_col >=0 && curr_col < COL))
    {
        // Make sure the current value = 1 and It is NOT visited yet
        if(Surface[curr_row][curr_col] == 1 && visited[curr_row][curr_col] == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    return 0;
}


/*
    We want to seach in all 8 directions i.e run DFS in 8 directions

            (x-1,y+1)  (x,y+1)  (x+1,y+1)
                  \      |      /
                    \    |    /
                      \  |  /
           (x-1,y)-----(x,y)-----(x+1,y)
                      /  |  \
                    /    |    \
                  /      |      \
             (x-1,y-1) (x,y-1)  (x+1,y-1)

        row_offset[] = {0, 1, 1,  1,  0, -1, -1, -1}
        col_offset[] = {1, 1, 0, -1, -1, -1,  0,  1}

*/
void DFS(int Surface[][COL], int curr_row, int curr_col, bool visited[][COL])
{
	static int row_offset[] = {0, 1, 1,  1,  0, -1, -1, -1};
	static int col_offset[] = {1, 1, 0, -1, -1, -1,  0,  1};

	visited[curr_row][curr_col] = true;

	for(int k = 0; k < 8; ++k)
    {
        int row_direction = curr_row + row_offset[k];
        int col_direction = curr_col + col_offset[k];

		if (isSafe(Surface, row_direction, col_direction, visited))
        {
			DFS(Surface, row_direction, col_direction, visited);
        }
    }
}

int countIslands(int Surface[][COL])
{
	// Make a bool array to mark visited cells, initialise them as unvisited
	bool visited[ROW][COL];
	memset(visited, false, sizeof(visited));

	// Initialize count as 0
	int countIsland = 0;
	for(int i = 0; i < ROW; ++i)
    {
        for (int j = 0; j < COL; ++j)
        {
            // If a cell with value 1 is not visited yet, then new island found
            if (Surface[i][j] == 1 && !visited[i][j])
            {
                DFS(Surface, i, j, visited);	 // Visit all 8 directions around this cell
                ++countIsland;
            }
        }
    }
	return countIsland;
}

int main()
{
	int Surface[][COL]= {
                    {1, 1, 0, 0, 0},
                    {0, 1, 0, 0, 1},
                    {1, 0, 0, 1, 1},
                    {0, 0, 0, 0, 0},
                    {1, 0, 1, 0, 1}
            	};

	printf("Number of islands is: %d\n", countIslands(Surface));

	return 0;
}
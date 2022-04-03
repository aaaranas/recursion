#include <stdio.h>
#include <queue>    //for queue
#include <utility>  //for pair
#include <cstring>  //for memset
#include <conio.h>  //for input validation

using namespace std;

//function for input validation (to accept only integers)
int getIntegerOnly()
{
    int num = 0, ch;
    do {
        ch = getch();

        if (ch >= 48 && ch <= 57) {
            printf("%c", ch);
            num = num * 10 + (ch - 48);
        }
        if (ch == 13)
            break;
    } while (1);

    return (num);
}

// function that detects whether cells are out of bounds, have a value of 0, or are visited cells
bool isValid(bool *isVisited, int *grid, int row, int col, int n, int m){

    if (row < 0 || col < 0 || row >= n || col >= m)         //nilapas bas grid
        return false;

    if (*((grid + row*m ) + col) == 0)                      // tan aw sa value dapat 1
        return false;

    if (*((isVisited + row*m ) + col) == true)              // na visit naba
        return false;

    return true;
}


int main(){
	int n,m;
	int count;

	do{
		printf("Input the number of rows (n): ");
		n = getIntegerOnly();
		printf("\nInput the number of columns (m): ");
		m = getIntegerOnly();
	}while (n<=0 || m<=0);

	int grid[n][m];
	int N,M;
		for(N=0; N<n; N++){
    	for(M=0;M<m;M++){
        printf("\nEnter value for grid[%d][%d]:", N+1, M+1);
        grid[N][M] = getIntegerOnly();

        if(grid[N][M]!=0&&grid[N][M]!=1){
            printf("\nInvalid Input. Try Again.\n");
            M--;
            }
      }}


   printf("\nGrid values:\n");
   for(N=0; N<n; N++){
		for(M=0;M<m;M++){
        printf("%2d ", grid[N][M]);
         }
         printf("\n");
      }

    bool isVisited[n][m];
    memset(isVisited, false, sizeof(isVisited));            // initialization of memset (making all arrays false)
    int currRow = 0, currCol = 0;

    int direction[] = { -1, 0, 1 };                         //initialization of the direction of neighbors

//while current row has not yet reached the maximum row
    while(currRow < n){
        if(isValid((bool*)isVisited, (int*)grid, currRow, currCol, n, m)){
            count++;
            int searchRow = currRow, searchCol = currCol;               //breadth first search
            queue<pair<int, int>> q;                                    //declaration of queue

            q.push({ searchRow, searchCol });                           //adding of nodes into the queue
            isVisited[searchRow][searchCol] = true;                     //marking the cells visited

            while (!q.empty()) {

                pair<int, int> cell = q.front();
                int x = cell.first;                                     //doing this if the queue is not empty yet
                int y = cell.second;

                q.pop();                                                //eliminating what's in front of queue once its done

                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++){                        //directions, passing of 2d array
                        if(direction[i] == 0 && direction[j] == 0)
                            continue;

                        int adjx = x + direction[i];
                        int adjy = y + direction[j];

                        if (isValid((bool*)isVisited, (int*)grid, adjx, adjy, n, m)) {
                            q.push({ adjx, adjy });                                 //adding nodes into the queue
                            isVisited[adjx][adjy] = true;
                        }

                    }

                }
            }
        }

        if(currCol + 1 < m)
            currCol++;                      //choosing of another cell of interest with a value 1 that is not adjacent to other 1s
        else{
            currCol = 0;
            currRow++;
        }
    }

    printf("\n\nThere are %d object/s.", count);
	return 0;
}

//https://www.geeksforgeeks.org/program-that-allows-integer-input-only/
//https://www.geeksforgeeks.org/breadth-first-traversal-bfs-on-a-2d-array/ (breadth first search algo)
//https://www.geeksforgeeks.org/pass-2d-array-parameter-c/ (passing of 2d array)
//https://www.geeksforgeeks.org/pointer-array-array-pointer/#:~:text=Pointers%20and%20two%20dimensional%20Arrays,help%20of%20pointer%20notation%20also. (pointer for array)
//https://www.geeksforgeeks.org/pair-in-cpp-stl/ (pair data struc)

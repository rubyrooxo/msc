#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

 #define ROWS 3
 #define COLS 3
 #define POSIBILITIES 181440

 typedef struct {
   char board[ROWS][COLS];
   int parentId;
 } eightTile;

 typedef struct {
   int x;
   int y;
 } coords;

eightTile stringToEightTile(char* a);
int addChildren(eightTile queue[POSIBILITIES], int currentBoard, int nextBoard);
void copyBoard(eightTile a[ROWS][COLS], eightTile b[ROWS][COLS]);
int isSameBoard(char a[ROWS][COLS], char b[ROWS][COLS]);
int hasBoardbeenused(eightTile queue[POSIBILITIES], int nextBoard);
int findSpace(char board[ROWS][COLS]);
void addBoard(eightTile eighttile, eightTile queue[POSIBILITIES], int index);

// void checkMoves(char board[ROWS][COLS], coords space, direction dir);
//int addMoves(eightTile *boards, int boardStart, int boardNext);
void printBoard(eightTile board[ROWS][COLS]);
// void printSolution(eightTile tile, *boards, int boardEnd);
//void test(void);




int main(int argc, char **argv) {

  eightTile queue[POSIBILITIES];
  int currentBoard, nextBoard;

  if (argc != 2) {
    printf("Usage: ./eightTile \"board\"\n");
    return 1;
  }

  stringToEightTile(argv[1], queue[0]);
  for (int y = 0; y < ROWS; y++) {
    for (int x = 0; x < COLS; x++) {
      printf("%c ", queue[0].board[y][x]); /* testing it prints as tile */
    }
    printf("\n");
  }


  queue[0].parentId = -1;
  printf("parent: %d\n", queue[0].parentId); /*-- testing parentid assignment works */

  while(currentBoard < nextBoard) {
    /* add children,
    check for solution (compare each to solution) -- write solution
    if solution, print */
  }

  }

eightTile stringToEightTile(char* a, char b[ROWS][COLS]) {
    int y=0, x=0;

    for (y = 0; y < ROWS; y++) {
      for (x = 0; x < COLS; x++) {
        b[y][x] = a[y * ROWS + x];
      }
    }
  }

int addChildren(eightTile queue[POSIBILITIES], int currentBoard, int nextBoard) {
    coords c;

      if(c.y < 2) {
        copyBoard(queue[nextBoard].board, queue[currentBoard].board);
        queue[nextBoard].parentId = queue[currentBoard].parentId;
        c = findSpace(queue[currentBoard]);
      /* move up */
        if(hasBoardbeenused(queue, nextBoard) = 0) {
        nextBoard++;
        }
      }
      if(c.y > 0) {
        copyBoard(queue[nextBoard].board, queue[currentBoard].board);
        queue[nextBoard].parentId = queue[currentBoard].parentId;
        c = findSpace(queue[currentBoard]);
      /* move down */
        if(hasBoardbeenused(queue, nextBoard) = 0) {
        nextBoard++;
        }
      }
      if(c.x < 2) {
        copyBoard(queue[nextBoard].board, queue[currentBoard].board);
        queue[nextBoard].parentId = queue[currentBoard].parentId;
        c = findSpace(queue[currentBoard]);
      /* move right */
        if(hasBoardbeenused(queue, nextBoard) = 0) {
        nextBoard++;
        }
      }
      if(c.x > 0) {
        copyBoard(queue[nextBoard].board, queue[currentBoard].board);
        queue[nextBoard].parentId = queue[currentBoard].parentId;
        c = findSpace(queue[currentBoard]);
      /* move left*/
        if(hasBoardbeenused(queue, nextBoard) = 0) {
        nextBoard++;
        }
      }

  }

void moveDown(char board[ROWS][COLS]) {
  int tmp;
  tmp = board[c.y+1][c.x];
  board[c.y+1][c.x] = ' ';
  board[c.y][c.x] = board[c.y+1][c.x];
}

void copyBoard(eightTile a[ROWS][COLS], eightTile b[ROWS][COLS]) {
    int x, y;
    for(y = 0; y < ROWS; y++) {
     for(x = 0; x < COLS; x++) {
        if(a[y][x] = b[y][x]) {
        }
      }
    }
  }

int isSameBoard(char a[ROWS][COLS], char b[ROWS][COLS]) {
     int x, y;
     for(y = 0; y < ROWS; y++) {
      for(x = 0; x < COLS; x++) {
         if(a[y][x] == b[y][x]) {
           return 0;
         }
       }
     }
     return 1;
   }

int hasBoardbeenused(eightTile queue[POSIBILITIES], int nextBoard) {
  for(i = 0; i < nextBoard; i++) {
    if(isSameBoard(queue[nextBoard].board, queue[i].board) = 1) {
      return 1;
    }
  }
  return 0;
}

coords findSpace(char board[ROWS][COLS]) {
   int x, y;
   coords c = ;
    for(y = 0; y < ROWS; y++) {
      for(x = 0; x < COLS; x++) {
        if(board[y][x] == ' ') {
          c.y = y;
          c.x = x;
          return c;
        }
     }
   }
}



/* void printBoard(eightTile board[ROWS][COLS]) {
 int x, y;
  for(y = 0; y < ROWS; y++) {
    for(x = 0; x < COLS; x++) {
      printf("%c", eightTile board[y][x]);
    }
  }
} */

#include <stdio.h>


#define MSIZE 12

char myMaze[MSIZE][MSIZE];
	
void printMaze();
void mazeTraverse(char m[MSIZE][MSIZE], int x, int y, int d);

void main()	{

	/*
	char myMaze[MSIZE][MSIZE] = {
		'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#',
		'#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '#',
		'.', '.', '#', '.', '#', '.', '#', '#', '#', '#', '.', '#',
		'#', '#', '#', '.', '#', '.', '.', '.', '.', '#', '.', '#',
		'#', '.', '.', '.', '.', '#', '#', '#', '.', '#', '.', '.',
		'#', '#', '#', '#', '.', '#', '.', '#', '.', '#', '.', '#', 
		'#', '.', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#',   
		'#', '#', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#',
		'#', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '#',
		'#', '#', '#', '#', '#', '#', '.', '#', '#', '#', '.', '#',
		'#', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '#', 
		'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'
		};
	*/
	
	//printMaze(2, 0);
	makeMaze();
	mazeTraverse(myMaze, 2, 0, 0);
}

void makeMaze(char m[MSIZE][MSIZE], int x, int r)	{
    bool made = false;

    while(made == false)
    {
        if(c == 11)	{
            foundExit = true;
		}

        if(canBlaze(m, r, c))
        {
            blaze(m, r, c);
            //printMaze(m);
            //system("pause");
        }
        else if(canMove(m, r, c))
        {
            m[r][c] = 3; //3 means you can't blaze from that square
            //printMaze(m);
            //system("pause");
            move(m, r, c); //move to first open square that can be found
        }
        else
            made = true;

    }
}


void mazeTraverse(char m[MSIZE][MSIZE], int x, int y, int d)	{
	
	int i, j;
	
	m[x][y] = 'X';
	printMaze(m);
	m[x][y] ='-';
	
	if(x == MSIZE - 1 || y == MSIZE - 1)	{
		return;
	}
	
	if(d == 0)	{
		if(checkNext(m, x + 1, y) == 1)	{
			
			mazeTraverse(m, x + 1, y, 3);
		}
		else if(checkNext(m, x, y + 1) == 1)	{
			mazeTraverse(m, x, y + 1, 0);
		}
		else if(checkNext(m, x - 1, y) == 1)	{
			mazeTraverse(m, x - 1, y, 1);
		}
		else if(checkNext(m, x, y - 1) == 1)	{
			mazeTraverse(m, x, y - 1, 2);
		}
	}
	else if(d == 1)	{
		if(checkNext(m, x, y + 1) == 1)	{
			mazeTraverse(m, x, y + 1, 0);
		}
		else if(checkNext(m, x - 1, y))	{
			mazeTraverse(m, x - 1, y, 1);
		}
		else if(checkNext(m, x, y - 1))	{
			mazeTraverse(m, x, y - 1, 2);
		}
		else if(checkNext(m, x + 1, y, 3))	{
			mazeTraverse(m, x + 1, y, 3);
		}
	}
	else if(d == 2)	{
		if(checkNext(m, x - 1, y))	{
			mazeTraverse(m, x - 1, y, 1);
		}
		else if(checkNext(m, x, y - 1))	{
			mazeTraverse(m, x, y - 1, 2);
		}
		else if(checkNext(m, x + 1, y))	{
			mazeTraverse(m, x + 1, y, 3);
		}
		else if(checkNext(m, x, y + 1, 0))	{
			mazeTraverse(m, x, y + 1, 0);
		}
	}
	else if(d == 3)	{
		if(checkNext(m, x, y - 1))	{
			mazeTraverse(m, x, y - 1, 2);
		}
		else if(checkNext(m, x + 1, y))	{
			mazeTraverse(m, x + 1, y, 3);
		}
		else if(checkNext(m, x, y + 1))	{
			mazeTraverse(m, x, y + 1, 0);
		}
		else if(checkNext(m, x - 1, y))	{
			mazeTraverse(m, x - 1, y, 1);
		}
	}
}

int checkNext(char m[MSIZE][MSIZE], int x, int y)	{
	if(m[x][y] != '#')	{
		return 1;
	}
	else 	{
		return 0;
	}
}


void printMaze(char m[MSIZE][MSIZE])	{
	int i, j;

	printf("\n");
	for(i = 0; i < 12; i++)	{
		for(j = 0; j < 12; j++)	{
				printf("%c ", m[i][j]);
		}
		printf("\n");
	}
	//printf("\n");
}

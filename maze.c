#include <stdlib.h>
#include <stdio.h>
#include "maze.h"

#ifndef READMAZE_OFF
Maze * readMaze(char * mazeFilename) {

	FILE* mafi = fopen(mazeFilename, "r");
	int test;
	Maze* maMaze = malloc(sizeof(*maMaze));
	test = fscanf(mafi, "%d %d", &(maMaze -> height), &(maMaze -> width));
	if(test != 2){
		return NULL;
	} 
	
    maMaze -> maze = malloc((maMaze -> height) * sizeof(MazeSquare*));
	int i;
	for(i = 0; i < (maMaze -> height); i++)
	{
		maMaze -> maze[i] = malloc((maMaze -> width) * sizeof(MazeSquare*));	}

	char crct = fgetc(mafi);
    int hor;
	int ver;
	for(hor = 0; hor < (maMaze -> height); hor++){
		for(ver = 0; ver < (maMaze -> width); ver++){
			if(!feof(mafi)){
				crct = fgetc(mafi);
				if(crct != '\n'){
					if(crct == WALL){
						maMaze -> maze[hor][ver].type = WALL;
						maMaze -> maze[hor][ver].visited = false;
					}else if(crct == SPACE){
						maMaze -> maze[hor][ver].type = SPACE;	
						maMaze -> maze[hor][ver].visited = false;
					}else if(crct == START){
						maMaze -> maze[hor][ver].type = START;
						maMaze -> maze[hor][ver].visited = false;
						maMaze -> start.xpos = hor;
						maMaze -> start.ypos = ver;
					}else{
						maMaze -> maze[hor][ver].type = END;
						maMaze -> maze[hor][ver].visited = false;
						maMaze -> end.xpos = hor;
						maMaze -> end.ypos = ver;
					}
				}
			}
		}
	    crct = fgetc(mafi);
	}
	fclose(mafi);
	return(maMaze);
}
#endif //#ifndef READMAZE_OFF

#ifndef FREEMAZE_OFF
void freeMaze(Maze * m) {
	//1. Free each of the "rows" of the maze
	int x;
	for (x = 0; x < (m -> height); x++){
		free(m -> maze[x]);
	}
	//2. Free the "spine" of the array	
	free(m -> maze);
}
#endif //#ifndef FREEMAZE_OFF

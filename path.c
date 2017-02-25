#include <stdio.h>
#include <stdlib.h>
#include "path.h"
#include <string.h>

#ifndef READPATH_OFF
char * readPath(char * pathFilename) {
	FILE* mafi = fopen(pathFilename, "r");
	//FILL IN
	char crct;
	int x = 0;
	while(!feof(mafi)){
		crct = fgetc(mafi);
		if(crct != '\337'){
			x++;
		}
	}
	fseek(mafi,0,SEEK_SET);
	
	char * path = malloc(1 + (sizeof(*path) * x));
	int y = 0;
	while(x>y){
		fscanf(mafi, "%c", &path[y++]);
	}
	path[y] = '\0';

	fclose(mafi);
	return(path);
}
#endif //#ifndef READPATH_OFF

#ifndef CHECKPATH_OFF
bool checkPath(Maze * m, char * path) {

	//FILL IN
	MazePos pos = m -> start;
	MazePos finish = m -> end;
	int hor = pos.xpos;
	int ver = pos.ypos;
	int fhor = finish.xpos;
	int fver = finish.ypos;
	int x = 0;
	int test = path[x];
	while(test != '\0'){
		if(path[x] == SOUTH){
			hor++;
			if(hor <= (m -> height -1) && hor >= 0 && ver <= (m -> width - 1) && ver >= 0){
				if(m -> maze[hor][ver].type == WALL || m -> maze[hor][ver].visited ==true){
					return false;
				}
				if(m -> maze[hor][ver].type == END){
					return true;
				}
				m -> maze[hor][ver].visited = true;
			}
			else{
				return false;
			}
		}
		if(path[x] ==NORTH){
			hor --;
			if(hor <= (m -> height - 1) && hor >= 0 && ver <= (m -> width -1) && ver >=0){
				if(m -> maze[hor][ver].type == WALL || m -> maze[hor][ver].visited ==true){
					return false;
				}
				if(m -> maze[hor][ver].type == END){
					return true;
				}
				m -> maze[hor][ver].visited = true;
			}
			else{
				return false;
			}
		}
		if(path[x] ==WEST){
			ver--;
			if (hor <= (m -> height - 1) && hor >= 0 && ver <= (m -> width - 1) && ver >= 0){
				if(m -> maze[hor][ver].type ==WALL || m -> maze[hor][ver].visited == true){
					return false;
				}
				if(m -> maze[hor][ver].type ==END){
					return true;
				}
				m -> maze[hor][ver].visited = true;
			}
			else{
				return false;
			}
		}
		if (path[x] == EAST){
			ver++;
			if(hor <= (m -> height - 1) && (hor >= 0) && ver <= (m -> width - 1) && (ver >= 0)){
				if(m -> maze[hor][ver].type == WALL || m -> maze[hor][ver].visited == true){
					return false;
				}
				if(m -> maze[hor][ver].type == END){
					return true;
				}
				m -> maze[hor][ver].visited = true;
			}
			else{
				return false;
			}
		}
		x++;
		test = path[x];
	}
	if(m -> maze[fhor][fver].visited == true){
		return true;
	}
	else{
		return false;
	}
}
#endif //#ifndef CHECKPATH_OFF

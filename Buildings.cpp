// CSE 101 Winter 2018, PA 4
//
// Name: Alexandra Kurland
// PID: A92137786
// Sources of Help: TODO
// Due: March 10th, 2018 at 11:59 PM

#ifndef __BUILDINGS_CPP__
#define __BUILDINGS_CPP__

#include "Buildings.hpp"
#include <queue>

//run a bfs type of algorithm to trace the buildings and replace 1s with 0s
int buildings(TwoD_Array<int> survey) {
  int buildings = 0;
  TwoD_Array<int> * ar = &survey;
  int row = survey.getNumRows();
  int col = survey.getNumCols();
  std::queue<std::pair<int,int>> q; 
  for(int rInd = 0; rInd < row; rInd++){
  	for(int cInd = 0; cInd < col; cInd++ ){
  		if(survey.at(rInd,cInd) == 1){
  		//if one then check to the left and to the right
  		int cCheck = cInd;
  		int rCheck = rInd;
  		//set equal to 0
  		survey.at(rCheck,cCheck) = 0;

  		checkN(ar, row, col, cCheck, rCheck);
  			//while

  		}
  		while(!q.empty()){
  			checkN()
  		}
  	}
  }
}

void checkN(TwoD_Array & arr, int col, int row, int c, int r, std::queue<std::pair<int,int>>){
 int cCheck = c;
 int rCheck = r;

 while(cCheck < col -1){ //idk
  	cCheck = cCheck + 1; //going all the way to the right
  	if(survey.at(rCheck, cCheck) == 1){ //erase
  		survey.at(rCheck,cCheck) = 0;
  		//look at its up and down neighbors to add them to queue
  		if(rCheck > 0){
  			if(survey.at(rCheck + 1,cCheck) == 1){
  				std::pair<int,int> p(rCheck-1,cCheck);
 				q.push(p);
 			}
  		}
  		if(rCheck < row - 1){
  			if(survey.at(rCheck -1, cCheck) == 1){
  				std::pair<int,int> p(rCheck +1, cCheck);
  				q.push(p);
  			}
  		}
  	}
  }
  cCheck = c;
  rCheck = r;
  while(cCheck > 0){
  	cCheck = cCheck - 1; //go all the way to the left
  	if(survey.at(rCheck, cCheck) == 1){
  		//maybe set to 0?
  		survey.at(rCheck,cCheck) = 0;
  		if(rCheck > 0){
  			if(survey.at(rCheck + 1,cCheck) == 1){
  				std::pair<int,int> p(rCheck-1,cCheck);
 				q.push(p);
 			}
  		}
  		if(rCheck < row - 1){
  			if(survey.at(rCheck -1, cCheck) == 1){
  				std::pair<int,int> p(rCheck +1, cCheck);
  				q.push(p);
  			}
  		}
  	}
  }
  //here all of the stuff is added to the q
  //pop from the q and go through the same method



 }
#endif

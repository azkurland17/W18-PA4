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
  for(int rInd = 0; rInd < row; rInd++){
  	for(int cInd = 0; cInd < col; cInd++ ){
  		if(survey.at(rInd,cInd) == 1){
  		//if one then delete and run bfs!!
  		survey.at(rInd,cInd) = 0;
  		std::queue<std::pair<int,int>> q; 
  		std::pair<int,int> p(rInd,cInd);
  		q.push(p);
  		std::pair<int,int> curr;
  			while(!q.empty()){
  				curr = q.front();
  				q.pop();
  				//for all neighbors of curr
  				if(cInd < size -1 ){
  					//check if one over right is one
  					if(survey.at(cInd+1, rInd) == 1){
  						q.push(std::pair<int,int> d(cInd+1, rInd));
  					}	
  				}
  				if(cInd > 0 ){
  					//check if one over left is one
  					if(survey.at(cInd-1, rInd) == 1){
  						q.push(std::pair<int,int> d(cInd-1, rInd));
  					}	
  				}
  				if(rInd > 0 ){
  					//check if one above
  					if(survey.at(cInd, rInd+1) == 1){
  						q.push(std::pair<int,int> d(cInd, rInd+1));
  					}	
  				}
  				if(rInd < row -1 ){
  					//check if one below
  					if(survey.at(cInd, rInd-1) == 1){
  						q.push(std::pair<int,int> d(cInd, rInd-1));
  					}	
  				}

  			}
  		}
  		buildings = buildings + 1;
  	}
   }
   return buildings;	
 }

#endif

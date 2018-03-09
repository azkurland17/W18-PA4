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
#include <iostream>
//run a bfs type of algorithm to trace the buildings and replace 1s with 0s
int buildings(TwoD_Array<int> survey) {
  int buildings = 0;
  int row = survey.getNumRows();
  int col = survey.getNumCols();
  for(int rInd = 0; rInd < row; rInd++){
  	for(int cInd = 0; cInd < col; cInd++ ){
		if(survey.at(rInd,cInd) == 1){
  		//if one then delete and run bfs!!
  		//survey.printOut();
  		survey.at(rInd,cInd) = 0;
  		std::queue<std::pair<int,int>> q; 
  		std::pair<int,int> p(rInd,cInd);
  		q.push(p);
  		std::pair<int,int> curr;
  			while(!q.empty()){	
  				curr = q.front();
  			    int cIndx = curr.second;
				int rIndx = curr.first;
		//		std::cout<<"curr = "<<rIndx<< " , "<<cIndx<<std::endl;
				survey.at(rIndx,cIndx) = 0;
				//survey.printOut();
				//std::cout<<"poop: "<<curr.first<<std::endl;
				q.pop();
  				//for all neighbors of curr
  				if(cIndx < col -1 ){
  					//check if one over right is one
  					if(survey.at(rIndx, cIndx+1) == 1){
  						std::pair<int,int> d(rIndx, cIndx+1);
						q.push(d);
		//				std::cout<<"right"<<std::endl;
  					}	
  				}
  				if(cIndx > 0 ){
  					//check if one over left is one
  					if(survey.at(rIndx, cIndx-1) == 1){
  						std::pair<int,int> d(rIndx, cIndx-1);
						q.push(d);
		//				std::cout<<"left"<<std::endl;
  					}	
  				}
  				if(rIndx > 0 ){
  					//check if one above
  					if(survey.at(rIndx-1, cIndx)  == 1){
  						std::pair<int,int> d( rIndx-1, cIndx);
  						q.push(d);
		//				std::cout<<"up"<<std::endl;
					}	
  				}
  				if(rIndx < row -1 ){
  					//check if one below
  					if(survey.at(rIndx+1, cIndx) == 1){
  						std::pair<int,int> d(rIndx+1,cIndx);
		//				std::cout<<"heredksfljdlsfjvfslsfjf"<<std::endl;
						q.push(d);
  					}	
  				}

  			}
  		buildings++;
		}
  	}
   }
   return buildings;	
 }

#endif

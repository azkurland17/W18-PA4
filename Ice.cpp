// CSE 101 Winter 2018, PA 4
//
// Name: Alexandra Kurland
// PID: A92137786
// Sources of Help: discussion slides
// Due: March 10th, 2018 at 11:59 PM

#ifndef __ICE_CPP__
#define __ICE_CPP__

#include "Ice.hpp"

int ice(TwoD_Array<int> rooms) {
  int rowSize = rooms.getNumRows();
  int colSize = rooms.getNumCols();
  TwoD_Array<int> trackRooms = TwoD_Array<int>(rowSize,colSize);
  //keep track of the subproblem answers

  //fill to start with 0
  for(int r = 0; r< rowSize; r++){
  	for(int c = 0; c< colSize; c++){
  		trackRooms.at(r,c) = 0;
  	}
  }
  int bRight = rooms.at(rowSize-1,colSize-1);
  //bottom right room last val
  if(bRight > 0){
  		trackRooms.at(rowSize-1,colSize-1) = bRight +1;
  }
  else{
  		trackRooms.at(rowSize-1,colSize-1) = 1;
  }

  for(int r = rowSize-1; r >= 0; r--){
  	for(int c = colSize-1; c >= 0; c--){
  		if(r != rowSize-1 && c != colSize-1){
  			int val1 = 1;
  			int val2 = 1;
  			if(rooms.at(r,c) > 0){ //if the temp is pos
  				val1 = trackRooms.at(r,c+1) + rooms.at(r,c);
  				val2 = trackRooms.at(r+1,c) + rooms.at(r,c);
  			}
  			else{
  				if(abs(rooms.at(r,c)) < trackRooms.at(r,c+1)){
  					val1 = trackRooms.at(r,c+1) + rooms.at(r,c);
  				}
  				if(abs(rooms.at(r,c)) < trackRooms.at(r+1,c)){
  					val2 = trackRooms.at(r+1,c) + rooms.at(r,c);
  				}
  			}
  			if(val1 > val2 ){
  				trackRooms.at(r,c) = val1;
  			}
  			else{
  				trackRoomsat(r,c) = val2;
  			} 
  		}

  		else if( r != rowSize-1){
  			if(c == colSize-1){
  				if(rooms.at(r,c) < 0){
  					if(abs(rooms.at(r,c)) < trackRooms.at(r+1,c)){
  						trackRooms.at(r,c) = trackRooms.at(r+1,c) + trackRooms.at(r,c);
  					}
  					else{
  						trackRooms.at(r,c) = 1;
  					}
  				}
  			}	
  			else{
  				trackRooms.at(r,c) = trackRooms.at(r+1,c) + trackRooms.at(r,c);
  			}
  		}
  		else if( c != colSize-1){
  			if(r == rowSize-1){
  				if(rooms.at(r,c) < 0){
  					if(abs(rooms.at(r,c)) < trackRooms.at(r,c+1)){
  						trackRooms.at(r,c) = trackRooms.at(r,c+1) - abs(rooms.at(r,c));
  					}
  					else{
  						trackRooms.at(r,c) = 1;
  					}
  				}
  			}	
  			else{
  				trackRooms.at(r,c) = trackRooms.at(r+1,c) + trackRooms.at(r,c);
  			}
  		}
  	}
  }


  return trackRooms.at(0,0);
}
#endif

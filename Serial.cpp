// CSE 101 Winter 2018, PA 4
//
// Name: Alexandra Kurland 
// PID: A92137786
// Sources of Help: Discussion slides
// Due: March 10th, 2018 at 11:59 PM

#ifndef __SERIAL_CPP__
#define __SERIAL_CPP__

#include "Serial.hpp"

int serial(std::vector<int> nums) {
	int size = nums.size();
	int firstVal = nums[0];
    int splitInd = size/2;
	int startInd = 0;
	int endInd = size -1;	
	
	while(1){
		if(size == 1){
			return nums[splitInd];
		}
		else if(nums[splitInd] == firstVal+splitInd){
			//check from split+1 to end 	
			if(splitInd != nums.size()-1){
				startInd = splitInd + 1;
				size = endInd +1 - startInd;
				splitInd = (size/2) + startInd;
			}
		}
		else if(nums[splitInd] < firstVal+splitInd){
			if(splitInd != 0){
				endInd = splitInd -1;
				size = endInd + 1 - startInd;
				splitInd = (size/2) + startInd; 
			}	
		}
	}
	return 0;
}

#endif

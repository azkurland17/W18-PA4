// CSE 101 Winter 2018, PA 4
//
// Name: Alexandra Kurland
// PID: A92137786
// Sources of Help: Lecture 8 and discussion slides
// Due: March 10th, 2018 at 11:59 PM

#ifndef __TENNIS_CPP__
#define __TENNIS_CPP__

#include "Tennis.hpp"
#include <queue>
#include <iostream>


bool compare(Interval i1, Interval i2 ){
      return i1.start > i2.start;
}
//using greedy alg to place intervals by start time 
//and add a new court when times conflict
int tennis(std::vector<Interval> lessons){
	//first sort the input 
	std::priority_queue< Interval, std::vector<Interval>,bool(*)(Interval, Interval)> pq(compare);

	for(auto it = lessons.begin(); it != lessons.end(); ++it){
		pq.push(*it);
	}
	std::vector<int> courts;
	int firstEnd = pq.top().end;
	pq.pop();
	courts.push_back(firstEnd);

	while(!pq.empty()){
		//store the ending times in an array
		int start = pq.top().start;
		int end = pq.top().end;
		bool done = false;
		pq.pop();
		for(int i = 0; i< courts.size(); i++){
			if(start >= courts[i]){
				done = true;
				courts[i] = end;
				break;
			}
		}
		if(!done){
			//must add another court
			courts.push_back(end);
		}
	}
	return courts.size();
}
#endif













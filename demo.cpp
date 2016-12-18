#include <iostream>
#include <map>
#include <fstream>
#include <boost/chrono.hpp>
#include "omp.h"

/**
 * @brief basic boost chrono
 *
 *   g++-6 -I /usr/local/Cellar/boost/1.62.0/include/boost -L /usr/local/Cellar/boost/1.62.0/lib -lboost_chrono -lboost_system -std=c++14 -fopenmp demo.cpp -o demo
 */

using namespace boost::chrono;

using namespace std;

/*
*   Method to count the votes for a state passed in the parameter and declare the winner of that particular state
*	parameter : string --> Name of the state 
*	return value : string --> candidate with highest number of votes in that particular state	
*/
string voteCounterMethod(string stateName){
    ifstream file(stateName);
    string ID, candidate;
    if (file.is_open()){
        int candidate1_voteCount = 0;
        int candidate2_voteCount = 0;
        int candidate3_voteCount = 0;
        string candidate_1=" 0";
        string candidate_2=" 1";
        string candidate_3=" 2";
        
        while(file.good()) {
            getline(file, ID, ',');
            getline(file, candidate, '\n') ;
            if(candidate.compare(candidate_1) == 0){
                candidate1_voteCount++;
            }else if(candidate.compare(candidate_2) == 0){
                candidate2_voteCount++;
            }else if (candidate.compare(candidate_3) == 0){
                candidate3_voteCount++;
            }
        }
        file.close();
        
        if(candidate1_voteCount>candidate2_voteCount){
        	if(candidate1_voteCount>candidate3_voteCount)
        		return candidate_1;
        	else 
        		return candidate_3;
        }else if(candidate2_voteCount>candidate3_voteCount){
        	return candidate_2;
        }else{
        	return candidate_3;
        }
    }
}

/*
*   Method to allocate number of electoral seats for all the states in the US
*	return value : map<string,int> --> map that contains state to number of seats mapping
*/

std::map<std::string, int> AssignSeatsToState(){
	std::map<std::string, int> map;
		map["Alabama.csv"]=9;
		map["New Jersey.csv"]=15;
		map["Alaska.csv"]=3;
		map["New Mexico.csv4;"]=5;
		map["Arizona.csv"]=10;
		map["New York.csv"]=5;
		map["Arkansas.csv"]=6;
		map["North Carolina.csv"]=6;
		map["California.csv"]=55;
		map["North Dakota.csv"]=3;
		map["Colorado.csv"]=9;
		map["Ohio.csv"]=20;
		map["Connecticut.csv"]=7;
		map["Oklahoma.csv"]=7;
		map["Delaware.csv"]=3;
		map["Oregon.csv"]=7;
		map["District of Columbia.csv"]=5;
		map["Pennsylvania.csv"]=21;
		map["Florida.csv"]=27;
		map["Georgia.csv"]=15;
		map["Hawaii.csv"]=4;
		map["Rhode Island.csv"]=4;
		map["Idaho.csv"]=4;
		map["South Carolina.csv"]=8;
		map["Illinois.csv"]=21;
		map["South Dakota.csv"]=3;
		map["Indiana.csv"]=11;
		map["Tennessee.csv"]=11;
		map["Iowa.csv"]=
		map["Texas.csv"]=34;
		map["Kansas.csv"]=6;
		map["Utah.csv"]=5;
		map["Kentucky.csv"]=8;
		map["Vermont.csv"]=
		map["Louisiana.csv"]=9;
		map["Virginia.csv"]=13;
		map["Maine.csv"]=4;
		map["Washington.csv"]=11;
		map["Maryland.csv"]=3;
		map["West Virginia.csv"]=5;
		map["Massachusetts.csv"]=12;
		map["Wisconsin.csv"]=10;
		map["Michigan.csv"]=17;
		map["Wyoming.csv"]=3;
		map["Minnesota.csv"]=10;
		map["Mississippi.csv"]=6;
		map["Missouri.csv"]=11;
		map["Montana.csv"]=3;
		map["Nebraska.csv"]=5;
		map["Nevada.csv"]=5;
		map["New Hampshire.csv"]=4;
	
	return map;

}

    int main(){
        string states[] = {"Alabama.csv","New Jersey.csv","Alaska.csv","New Mexico.csv","Arizona.csv","New York.csv","Arkansas.csv","North Carolina.csv","California.csv","North Dakota.csv","Colorado.csv","Ohio.csv","Connecticut.csv","Oklahoma.csv","Delaware.csv","Oregon.csv","District of Columbia.csv","Pennsylvania.csv","Florida.csv","Georgia.csv","Hawaii.csv","Rhode Island.csv","Idaho.csv","South Carolina.csv","Illinois.csv","South Dakota.csv","Indiana.csv","Tennessee.csv","Iowa.csv","Texas.csv","Kansas.csv","Utah.csv","Kentucky.csv","Vermont.csv","Louisiana.csv","Virginia.csv","Maine.csv","Washington.csv","Maryland.csv","West Virginia.csv","Massachusetts.csv","Wisconsin.csv","Michigan.csv","Wyoming.csv","Minnesota.csv","Mississippi.csv","Missouri.csv","Montana.csv","Nebraska.csv","Nevada.csv","New Hampshire.csv"};
    	int candidates[3] = {0,0,0}; 
        
        //initializing states to electoral seats
        std::map<std::string, int> StateToSeatsMap;
        StateToSeatsMap = AssignSeatsToState();
        
        //state timer
        auto dt_s = high_resolution_clock::now();
      	
      	// TO DO:  change 50 to states.length
      	
      	//#pragma omp parallel for num_threads(32) 			
        for(int i=0; i< 50;i++){
        	
        	string winnerOfTheState = voteCounterMethod(states[i]);
        	
        	//#pragma omp critical(updateCount)        
            if(winnerOfTheState == " 0")
            	candidates[0] = candidates[0]+StateToSeatsMap[states[i]];
            else if(winnerOfTheState == " 1")
            	candidates[1] = candidates[1]+StateToSeatsMap[states[i]];
            else 
             	candidates[2] = candidates[2]+StateToSeatsMap[states[i]];
        
        }
        
        //end timer
        auto dt = duration_cast<nanoseconds> (high_resolution_clock::now() - dt_s);
     	
     	// TO DO: change 3 to candidate's length
     	string winnerName = "Vaisham";
     	for(int index = 0; index < 3;index++){
     		if(candidates[index] >=270){
     			if(index == 0)
     				winnerName = "Vaisham";
     			else if(index == 1)
     				winnerName = "Chandana";
     			else
     				winnerName = "Tushara";
     			
     			break;
     		}	
     	}
      	std::cout << "\n Winner Is " << winnerName << "\n";
        std::cout << "\ndt = " << dt.count() << " ns" << "\n";

        return 0;
    }







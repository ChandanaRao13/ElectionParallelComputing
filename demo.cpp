#include <iostream>
#include <fstream>
#include <boost/chrono.hpp>
#include "omp.h"

/**
 * @brief basic boost chrono
 *
 * To build:
 * g++-6 -I /usr/local/gcc/boost_1_60_0/include -L /usr/local/gcc/boost_1_60_0/lib -lboost_chrono -lboost_system -std=c++14 demo.cpp -o demo
 *g++-6 -I /usr/local/Cellar/boost/1.62.0/include -L /usr/local/Cellar/boost/1.62.0/lib -lboost_chrono -lboost_system -std=c++14 demo.cpp -o demo
 *      Author: gash
 */

using namespace boost::chrono;

using namespace std;

void calculate(string stateName){
    //std::cout<<"State ::"<<stateName<<endl;
    ifstream file(stateName);
    string ID, candidate;
    if (file.is_open()){
        int vcount =0;
        int ccount =0;
        int tcount=0;
        string s1=" 0";
        string s2=" 1";
        string s3=" 2";
        
        
        //#pragma omp parallel for reduction(+:vcount,ccount,tcount)
        for(int i=0;i<13964301;i++) {
            getline(file, ID, ',');
            getline(file, candidate, '\n') ;
            //std::cout << "candidate:" << candidate <<"\n" ;
            
            //#pragma omp critical(updateCount)
            if(candidate.compare(s1) == 0){
                //std::cout << "Payan"<<"\n";
                vcount++;
            }else if(s2.compare(candidate) == 0){
                //std::cout << "Rao"<<"\n";
                ccount++;
            }else if (s3.compare(candidate) == 0){
                //std::cout << "Tush"<<"\n";
                tcount++;
            }else{
                //std::cout << "Else"<<"\n";
            }
            //std::cout << "candidate2: " << candidate << "\n" ;
        }
        //std::cout << "Vote Count: Vaisham--> " << vcount << "\n" ;
        //std::cout << "Vote Count: Chandana -->" << ccount << "\n" ;
        //std::cout << "Vote Count: Tushara -->" << tcount << "\n" ;
        file.close();
    }
}

    int main(){
        //std::cout << "num threads = " << omp_get_num_threads() << std::endl;
        string states[] = {"Alabama.csv","New Jersey.csv","Alaska.csv","New Mexico.csv","Arizona.csv","New York.csv","Arkansas.csv","North Carolina.csv","California.csv","North Dakota.csv","Colorado.csv","Ohio.csv","Connecticut.csv","Oklahoma.csv","Delaware.csv","Oregon.csv","District of Columbia.csv","Pennsylvania.csv","Florida.csv","Georgia.csv","Hawaii.csv","Rhode Island.csv","Idaho.csv","South Carolina.csv","Illinois.csv","South Dakota.csv","Indiana.csv","Tennessee.csv","Iowa.csv","Texas.csv","Kansas.csv","Utah.csv","Kentucky.csv","Vermont.csv","Louisiana.csv","Virginia.csv","Maine.csv","Washington.csv","Maryland.csv","West Virginia.csv","Massachusetts.csv","Wisconsin.csv","Michigan.csv","Wyoming.csv","Minnesota.csv","Mississippi.csv","Missouri.csv","Montana.csv","Nebraska.csv","Nevada.csv","New Hampshire.csv"};
    
        auto dt_s = high_resolution_clock::now();
        //#pragma omp parallel for num_threads(4)
        for(int i=0; i< 50;i++){
            //std::cout<< "Thread_num::"<< omp_get_thread_num() <<":: state "<<states[i]<<endl;
             calculate(states[i]);
        }
        
        auto dt = duration_cast<nanoseconds> (high_resolution_clock::now() - dt_s);
        std::cout << "\ndt = " << dt.count() << " ns" << "\n";

        return 0;
    }







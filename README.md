# ElectionParallelComputing
OpenMP 


Commands:

### Mac
#### g++-6 -I /usr/local/Cellar/boost/1.62.0/include/boost -L /usr/local/Cellar/boost/1.62.0/lib -lboost_chrono -lboost_system -std=c++14 -c -fopenmp -fPIC -Wall USElectionManager.cpp;
####
#### g++-6 -I /usr/local/Cellar/boost/1.62.0/include/boost -L /usr/local/Cellar/boost/1.62.0/lib -lboost_chrono -lboost_system -std=c++14 -fopenmp -shared -o libUSElection.so USElectionManager.o
####
#### python USElectionManager.py
####
#### Note: Enter the names of the candidate along with double quotes - Ex: "Chandana Rao" 

### Ubuntu
#### boost include location: /usr/include/boost
#### boost lib     location: /usr/lib/x86_64-linux-gnu/
#### 
#### g++-6 -I /usr/include/boost -L /usr/lib/x86_64-linux-gnu/ -lboost_chrono -lboost_system -std=c++14 -c -fopenmp -fPIC -Wall USElectionManager.cpp
####
#### g++-6 -I /usr/include/boost -L /usr/lib/x86_64-linux-gnu/ -lboost_chrono -lboost_system -std=c++14 -fopenmp -shared -o libUSElection.so USElectionManager.o

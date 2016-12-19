# ElectionParallelComputing
OpenMP 


Commands:
$g++-6 -I /usr/local/Cellar/boost/1.62.0/include/boost -L /usr/local/Cellar/boost/1.62.0/lib -lboost_chrono -lboost_system -std=c++14 -c -fopenmp -fPIC -Wall USElectionManager.cpp;

$g++-6 -I /usr/local/Cellar/boost/1.62.0/include/boost -L /usr/local/Cellar/boost/1.62.0/lib -lboost_chrono -lboost_system -std=c++14 -fopenmp -shared -o libUSElection.so USElectionManager.o

$python USElectionManager.py

Note: Enter the names of the candidate along with double quotes - Ex: "Chandana Rao" 

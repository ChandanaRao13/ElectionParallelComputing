from ctypes import cdll
lib = cdll.LoadLibrary('./libUSElection.so') 
prompt = "> "

class USElectionManager(object):
    def __init__(self):
        self.obj = lib.USElectionManager_new()

    def USElection_VoteCountingProccess(self, number_of_counters, candidate1, candidate2, candidate3):
        lib.USElectionManager_VoteCountingProccess(self.obj, number_of_counters , candidate1, candidate2, candidate3)

print "Welcome To US Election Board 2017"
print "Please enter number of Counters available"
number_of_counters = input(prompt)
print "Please enter the names of the candidates!"
candidate1 = input("Candidate No 1 = ")
candidate2 = input("Candidate No 2 = ")
candidate3 = input("Candidate No 3 = ")

USElectionManagerObject = USElectionManager()
USElectionManagerObject.USElection_VoteCountingProccess(number_of_counters, candidate1, candidate2, candidate3);
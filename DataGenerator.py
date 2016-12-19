from random import shuffle

class ElectionDataGenerator():
    def __init__(self):
        self.USStates = self.__get_states()
        self.candiates = ["0", "1"]
        self.secondary = "2"
        self.votingPercentage = [48.0, 46.0]

    def generateData(self):
        for usState in self.USStates:
            file = open(usState["state"] + '.csv', 'w')
            voteCount = usState["total"]
            candidates = self.candiates
            shuffle(candidates)
            index = 0
            start = 0
            for x in candidates:
                percentage = self.votingPercentage[index]
                myVotePercentage = (percentage * float(voteCount)) / 100.0
                self.__write_vote(file, candidates[index], start, start + myVotePercentage)
                index += 1
                start = start + myVotePercentage
            myVotePercentage = (6.0 * float(voteCount)) / 100.0
            self.__write_vote(file, self.secondary, start, start + myVotePercentage)
            file.close()


    def __write_vote(self, file, candidate, start, end):
        for x in range(int(end - start)):
            file.write(str(x + 1 + int(start)) + ", " + candidate + '\n')


    def __write_headers(self, file):
        file.write("voterId,\tcandidate\n")
        pass

    def __get_states(self):
        return [{"state": "Alabama", "total": 2123372}, {"state": "Alaska", "total": 318608},
         {"state": "Arizona", "total": 2573165}, {"state": "Arkansas", "total": 1130635},
         {"state": "California", "total": 13964413}, {"state": "Colorado", "total": 2780220},
         {"state": "Connecticut", "total": 1644920}, {"state": "Delaware", "total": 441590},
         {"state": "District of Columbia", "total": 312575}, {"state": "Florida", "total": 9420039},
         {"state": "Georgia", "total": 4092373}, {"state": "Hawaii", "total": 437664},
         {"state": "Idaho", "total": 690255}, {"state": "Illinois", "total": 5536424},
         {"state": "Indiana", "total": 2740958}, {"state": "Iowa", "total": 1566031},
         {"state": "Kansas", "total": 1184402}, {"state": "Kentucky", "total": 1924149},
         {"state": "Louisiana", "total": 2029032}, {"state": "Maine", "total": 1477697},
         {"state": "Maryland", "total": 2781446}, {"state": "Massachusetts", "total": 3325046},
         {"state": "Michigan", "total": 4799284}, {"state": "Minnesota", "total": 2944813},
         {"state": "Mississippi", "total": 1158417}, {"state": "Missouri", "total": 2763504},
         {"state": "Montana", "total": 497147}, {"state": "Nebraska", "total": 1688354},
         {"state": "Nevada", "total": 1125385}, {"state": "New Hampshire", "total": 741885},
         {"state": "New Jersey", "total": 3906709}, {"state": "New Mexico", "total": 798318},
         {"state": "New York", "total": 1688354}, {"state": "North Carolina", "total": 4741665},
         {"state": "North Dakota", "total": 344360}, {"state": "Ohio", "total": 5496487},
         {"state": "Oklahoma", "total": 1452992}, {"state": "Oregon", "total": 2001336},
         {"state": "Pennsylvania", "total": 1688354}, {"state": "Rhode Island", "total": 1688354},
         {"state": "South Carolina", "total": 2103027}, {"state": "South Dakota", "total": 365988},
         {"state": "Tennessee", "total": 2475017}, {"state": "Texas", "total": 8969226},
         {"state": "Utah", "total": 1118616}, {"state": "Vermont", "total": 320467},
         {"state": "Virginia", "total": 3982752}, {"state": "Washington", "total": 3183761},
         {"state": "West Virginia", "total": 713051}, {"state": "Wisconsin", "total": 2975313},
         {"state": "Wyoming", "total": 255849}]


if __name__ == "__main__":
    electionDataGenerator = ElectionDataGenerator()
    electionDataGenerator.generateData()
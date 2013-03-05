"""
Cardinality Estimation technique
Linear Counting

Daniel Alabi
probcounter.py
"""

import random
import math

class bitset:
    def __init__(self, size):
        self.bits = (1 << size)
        self.size = size

    def set(self, pos):
        self.bits |= (1 << pos)

    def isset(self, pos):
        return self.bits & (1 << pos)

    def zeroscount(self):
        zeros = 0
        c = self.bits
        while c > 1:
            zeros += int(not(c & 1))
            c >>= 1
        return zeros

    def __repr__(self):
        c = self.bits        
        pstring = ""
        while c > 1:
            if c & 1:
                pstring += "1"
            else:
                pstring += "0"
            c >>= 1
        return pstring

def linearcounter(dataset, mapsize, shift=0):
    bitmap = bitset(mapsize)
    for item in dataset:
            bitmap.set((hash(item)+int(random.random()*shift))%mapsize) 
    nzeros = bitmap.zeroscount()
    if nzeros == 0:
        linearcounter(dataset, mapsize, shift+10)
        return
    
    return (-mapsize*math.log(float(nzeros)/float(mapsize)))

if __name__ == "__main__":
    # 200 numbers between 0 and 10
    dataset = [int(random.random()*10) for i in range(0, 200)]

    # print the no. of unique values in the dataset
    print "no. unique values: ", len((dict([(i, None) for i in dataset])).keys())

    # test mapsize 20, 30, 40, 50,60, 70, 80, 100, 120
    # load factor: 10, 6.67, 5.0, 4.0, 3.34, 2.86, 2.50, 2, 1.66
    for mapsize in [20, 30, 40, 50, 60, 70, 80, 100, 120]:
        print "load factor:", 200/float(mapsize),"; cardinality estimation:" , linearcounter(dataset, mapsize, 0)

"""
Observation:
As the mapsize increases (and as a result the load factor
decreases but the dataset is constant),
the cardinality estimation becomes more accurate.
"""

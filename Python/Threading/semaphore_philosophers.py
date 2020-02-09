import threading
from multiprocessing.dummy import Pool as ThreadPool 
from threading import Lock
import time
import pdb

#assume forks are not ordered, all are located at center
numOfForks = 6
numOfRemainingForks = numOfForks
numOfPhilosophers = 5

forksCaptured = [0]*numOfPhilosophers
numOfForksNeededToEat = 6
mealCount = [0]*numOfPhilosophers #how many meal a philosopher ate

semaphore = threading.BoundedSemaphore(numOfForks)
eating = [False]* numOfPhilosophers

lock= Lock() #for get and leave a fork

def getAFork(tNum):
    global lock, numOfRemainingForks, semaphore, forksCaptured

    lock.acquire()
    if numOfRemainingForks == 0: #if no fork
        lock.release()
        return False
    semaphore.acquire()
    numOfRemainingForks -= 1
    forksCaptured[tNum] += 1
           
    lock.release()
    
    return True

def leaveAFork(tNum):
    global lock, numOfRemainingForks, forksCaptured

    if forksCaptured[tNum] <= 0:    #if I didn't get any
        return              #couldn't leave

    lock.acquire()
    semaphore.release()
    forksCaptured[tNum] -= 1
    numOfRemainingForks += 1
    lock.release()


def eat(p):
    global semaphore, numOfRemainingForks, forksCaptured, numOfForksNeededToEat

    while True:
        #pdb.set_trace()
    
        if not getAFork(p):
            continue
        
        if forksCaptured[p] < numOfForksNeededToEat: #mine are not enough, leave all
            if numOfRemainingForks > 0:         #try to get one more     
                continue          
            else:                   #if there is no fork and mine are not enough
                while forksCaptured[p]:
                    leaveAFork(p)
                continue    #start from scratch
            
        print "{} will eat: , forks are on : {}, meal Counts: {} \n".format(p, forksCaptured, mealCount),

        eating[p] = True
        print "{} is started eating, {}\n".format(p, eating),
        mealCount[p] += 1
        time.sleep(0.5*p + 0.2)
        eating[p] = False
        print "{} is finished eating, {}\n".format(p, eating),
        
        leaveAFork(p)
        leaveAFork(p)
            

if __name__ == '__main__':
    pool = ThreadPool(numOfPhilosophers) 

    if numOfForksNeededToEat == 0:
        numOfForksNeededToEat = 1 #minimum 1

    results = pool.map(eat,[0,1,2,3,4]) #threads start not in array order

    print "x"
    time.sleep(0.5)
    input = raw_input()
    while True:
        print "x"
        time.sleep(0.5)
        input = raw_input()
        print input
        if input.index("q") >= 0 or input.index("Q") >= 0 or input.index("c") >= 0 or input.index("C") >= 0 or input.index("Z") >= 0 or input.index("z") >= 0:
            exit(0)


import threading
from multiprocessing.dummy import Pool as ThreadPool 
from threading import Lock
import time

lock= Lock()

forkNum = 5
forks = [-1]*5
locks = [Lock()]*5
eating = [False]*5

def eat(p):
    global forks, forkNum, eating
    right = False
    left=False
    
    while not right or not left:
        lock.acquire()
        print p,forks
        lock.release()
        if not right and forks[p-1] == -1: #clockwise
            forks[p-1] = p #try to get
            right = forks[p-1] == p #could I get
        if not left and forks[p] == -1: #clockwise
            forks[p] = p #try to get
            left = forks[p] == p #could I get
        
        if not right or not left: #couldn't get together, leave two, then wait
            if right:
                forks[p-1] = -1 #leaving right
                right = False
            if left:
                forks[p] = -1 #leaving left
                left = False
            time.sleep(0.1 )
        
    forkNum -= 2
    print "{} is started eating".format(p)
    eating[p] = True
    
    lock.acquire()
    print eating
    print forks
    lock.release()
    
    time.sleep(0.1* p**2 + 0.1)
    eating[p] = False
    print "{} is finished eating".format(p)
    forkNum += 2
    forks[p-1] = -1 #leaving right
    right = False
    forks[p] = -1 #leaving left
    Left = False
    
    lock.acquire()
    print forks, forkNum
    lock.release()
    

pool = ThreadPool(5) 
results = pool.map(eat,[0,1,2,3,4]) #threads start not in array order

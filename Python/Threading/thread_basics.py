import threading
from multiprocessing.dummy import Pool as ThreadPool 
from threading import Lock
import time

lock= Lock()
incremented = 0
parameter = 0

#not printing in order
def threadOrder(a):
    print "thread from {} --- currentThread: {}".format(a, str( threading.current_thread()))

def threadOrderWithNewLine(a):
    print "thread from {} --- currentThread: {}\n".format(a, str( threading.current_thread()))
 
def currentThread(a):
    global incremented, parameter
    print "thread : " + str(a)
    
    incremented += 1
    parameter = a

    print "from: " + str(a) + "--- currentThread: " + str( threading.current_thread())
    print "incremented val is: " + str(incremented)
    print "parameter val is: " + str(parameter)

def threadWithLock(a):
    print str(a) + " will sleep"
    time.sleep(0.3)
    print str(a) +  " woke up"
    
    lock.acquire()
    currentThread(a)
    lock.release()

pool0 = ThreadPool(4) 
results = pool0.map(threadOrder,['a', 'b', 'c', 'd', 'e', 'f', 'g']) #threads start not in array order
print "---------with NewLine--------------------"
results = pool0.map(threadOrderWithNewLine,['a', 'b', 'c', 'd', 'e', 'f', 'g']) #threads start not in array order

print "---------without Lock--------------------"
pool = ThreadPool(4) 
#results = pool.map(currentThread,[1,2,3,4])
print "---------with Lock--------------------"
pool2 = ThreadPool(4) 
#results = pool2.map(threadWithLock,[5,6,7,8])

print results





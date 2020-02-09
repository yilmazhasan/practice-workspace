import threading
from multiprocessing.dummy import Pool as ThreadPool 
from threading import Lock
import time
import Queue

lock= Lock()
incremented = 0
parameter = 0

q = Queue.Queue()
threadQ = Queue.Queue()

def putToQ(tupleValQ):
    time.sleep(0.1)
    global threadQ
    tupleValQ[1].put(tupleValQ[0])
    threadQ.put(threading.current_thread())
    #queue.put(val) val, queue
    return tupleValQ[0]


pool = ThreadPool(7) 
results = pool.map(putToQ, zip([i for i in range (20)], [q]*20)) #threads start not in array order

print "queue: ", 
while not q.empty():
    print q.get(),
print " "

print "threadQueue: ", 
while not threadQ.empty():
    print threadQ.get()

print "results: ", results





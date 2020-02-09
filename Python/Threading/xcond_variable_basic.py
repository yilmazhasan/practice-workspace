import threading
from multiprocessing.dummy import Pool as ThreadPool 
from threading import Lock
import time
import Queue
from collections import defaultdict
import sys
import pdb

lock= Lock()
condition= threading.Condition(lock)

numOfConsumers = 3

consumeCount = 0
allProductionCount = 0
conditionAcquirers = []

productionLimit =  sys.maxint;
resourceQ = Queue.Queue()
resourceStack = []
resourceQTaken = defaultdict(list)


def producer(num):
    global lock, condition, allProductionCount, numOfConsumers
    while True:
    
        print "producer {} attempt to acquire".format(num)
        condition.acquire()
        print "producer {} acquired".format(num)
        conditionAcquirers.append("producer_" + str(num))
        print conditionAcquirers
        time.sleep(0.5)
    
#        condition.notify()
#        print "producer notified "

#        pdb.set_trace()
        condition.notifyAll()
        print "notified All"

        time.sleep(5);

        condition.release()
        print "producer {} released".format(num) 
        del conditionAcquirers[conditionAcquirers.index("producer_" + str(num))]
        print conditionAcquirers
        
def consume(num): #first wait, if event comes then consume; if producer is faster than consumer and productions are limited, some productions will not be consumed
    global lock, condition, consumeCount

    while True:
        print "consumer {} tries to acquire".format(num)
        condition.acquire()
        print "consumer {} acquired".format(num)
        conditionAcquirers.append("consumer_" + str(num))
        print conditionAcquirers

        
        del conditionAcquirers[conditionAcquirers.index("consumer_" + str(num))]
        print conditionAcquirers
        print "consumer {} waiting".format(num)
        condition.wait() 
        print "consumer {} awaked".format(num)  #to awake notifier should release the condition
        conditionAcquirers.append("consumer_" + str(num))
        print conditionAcquirers
        
        time.sleep(1.5)

        condition.release()
        print "consumer {} released".format(num)
        del conditionAcquirers[conditionAcquirers.index("consumer_" + str(num))]
        print conditionAcquirers


thProducer = threading.Thread(target = producer, args=[1]) 
print "producer will start"
thProducer.start()
print "producer started"

consumerThreadPool = ThreadPool(numOfConsumers)
consumerThreadPool.map(consume, [i for i in range(numOfConsumers)])

consumerThreadPool.join()



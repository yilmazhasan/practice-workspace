#if resource is checked before condition.wait(), a thread can take all resources, others no any.
#Thus before checking, all threads should sync by waiting.
#condition.wait() line in consumer is important


import threading
from multiprocessing.dummy import Pool as ThreadPool 
from threading import Lock
import time
import Queue
from collections import defaultdict
import sys

lock= Lock()
condition= threading.Condition()

resourceQ = Queue.Queue()

resourceStack = []

resourceQTaken = defaultdict(list)

numOfConsumers = 3

consumeCount = 0
allProductionCount = 0
productionLimit =  sys.maxint;

def producer(num):
    global lock, condition, resourceStack, allProductionCount, productionLimit, numOfConsumers
    while True:
        print "...."
        if allProductionCount == productionLimit:
            print "----"
            return
        print "producer {} attempt to acquire".format(num)
        condition.acquire()
        print "producer {} acquired".format(num)
        resourceStack.append("val: " + str(allProductionCount))
        allProductionCount += 1
        print "resourceStack: " , resourceStack
#        if(len(resourceStack)) >= numOfConsumers:
        condition.notifyAll()
        print "notified All"
        #else:
            #print "notified one"
            #condition.notify()
        print "producer put totally {}".format(allProductionCount)

        condition.release()
        print "producer {} released".format(num) 
        
        #time.sleep(1.5)

def consume(num): #first wait, if event comes then consume; if producer is faster than consumer and productions are limited, some productions will not be consumed
    global lock, condition, resourceStack, consumeCount

    while True:
        #time.sleep(0.2) #if sleeps before acquire, then others can consume
        condition.acquire()
        print "consumer {} acquired".format(num)
        
        #time.sleep(0.5) ##if sleeps after acquire, then others can not consume
        while True:  
            print "consumer {} started waiting".format(num)
            condition.wait()
            print "consumer {} waiting end".format(num)

            if len(resourceStack) >= 1:
                resourceQTaken[num] += [resourceStack.pop()]
                consumeCount += 1
                print "consumer {} get : {}".format(num, resourceQTaken[num][-1])
                print "total consumption is {}".format(consumeCount)
                break

        print [(key,len(resourceQTaken[key])) for key in resourceQTaken.keys()]
            
        condition.release()
        print "consumer {} released".format(num)


thProducer = threading.Thread(target = producer, args=[1]) 
print "producer will start"
thProducer.start()
print "producer started"

consumerThreadPool = ThreadPool(numOfConsumers)
consumerThreadPool.map(consume, [i for i in range(numOfConsumers)])



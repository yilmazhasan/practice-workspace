import threading
from multiprocessing.dummy import Pool as ThreadPool 
from threading import Lock
import time
import Queue
from collections import defaultdict

lock= Lock()

resource = Queue.Queue()
resourceEvent = threading.Event()

resourceTaken = defaultdict(list)

consumeCount = 0
allProductionCount = 0
productionLimit = 10# sys.maxint;

def producer():
    global lock, resource, resourceEvent, allProductionCount, productionLimit
    while True:
        if allProductionCount == productionLimit:
            return
        #lock.acquire()
        resource.put("val: " + str(allProductionCount))
        allProductionCount += 1
        print "producer put totally {}".format(allProductionCount)
        resourceEvent.set()
        #lock.release()   
        
        time.sleep(0.1)

def consume_ifSignalled(num): #first wait, if event comes then consume; if producer is faster than consumer and productions are limited, some productions will not be consumed
    global lock, resource, resourceEvent, consumeCount

    while True:
        #time.sleep(0.2) #if sleeps before acquire, then others can consume
        lock.acquire()
        time.sleep(0.2) ##if sleeps after acquire, then others can not consume
        print "consumer {} waiting".format(num)
        resourceEvent.wait(0.1)
        print "asd"
        resourceEvent.clear()
        resourceTaken[num] += [resource.get()]
        consumeCount += 1
        print "total consumption num is {}".format(consumeCount)
        print "consumer {} get : {}".format(num, resourceTaken[num][-1])
        print [(key,len(resourceTaken[key])) for key in resourceTaken.keys()]
            
        lock.release()

def consume_ifResourceExists(num): #first consume, if no resource then wait : if productions are limited, this will consume all productions
    global lock, resource, resourceEvent, consumeCount

    while True:
        lock.acquire()
        if not resource.empty():
            resourceTaken[num] += [resource.get()]
            consumeCount += 1
            print "total consumption num is {}".format(consumeCount)
            print "consumer {} get : {}".format(num, resourceTaken[num][-1])
            print [(key,len(resourceTaken[key])) for key in resourceTaken.keys()]
        else:
            print "consumer {} waiting".format(num)
            resourceEvent.wait()
            resourceEvent.clear()
            
        lock.release()

thProducer = threading.Thread(target = producer) 
thProducer.start()

numOfConsumers = 3
consumerThreadPool = ThreadPool(numOfConsumers)

consumerThreadPool.map(consume_ifSignalled, [i for i in range(numOfConsumers)])





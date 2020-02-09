import threading
from multiprocessing.dummy import Pool as ThreadPool 
from threading import Lock
import time
import Queue
from collections import defaultdict

import sys

resource = Queue.Queue() #async, awaits
resourceTaken = defaultdict(list)

consumeCount = 0
allProductionCount = 0
productionLimit =  sys.maxint;

def producer(): #produce with an interval
    global resource, resourceEvent, allProductionCount, productionLimit
    while True:
        if allProductionCount == productionLimit:
            return
        resource.put("val: " + str(allProductionCount))
        allProductionCount += 1
        print "producer put totally {}".format(allProductionCount)
        
        time.sleep(1)

def consume(num): #consume whenever a production is available
    global resource, resourceEvent, consumeCount

    while True:
        print "consumer {} waiting".format(num)
        resourceTaken[num] += [resource.get()]
        consumeCount += 1
        print "total consumption num is {}".format(consumeCount)
        print "consumer {} get : {}".format(num, resourceTaken[num][-1])
        print [(key,len(resourceTaken[key])) for key in resourceTaken.keys()]


thProducer = threading.Thread(target = producer) 
thProducer.start()

numOfConsumers = 3
consumerThreadPool = ThreadPool(numOfConsumers)

consumerThreadPool.map(consume, [i for i in range(numOfConsumers)])





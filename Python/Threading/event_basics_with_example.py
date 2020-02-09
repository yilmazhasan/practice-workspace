import threading
from multiprocessing.dummy import Pool as ThreadPool 
from threading import Lock
import time
import Queue
from collections import defaultdict

import sys

toasts = []
toastEvent = threading.Event()

toastTaken = defaultdict(list)

numOfchilds = 3
produceCountInOneTime = numOfchilds

totalConsumeCount = 0
totalProducedCount = 0

produceCountLimit =  sys.maxint;

printLock = Lock()

def printSync(str):
    printLock.acquire()
    print str
    printLock.release()

def parent(): #producer
    global toasts, toastEvent, totalProducedCount, produceCountLimit
    while True:
        time.sleep(1.5)

        if totalProducedCount == produceCountLimit:
            return
        for i in range(produceCountInOneTime-1): #produce one less
            toasts.append("toast_" + str(totalProducedCount))
            totalProducedCount += 1
        
        printSync( "parent put total {} toasts".format(totalProducedCount))

        toastEvent.set() #wakes all children, toasts are ready
        toastEvent.clear() #right after clear it, or a child can clear it

def child(id): #consumer
    global toasts, toastEvent, totalConsumeCount

    while True:
        printSync( "child {} waiting".format(id))
        toastEvent.wait()
        toastEvent.clear() #right after clear it
        try:
            toastTaken[id] += [toasts.pop()] #if no in container then throws an exception
        
            totalConsumeCount += 1
            printSync( "total consumption count : {}".format(totalConsumeCount))
            printSync( "child {} get : {}".format(id, toastTaken[id][-1]))
            printSync( [(key,len(toastTaken[key])) for key in toastTaken.keys()])
        except:
            printSync( "child_{} whining about empty plate! Where is my TOAST!".format(id))

thparent = threading.Thread(target = parent) 
thparent.start()

numOfchildrs = 3
childrThreadPool = ThreadPool(numOfchildrs)

childrThreadPool.map(child, [i for i in range(numOfchildrs)])





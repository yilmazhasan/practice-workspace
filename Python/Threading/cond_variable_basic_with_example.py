import threading
from multiprocessing.dummy import Pool as ThreadPool 
from threading import Lock
import time
import Queue
from collections import defaultdict

import sys

toasts = []
toastPlateCondition= threading.Condition()

toastTaken = defaultdict(list)

numOfChilds = 3
produceCountInOneTime = numOfChilds-1

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
        time.sleep(2)

        toastPlateCondition.acquire()
        if totalProducedCount == produceCountLimit:
            return

        for i in range(produceCountInOneTime-1): #produce toasts one less but notify all
            toasts.append("toast_" + str(totalProducedCount))
            totalProducedCount += 1

        if produceCountInOneTime == numOfChilds:
            toastPlateCondition.notifyAll() #serve them all together
        else:
            for i in range(produceCountInOneTime): #produce toasts
                toastPlateCondition.notify() #serve them one by one
        
        printSync( "parent put total {} toasts".format(totalProducedCount))
        toastPlateCondition.release()

def child(id): #consumer
    global toasts, toastEvent, totalConsumeCount

    while True:
        printSync( "child {} waiting".format(id))
        toastPlateCondition.acquire()
        toastPlateCondition.wait()

        try:
            toastTaken[id] += [toasts.pop()] #if no in container then throws an exception
        
            printSync( "child {} get : {}".format(id, toastTaken[id][-1]))

            totalConsumeCount += 1
            printSync( "total consumption count : {}".format(totalConsumeCount))
            printSync( [(key,len(toastTaken[key])) for key in toastTaken.keys()])
        except:
            printSync( "child_{} whining about empty plate! Where is TOAST, you CALLED me!".format(id))
            
            time.sleep(2) #wait at least a time or next plate to be served, don't take all, let others take by one
        toastPlateCondition.release()

thparent = threading.Thread(target = parent) 
thparent.start()

numOfchildrs = 3
childrThreadPool = ThreadPool(numOfchildrs)

childrThreadPool.map(child, [i for i in range(numOfchildrs)])





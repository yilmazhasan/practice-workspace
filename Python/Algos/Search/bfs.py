#!/bin/python

import math
import os
import random
import re
import sys
from collections import defaultdict


def getUnvisitedsOfANode(fromNode, adjListDict, visiteds):
    if(adjListDict[fromNode] == []):
        return [];
    
    visitableNodes = adjListDict[fromNode]
    unvisitedNodes = []
    for city in visitableNodes:
        if(visiteds[city] == 0 and fromNode != city):
            unvisitedNodes.append(city)
    
    return unvisitedNodes;


def bfs(fromNode, pairList):

    adjListDict = defaultdict(list)

    for fromTo in pairList:
        adjListDict[fromTo[0]] += [fromTo[1]]
        adjListDict[fromTo[1]] += [fromTo[0]]


    visitableNodes = adjListDict[fromNode]
    visiteds = defaultdict(int)

    for city in visitableNodes:
        visiteds[city] = 1
    
    for city in visitableNodes:
        unvisitedNodes = getUnvisitedsOfANode(city, adjListDict, visiteds)
        for city in unvisitedNodes:
            visiteds[city] = 1
            
            visitableNodes += unvisitedNodes

    return visitableNodes

fromN = 1
pairList = [[1,2], [2,3], [3,4], [1,3], [4,5]]
print("pairList: ", pairList, "---")
print("from: ", fromN, "visitables: ", bfs(1, pairList))

           

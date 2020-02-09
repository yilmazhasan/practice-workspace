#!/bin/python

def dfs(s, adjList, visited):
#    global visited,adjList
    visited[s]=1;l=len(adjList[s]);
    print("visiting->{}".format(s))
    print(visited)
    if(l!=0): 
        for i in xrange(l):
            if(visited[adjList[s][i]]==0): 
                dfs(adjList[s][i], adjList, visited)
                



adjList = [[]]*8
pairList = [[1,3], [4,1], [2,3], [3,4], [1,3], [5,6]]
visited = [0]*8

for fromTo in pairList:
    adjList[fromTo[0]] = adjList[fromTo[0]] + [fromTo[1]]
    adjList[fromTo[1]] = adjList[fromTo[1]] + [fromTo[0]]

print(adjList)
dfs(1, adjList, visited)

           

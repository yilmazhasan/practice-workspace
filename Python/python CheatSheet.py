#PYTHON CHEATSHEET

bc = 'on' if c.page=='blog' else 'off' #ternary cond

#loop, iterate:
for idx, val in enumerate(ints):
    print(idx, val)
	
range(start,end,step)

#type mixation concat and join
"{} and {}".format("string", 1)
', '.join(str(x) for x in list_of_ints)	
	
	
ord(c) <-> chr(c) | unichr(c) #code of char c     
#array - containers
lst = [None] * 5

indices = [i for i, x in enumerate(my_list) if x == "whatever"]	#find all occurences in array

q  =Queue.Queue()	#async
q.put(val), q.get(), q.empty, q.qsize()

#list operations
filtered = filter(lambda x : x == False, citiesInConnectedComp.values()) #map(function_to_apply, list_of_inputs), reduce((lambda x,y : y-x), [2,3,4]), etc

list(set(t) - set(s))	#remove duplicates and difference

#set
Operators:
| → union (vertical bar char)
& → intersection
- ^ → difference/symmetric diff.
< <= > >= → inclusion relatio

    
#Dict
d = dict()

for i in range(1,100):
    key = i % 10
    if key in d:
        d[key] += 1
    else:
        d[key] = 1

#If you wanted a default, you can always use dict.get():

d = dict()

for i in range(100):
    key = i % 10
    d[key] = d.get(key, 0) + 1

#... and if you wanted to always ensure a default value for any key you can use defaultdict from the collections module, like so:
from collections import defaultdict

d = defaultdict(int)	  #giving type is crucial, if not the same with normal dict()

for i in range(100):
    d[i % 10] += 1

#itrerate over dict	
for k,v in d.iteritems():  
	
#sort dict by key
dic  = collections.OrderedDict(sorted(dic.items()))
	
#max min values
sys.maxint    

#rest parameter
def wrapper(func, *args):
	
	
#IO
# print options - to remove newline from print add comma end, e.g. "print(),"
sep=" " #items separator, default space
end="\n" #end of print, default new line
#read stdin
from sys import stdin
x = stdin.read(1) #reads char
userinput = stdin.readline()

set1 = [float(x)  for x  in line if not x.isspace()]

#read file
f = open("file.txt", "r")
for x in f:

with open(…) as f:
 for line in f :
 # processing ofline

f = open("file.txt","w",encoding="utf8") #modes: r,w,a ... + x,b,t

file=sys.stdout #print to file, default standard output

#decimal
print ("%.1f" % fnum);

####
import fileinput

for line in fileinput.input():
    pass
    print(line)
	
	line.split
####
name = input("Enter your name: ")	
name = raw_input("Enter your name: ")	
	
	
####
with open('myfile.txt') as f:
first_line = f.readline()
	
#addition, vector
import operator
tuple(map(operator.add, a, b))	
	
##type conversion #type cast
float(n)
results = list(map(int, results))
		
#Array actions: 
numbers.sort(reverse = True) 

#line continuation
a = '1' + '2' + '3' + \
    '4' + '5'


#copy
from copy import copy, deepcopy
copy.copy(c) # shallow copy of container
copy.deepcopy(c) # deep copy of container

#built-in functions
bit(num) #bit representation
bytearray()
iter() #takes an iterable and return val can be used with next()
next()
slice(start, stop, step) # eqto String[-1:-4:-1] (gives reverse order) - slice returns an slice obj which can be used as [index] value for array, string or tuple

#Generic operations:
len(c) # items count
min(c) max(c) sum(c)
sorted(c) # list sorted copy
val in c # boolean, membership operator in (absence not in)
enumerate(c) #iterator on (index, value)
zip(c1,c2…)  #iterator e.g [(c1i, c2i)], combines all iterables
zip(*zipIterObj) #unzips returns c1, c2
all(c) # True if all c items evaluated to true, else False
any(c) # True if at least one item of c evaluated true, else False


#Signaling an error: 
raise ExcClass(..)
#Errors processing:
try:
 #normal procesising block
except Exception as e:


#import
from monmod import nom1,nom2 as fct

import monmod # access via monmod.nom1 …
##modules and packages searched in python path (cf sys.path)

#Dummy notes: be careful about tab and 4 space for indent in text editors


#cheat sheet elementary
#https://perso.limsi.fr/pointal/_media/python:cours:mementopython3-english.pdf


#iter
# list of vowels
vowels = ['a', 'e', 'i', 'o', 'u']
vowelsIter = iter(vowels)
# prints 'a'
print(next(vowelsIter))



#Advanced

import time

start = time.time()
print("hello")
end = time.time()
print(end - start) #elapsed time

pyObj = compile(source, filename, mode, flags=0, dont_inherit=False, optimize=-1) #returns an python object
#mode - Either exec or eval or single
eval(pyObj)
exec(pyObj)

codeInString = 'a = 5\nb=6\nsum=a+b\nprint("sum =",sum)'
codeObejct = compile(codeInString, 'sumstring', 'exec')

exec(codeObejct)

#source - a normal string, a byte string, or an AST object
#filename - file from which the code was read. If it wasn't read from a file, you can give a name yourself
#mode - Either exec or eval or single.
#eval - accepts only a single expression.
#exec - It can take a code block that has Python statements, class and functions and so on.
#single - if it consists of a single interactive statement
#flags (optional) and dont_inherit (optional) - controls which future statements affect the compilation of the source. Default Value: 0
#optimize (optional) - optimization level of the compiler. Default value -1.


#to look

Python3 bytes() : arr = bytes(size), rList = [1, 2, 3, 4, 5], arr = bytes(rList) #arr is b'\x01\x02\x03\x04\x05'
Python compile()
Python zip()
Python slice()






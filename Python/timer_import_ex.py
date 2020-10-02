import timeit

def foo():
    print("s")
# ... contains code I want to time ...

def dotime():
    t = timeit.Timer("foo()", "from __main__ import foo")
    time = t.timeit(1)
    print "took %fs\n" % (time,)

dotime()
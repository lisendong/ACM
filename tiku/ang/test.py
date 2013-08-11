import sys
from random import *
n = 10
m = 50
#print str(n)+" "+str(m)
print 1
print n
a = dict()
for i in range(1, n+1):
    a[i] = 0
for i in range(m):
    command =randint(1, 4)
    left = randint(1, 10)
    right = randint(left, 10)
    if command == 4:
        data = randint(1, 3)
    else:
        data = randint(1, 10000)
    print str(command)+" "+str(left)+" "+str(right)+" "+str(data)
    if command == 1:
        for i in range(left, right+1):
            a[i]+=data
    if command == 2:
        for i in range(left, right+1):
            a[i]*=data
    if command == 3:
        for i in range(left, right+1):
            a[i]=data
    if command == 4:
        isum = 0
        for i in range(left, right+1):
            isum+=pow(a[i], data)
        print "#"+str(isum%10007)
print "0 0"

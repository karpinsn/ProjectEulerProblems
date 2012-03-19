from functools import reduce
from itertools import product, starmap
from operator import mul 
import time

GlobalFactorList = []

# http://stackoverflow.com/questions/6800193/what-is-the-most-efficient-way-of-finding-all-the-factors-of-a-number-in-python
def factors(n):
    if len(GlobalFactorList) > n:
        return GlobalFactorList[n - 1]
    
    return sorted(list(set(reduce(list.__add__, ([i, n//i] for i in range(1, int(n**0.5) + 1) if n % i == 0)))))

def quad2Tri(quad):
    a = quad[2] + quad[1]
    a = a / 2 if a % 2 == 0 else 0

    b = quad[2] + quad[0]
    b = b / 2 if b % 2 == 0 else 0

    c = quad[1] + quad[0]
    c = c / 2 if c % 2 == 0 else 0

    if not a+b+c == quad[3]:
        a = 0 

    return (a,b,c)

def isValidTri(triangle):
    return triangle[0] > triangle[1] and triangle[1] > triangle[2] and triangle[1] + triangle[2] > triangle[0] 

def number2Quads(number, currentQuad, quads):
    if 3 == len(currentQuad):
        if currentQuad[2] <= number:
            quads.append(currentQuad + (number,))
        return 
        
    
    facts = factors(number) 
   
    for i in range(2, len(facts)):
        if len(currentQuad) == 0 or currentQuad[len(currentQuad) - 1] <= facts[i]:    
            quad = currentQuad + (facts[i],) 
            number2Quads(number / facts[i], quad, quads) 

    return quads

def checkFactor(factor, n):
    radiusSum = 0
    currentQuad = ()
    quads = []
    quadSets = number2Quads(factor*factor, currentQuad, quads)

    for quad in quadSets:
        tri = quad2Tri(quad)
        if isValidTri(tri):
            num = tri[0]*tri[1]*tri[2]

            if num % factor == 0:
                radius = num / factor
                if radius <= n:
                    radiusSum = radiusSum + radius
                    print "Factor: ", factor, " tri: ", quad2Tri(quad), " quad: ", quad, " radius: ", radius
    
    return radiusSum


print "Generating factors for (", len(GlobalFactorList) - 1, ",", 1000, ")"
'''
for n in range(1, 10000):
    GlobalFactorList.append(sorted(list(set(reduce(list.__add__, ([i, n//i] for i in range(1, int(n**0.5) + 1) if n % i == 0))))))
   ''' 
radiusSum = 0
n = 1000000000

print factors(96)

quad = (1000, 2000, 3000, 6000)
tri = quad2Tri(quad)
print tri

'''
for factor in xrange(96, 1000000, 96):
    factors(factor)
    radius = checkFactor(factor, n)
    if radius:
        radiusSum += radius
        #print "Current radial sum: ", radiusSum
'''
print "S(n): ", radiusSum

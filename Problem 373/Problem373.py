import math

def divisibleByTwo(number):
    # Could do this with bit manipulation for speed
    return number % 2 == 0

def quickRoot(number):
    intRoot = int(math.sqrt(number))
    return intRoot if intRoot**2 == number else 0

def radiFinder(triangle):
    s = (triangle[0] + triangle[1] + triangle[2])
    if not divisibleByTwo(s):
        return 0
    
    s /= 2
    denom = 4 * quickRoot(s*(s-triangle[0])*(s-triangle[1])*(s-triangle[2]))
    if not denom:
        return 0

    num = triangle[0] * triangle[1] * triangle[2]
    
    return num / denom if num % denom == 0 else 0

n = 100  
S = 0
triangleCount = 0

for a in xrange(1, n * 2 + 1):
    for b in xrange(a/2, a + 1):
        for c in xrange(a - b + 1, b + 1):   
            temp = radiFinder((a, b, c))
            triangleCount = triangleCount + 1
            if temp and temp <= n:
                S = S + temp
                num = math.degrees(math.acos(math.fabs(b**2 + c**2 - a**2)/(2*b*c))) 
          
                factor = (a+b+c)*(a+b-c)*(a-b+c)*(-a+b+c)
                factor = factor**.5
                #if not factor % 96 == 0:
                print (a,b,c), " ", temp, " ", num, factor % 96 == 0
                


print "Total Triangles: ", triangleCount
print "S (", n, ") = ", S


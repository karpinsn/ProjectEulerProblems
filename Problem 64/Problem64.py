import math

oddPeriod = 0

for n in xrange(1, 10000):
    azero = int(math.sqrt(n))
    if azero**2 == n:
        # Perfect square, no continued fraction
        continue

    a = azero
    m = 0
    d = 1
    period = 0

    while True:
        if a == 2 * azero:
            # Found the end of the period
            break

        m = d * a - m
        d = (n - m**2) / d
        a = (azero + m) / d
        period += 1

    if period % 2 == 1:
        oddPeriod += 1
    #print "Period n = ", n, ": ", period 

print oddPeriod

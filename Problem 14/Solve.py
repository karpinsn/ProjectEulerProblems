def EvenRule(number):
    return number/2

def OddRule(number):
    return (3*number) + 1

chainLength = 1 
maxStart = 1
maxChain = 1

for number in xrange(1,1000000):
    chainLength = 1
    start = number
    while(number != 1):
        if number%2 == 0:
            number = EvenRule(number)
            chainLength += 1
        else:
            number = OddRule(number)
            chainLength += 1
        
    if chainLength >= maxChain:
        maxChain = chainLength
        maxStart = start 
        print "MaxChain: ", maxChain, " Num: ", maxStart

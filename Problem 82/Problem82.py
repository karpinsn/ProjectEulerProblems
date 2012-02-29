# Project Euler - Problem 82 

import heapq
import csv

def int_wrapper(reader):
    for v in reader:
        yield map(int, v)

Inf = 2147483648

# This time only looking for an end column
endLocation = 79

# Stores the next possible places
possiblePlaces = []
grid = []

gridReader = csv.reader(open("Matrix.csv", "rb"))
#gridReader = csv.reader(open("TestMatrix.csv", "rb"))
gridReader = int_wrapper(gridReader)

for row in gridReader:
    grid.append(row)

# Create a list the holds the solution
minDist = []
for row in range(0, len(grid)):
    minDist.append([])
    for col in range(0, len(grid[row])):
        minDist[row].append((Inf, False))

# Now add all the possible starting locations
for row in range(0, len(grid)):
    heapq.heappush(possiblePlaces, (grid[row][0], (row,0)))

while possiblePlaces:
    (current, index) = heapq.heappop(possiblePlaces)

    # Check if we are at the final location
    if index[1] == endLocation:
        print "We found it!"
        print current
        break

    if minDist[index[0]][index[1]][1]:
        print "Found a duplicate!"
        # We have been here before so skip over it
        # We can do this as the same possiblePlace 
        # can exist multiple times in the queue
        continue

    # Check for one to the right
    if index[1] + 1 < len(grid[index[0]]):
        # Grab the right location 
        right = grid[index[0]][index[1] + 1] 

        if not minDist[index[0]][index[1] + 1][1]:
            # Have not been here before
            if current + right < minDist[index[0]][index[1] + 1][0]:
                # Our distance is smaller, then use it!
                minDist[index[0]][index[1] + 1] = (current + right, False)
                heapq.heappush(possiblePlaces, (current + right, (index[0], index[1] + 1)))
    
    # Check for one downwards
    if index[0] + 1 < len(grid):
        # Grab the down location
        down = grid[index[0] + 1][index[1]]  

        if not minDist[index[0] + 1][index[1]][1]:
            # Have not been here before
            if current + down < minDist[index[0] + 1][index[1]][0]:
                minDist[index[0] + 1][index[1]] = (current + down, False)
                heapq.heappush(possiblePlaces, (current + down, (index[0] + 1, index[1])))

    # Check upwards
    if index[0] - 1 >= 0:
        # Grab the up location
        up = grid[index[0] - 1][index[1]]

        if not minDist[index[0] - 1][index[1]][1]:
            # Have not been here before
            if current + up < minDist[index[0] - 1][index[1]][0]:
                minDist[index[0] - 1][index[1]] = (current + up, False)
                heapq.heappush(possiblePlaces, (current + up, (index[0] - 1, index[1])))

    # Finalize the current location
    minDist[index[0]][index[1]] = (current, True)


#for row in range(0, len(grid)):
 #   print minDist[row]

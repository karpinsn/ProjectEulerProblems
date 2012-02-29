# Project Euler - Problem 83 

import heapq
import csv

def int_wrapper(reader):
    for v in reader:
        yield map(int, v)

Inf = 2147483648

endLocation = (79, 79)
#endLocation = (80, 80)
#endLocation = (4, 4)

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

heapq.heappush(possiblePlaces, (grid[0][0], (0,0)))

while possiblePlaces:
    (current, index) = heapq.heappop(possiblePlaces)

    # Check if we are at the final location
    if index == endLocation:
        print "We found it!"
        print current
        break

    if minDist[index[0]][index[1]][1]:
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

    # Check for one to the left
    if index[1] - 1 >= 0:
        # Grab the right location 
        left = grid[index[0]][index[1] - 1] 

        if not minDist[index[0]][index[1] - 1][1]:
            # Have not been here before
            if current + left < minDist[index[0]][index[1] - 1][0]:
                # Our distance is smaller, then use it!
                minDist[index[0]][index[1] - 1] = (current + left, False)
                heapq.heappush(possiblePlaces, (current + left, (index[0], index[1] - 1)))

    # Check for one down
    if index[0] + 1 < len(grid):
        # Grab the down location
        down = grid[index[0] + 1][index[1]]  

        if not minDist[index[0] + 1][index[1]][1]:
            # Have not been here before
            if current + down < minDist[index[0] + 1][index[1]][0]:
                minDist[index[0] + 1][index[1]] = (current + down, False)
                heapq.heappush(possiblePlaces, (current + down, (index[0] + 1, index[1])))

    # Check for one down
    if index[0] - 1 >= 0:
        # Grab the down location
        up = grid[index[0] - 1][index[1]]  

        if not minDist[index[0] - 1][index[1]][1]:
            # Have not been here before
            if current + up < minDist[index[0] - 1][index[1]][0]:
                minDist[index[0] - 1][index[1]] = (current + up, False)
                heapq.heappush(possiblePlaces, (current + up, (index[0] - 1, index[1])))

    minDist[index[0]][index[1]] = (current, True)


#for row in range(0, len(grid)):
 #   print minDist[row]

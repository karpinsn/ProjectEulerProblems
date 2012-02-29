rows = [[int(n) for n in s.split(',')] for s in open('Matrix.csv').readlines()]
nrows = len(rows)-1

for i in range(nrows, -1, -1):
     for j in range(nrows, -1, -1):
         if (i==nrows and j==nrows): continue    #these 4 lines check for out-of-bounds conditions
         if (j==nrows): minx = rows[i+1][j]
         elif (i==nrows): minx = rows[i][j+1]
         else: minx = min(rows[i+1][j], rows[i][j+1])
         rows[i][j] += minx

print "Answer to PE81 = ", rows[0][0]

import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

map = []

h, w = [int(i) for i in input().split()]
for i in range(h):
    row = input()
    map.append([x for x in row.split()])

print(map)

meilleur = 0

mouv = [[0,1],[1,0],[0,-1],[-1,0]]

#on cherche X dans map
for i in range(h):
    for j in range(w):
        if map[i][j] == 'X':
            x = i
            y = j
            break


# Write an answer using print
# To debug: print("Debug messages...", file=sys.stderr, flush=True)

print("answer")

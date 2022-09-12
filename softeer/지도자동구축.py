import sys
import math

N = int(input())

result = 2
for i in range(N):
    result += math.pow(2, N-i-1)

print(int(math.pow(result,2)))

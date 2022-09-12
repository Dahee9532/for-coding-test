import sys

M, N, K = map(int, input().split())


mString =  input()

nString =  input()

if(nString.find(mString) != -1):
    print("secret")

if(N < M or nString.find(mString) == -1):
    print("normal")
    exit()

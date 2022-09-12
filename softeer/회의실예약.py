import sys

N, M = map(int, input().split())

roomName = []
for i in range(N):
    roomName.append(input())

roomName.sort()

reserveList = []
for i in range(M):
    reserveList.append(input())

for i in range(N):
    if(i != 0):
        print("-----")
    print("Room "+roomName[i]+":")
    timeList = []
    countList = 0
    for j in range(M):
        if(reserveList[j].split( )[0] == roomName[i]):
            countList+=1
            timeList.append(int(reserveList[j].split( )[1]))
            timeList.append(int(reserveList[j].split( )[2]))
    if not timeList:
        print("1 available:\n09-18")

    else:
        timeList.sort()
        avaTime = []

    # 9 12 12 15 15 18
    # 11 12 16 18
    # 10 11 14 16

        for k in range(int(len(timeList)/2)+1):
            if(k == 0):
                start = 9
            else:
                start = timeList[2*k-1]

            if(k == int(len(timeList)/2)):
                end = 18
            
            else:
                end = timeList[2*k]
                
            if(int(start) == int(end)):
                continue

            if(int(start) == 9): 
                start = str("09")
            avaTime.append(str(start)+"-"+str(end))

        if not avaTime:
            print("Not available")
        else:
            print(len(avaTime),"available:")
            for l in avaTime:
                print(l)

        

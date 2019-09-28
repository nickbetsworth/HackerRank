#https://www.hackerrank.com/challenges/minimum-distances/problem

def minimumDistance(a):
    lastSeen = {}
    minDists = {}

    for id, val in enumerate(a):
        # If this is a value we have not yet encountered, add it to the last seen
        if val not in lastSeen:
            lastSeen[val] = id
        else:
            distance = id - lastSeen[val]
            if val not in minDists:
                minDists[val] = distance
            else:
                minDists[val] = min(minDists[val], distance)

    if len(minDists) == 0:
        return -1
    else:
        return min(minDists.values())
            
if __name__ == '__main__':
    n = int(input())
    a = list(map(int, input().rstrip().split()))

    result = minimumDistance(a)

    print(result)
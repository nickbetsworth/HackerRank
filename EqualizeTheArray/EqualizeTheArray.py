#https://www.hackerrank.com/challenges/equality-in-a-array/problem

import collections

# Complete the equalizeArray function below.
def equalizeArray(arr):
    counts = collections.Counter(arr)
    return len(arr) - max(counts.values())

n = int(input())
arr = list(map(int, input().rstrip().split()))

result = equalizeArray(arr)

print(result)

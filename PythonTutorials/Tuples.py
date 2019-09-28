#https://www.hackerrank.com/challenges/python-tuples/problem

if __name__ == "__main__":
    _ = int(input())

    inputTuple = tuple(map(int, input().split()))
    print(hash(inputTuple))
#https://www.hackerrank.com/challenges/python-lists/problem

def performAction(action, list):
    args = action.split()
    actionString = args[0]
    if args[0] == 'print':
        print(list)
    else:
        getattr(list, args[0])(*map(int, args[1:]))

if __name__ == "__main__":
    n = int(input())

    list = []
    [performAction(input(), list) for _ in range(n)]
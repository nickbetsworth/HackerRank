#https://www.hackerrank.com/challenges/repeated-string/problem

if __name__ == "__main__":
    s = input()
    n = int(input())

    # Count how many times we would traverse the input string in its entirety given n
    numFullTraversals = n // len(s)

    # Work out how far along the string we would get on the final traversal
    numCharsLastTraversal = n % len(s)

    # Count the number of a's per whole loop of the input string
    total = s.count('a') * numFullTraversals + s[:numCharsLastTraversal].count('a')

    print(total)
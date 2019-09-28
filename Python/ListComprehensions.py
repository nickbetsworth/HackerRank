#https://www.hackerrank.com/challenges/list-comprehensions/problem

# Useful reading:
# https://docs.python.org/3/tutorial/datastructures.html#list-comprehensions
# "A list comprehension consists of brackets containing an expression followed by a for clause, then zero or more for or if clauses."

if __name__ == "__main__":
    x, y, z, n = (int(input()) for _ in range(4))

    print([[a, b, c] for a in range(x+1) for b in range(y+1) for c in range(z+1) if a+b+c != n])
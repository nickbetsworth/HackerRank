#https://www.hackerrank.com/challenges/nested-list/problem

if __name__ == '__main__':
    nameScores = []
    for _ in range(int(input())):
        name = input()
        score = float(input())

        nameScores.append((name, score))

    uniqueScores = set([i[1] for i in nameScores])
    secondLowestScore = sorted(uniqueScores)[1]

    lowestNameScores = filter(lambda x: x[1] == secondLowestScore, nameScores)
    lowestNames = sorted([name for name,_ in lowestNameScores])

    print(*lowestNames, sep='\n')
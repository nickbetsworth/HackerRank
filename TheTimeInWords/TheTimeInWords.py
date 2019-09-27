#https://www.hackerrank.com/challenges/the-time-in-words/problem

digitsToWord = {
    1: 'one',
    2: 'two',
    3: 'three',
    4: 'four',
    5: 'five',
    6: 'six',
    7: 'seven',
    8: 'eight',
    9: 'nine',
    10: 'ten',
    11: 'eleven',
    12: 'twelve',
    13: 'thirteen',
    14: 'fourteen',
    15: 'quarter',
    16: 'sixteen',
    17: 'seventeen',
    18: 'eighteen',
    19: 'nineteen',
    20: 'twenty',
    30: 'half'
}

def getMinutesString(m):
    if m == 30:
        return digitsToWord[m]
    elif m % 15 == 0:
        return digitsToWord[m % 30]
    
    # If we're past half past, we want to count backwards
    if m > 30:
        m = 60 - m

    if m > 20:
        # Trickery to avoid having definitions 21 -> 29
        return digitsToWord[20] + ' ' + digitsToWord[m-20] + ' minutes'
    else:
        return digitsToWord[m] + ' minute' + ('s' if m > 1 else '')

def getDirection(m):
    if m > 30:
        return 'to'
    else:
        return 'past'

def getHourString(h, m):
    if m > 30:
        return digitsToWord[h + 1]
    else:
        return digitsToWord[h]

def convertToWords(h, m):
    if m == 0:
        return digitsToWord[h] + " o' clock"
    
    return getMinutesString(m) + ' ' + getDirection(m) + ' ' + getHourString(h, m)


if __name__ == '__main__':
    h = int(input())
    m = int(input())

    print(convertToWords(h, m))
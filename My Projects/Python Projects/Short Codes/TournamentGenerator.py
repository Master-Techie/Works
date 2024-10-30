# import random

def t_fixtures(n,l):
    matches = []
    fixtures = []

    for k in range(1,n):
        for i in range(n//2):
            matches.append((l[i], l[n-i-1]))
        l.insert(1,l.pop())
        fixtures.extend(matches)
        matches = []

    return fixtures

    # print(fixtures)

# t_fixtures(4,["a","b","c","d"])
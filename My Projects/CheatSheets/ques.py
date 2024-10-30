"""
def cons_sel(d={}):
    vowels = "AEIOUaeiou"
    for i in d:
        if d[i][0] not in vowels:
            print(d[i])

a = {1:"Python", 2:"Internet Fundamentals ", 3:"Networking ", 
4:"Oracle sets", 5:"Understanding HTML"}

cons_sel(a)
"""


"""
def search_word(s="",q=""):
    l = s.split()
    c = 0
    for i in l:
        if q.lower() == i.lower():
            c += 1
    return c

STRING = "Learning history helps to know about history with interest in history"
SEARCH = "history"

f = search_word(STRING,SEARCH)
print("The word",SEARCH,"occurs",f,"times.")
"""


d1 = {"Delhi":20,"Mumbai":50}
d1.pop("Mumbai")
print(d1)

"""
mystr = "Computer Science"
print(mystr[::2])
"""



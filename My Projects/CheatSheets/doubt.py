mon = {"JAN":31,"FEB":28,"MAR":31,"APR":30,"MAY":31,"JUN":30,"JLY":31,"AUG":31,"SEP":30,"OCT":31,"NOV":30,"DEC":31}

l1 = []
for i in mon:
    l1.append([mon[i], i])
l1.sort()

l2 = []
for j in l1:
    l2.append([j[1] ,j[0]])

mon_sorted = dict(l2)
print(mon_sorted)
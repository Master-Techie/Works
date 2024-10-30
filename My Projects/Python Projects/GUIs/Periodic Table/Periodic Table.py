from tabulate import tabulate

f1 = open("Periodic_Table1.txt","r")
f2 = open("Periodic_Table2.txt","r")

l1 = f1.read().split("\n")
l = []
for i in l1:
    x = i.split(",")
    l.append(x)

l2 = f2.read().split("\n")
lst = []
for i in l2:
    x = i.split(",")
    lst.append(x)

for i in range(1,8):
    l[i-1].insert(0,i)

table1 = tabulate(l[:7], headers=[i for i in range(1,19)], tablefmt="grid")
table2 = tabulate(l[7:], tablefmt="grid")

print("Periodic Table :-\n")
print(table1,"\n")
print(table2)

details = ["Name","Atomic Number","Type of element","Group Number","Period Number","Block","Atomic Mass","State of element","Density (in gm/cc)","Electronegativity","Electronic Configuration","Symbol"]

while True:
    print(f"\n{'-'*112}\n")
    s = input("Enter the symbol, or atomic number, or name of the element (Press 'quit' to exit) : ").capitalize()
    print()

    for i in lst:
        if (i[-1] == s or (i[0] == s) or (i[1] == s)):
            for j in range(-1,11):
                print(f"{details[j]} : {i[j]}")

    if s == "Quit":
        break

f1.close()
f2.close()
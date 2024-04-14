f = open("input.txt", "r")
s = f.read()
f.close()

for i in range(4, len(s)):
    c = 1
    for j in range(i - 4, i):
        for k in range(i - 4, j):
            if k != j and s[k] == s[j]:
                c = 0
    if c == 1:
        print(i)
        break

for i in range(14, len(s)):
    c = 1
    for j in range(i - 14, i):
        for k in range(i - 14, j):
            if k != j and s[k] == s[j]:
                c = 0
    if c == 1:
        print(i)
        break
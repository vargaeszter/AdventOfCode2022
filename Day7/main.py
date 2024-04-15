class Folder:
  def __init__(self, name):
    self.name = name
    self.children = []
    self.size = 0

def getTotalSize(folder: Folder):
    for child in folder.children:
        folder.size = folder.size + getTotalSize(child)

    return  folder.size

def findMaxDeletableSize(folder: Folder):
    if folder.size <= 100000:
        sum = folder.size
        for child in folder.children:
            sum = sum + findMaxDeletableSize(child)
        return sum
    else:
        sum = 0
        for child in folder.children:
            sum = sum + findMaxDeletableSize(child)
        return sum

def fullSpace(folder: Folder):
        sum = folder.size
        for child in folder.children:
            tmp = fullSpace(child)
            sum = sum + tmp
        return sum


def findFolderToDelete(folder: Folder, threshold: int):
    minChild = 70000000
    sum = folder.size
    hasOnlySmallChild = True
    tmp = 0
    for child in folder.children:
        tmp = findFolderToDelete(child, threshold)
        if tmp >= threshold and tmp <= minChild:
            hasOnlySmallChild = False
            sum = tmp
            minChild = tmp
        if hasOnlySmallChild:
            sum = sum + tmp
    return sum


f = open("input.txt", "r")
input = f.read()
f.close()

rootname = "/"
root = Folder(rootname)
stack = [root]
temp = root

for s in input.splitlines():
    line = s.split(' ')
    if s[0] == '$':
        if len(line) == 3:
            if line[2] != "..":
                folder = Folder(line[2])
                temp.children.append(folder)
                temp = folder
                stack.append(temp)
            else:
                stack.pop()
                temp = stack[len(stack) - 1]
    elif len(line) == 2:
        if line[0] != "$" and line[0] != "dir":
            temp.size = temp.size + int(line[0])


extraNeededSpace = 30000000 - (70000000 - fullSpace(root))

print(findFolderToDelete(root, extraNeededSpace))

getTotalSize(root)

print(root.size)

print(findMaxDeletableSize(root))
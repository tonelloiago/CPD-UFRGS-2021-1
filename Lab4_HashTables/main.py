from Hashing import *

"""
Read input file and separate lines
"""

def readFile(inputFile):
    with open(inputFile) as file:

        dataSet = []

        for line in file:
            line = line.replace("\n", "")
            dataSet.append(line)
    
    return dataSet
            

words = readFile('nomes_10000.txt')
querys = readFile('consultas.txt')

testSizes = [503, 2503, 5003, 7507]

size = testSizes[0] - 1

nomes_10k = Hashing(size)

for i in range(len(words)):
    nomes_10k.insertIntoTable(words[i], size)

maximo = 0
sum = 0
for name in querys:
    queryResult = nomes_10k.hashTableQuery(name, size)

    sum += queryResult

    if queryResult > maximo:
        maximo = queryResult

media = sum / len(querys)

print(maximo)
print(media)


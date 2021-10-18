from Hashing import *
import os
import glob

"""
#Remove files from previous runs
"""
def cleanSaidas():

    txt_files = glob.glob('saidas/*.txt')

    for txt_file in txt_files:
        try:
            os.remove(txt_file)
        except OSError as e:
            print(f"Error:{ e.strerror}")

"""
Write output files
"""
def writeFile(phrase, fileName):
    with open(fileName, "a") as file:
        file.write(phrase)
        file.close()


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



#Read files
words = readFile('nomes_10000.txt')
querys = readFile('consultas.txt')

#Remove files from previous runs
cleanSaidas()

testSizes = [503, 2503, 5003, 7507]

#Insert and calculates for each test size
for sizeIn in testSizes:
    size = sizeIn - 1

    #Initialize hash table
    nomes_10k = Hashing(size)

    #Insert names in the hash table
    for i in range(len(words)):
        nomes_10k.insertIntoTable(words[i], size)

    maximum = 0
    sum = 0

    path = "saidas/experimento" + str(sizeIn) + ".txt"

    for name in querys:

        queryResult = nomes_10k.hashTableQuery(name, size)
        writeFile(f'{name} {queryResult}\n', path)

        sum += queryResult

        if queryResult > maximum:
            maximum = queryResult

    avg = sum / len(querys)

    writeFile(f'MEDIA {avg}\n', path)
    writeFile(f'MAXIMO {maximum}\n', path)


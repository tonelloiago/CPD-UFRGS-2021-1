from sortingAlgorithms import shellSort

def writeFile(fileName, arr):
    file = open(fileName, "w")

    for element in arr:
        if element == arr[len(arr) - 1]:
            file.write(str(element))
        else:
            file.write(str(element))
            file.write(" ")
    
    file.close()
    
def readFile(fileName):

    try:
        file = open(fileName, "r")

        array = []

        for line in file:
            input = list(map(int, line.split()))    
            size = input[0]

            del(input[0])
           
            print(input)


            shellSort(input, size)


            #AQUI É O LAÇO QUE CONTROLA O PROCESSO

                            

        file.close()
        return array
    except:
        return -1

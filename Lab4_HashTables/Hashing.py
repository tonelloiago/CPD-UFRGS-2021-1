class Hashing:

    #Constructor
    def __init__(self, hashTableSize):

        #Initialize table
        self.table = []

        for i in range(hashTableSize):
            self.table.append([])
      
    """
    Function: c0.a^k-1 + c1.a^k-2 + ... + ck-2.a^1 + ck-1.a^0

    In this case: a = 41, k = carac index
    """
    def hashingFunction(self, str, hashTableSize):

        indexCalculated = 0
        updatedSize = len(str) - 1

        try:

            i = 0

            while i < len(str):
                indexCalculated += ord(str[i]) * (37 ** updatedSize)
                i += 1
                updatedSize -= 1
        
        except:
            print("hm") #String vazia

        return indexCalculated % hashTableSize

#Insere um novo nome na tabela
    def insertIntoTable(self, word, hashTableSize):

        index = self.hashingFunction(word, hashTableSize)
        self.table[index].append(word)

#Realiza uma consulta na tabela
    def hashTableQuery(self, toFind, hashTableSize):
        
        colisions, count = 0, 0
        index = self.hashingFunction(toFind, hashTableSize)

        for name in self.table[index]:

            count += 1

            if name == toFind:
                colisions += 1
                break 

            elif count == len(self.table[index]):
                colisions = len(self.table[index]) + 1

            else: 
                colisions += 1

        return colisions


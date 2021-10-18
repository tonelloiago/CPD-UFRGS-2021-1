class Hashing:

    #Constructor
    def __init__(self, hashTableSize):

        #Initialize table
        self.table = []

        for i in range(hashTableSize):
            self.table.append([])
      
    """
    Function: c0.a^k-1 + c1.a^k-2 + ... + ck-2.a^1 + ck-1.a^0

    In this case: a = 37, k = carac index
    """
    def hashingFunction(self, str, hashTableSize):

        i = 0
        indexCalculated = 0
        updatedSize = len(str) - 1

        while i < len(str):
            indexCalculated += ord(str[i]) * (37 ** updatedSize)
            i += 1
            updatedSize -= 1

        return indexCalculated % hashTableSize

    #Inserts the name in table
    def insertIntoTable(self, word, hashTableSize):

        index = self.hashingFunction(word, hashTableSize)
        self.table[index].append(word)

    #Performs a query on the table
    def hashTableQuery(self, toFind, hashTableSize):
        
        colisions = 0
        index = self.hashingFunction(toFind, hashTableSize)

        for name in self.table[index]:


            #Return 1 if don't have colisions
            if name == toFind:
                colisions += 1
                break 
            else: 
                colisions += 1

        return colisions


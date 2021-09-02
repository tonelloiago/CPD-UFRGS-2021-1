def shell_sort_test(dna_seq):

    changes = 0
 
    for i in range(len(dna_seq)):   

        temp = dna_seq[i]
        j = i -1

        while  j >= 0 and ord(dna_seq[j]) > ord(temp):
            dna_seq[j+1] = dna_seq[j]
            changes += 1
            j -= 1

        dna_seq[j+1] = temp

    return changes



def process(dna_seq, words):

    dict_seq = {}

    for i in range(words):
        word = list(dna_seq[i])
        n_changes = shell_sort_test(word)
        dict_seq[dna_seq[i]] = n_changes

    dictSorted = {k: v for k, v in sorted(dict_seq.items(), key=lambda item: item[1])}

    for key in dictSorted.keys():
        print(key)  


def main():
    num_sets = int(input())
    
    while num_sets > 0:

        string = input()  
        
        dnaSequence = []
        if string:
  
            lenght, words = map(int, (string.split()))

            count = 0
            while count < words:

                strAux = input()

                if strAux:
                    dnaSequence.append(strAux)
                    count += 1

            process(dnaSequence, words)
            print()
        
            num_sets -= 1
        

if __name__ == "__main__":
    main()


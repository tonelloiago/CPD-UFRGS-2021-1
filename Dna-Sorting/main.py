import sys

def get_arguments():
    arguments = sys.argv
    del arguments[0]    #.py file

    if not arguments:
        raise Exception("Please include path to input file.")
    
    return arguments[0] #Input file path


def shell_sort_test(args, dna_seq):

    changes = 0
    n = len(dna_seq)
    gap = n//2
  
    while gap > 0:
        
        for i in range(gap,n):   

            temp = dna_seq[i]
            j = i

            while  j >= gap and ord(dna_seq[j-gap]) > ord(temp):
                dna_seq[j] = dna_seq[j-gap]
                changes += 1
                j -= gap
  
            dna_seq[j] = temp
        gap //= 2

    return changes


def readInputFile(file_path):
    file = open(file_path, "r")

    input = []
    args = []

    for line in file:
        line = line.strip('\n')

        if line:
            input.append(line)
            print(input)
        else:
            continue

    args = input[1].split(" ")

    dna_seq = []
    for i in range(int(args[1])):
        dna_seq.append(input[i + 2])    #2 is the number of elements before sequences

    dict_seq = {}

    for i in range(int(args[1])):
        n_changes = shell_sort_test(args, list(dna_seq[i]))
        dict_seq[dna_seq[i]] = n_changes

    ordenado = {k: v for k, v in sorted(dict_seq.items(), key=lambda item: item[1])}

    print(ordenado)
            



 


def main():
    filePath = get_arguments()
    readInputFile(filePath)

    


if __name__ == "__main__":
    main()
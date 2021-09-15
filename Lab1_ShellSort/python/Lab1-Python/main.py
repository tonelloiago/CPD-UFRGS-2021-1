import sys
from auxFunctions import readFile

#Getting path of the text file
def get_config():
    arguments = sys.argv
    del(arguments[0])

    if not arguments:
        raise Exception("Please include path to text file.")

    return arguments[0] #Array file


def main():

    file = get_config()
    readFile(file)


if __name__ == "__main__":
    main()
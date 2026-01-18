#!/usr/bin/python

from sys import argv

def usage(): 
    print "mk-bin -- ECE 429 script without much error checking."
    print "          Creates a big-endian formatted file in HEX."
    print "          Input must be a generated file from od."
    print "Usage:"
    print "          ./mk-bin.py <filename>"

def main():
    Text = open(FileName)
    # Read each line
#    print "Read line by line"
    for Line in Text.readlines():
        # Strip out the new line
        LittleEndian = Line.replace('\n','')
        # Get all words (Addr W0 W1 W2 W3)
        Words = LittleEndian.split(' ')
        # Drop the address because we have fixed address 0x8002000
        Words.pop(0)
        # Reorganize the bytes in BigEndian.
        for OneWord in Words: 
            if len(OneWord) > 0:
                #BigEndian = OneWord[6] + OneWord[7] + OneWord[4] + OneWord[5] + OneWord[2] + OneWord[3] + OneWord[0] + OneWord[1]
                #print BigEndian
                print OneWord
                #            print "LE: %r, BE: %r" % (OneWord, BigEndian)


if __name__ == "__main__":
    # FileName is the output from linux command od
    if len(argv) <= 1:
        usage()
        print "Error: missing file name"
        exit(1)
    if len(argv) > 2:
        usage()
        print "Error: Why are you specifying so many files?"

        exit(1)

    Script, FileName = argv
    main()



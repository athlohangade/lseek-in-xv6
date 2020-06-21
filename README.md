# lseek-in-xv6

This repo is about implementation of lseek system call in xv6 OS.
The testing is done through 2 programs.

## Program1 :
-   **Usage** : Run qemu and enter command in following format :

    >   program1 filename offset length string

    Eg: program1 hello.txt 3 15 name is Atharva.

    This will match the string 'name is Atharva' with data from offset 3 in file
    hello.txt and print whether string is matched or not

-   For now two text files are added for testing, namely *hello.txt and some_info.txt*


## Program2 :
-   **Usage** : Run qemu and enter command in following format :

    > program2 filename

    Eg: program2 some_info.txt

-   The program2 will divide the data from some_info.txt into 10 chunks of same
    size.
-   The **filelength must be multiple of 10** for correct results. This is because
    the chunks are written to file *copy* in random order and if there is even one
    chunk with different size than others then it may overwrite the previously
    written data by other chunk as the order is random.

-   The program2 prints the length of the file given as input and the length of
    the *copy* file after writing into it in random order. The sizes of two
    files should be same.
-   Also the program2 prints the content of both the file to ensure the
    correctness of the test.

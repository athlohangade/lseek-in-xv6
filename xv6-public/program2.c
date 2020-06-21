#include "types.h"
#include "user.h"
#include "fcntl.h"

#define MAX_SIZE    1024

int main(int argc, char *argv[]) {

    int fd1, fd2, file_length, individual_length, i;
    int random_order[10] = {3, 9, 1, 8, 0, 7, 5, 2, 4, 6};
    char data[MAX_SIZE];

    if (argc != 2) {
        printf(1, "Usage : %s 'filename'\n", argv[0]);
        exit();
    }

    fd1 = open(argv[1], O_RDONLY);
    if (fd1 == -1) {
        printf(1, "Error while opening the file\n");
        exit();
    }
    fd2 = open("copy", O_CREATE | O_RDWR);
    if (fd2 == -1) {
        printf(1, "Error while opening the file\n");
        exit();
    }

    file_length = lseek(fd1, 0, SEEK_END);
    printf(1, "FILE1 LENGTH = %d\n", file_length);
    lseek(fd1, 0, SEEK_SET);
    read(fd1, data, file_length);
    data[file_length] = '\0';
    printf(1, "DATA FROM FILE1 : %s\n", data);

    individual_length = (int)(file_length / 10);
    for (i = 0; i < 9; i++) {
        lseek(fd1, individual_length * random_order[i], SEEK_SET);
        read(fd1, data, individual_length);
        data[individual_length] = '\0';
        lseek(fd2, individual_length * random_order[i], SEEK_SET);
        write(fd2, data, individual_length);
    }
    individual_length = file_length - (9 * individual_length);

    lseek(fd1, individual_length * random_order[9], SEEK_SET);
    read(fd1, data, individual_length);
    data[individual_length] = '\0';
    lseek(fd2, individual_length * random_order[9], SEEK_SET);
    write(fd2, data, individual_length);

    file_length = lseek(fd2, 0, SEEK_END);
    printf(1, "FILE2 LENGTH = %d\n", file_length);

    lseek(fd2, 0, SEEK_SET);
    read(fd2, data, file_length);
    data[file_length] = '\0';
    printf(1, "DATA FROM FILE2 : %s\n", data);

    close(fd1);
    close(fd2);
    exit();
}

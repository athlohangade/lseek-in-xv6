#include "types.h"
#include "user.h"
#include "fcntl.h"

#define MAX_SIZE    1024

int main(int argc, char *argv[]) {

    int fd, offset, length, i, j, k;
    char data[MAX_SIZE];
    char user_string[MAX_SIZE];

    if (argc < 5) {
        printf(1, "Usage : %s 'filename' 'offset' 'len' 'string'\n", argv[0]);
        exit();
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        printf(1, "Error while opening the file\n");
        exit();
    }

    offset = atoi(argv[2]);
    length = atoi(argv[3]);

    lseek(fd, offset, SEEK_SET);
    read(fd, data, length);
    data[length] = '\0';

    k = 0;
    for (i = 4; i < argc; i++) {
        for (j = 0; argv[i][j] != '\0'; j++) {
            user_string[k++] = argv[i][j];
        }
        user_string[k++] = ' ';
    }
    user_string[k - 1] = '\0';

    if (!(strcmp(data, user_string))) {
        printf(1, "Strings matched\n");
    }
    else {
        printf(1, "Strings did not matched\n");
    }

    close(fd);
    exit();
}

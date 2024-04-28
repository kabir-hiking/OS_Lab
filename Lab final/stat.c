#include <stdio.h>
#include <sys/stat.h>

int main() {
    const char *filename = "word.c";
    struct stat file_info;

    if (stat(filename, &file_info) != 0) {
        perror("Error while getting file information");
        return 1;
    }

    printf("File: '%s'\n", filename);
    printf("Size: %lld bytes\n", (long long)file_info.st_size);
    printf("Blocks: %lld\n", (long long)file_info.st_blocks);
    printf("IO Block: %ld\n", (long)file_info.st_blksize);
    printf("Device: %lxh/%ldd\n", (long)file_info.st_dev, (long)file_info.st_dev);
    printf("Inode: %ld\n", (long)file_info.st_ino);
    printf("Links: %ld\n", (long)file_info.st_nlink);
    printf("Access: %s", ctime(&file_info.st_atime));
    printf("Modify: %s", ctime(&file_info.st_mtime));
    printf("Change: %s", ctime(&file_info.st_ctime));

    return 0;
}

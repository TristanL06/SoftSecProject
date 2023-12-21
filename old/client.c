// client.c
#include "client.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int uploadFile(const char *filename) {
    // Assuming the existence of libclient.so functions
    // You need to replace the following calls with the actual library functions

    // Open the local file
    FILE *localFile = fopen(filename, "rb");
    if (localFile == NULL) {
        perror("Error opening local file");
        return 1;
    }

    // Get file size
    fseek(localFile, 0, SEEK_END);
    long fileSize = ftell(localFile);
    rewind(localFile);

    // Read file content into buffer
    char *buffer = (char *)malloc(fileSize);
    if (buffer == NULL) {
        perror("Error allocating memory for buffer");
        fclose(localFile);
        return 1;
    }

    fread(buffer, 1, fileSize, localFile);
    fclose(localFile);

    // Assuming libclient.so function for sending message
    if (sndmsg(buffer, fileSize, filename) != 0) {
        fprintf(stderr, "Error uploading file\n");
        free(buffer);
        return 1;
    }

    printf("File uploaded successfully.\n");

    free(buffer);
    return 0;
}

void listFiles() {
    // Assuming libclient.so function for listing files
    // You need to replace the following call with the actual library function

    char filelist[1024];
    if (getfilelist(filelist) != 0) {
        fprintf(stderr, "Error listing files\n");
        return;
    }

    printf("Files on the server:\n%s\n", filelist);
}

int downloadFile(const char *filename) {
    // Assuming the existence of libclient.so functions
    // You need to replace the following calls with the actual library functions

    // Assuming libclient.so function for receiving message
    int fileSize;
    char *buffer = recvmsg(filename, &fileSize);
    if (buffer == NULL) {
        fprintf(stderr, "Error downloading file\n");
        return 1;
    }

    // Open local file for writing
    FILE *localFile = fopen(filename, "wb");
    if (localFile == NULL) {
        perror("Error opening local file for writing");
        free(buffer);
        return 1;
    }

    // Write buffer content to local file
    fwrite(buffer, 1, fileSize, localFile);
    fclose(localFile);

    printf("File downloaded successfully.\n");

    free(buffer);
    return 0;
}

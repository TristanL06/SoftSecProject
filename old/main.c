// main.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "client.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <command> [options]\n", argv[0]);
        return 1;
    }

    char *command = argv[1];

    if (strcmp(command, "-up") == 0) {
        if (argc != 4) {
            fprintf(stderr, "Usage: %s -up <local_file_path> <server_file_path>\n", argv[0]);
            return 1;
        }

        char *localFilePath = argv[2];
        char *serverFilePath = argv[3];

        // Call the function to upload the file to the server
        int result = uploadFile(localFilePath);
        if (result != 0) {
            fprintf(stderr, "Error uploading file\n");
            return 1;
        }

        printf("File uploaded successfully.\n");
    } else if (strcmp(command, "-list") == 0) {
        // Call the function to list files on the server
        listFiles();
    } else if (strcmp(command, "-down") == 0) {
        if (argc != 4) {
            fprintf(stderr, "Usage: %s -down <server_file_path> <local_file_path>\n", argv[0]);
            return 1;
        }

        char *serverFilePath = argv[2];
        char *localFilePath = argv[3];

        // Call the function to download the file from the server
        int result = downloadFile(serverFilePath);
        if (result != 0) {
            fprintf(stderr, "Error downloading file\n");
            return 1;
        }

        printf("File downloaded successfully.\n");
    } else {
        fprintf(stderr, "Unknown command: %s\n", command);
        return 1;
    }

    return 0;
}

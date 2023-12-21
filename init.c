// Include necessary headers
#include "client.h"
#include "server.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // Parse command-line options and arguments
    if (argc < 3) {
        // Print usage information
        printf("Usage: %s -up <filename> | -list | -down <filename>\n", argv[0]);
        return 1;
    }

    // Assuming the server is running on port 1234
    int serverPort = 1234;

    // Placeholder for the message to be sent to the server
    char message[1024];

    if (strcmp(argv[1], "-up") == 0) {
        // Upload file to the server
        const char *filename = argv[2];
        snprintf(message, sizeof(message), "UPLOAD %s", filename);
    } else if (strcmp(argv[1], "-list") == 0) {
        // List files on the server
        snprintf(message, sizeof(message), "LIST");
    } else if (strcmp(argv[1], "-down") == 0) {
        // Download file from the server
        const char *filename = argv[2];
        snprintf(message, sizeof(message), "DOWNLOAD %s", filename);
    } else {
        // Handle invalid options
        printf("Invalid option: %s\n", argv[1]);
        return 1;
    }

    // Send the constructed message to the server
    if (sndmsg(message, serverPort) == 0) {
        printf("Command sent successfully.\n");
    } else {
        printf("Failed to send command.\n");
        return 1;
    }

    // Clean up and exit
    return 0;
}

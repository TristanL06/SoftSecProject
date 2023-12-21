// server.c
#include "server.h"
#include <stdio.h>
#include <string.h>

int startServer(int port) {
    // Assuming the existence of libserver.so function
    // You need to replace the following call with the actual library function

    if (startserver(port) != 0) {
        fprintf(stderr, "Error starting server\n");
        return 1;
    }

    printf("Server started on port %d\n", port);
    return 0;
}

void stopServer() {
    // Assuming the existence of libserver.so function
    // You need to replace the following call with the actual library function

    stopserver();
    printf("Server stopped\n");
}

int getMessage(char msg_read[1024]) {
    // Assuming the existence of libserver.so function
    // You need to replace the following call with the actual library function

    if (getmsg(msg_read) != 0) {
        fprintf(stderr, "Error reading message from server\n");
        return 1;
    }

    return 0;
}

// server.h
#ifndef SERVER_H
#define SERVER_H

int startServer(int port);
void stopServer();
int getMessage(char msg_read[1024]);

#endif // SERVER_H

/*
 * Author: Philipp Aeschlimann - September 2009
 * Version 1.0
 * tcpserver.c - A simple TCP-Server
 *
 * tcpserver.c is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

//Fehler sauber ausgeben
void error(char *msg) {
  perror(msg);
  exit(0);
}

//void main routine
int main(int argc, char *argv[]) {
  int sockfd, newsockfd, portno, clilen;
  char buffer[256];
  struct sockaddr_in serv_addr, cli_addr;
  int n;

  if (argc < 2) {
    fprintf(stderr, "ERROR, kein Port angegeben\n");
    exit(0);
  }
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0){
    error("ERROR, konnte Socket nicht öffnen\n");
    exit(0);
  }
  bzero((char *) & serv_addr, sizeof (serv_addr));
  portno = atoi(argv[1]);

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(portno);

  if (bind(sockfd, (struct sockaddr *) & serv_addr,sizeof (serv_addr)) < 0){
    error("ERROR, konnte Socket nicht anbinden\n");
    exit(0);
  }
  listen(sockfd, 5);
  clilen = sizeof (cli_addr);
  newsockfd = accept(sockfd, (struct sockaddr *) & cli_addr, &clilen);
  if (newsockfd < 0){
    error("ERROR, konnte Client nicht anbinden");
    exit(0);
  }
  printf("Erstellter Client-Socket hat Deskriptor Nr. %d.\n",newsockfd);

  // Nachricht von Client empfangen
  char receiveBuffer[100];
  int numOfBytes = recv(newsockfd, receiveBuffer, 100, 0);
  if (numOfBytes < 0) {
    error("ERROR, Nachricht konnte nicht empfangen werden!");
    exit(0);
  }
  receiveBuffer[numOfBytes] = '\0';
  printf("Message vom Client:%s\n ", receiveBuffer);

  // Bestätigung an Client senden
  numOfBytes = send(newsockfd, "Received ;-)\n", 20, 0);
  if (numOfBytes < 0) {
    error("ERROR, Bestätigung konnte nicht gesendet werden!");
    exit(0);
  }

  // Finally close the connection
  close(newsockfd);
  close(sockfd);

  return 0;
}


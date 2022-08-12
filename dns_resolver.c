#include <stdio.h>
#include <netdb.h>
#include <arpa/inet.h>

void create_line(int);
void menu(char *name);

int main(int argc, char *argv[]) {

  
  if(argc < 2) {
    menu(argv[0]);
    return 1;
  }

  char *DNS = argv[1];
  struct  hostent *target = gethostbyname(DNS);
  if(target == NULL) {
    menu(argv[0]);
    return 1;
  }
  char *ip = inet_ntoa((*(struct in_addr *)target->h_addr_list[0]));

  create_line(10);
  printf("[+] DNS %s has IP %s\n", DNS, ip);
  create_line(10);
  return 0;
}

/**************************************************
*                    Functions                    *
***************************************************/ 

void create_line(int line_length) {
  int i;
  for(i = 0; i < line_length; i++) printf("#####");
  printf("\n");
}

void menu(char *name) {
  create_line(10);
  printf("[+] DNS Resolver\t\t\t\t #\n");
  printf("[+] Usage: %s HOST\t\t\t #\n", name);
  printf("[+] Usecase: %s www.mysite.com\t #\n", name);
  create_line(10);
}
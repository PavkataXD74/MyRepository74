#include <stdio.h>
#include <stdlib.h>

int main() {

    unsigned char rooms = 0;
  
    unsigned char room1 = 1 << 0;
    unsigned char room2 = 1 << 1;
    unsigned char room3 = 1 << 2;
    unsigned char room4 = 1 << 3;
    unsigned char room5 = 1 << 4;
    unsigned char room6 = 1 << 5;
    unsigned char room7 = 1 << 6;
    unsigned char room8 = 1 << 7;

    rooms = rooms | room1;
    rooms = rooms | room2;
    rooms = rooms | room3;
    rooms = rooms | room4;
    rooms = rooms | room5;
    rooms = rooms | room6;
    rooms = rooms | room7;
    rooms = rooms | room8;

    int continueCycle = 1;
    while (continueCycle == 1) {
      int op = 0;
      do {
        printf("Switch lights in chosen room: 1\n");
        printf("Display the state of all rooms: 2\n");
        printf("Exit the program: 3\n");
        printf("which option do you chose:");
        scanf("%d", &op);
      } while (op != 1 && op != 2 && op != 3);

      switch (op) {
        case 1: {
          int room = 0;
          printf("Which room do you want to switch the lights in:");
          scanf("%d", &room);
          unsigned char roombit = 1 << (room - 1);
          rooms = rooms ^ roombit;
          printf("The switch was fliped in room: %d\n", room);
          break;
        }

        case 2: {
          printf("the light is on in rooms: \n");
          for (int i = 0; i < 8; i++) {
              unsigned char checker = 1 << i;
              int LightOn = (rooms & checker) == checker;
              if(LightOn == 1){
                printf("%d\n", i + 1);
              }
            }
          printf("The state has been printed sucessfuly\n");
          break;
          }

        case 3: {
          continueCycle = 0;
          break;
        }
      }
    }
  return 0;
}
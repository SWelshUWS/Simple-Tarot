
/*
  Simple Tarot App v1.0
  Written by Stacey Welsh
  May 2022

  A simple text based tarot application

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <https://www.gnu.org/licenses/>.


*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>


/*
      *** still to do ***

      1) need to stop double cards from coming up
      2) include reversals


*/


// initialize card struct type
struct cards {
  int IDno;
  char *name;
};

// get details for the card through passed ID number
char* getCardDets(int ID){

  char *name;

  // change this for a hash map for speed
  struct cards tarot[78] = {
          {.IDno = 0, .name = "The Fool 🤡"},
          {.IDno = 1, .name = "The Magician ⚚"},
          {.IDno = 2, .name = "The High Priestess ⚛"},
          {.IDno = 3, .name = "The Empress ♀"},
          {.IDno = 4, .name = "The Emperor ♂"},
          {.IDno = 5, .name = "The Heirophant ☧"},
          {.IDno = 6, .name = "The Lovers ⚥"},
          {.IDno = 7, .name = "The Chariot 🛸"},
          {.IDno = 8, .name = "Strength 🦁"},
          {.IDno = 9, .name = "The Hermit 🧙"},
          {.IDno = 10, .name = "The Wheel of Fortune ☸"},
          {.IDno = 11, .name = "Justice ⚖"},
          {.IDno = 12, .name = "The Hanged Man ✚"},
          {.IDno = 13, .name = "Death ☠"},
          {.IDno = 14, .name = "Temperance ☯"},
          {.IDno = 15, .name = "The Devil ⛧"},
          {.IDno = 16, .name = "The Tower ♜"},
          {.IDno = 17, .name = "The Star ★"},
          {.IDno = 18, .name = "The Moon ☽"},
          {.IDno = 19, .name = "The Sun ☼"},
          {.IDno = 20, .name = "Judgement 🕚"},
          {.IDno = 21, .name = "The World 🌍"},
          {.IDno = 22, .name = "Ace of Wands ♧"},
          {.IDno = 23, .name = "2 of Wands ♧"},
          {.IDno = 24, .name = "3 of Wands ♧"},
          {.IDno = 25, .name = "4 of Wands ♧"},
          {.IDno = 26, .name = "5 of Wands ♧"},
          {.IDno = 27, .name = "6 of Wands ♧"},
          {.IDno = 28, .name = "7 of Wands ♧"},
          {.IDno = 29, .name = "8 of Wands ♧"},
          {.IDno = 30, .name = "9 of Wands ♧"},
          {.IDno = 31, .name = "10 of Wands ♧"},
          {.IDno = 32, .name = "Page of Wands ♧"},
          {.IDno = 33, .name = "Knight of Wands ♧"},
          {.IDno = 34, .name = "Queen of Wands ♧"},
          {.IDno = 35, .name = "King of Wands ♧"},
          {.IDno = 36, .name = "Ace of Wands ♧"},
          {.IDno = 37, .name = "2 of Cups ♥"},
          {.IDno = 38, .name = "3 of Cups ♥"},
          {.IDno = 39, .name = "4 of Cups ♥"},
          {.IDno = 40, .name = "5 of Cups ♥"},
          {.IDno = 41, .name = "6 of Cups ♥"},
          {.IDno = 42, .name = "7 of Cups ♥"},
          {.IDno = 43, .name = "8 of Cups ♥"},
          {.IDno = 44, .name = "9 of Cups ♥"},
          {.IDno = 45, .name = "10 of Cups ♥"},
          {.IDno = 46, .name = "Page of Cups ♥"},
          {.IDno = 47, .name = "Knight of Cups ♥"},
          {.IDno = 48, .name = "Queen of Cups ♥"},
          {.IDno = 49, .name = "King of Cups ♥"},
          {.IDno = 50, .name = "Ace of Swords ♤"},
          {.IDno = 51, .name = "2 of Swords ♤"},
          {.IDno = 52, .name = "3 of Swords ♤"},
          {.IDno = 53, .name = "4 of Swords ♤"},
          {.IDno = 54, .name = "5 of Swords ♤"},
          {.IDno = 55, .name = "6 of Swords ♤"},
          {.IDno = 56, .name = "7 of Swords ♤"},
          {.IDno = 57, .name = "8 of Swords ♤"},
          {.IDno = 58, .name = "9 of Swords ♤"},
          {.IDno = 59, .name = "10 of Swords ♤"},
          {.IDno = 60, .name = "Page of Swords ♤"},
          {.IDno = 61, .name = "Knight of Swords ♤"},
          {.IDno = 62, .name = "Queen of Swords ♤"},
          {.IDno = 63, .name = "King of Swords ♤"},
          {.IDno = 64, .name = "Ace of Pentacles ♦"},
          {.IDno = 65, .name = "2 of Pentacles ♦"},
          {.IDno = 66, .name = "3 of Pentacles ♦"},
          {.IDno = 67, .name = "4 of Pentacles ♦"},
          {.IDno = 68, .name = "5 of Pentacles ♦"},
          {.IDno = 69, .name = "6 of Pentacles ♦"},
          {.IDno = 70, .name = "7 of Pentacles ♦"},
          {.IDno = 71, .name = "8 of Pentacles ♦"},
          {.IDno = 72, .name = "9 of Pentacles ♦"},
          {.IDno = 73, .name = "10 of Pentacles ♦"},
          {.IDno = 74, .name = "Page of Pentacles ♦"},
          {.IDno = 75, .name = "Knight of Pentacles ♦"},
          {.IDno = 76, .name = "Queen of Pentacles ♦"},
          {.IDno = 77, .name = "King of Pentacles ♦"}
        };

        // find the name for the corresponding ID from struct major
        // fixed 79 to 78
        for (int i = 0; i < 78; i++){
          if (tarot[i].IDno == ID){
          name = tarot[i].name;
          }
        }
        return name;

}


// selects a random card
int cardSelect(){
  srand(time(NULL)); // seed rand() with time value
  int r = rand() % 78; // random number from 0 to 78
  return r;
}

int singleCard(){
  char *name;
  int card = cardSelect(); // get random card number
  name = getCardDets(card); // retrieve card name
  printf("%d: %s\n",card, name);
  printf("\n**************************\n\n" );

}

int tripleCard(){

  int cards[3];
  char *name;


  for (int i = 0; i < 3; i++){
    cards[i]= cardSelect(); // get 3 cards
    name = getCardDets(cards[i]); // get card names for each in the array
    switch(i){
      case 0:
        printf("Past: ");
        break;

      case 1:
        printf("Present: ");
        break;

      case 2:
        printf("Future: ");
        break;

    }
    printf("%d - %s \n", cards[i], name);
    sleep(1);
  }
  printf("\n**************************\n\n" );


}

// as with triplecard() but with 10 instead
int celticCross(){
  int cards[10];
  char *name;
  for (int i = 0; i < 10; i++){
    cards[i] = cardSelect();
    name = getCardDets(cards[i]);
    switch(i){
      case 0:
        printf("The situation: ");
        break;

      case 1:
        printf("Crossing: ");
        break;

      case 2:
        printf("Above: ");
        break;

      case 3:
        printf("Below: ");
        break;

      case 4:
        printf("Coming: ");
        break;

      case 5:
        printf("Going: ");
        break;

      case 6:
        printf("Hopes and fears: ");
        break;

      case 7:
        printf("Unexpected element: ");
        break;

      case 8:
        printf("How you are seen: ");
        break;

      case 9:
        printf("Final outcome: ");
        break;

    }
    printf("%d: %s \n", cards[i], name);
    sleep(1);
  }
  printf("\n**************************\n\n" );
  
}




int main(int argc, char *argv[]){

  FILE *f;
   char s;
   f=fopen("asciiart","r");
   while((s=fgetc(f))!=EOF) {
      printf("%c",s);
   }
   printf("\nby Stacey Welsh\n*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*\n\n");
   fclose(f);




  // options to be parsed into struct
  int i;
  int option;



  // text to display when -h specified
  const char * helpText = "\nSimple-Tarot - it's, well, a simple tarot app.\n"
  "=====================================================\n\n"
  "Basic Usage:\n"
  "tarot [options] \n\n"
  "=====================================================\n\n"
  "\t -h: \tdisplay basic usage info and exit.\n"
  "\t -v: \tshow display version and exit\n"
  "\t -s: \tsingle card reading\n"
  "\t -t: \ttriple card reading\n"
  "\t -c: \tceltic-cross style reading\n\n"
  "For card definitions, check out https://labyrinthos.co/blogs/tarot-card-meanings-list\n\n";


  if(argc > 1){    // if arguments are provided
    // put ':' at the starting of the string so compiler can distinguish between '?' and ':'
    while((option = getopt(argc, argv, "hvstc")) != -1){ //get option from the getopt() method

      switch(option){
        // options with no value
        case 'h':
          printf("%s", helpText);
          exit(0);
          break;

        case 'v':
          printf("%s\n", "Simple-Tarot v1.0 - May 2022\n");
          exit(0);
          break;

        case 's':
          printf("%s\n", "*~*~* Single Card Reading *~*~*\n");
          singleCard();
          break;

        case 't':
            printf("%s\n", "*~*~* Triple Card Reading *~*~*\n");
            tripleCard();
          break;
        
        case 'c':     
          printf("*~*~* Celtic Cross Reading *~*~* \n\n");
          celticCross();
          break;



    if (argv[optind]){   
      printf("%s\n", "too many arguments");
          exit(0); 
    }
  }


  return 0;

}
  }
}
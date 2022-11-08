#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CARDS 52
#define FACES 13
struct card {
   const char *face;
   const char *suit;
};

typedef struct card Card;
void fillDeck( Card * const wDeck, const char * wFace[], const char * wSuit[] );
void shuffle( Card * const wDeck );
void deal( const Card * const wDeck );
int main( void )
{ printf("    bot1            bot2           bot3            bot4 \n\n");
   Card deck[ CARDS ];
   const char *face[] = { "A", "2", "3", "4", "5",
      "6", "7", "8", "9", "10",
      "J", "Q", "K"};
   const char *suit[] = { "Co", "Ro", "Tep", "Bich"};

   srand( time( NULL ) );

   fillDeck( deck, face, suit );
   shuffle( deck );
   deal( deck );
  
}
void fillDeck( Card * const wDeck, const char * wFace[],  const char * wSuit[] )
{ 
   size_t i;

   for ( i = 0; i < CARDS; ++i ) { 
      wDeck[ i ].face = wFace[ i % FACES ];
      wDeck[ i ].suit = wSuit[ i / FACES ];
   }
}
void shuffle( Card * const wDeck )
{ 
   size_t i;
   size_t j;
   Card temp;
   for ( i = 0; i < CARDS; ++i ) { 
      j = rand() % CARDS;
      temp = wDeck[ i ];      
      wDeck[ i ] = wDeck[ j ];
      wDeck[ j ] = temp;      
   } 
}
void deal( const Card * const wDeck )
{
   size_t i;
   for ( i = 0; i < CARDS; ++i ) {
      printf( "%5s %-8s%s", wDeck[ i ].face, wDeck[ i ].suit,
         ( i + 1 ) % 4 ? "  " : "\n" );
   }
}

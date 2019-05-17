/*----------------------------------------------------------
 *				HTBLA-Leonding / Class
 * ---------------------------------------------------------
 * Exercise Number: 0
 * Title:			deletable_primes.c
 * Author:			P. Bauer
 * Due Date:		October 16, 2012
 * ----------------------------------------------------------
 * Description:
 * Implementation of deletable_primes.h.
 * ----------------------------------------------------------
 */
#include "deletable_primes.h"
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/*
  multi variable damit man zur stelle kommt( einerstelle, zehenrstelle....)
  Man dividiert die Zahl mit multi um eine dezimal zu bekommen und das komma zeichen vor der nummer die man
  löschen möchte zu verschieben. Da long ein integer ist und man keine DEzimalzahlen hineinspeichern kann, werden
  die ZAhlen nach dem Komma weggeschnitten. Somit muss man sich die nicht zu löschenden zahlen zu der jetzt noch übrigen Zahl hinzufügen.
  DAzu die jetzige ZAhl mit dem Multiplikator multiplizieren damit man auf die richtige Größe der Zahl zu kommen und dann noch das Mpdulo ergebnis der
  Zahl mit dem Multiplikator da man da als ergebnis die Zahl bekommt die weggeschnitten wurden ohne der ersten ZAhl da man diese wegscheiden wollte.

*/
unsigned long remove_digit(int index, unsigned long n){
    long multi=pow(10,index);
    return (n/(multi*10))*multi+(n%multi);
}



/*
  Man Zählt wieviel man mal eine primzahl in der mitgegebenen Zahl n heraus löschen kann so das am Schluss keine Primzahl in n vorhanden ist
*/
int get_ways(unsigned long n){


  if (n<10 && isPrim(n))
    return 1;



  int way=0;


  for (int i = 0; i < getLength(n); i++) {
    if(isPrim(remove_digit(i,n)))
      way+=get_ways(remove_digit(i,n));
  }



 return way;
}


/*
man geth bis zur Wurzel der übergebenen ZAhl da man nicht alle ZAhlen durchgehen muss weil wenn man über der Wurzel ist muss man mit einer Zahl kleiner 2 und größer 0 rechnen
damit die LAufzeit kürzer ist
*/
bool isPrim(unsigned long n){
  if (n <= 1 || (n % 2 == 0 && n > 2))
      return false;

  for(int i = 2; i <= sqrt(n); i++)
    {
        if(n%i == 0)
            return false;
    }




  return true;
}



// einfaches herausfinden welche länge die Zahl hat
int getLength(unsigned long n){

  int lenght=0;

    while (n>1) {
      n/=10;
      lenght++;
    }


  return lenght;

}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
  char* word;
  int repetition;
  struct node* next;
};

char* trim(char word[]) { /* funkcja obcina stringa ze znakow specjalnych, np *()slowo zamienia na slowo */
  int i;
  for(i=0;word[i]!='\0';i++) { /* zakladam, ze znaki specjalne nie moga pojawic sie w srodku slowa */
    if(word[i] < 65 || (word[i] > 90 && word[i] < 97 ) || word[i] > 122) {
      word[i] = ""; /* jakos wywalic znak */
    }
  }
  return word;
}

void readFile() {
  struct node* lists[26];
  char buffer[100];
  char* word;
  FILE* fileHandle;
  int wordLength;
  struct node* newNode;
  struct node* head = NULL;
  int currentList;

  fileHandle = fopen("file.txt", "rt"); /* rt - reading text */
  while(fscanf(fileHandle, "%s", buffer) != EOF) {
    /*printf("%c\n",buffer[0]);*/
    wordLength = strlen(buffer);
    word  = (char*)malloc(wordLength*sizeof(char)); /*  deklaracja pamieci */
    word = buffer; /* przepisanie z bufora na styrte */
    /*currentList = (int)word[0]; 65, 97*/
    printf("%s\n",word);
    /* Jesli takiego wyrazu jeszcze nie ma na liscie: */
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->word = word;
    newNode->repetition = 1;
    newNode->next = lists[currentList];
    head = newNode;
    /* Jesli juz jest, to repetition+1 */
  }
  /* czytaj plik po wyrazie i pakuj wyraz do bufora. */
  /*  */
}

int wordsCount() { /* zwraca liczbe wszystkich oraz roznych wyrazow */
  return;
}

void longestWord() { /* znajduje najdluzsze slowo */
  /*return;*/
}

int main(void) {

  readFile();
  return 0;
}

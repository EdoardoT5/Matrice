#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generaMatrice(int **matrice, int n) {
  srand(time(NULL));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      matrice[i][j] = rand() % 10;
    }
  }
  printf("Matrice generata.\n");
}

void stampaMatrice(int **matrice, int n) {
  printf("Matrice:\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", matrice[i][j]);
    }
    printf("\n");
  }
}

void salvaMatriceSuCsv(int **matrice, int n) {
  FILE *file;
  file = fopen("matrice.csv", "w");
  if (file) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        fprintf(file, "%d,", matrice[i][j]);
      }
      fprintf(file, "\n");
    }
    printf("Matrice salvata su file CSV.\n");
    fclose(file);
  } else {
    printf("Errore durante l'apertura del file.\n");
  }
}

void stampaMatriceDaCsv(int **matrice, int n) {
  FILE *file;
  file = fopen("matrice.csv", "r");
  if (file) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        fscanf(file, "%d,", &matrice[i][j]);
      }
    }
    printf("Matrice caricata dal file CSV.\n");
    fclose(file);
  } else {
    printf("Errore durante l'apertura del file.\n");
  }
}

int main() {
  int n;
  printf("Inserisci la dimensione della matrice: ");
  scanf("%d", &n);

  int **matrice;
  matrice = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++) {
    matrice[i] = (int *)malloc(n * sizeof(int));
  }

  int scelta;
  do {
    printf("\nMenu:\n");
    printf("1) Generare una matrice casuale di dimensioni NxN\n");
    printf("2) Salvare la matrice su un file CSV\n");
    printf("3) Prendere la matrice dal file CSV e stamparla\n");
    printf("0) Esci\n");
    printf("Scelta: ");
    scanf("%d", &scelta);
    switch (scelta) {
    case 1:
      generaMatrice(matrice, n);
      stampaMatrice(matrice, n);
      break;
    case 2:
      salvaMatriceSuCsv(matrice, n);
      break;
    case 3:
      stampaMatriceDaCsv(matrice, n);
      stampaMatrice(matrice, n);
      break;
    case 0:
      printf("Uscita.\n");
      break;
    default:
      printf("Scelta non valida.\n");
    }
  } while (scelta != 0);

  for (int i = 0; i < n; i++) {
    free(matrice[i]);
  }
  free(matrice);

  return 0;
}
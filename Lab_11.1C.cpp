#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Функція для створення текстового файлу
void CreateTXT(const char* fname) {
    FILE* fout = fopen(fname, "w");
    if (fout == NULL) {
        perror("Error opening file for writing");
        return;
    }
    char line[256];
    char ch;
    do {
        printf("Enter line: ");
        fgets(line, sizeof(line), stdin); // Введення рядка
        line[strcspn(line, "\n")] = '\0'; // Видалення символа нового рядка
        fprintf(fout, "%s\n", line);     // Запис рядка у файл
        printf("Continue? (y/n): ");
        scanf(" %c", &ch);
        getchar(); // Забираємо зайвий символ після вводу
    } while (ch == 'y' || ch == 'Y');
    fclose(fout);
}

// Функція для виведення вмісту текстового файлу
void PrintTXT(const char* fname) {
    FILE* fin = fopen(fname, "r");
    if (fin == NULL) {
        perror("Error opening file for reading");
        return;
    }
    char line[256];
    printf("\nFile content:\n");
    while (fgets(line, sizeof(line), fin) != NULL) {
        printf("%s", line); // Виведення рядка на екран
    }
    fclose(fin);
}

// Функція для перевірки наявності трьох поспіль зірочок
int HasThreeStarsInRow(const char* fname) {
    FILE* fin = fopen(fname, "r");
    if (fin == NULL) {
        perror("Error opening file for reading");
        return 0;
    }
    char line[256];
    while (fgets(line, sizeof(line), fin) != NULL) {
        if (strstr(line, "***") != NULL) { // Пошук трьох поспіль зірочок
            fclose(fin);
            return 1; // Знайдено
        }
    }
    fclose(fin);
    return 0; // Не знайдено
}

int main() {
    char fname[100];

    // Введення імені файлу
    printf("Enter file name: ");
    scanf("%s", fname);
    getchar(); // Забираємо символ нового рядка після вводу

    // Створення файлу
    CreateTXT(fname);

    // Виведення вмісту файлу
    PrintTXT(fname);

    // Перевірка на наявність трьох поспіль зірочок
    if (HasThreeStarsInRow(fname)) {
        printf("\nThe file contains three consecutive stars (***).\n");
    }
    else {
        printf("\nThe file does not contain three consecutive stars (***).\n");
    }

    return 0;
}

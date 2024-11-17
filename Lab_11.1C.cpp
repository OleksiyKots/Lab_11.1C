#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ������� ��� ��������� ���������� �����
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
        fgets(line, sizeof(line), stdin); // �������� �����
        line[strcspn(line, "\n")] = '\0'; // ��������� ������� ������ �����
        fprintf(fout, "%s\n", line);     // ����� ����� � ����
        printf("Continue? (y/n): ");
        scanf(" %c", &ch);
        getchar(); // �������� ������ ������ ���� �����
    } while (ch == 'y' || ch == 'Y');
    fclose(fout);
}

// ������� ��� ��������� ����� ���������� �����
void PrintTXT(const char* fname) {
    FILE* fin = fopen(fname, "r");
    if (fin == NULL) {
        perror("Error opening file for reading");
        return;
    }
    char line[256];
    printf("\nFile content:\n");
    while (fgets(line, sizeof(line), fin) != NULL) {
        printf("%s", line); // ��������� ����� �� �����
    }
    fclose(fin);
}

// ������� ��� �������� �������� ����� ������ ������
int HasThreeStarsInRow(const char* fname) {
    FILE* fin = fopen(fname, "r");
    if (fin == NULL) {
        perror("Error opening file for reading");
        return 0;
    }
    char line[256];
    while (fgets(line, sizeof(line), fin) != NULL) {
        if (strstr(line, "***") != NULL) { // ����� ����� ������ ������
            fclose(fin);
            return 1; // ��������
        }
    }
    fclose(fin);
    return 0; // �� ��������
}

int main() {
    char fname[100];

    // �������� ���� �����
    printf("Enter file name: ");
    scanf("%s", fname);
    getchar(); // �������� ������ ������ ����� ���� �����

    // ��������� �����
    CreateTXT(fname);

    // ��������� ����� �����
    PrintTXT(fname);

    // �������� �� �������� ����� ������ ������
    if (HasThreeStarsInRow(fname)) {
        printf("\nThe file contains three consecutive stars (***).\n");
    }
    else {
        printf("\nThe file does not contain three consecutive stars (***).\n");
    }

    return 0;
}

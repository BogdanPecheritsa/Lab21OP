#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <Windows.h>

void countWordsAndCharacters(const char* text, int* wordCount, int* charCount) {
    *wordCount = 0;
    *charCount = 0;

    int inWord = 0;

    while (*text) {
        if (isspace((unsigned char)(*text))) {
            inWord = 0;
        }
        else {
            if (!inWord) {
                (*wordCount)++;
                inWord = 1;
            }
            (*charCount)++;
        }
        text++;
    }
}

int hasDoubleLetters(const char* word) {
    while (*word && *(word + 1)) {
        if (tolower((unsigned char)(*word)) == tolower((unsigned char)(*(word + 1)))) {
            return 1;
        }
        word++;
    }
    return 0;
}

void removeWordsWithDoubleLetters(char* text) {
    char* src = text;
    char* dest = text;

    while (*src) {
        if (!isalpha((unsigned char)(*src))) {
            *dest = *src;
            dest++;
            src++;
        }
        else {
            char word[50];
            int i = 0;

            while (isalpha((unsigned char)(*src))) {
                word[i] = *src;
                i++;
                src++;
            }

            word[i] = '\0';

            if (!hasDoubleLetters(word)) {
                strcpy_s(dest, _countof(word), word);
                dest += i;
            }
        }
    }

    *dest = '\0';
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char text[1000];

    printf("Введіть текстовий рядок: ");
    gets_s(text, sizeof(text));

    int wordCount, charCount;

    countWordsAndCharacters(text, &wordCount, &charCount);
    printf("Кількість слів: %d\n", wordCount);
    printf("Кількість символів: %d\n", charCount);

    removeWordsWithDoubleLetters(text);

    printf("Текст після видалення слів з подвоєними літерами: %s\n", text);

    return 0;
}
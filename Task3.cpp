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

void removeWordsWithDoubleLetters(char* text) {
    char* src = text;
    char* dest = text;

    while (*src) {
        if (!isalpha((unsigned char)(*src)) || !isalpha((unsigned char)(*(src + 1)))) {
            *dest = *src;
            dest++;
            src++;
        }
        else if (tolower((unsigned char)(*src)) == tolower((unsigned char)(*(src + 1)))) {
            while (isalpha((unsigned char)(*src)) && isalpha((unsigned char)(*(src + 1)))) {
                src++;
            }
        }
        else {
            *dest = *src;
            dest++;
            src++;
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
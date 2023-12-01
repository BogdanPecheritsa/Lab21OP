#include <stdio.h>
#include <Windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char str[100];
    int shortestGroupLength = INT_MAX;
    int shortestGroupCount = 0;
    int currentGroupLength = 0;

    printf("Введіть рядок з груп цифр, розділених пробілами: ");
    gets_s(str, sizeof(str));

    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] >= '0' && str[i] <= '9') {
            currentGroupLength++;
        }
        else if (currentGroupLength > 0) {
            if (currentGroupLength < shortestGroupLength) {
                shortestGroupLength = currentGroupLength;
                shortestGroupCount = 1;
            }
            else if (currentGroupLength == shortestGroupLength) {
                shortestGroupCount++;
            }
            currentGroupLength = 0;
        }
    }

    printf("Найкоротша група має довжину %d і їх кількість - %d\n", shortestGroupLength, shortestGroupCount);

    return 0;
}
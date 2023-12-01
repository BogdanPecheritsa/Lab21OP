#include <stdio.h>
#include <Windows.h>

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char str[100];
    int uppercaseCount = 0;

    printf("Введіть рядок: ");
    scanf_s("%s", str, sizeof(str));

    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            uppercaseCount++;
        }
    }

    printf("Загальна кількість великих латинських літер: %d\n", uppercaseCount);

    return 0;
}
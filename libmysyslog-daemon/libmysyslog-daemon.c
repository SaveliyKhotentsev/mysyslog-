#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include "libmysyslog.h"

#define CONFIG_PATH "/etc/mysyslog/mysyslog.cfg"
#define MAX_LOG_PATH 256

static volatile int keepRunning = 1;

void intHandler(int signum) {
    keepRunning = 0; // Устанавливаем флаг для завершения программы
}

int read_config(const char* path, int* level, int* driver, int* format, char* log_path) {
    FILE* file = fopen(path, "r");
    if (!file) {
        perror("Could not open config file");
        return -1; // Возвращаем ошибку, если не удалось открыть файл
    }

    fscanf(file, "level=%d\n", level)  ;
    fscanf(file, "driver=%d\n", driver)  ;
    fscanf(file, "format=%d\n", format) ;
    fscanf(file, "path=%s\n", log_path)  ;

    fclose(file);
    return 0; // Возвращаем 0, если все прошло успешно
}

int main() {
    // Устанавливаем обработчики сигналов
    signal(SIGINT, intHandler);
    signal(SIGTERM, intHandler);

    // Переменные для конфигурации
    int level, driver, format;
    char log_path[MAX_LOG_PATH];

    // Чтение конфигурации
    if (read_config(CONFIG_PATH, &level, &driver, &format, log_path) != 0) {
        exit(EXIT_FAILURE); // Завершаем программу при ошибке
    }

    // Основной цикл логирования
    while (keepRunning) {
        mysyslog("Daemon log message", level, driver, format, log_path);
        sleep(5); // Логируем сообщение каждые 5 секунд
    }

    return 0; // Успешное завершение программы
}

#include "libmysyslog.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Вспомогательная функция для получения текущего времени в виде строки
static const char* get_current_time() {
    static char buffer[20];
    time_t now = time(NULL);
    struct tm* tm_info = localtime(&now);
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tm_info);
    return buffer;
}

// Функция для вывода сообщения в консоль
static int log_to_console(const char* msg, int format) {
    if (format == FORMAT_WITH_TIMESTAMP) {
        printf("[%s] %s\n", get_current_time(), msg);
    } else {
        printf("%s\n", msg);
    }
    return 0;
}

// Функция для вывода сообщения в файл
static int log_to_file(const char* msg, int format, const char* path) {
    FILE* file = fopen(path, "a");
    if (file == NULL) {
        return -1; // Ошибка открытия файла
    }

    if (format == FORMAT_WITH_TIMESTAMP) {
        fprintf(file, "[%s] %s\n", get_current_time(), msg);
    } else {
        fprintf(file, "%s\n", msg);
    }

    fclose(file);
    return 0;
}

// Основная функция для вывода сообщения в журнал
int mysyslog(const char* msg, int level, int driver, int format, const char* path) {
    const char* level_str;

    // Определение уровня важности
    switch (level) {
        case LOG_DEBUG:
            level_str = "DEBUG";
            break;
        case LOG_INFO:
            level_str = "INFO";
            break;
        case LOG_WARNING:
            level_str = "WARNING";
            break;
        case LOG_ERROR:
            level_str = "ERROR";
            break;
        case LOG_CRITICAL:
            level_str = "CRITICAL";
            break;
        default:
            level_str = "UNKNOWN";
    }

    char full_msg[1024];
    snprintf(full_msg, sizeof(full_msg), "[%s] %s", level_str, msg);

    // Выбор драйвера для вывода
    switch (driver) {
        case DRIVER_CONSOLE:
            return log_to_console(full_msg, format);
        case DRIVER_FILE:
            return log_to_file(full_msg, format, path);
        default:
            return -1; // Неизвестный драйвер
    }
}

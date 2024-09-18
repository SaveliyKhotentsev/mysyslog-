#ifndef MYSYSLOG_H
#define MYSYSLOG_H

// Уровни важности
#define LOG_INFO 0
#define LOG_WARNING 1
#define LOG_ERROR 2

// Драйверы вывода
#define DRIVER_CONSOLE 0
#define DRIVER_FILE 1

// Форматы вывода
#define FORMAT_PLAIN 0
#define FORMAT_WITH_TIMESTAMP 1

// Функция для вывода сообщения в журнал
int mysyslog(const char* msg, int level, int driver, int format, const char* path);

#endif // MYSYSLOG_H

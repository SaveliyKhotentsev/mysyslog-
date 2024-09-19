#ifndef LIBMYSYSLOG_H
#define LIBMYSYSLOG_H
// Уровни важности
#define LOG_DEBUG 0
#define LOG_INFO 1
#define LOG_WARNING 2
#define LOG_ERROR 3
#define LOG_CRITICAL 4

// Драйверы вывода
#define DRIVER_CONSOLE 0
#define DRIVER_FILE 1

// Форматы вывода
#define FORMAT_PLAIN 0
#define FORMAT_WITH_TIMESTAMP 1

// Функция для вывода сообщения в журнал
int mysyslog(const char* msg, int level, int driver, int format, const char* path);

#endif // MYSYSLOG_H

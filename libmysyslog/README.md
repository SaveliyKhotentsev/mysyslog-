# Библиотеку libmysyslog на языке Си
14.  Разработать расширяемую библиотеку libmysyslog на языке Си, которая сможет выводить данные в журнал в разных форматах. В рамках библиотеки необходимо реализовать функцию, через которую другие программы смогут выводить данные в журнал:

int mysyslog(const char* msg, int level, int driver, int format, const char* path);
 Должны поддерживаться следующие уровни журналирования: DEBUG, INFO, WARN, ERROR, CRITICAL.

15.  Для библиотеки libmysyslog реализовать в виде подключаемого плагина 2 драйвера (libmysyslog-text, libmysyslog-json): вывод в журнал в виде строки с разделителем и вывод в журнал в виде json строки. Каждый драйвер должен быть отдельным проектом и собираться отдельно (в итоге иметь отдельный deb-пакет).

Структура журнала в текстовом формате:

timestamp log_level process message

Пример журнала в текстовом формате:

1439482969 ERROR example-app this is an error
Структура журнала в формате JSON:

{"timestamp": ..., "log_level": ..., "process": ..., "message": ...}
Пример журнала в формате JSON:

{"timestamp":1439482969,"log_level":"ERROR","process":"example-app","message":"this is an error"}

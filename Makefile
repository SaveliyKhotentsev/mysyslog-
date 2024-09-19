CC = gcc
CFLAGS = -Wall -fPIC -shared
INCLUDE = -Ilibmysyslog -Ilibmysyslog-text -Ilibmysyslog-json

# Общие правила для всех библиотек
all: libmysyslog/libmysyslog.so libmysyslog-text/libmysyslog-text.so libmysyslog-json/libmysyslog-json.so

# Сборка основной библиотеки
libmysyslog/libmysyslog.so: libmysyslog/libmysyslog.o
	$(CC) $(CFLAGS) -o libmysyslog/libmysyslog.so libmysyslog/libmysyslog.o

libmysyslog/libmysyslog.o: libmysyslog/libmysyslog.c libmysyslog/libmysyslog.h
	$(CC) $(CFLAGS) -c libmysyslog/libmysyslog.c -o libmysyslog/libmysyslog.o

# Сборка текстового драйвера
libmysyslog-text/libmysyslog-text.so: libmysyslog-text/libmysyslog-text.o
	$(CC) $(CFLAGS) -o libmysyslog-text/libmysyslog-text.so libmysyslog-text/libmysyslog-text.o

libmysyslog-text/libmysyslog-text.o: libmysyslog-text/libmysyslog-text.c libmysyslog-text/libmysyslog-text.h
	$(CC) $(CFLAGS) -c libmysyslog-text/libmysyslog-text.c -o libmysyslog-text/libmysyslog-text.o

# Сборка JSON-драйвера
libmysyslog-json/libmysyslog-json.so: libmysyslog-json/libmysyslog-json.o
	$(CC) $(CFLAGS) -o libmysyslog-json/libmysyslog-json.so libmysyslog-json/libmysyslog-json.o

libmysyslog-json/libmysyslog-json.o: libmysyslog-json/libmysyslog-json.c libmysyslog-json/libmysyslog-json.h
	$(CC) $(CFLAGS) -c libmysyslog-json/libmysyslog-json.c -o libmysyslog-json/libmysyslog-json.o

# Очистка
clean:
	rm -f libmysyslog/*.o libmysyslog/*.so
	rm -f libmysyslog-text/*.o libmysyslog-text/*.so
	rm -f libmysyslog-json/*.o libmysyslog-json/*.so

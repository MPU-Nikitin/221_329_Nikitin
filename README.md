# 221_329_Nikitin

## Введение

Это приложение предназначено для проверки записей транзакций путем чтения из различных форматов файлов и валидации хеш-функции SHA-256 для каждой транзакции.

## Основные возможности

- Проверка хешей транзакций и выделение несоответствий.
- Чтение транзакций из файлов формата txt.
- Открытие и загрузка файлов транзакций через пользовательский интерфейс.

## Описание работы

Приложение открывает plaintext файл и построчно считывает данные транзаций, после чего отображает их в табличном виде, подсвечивая невалидные хэши, путем подсчета хэша конкретной транзакции (строка_суммы + строка_номера + строка_даты + хэш предыдущей транзакций) и сравнения с хэшем транзации из файла.

0. Запуск приложения.

![image](https://github.com/MPU-Nikitin/221_329_Nikitin/assets/62671417/99c85bb3-7c99-48d9-a438-033c530cb8bb)

![image](https://github.com/MPU-Nikitin/221_329_Nikitin/assets/62671417/2dd01799-b69c-4d15-b369-363f071dc13b)


1. Запуск приложения с файлом records.txt в папке запуска.

![image](https://github.com/MPU-Nikitin/221_329_Nikitin/assets/62671417/545b3414-ddaa-43b9-86b7-9ec25aa6a81a)

2. Пример открытия файла с невалидными хэшами.

![image](https://github.com/MPU-Nikitin/221_329_Nikitin/assets/62671417/b498c06a-1035-475a-8845-07e008f94ab0)


## Установка

1. Клонирование репозитория:
   ```bash
   git clone https://github.com/MPU-Nikitin/221_329_Nikitin
2. Соборка приложения
   ```bash
   mkdir build && cd $_
   cmake ..
   make -j
   ```
3. Запуск
   ```bash
   ./bin/221_329_Nikitin
   ```
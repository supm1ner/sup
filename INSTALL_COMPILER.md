# Установка и сборка компилятора Sup

## ✅ Текущий статус

- **CMake**: Установлен (`C:\Program Files\CMake\bin\cmake.exe`, версия 4.3.0-rc2)
- **C++ компилятор**: MinGW-w64 установлен (GCC 15.2.0)
- **Компилятор Sup**: Собран и работает (`sup.exe`)

## Быстрая сборка (рекомендуется)

Используйте скрипт `build_simple.bat` для быстрой сборки без CMake:

```bash
./build_simple.bat
```

Этот скрипт:
- Компилирует все исходные файлы
- Создает исполняемый файл `sup.exe`
- Автоматически тестирует компилятор

## Использование компилятора

После сборки компилятор доступен как `sup.exe`:

```bash
# Показать версию
./sup.exe version

# Скомпилировать программу
./sup.exe compile examples/hello.sup

# Скомпилировать и запустить
./sup.exe dev examples/hello.sup
```

## Примеры

### Hello World
```bash
./sup.exe dev examples/hello.sup
```

Вывод:
```
Hello, Sup!
```

### Математические операции
```bash
./sup.exe dev examples/math.sup
```

Вывод:
```
8
10
```

## Установка зависимостей (если нужно)

### Windows

#### MinGW-w64 (рекомендуется)

Установка через winget:
```bash
winget install -e --id GnuWin32.Make
```

Или через MSYS2:
1. Скачайте MSYS2: https://www.msys2.org/
2. Установите MSYS2
3. Откройте MSYS2 терминал:
```bash
pacman -S mingw-w64-x86_64-gcc mingw-w64-x86_64-cmake
```

#### CMake

Скачайте с официального сайта: https://cmake.org/download/

### Проверка установки

```bash
g++ --version
cmake --version
```

## Сборка через CMake (альтернатива)

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

## Исправленные проблемы (v0.1.1)

1. ✅ **Добавлен конструктор по умолчанию для Symbol** - исправлена ошибка компиляции SemanticAnalyzer.cpp
2. ✅ **Исправлен парсинг типов** - типы теперь могут быть как KEYWORD (int, float, string), так и IDENTIFIER
3. ✅ **Добавлена поддержка оператора ':'** - для аннотаций типов параметров и переменных
4. ✅ **Улучшен вывод типов** - переменные без явной аннотации используют `auto`
5. ✅ **Добавлена встроенная функция print** - транслируется в `std::cout`
6. ✅ **Исправлено определение компилятора** - автоматически определяет g++ на Windows
7. ✅ **Исправлен бесконечный цикл** - добавлена защита от зацикливания при ошибках парсинга

## Структура проекта

```
sup-compiler/
├── include/          # Заголовочные файлы
│   ├── AST.h
│   ├── CodeGenerator.h
│   ├── Lexer.h
│   ├── Parser.h
│   ├── SemanticAnalyzer.h
│   └── Token.h
├── src/              # Исходные файлы
│   ├── CodeGenerator.cpp
│   ├── Lexer.cpp
│   ├── main.cpp
│   ├── Parser.cpp
│   └── SemanticAnalyzer.cpp
├── examples/         # Примеры программ
│   ├── hello.sup
│   ├── math.sup
│   └── telegram_bot.sup
├── build_simple.bat  # Скрипт быстрой сборки
├── sup.exe          # Скомпилированный компилятор
└── CMakeLists.txt   # Конфигурация CMake
```

## Проблемы?

### "g++: command not found"
- Установите MinGW-w64 (см. выше)
- Убедитесь, что g++ в PATH

### Ошибки компиляции
- Убедитесь, что компилятор поддерживает C++17
- Проверьте версию: `g++ --version` (должна быть 7+)

### Путь содержит кириллицу
- CMake может иметь проблемы с кириллическими символами в пути
- Используйте `build_simple.bat` вместо CMake
- Или переместите проект в путь без кириллицы

## Дополнительная информация

- Документация по сборке: `BUILD.md`
- Использование CLI: `CLI_USAGE.md`
- Примеры программ: `examples/`
- VS Code расширение: `VSCODE_EXTENSION.md`

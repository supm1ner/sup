# Инструкции по сборке Sup Compiler

## Требования

- **CMake** 3.14 или выше
- **C++17** совместимый компилятор:
  - GCC 7+ (Linux)
  - Clang 5+ (macOS/Linux)
  - MSVC 2017+ (Windows)
- **Git** (для автоматической загрузки Google Test)

## Установка зависимостей

### Windows

1. Установите Visual Studio 2017 или новее с поддержкой C++
2. Установите CMake: https://cmake.org/download/
3. Установите Git: https://git-scm.com/download/win

### Linux (Ubuntu/Debian)

```bash
sudo apt update
sudo apt install build-essential cmake git
```

### macOS

```bash
# Установите Homebrew, если еще не установлен
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

# Установите зависимости
brew install cmake git
```

## Сборка проекта

### Шаг 1: Создание директории для сборки

```bash
mkdir build
cd build
```

### Шаг 2: Конфигурация проекта

```bash
cmake ..
```

Для сборки в режиме отладки:

```bash
cmake -DCMAKE_BUILD_TYPE=Debug ..
```

Для сборки в режиме релиза:

```bash
cmake -DCMAKE_BUILD_TYPE=Release ..
```

### Шаг 3: Компиляция

```bash
cmake --build .
```

Или для параллельной сборки (быстрее):

```bash
cmake --build . -j 4
```

### Шаг 4: Запуск тестов

```bash
ctest --output-on-failure
```

Или напрямую:

```bash
./sup_tests
```

## Структура сборки

После успешной сборки в директории `build/` будут созданы:

- `sup` или `sup.exe` - основной исполняемый файл компилятора
- `sup_tests` или `sup_tests.exe` - исполняемый файл тестов
- `libsup_compiler_lib.a` (Linux/macOS) или `sup_compiler_lib.lib` (Windows) - библиотека компилятора

## Использование

После сборки можно использовать компилятор:

```bash
# Из директории build
./sup compile ../examples/hello.sup

# Или добавить в PATH и использовать из любого места
export PATH=$PATH:/path/to/build
sup compile examples/hello.sup
```

## Устранение проблем

### Ошибка: CMake не найден

Убедитесь, что CMake установлен и добавлен в PATH:

```bash
cmake --version
```

### Ошибка: Компилятор не найден

Убедитесь, что установлен C++ компилятор:

```bash
# Linux/macOS
g++ --version
# или
clang++ --version

# Windows
cl.exe
```

### Ошибка: Google Test не загружается

Проверьте подключение к интернету. CMake автоматически загружает Google Test при первой сборке.

Если проблема сохраняется, можно вручную клонировать Google Test:

```bash
cd build/_deps
git clone https://github.com/google/googletest.git
cd googletest
git checkout release-1.12.1
```

### Ошибка компиляции C++17

Убедитесь, что ваш компилятор поддерживает C++17:

- GCC 7+
- Clang 5+
- MSVC 2017+

## Очистка сборки

Для полной пересборки проекта:

```bash
rm -rf build
mkdir build
cd build
cmake ..
cmake --build .
```

## Установка

После успешной сборки можно установить компилятор в систему:

```bash
cd build
sudo cmake --install .
```

По умолчанию установка происходит в `/usr/local/bin` (Linux/macOS) или `C:\Program Files` (Windows).

Для установки в другую директорию:

```bash
cmake --install . --prefix /custom/path
```

## Разработка

Для разработки рекомендуется использовать IDE с поддержкой CMake:

- **Visual Studio Code** с расширением CMake Tools
- **CLion** от JetBrains
- **Visual Studio** 2017+ (Windows)

Все эти IDE могут автоматически конфигурировать и собирать проект.

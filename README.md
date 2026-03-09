<div align="center">

# 🚀 Sup Programming Language

**Современный компилируемый язык программирования с простым синтаксисом**

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![Version](https://img.shields.io/badge/version-1.0.0-blue.svg)](https://github.com/supm1ner/sup)
[![Platform](https://img.shields.io/badge/platform-Windows%20%7C%20Linux%20%7C%20macOS-lightgrey.svg)](https://github.com/supm1ner/sup)

[Быстрый старт](#-быстрый-старт) • [Примеры](#-примеры) • [Документация](#-документация) • [VS Code](#-vs-code-расширение)

</div>

---

## 📖 О проекте

**Sup** — это компилируемый язык программирования, который сочетает простоту Python с производительностью C++. Sup компилируется в C++ код, что обеспечивает высокую скорость выполнения программ.

### ✨ Особенности

- 🎯 **Простой синтаксис** — легко учить и использовать
- ⚡ **Высокая производительность** — компиляция в C++
- 📦 **Стандартная библиотека** — математика, строки, массивы
- 🎨 **VS Code поддержка** — подсветка синтаксиса и иконки файлов
- 🔧 **CLI инструменты** — удобная работа с компилятором
- 📚 **Богатые примеры** — от Hello World до Telegram ботов

---

## 🚀 Быстрый старт

### Установка

```bash
# Клонируйте репозиторий
git clone https://github.com/supm1ner/sup.git
cd sup

# Соберите компилятор (Windows)
build_simple.bat

# Или используйте CMake
mkdir build && cd build
cmake ..
cmake --build .
```

### Первая программа

Создайте файл `hello.sup`:

```sup
func main() -> int {
    print("Hello, Sup! 🚀")
    return 0
}
```

Запустите:

```bash
./sup.exe dev hello.sup
```

---

## 💡 Примеры кода

### Hello World

```sup
func main() -> int {
    var name = "World"
    print("Hello, " + name + "!")
    return 0
}
```

### Функции и математика

```sup
func factorial(n: int) -> int {
    if n <= 1 {
        return 1
    }
    var result = 1
    var i = 2
    while i <= n {
        result = result * i
        i = i + 1
    }
    return result
}

func main() -> int {
    var fact = factorial(5)
    print("5! = " + str(fact))  # 120
    return 0
}
```

### Калькулятор

```sup
func add(a: float, b: float) -> float {
    return a + b
}

func divide(a: float, b: float) -> float {
    if b == 0.0 {
        print("Ошибка: деление на ноль!")
        return 0.0
    }
    return a / b
}

func main() -> int {
    var result = add(10.0, 5.0)
    print("10 + 5 = " + str(result))
    
    var quot = divide(20.0, 4.0)
    print("20 / 4 = " + str(quot))
    
    return 0
}
```

---

## 📚 Стандартная библиотека

Sup поставляется с богатой стандартной библиотекой:

### 📐 Математика (`lib/math.sup`)

```sup
# Константы
const PI = 3.14159265359
const E = 2.71828182846

# Функции
sqrt(16.0)        # 4.0 - квадратный корень
pow(2.0, 10)      # 1024.0 - возведение в степень
factorial(5)      # 120 - факториал
fibonacci(10)     # 55 - числа Фибоначчи
abs(-15.5)        # 15.5 - абсолютное значение
min(10.0, 25.0)   # 10.0 - минимум
max(10.0, 25.0)   # 25.0 - максимум
```

### 📝 Строки (`lib/string.sup`)

```sup
repeat("*", 20)           # ********************
separator("=", 50)        # ==================================================
header("My App")          # Красивый заголовок
box("Message", 30)        # Рамка вокруг текста
```

### 📊 Массивы (`lib/array.sup`)

```sup
findMax(1, 100)           # 100 - максимум в диапазоне
findMin(1, 100)           # 1 - минимум в диапазоне
range(0, 10, 2)           # 0, 2, 4, 6, 8, 10
```

[📖 Полная документация библиотеки](lib/README.md)

---

## 🎨 VS Code расширение

Установите расширение для удобной разработки:

### Возможности

- ✅ Подсветка синтаксиса
- ✅ Иконки файлов `.sup`
- ✅ Автозакрытие скобок и кавычек
- ✅ Комментирование (`Ctrl+/`)
- ✅ Сворачивание кода

### Установка

```bash
code --install-extension vscode-extension/sup-language-0.2.0.vsix
```

Активируйте иконки: `Ctrl+,` → "File Icon Theme" → "Sup File Icons"

[📖 Подробная инструкция](vscode-extension/INSTALL_VSIX.md)

---

## 🛠️ CLI команды

```bash
# Показать версию
./sup.exe version

# Скомпилировать программу
./sup.exe compile program.sup

# Скомпилировать и запустить (режим разработки)
./sup.exe dev program.sup
```

---

## 📂 Примеры программ

В папке `examples/` вы найдете:

| Пример | Описание | Команда |
|--------|----------|---------|
| `hello.sup` | Hello World | `./sup.exe dev examples/hello.sup` |
| `math.sup` | Математические операции | `./sup.exe dev examples/math.sup` |
| `calculator.sup` | Полнофункциональный калькулятор | `./sup.exe dev examples/calculator.sup` |
| `telegram_bot_advanced.sup` | Telegram бот-калькулятор | `./sup.exe dev examples/telegram_bot_advanced.sup` |
| `library_test.sup` | Тест стандартной библиотеки | `./sup.exe dev examples/library_test.sup` |

[📖 Все примеры с описанием](examples/README.md)

---

## 📖 Синтаксис языка

### Типы данных

```sup
var x: int = 10           # Целое число
var y: float = 3.14       # Дробное число
var name: string = "Sup"  # Строка
var flag: bool = true     # Логическое значение
const PI = 3.14159        # Константа
```

### Условия

```sup
if x > 0 {
    print("Положительное")
} else {
    print("Отрицательное или ноль")
}
```

### Циклы

```sup
# While цикл
while i < 10 {
    print(str(i))
    i = i + 1
}

# For цикл
for item in collection {
    print(item)
}
```

### Функции

```sup
func add(a: int, b: int) -> int {
    return a + b
}

func greet(name: string) -> int {
    print("Привет, " + name + "!")
    return 0
}
```

---

## 🏗️ Архитектура компилятора

```
┌─────────────────────────────────────────────┐
│           Sup Source Code (.sup)            │
└──────────────────┬──────────────────────────┘
                   │
                   ▼
┌─────────────────────────────────────────────┐
│         Lexer (Лексический анализ)          │
│         Tokens: KEYWORD, IDENTIFIER, etc.   │
└──────────────────┬──────────────────────────┘
                   │
                   ▼
┌─────────────────────────────────────────────┐
│       Parser (Синтаксический анализ)        │
│       AST: Abstract Syntax Tree             │
└──────────────────┬──────────────────────────┘
                   │
                   ▼
┌─────────────────────────────────────────────┐
│    Semantic Analyzer (Семантический анализ) │
│    Type checking, Symbol table              │
└──────────────────┬──────────────────────────┘
                   │
                   ▼
┌─────────────────────────────────────────────┐
│       Code Generator (Генерация C++)        │
│       C++ source code                       │
└──────────────────┬──────────────────────────┘
                   │
                   ▼
┌─────────────────────────────────────────────┐
│         G++ Compiler (Компиляция)           │
│         Native executable                   │
└─────────────────────────────────────────────┘
```

---

## 📊 Структура проекта

```
sup/
├── src/                    # Исходный код компилятора
│   ├── main.cpp           # CLI инструмент
│   ├── Lexer.cpp          # Лексический анализатор
│   ├── Parser.cpp         # Синтаксический анализатор
│   ├── SemanticAnalyzer.cpp
│   └── CodeGenerator.cpp  # Генератор C++ кода
├── include/               # Заголовочные файлы
├── lib/                   # Стандартная библиотека
│   ├── math.sup          # Математические функции
│   ├── string.sup        # Строковые операции
│   └── array.sup         # Работа с массивами
├── examples/              # Примеры программ
├── vscode-extension/      # VS Code расширение
├── tests/                 # Тесты
└── docs/                  # Документация
```

---

## 🔧 Требования

### Для использования компилятора

- **Windows**: MinGW-w64 (GCC 7.0+)
- **Linux/macOS**: GCC 7.0+ или Clang 5.0+
- **CMake**: 3.14+ (опционально)

### Для разработки

- C++17 совместимый компилятор
- Git
- VS Code (рекомендуется)

---

## 📚 Документация

- [📖 Быстрый старт](QUICKSTART.md) - начните за 5 минут
- [📖 Использование CLI](CLI_USAGE.md) - команды компилятора
- [📖 Стандартная библиотека](lib/README.md) - все функции с примерами
- [📖 Примеры программ](examples/README.md) - от простых до сложных
- [📖 VS Code расширение](vscode-extension/INSTALL_VSIX.md) - установка и настройка
- [📖 Сборка компилятора](BUILD.md) - как собрать из исходников
- [📖 Telegram бот](TELEGRAM_BOT_EXPLANATION.md) - объяснение работы

---

## 🎯 Roadmap

### Текущая версия (1.0)

- ✅ Базовый компилятор (Lexer, Parser, CodeGen)
- ✅ Стандартная библиотека (35+ функций)
- ✅ VS Code расширение с иконками
- ✅ CLI инструменты
- ✅ Примеры программ

### Планируется (1.1)

- 🔄 Система импорта модулей
- 🔄 Поддержка массивов
- 🔄 Структуры и классы
- 🔄 Обработка ошибок (try/catch)

### Будущее (2.0)

- 🔮 HTTP библиотека
- 🔮 JSON парсинг
- 🔮 Файловый ввод/вывод
- 🔮 Пакетный менеджер
- 🔮 Отладчик
- 🔮 REPL (интерактивный режим)

---

## 🤝 Вклад в проект

Мы приветствуем вклад в развитие Sup! Вот как вы можете помочь:

1. 🐛 **Сообщайте об ошибках** - создавайте issues
2. 💡 **Предлагайте идеи** - новые возможности и улучшения
3. 📝 **Улучшайте документацию** - исправления и дополнения
4. 🔧 **Пишите код** - pull requests приветствуются
5. 📚 **Создавайте примеры** - покажите возможности языка

### Как внести вклад

```bash
# 1. Форкните репозиторий
# 2. Создайте ветку для изменений
git checkout -b feature/amazing-feature

# 3. Внесите изменения и закоммитьте
git commit -m "Add amazing feature"

# 4. Отправьте изменения
git push origin feature/amazing-feature

# 5. Создайте Pull Request
```

---

## 📜 Лицензия

Этот проект распространяется под лицензией MIT. Подробности в файле [LICENSE](LICENSE).

```
MIT License

Copyright (c) 2024 Sup Programming Language

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction...
```

---

## 👨‍💻 Автор

**Kirill Belakov**

- GitHub: [@supm1ner](https://github.com/supm1ner)
- Email: kirillbelakov2222@gmail.com

---

## 🌟 Поддержите проект

Если вам нравится Sup, поставьте ⭐ на GitHub!

Это помогает другим разработчикам найти проект и мотивирует нас продолжать разработку.

---

## 📞 Связь и поддержка

- 🐛 **Нашли баг?** [Создайте issue](https://github.com/supm1ner/sup/issues)
- 💡 **Есть идея?** [Обсудите в Discussions](https://github.com/supm1ner/sup/discussions)
- 📧 **Вопросы?** Напишите на kirillbelakov2222@gmail.com

---

## 🎓 Обучающие материалы

### Для начинающих

1. [Быстрый старт](QUICKSTART.md) - первые шаги
2. [Hello World](examples/hello.sup) - простейшая программа
3. [Математика](examples/math.sup) - базовые операции

### Для продвинутых

1. [Калькулятор](examples/calculator.sup) - сложная логика
2. [Telegram бот](examples/telegram_bot_advanced.sup) - реальное приложение
3. [Стандартная библиотека](lib/README.md) - все возможности

---

## 📈 Статистика проекта

- **Строк кода компилятора**: ~3000+
- **Функций в стандартной библиотеке**: 35+
- **Примеров программ**: 7
- **Документации**: 15+ файлов
- **Версия**: 1.0.0

---

<div align="center">

### 🚀 Начните программировать на Sup уже сегодня!

[Скачать](https://github.com/supm1ner/sup/releases) • [Документация](QUICKSTART.md) • [Примеры](examples/)

---

**Сделано с ❤️ для разработчиков**

</div>

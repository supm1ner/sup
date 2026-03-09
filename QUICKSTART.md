# Быстрый старт с Sup Programming Language

## 🚀 За 5 минут

### 1. Проверьте компилятор

```bash
./sup.exe version
```

Должно вывести: `Sup Compiler v1.0`

### 2. Запустите первую программу

```bash
./sup.exe dev examples/hello.sup
```

Вы увидите:
```
Hello, World!
Привет, мир!
```

### 3. Попробуйте калькулятор

```bash
./sup.exe dev examples/calculator.sup
```

### 4. Протестируйте библиотеки

```bash
./sup.exe dev examples/library_test.sup
```

---

## 📚 Основы языка

### Hello World

```sup
func main() -> int {
    print("Hello, World!")
    return 0
}
```

### Переменные

```sup
var x = 10              # Автоматический вывод типа
var y: int = 20         # Явное указание типа
const PI = 3.14159      # Константа
```

### Функции

```sup
func add(a: int, b: int) -> int {
    return a + b
}

func main() -> int {
    var result = add(5, 3)
    print("Результат: " + str(result))
    return 0
}
```

### Условия

```sup
func checkNumber(x: int) -> int {
    if x > 0 {
        print("Положительное")
    } else {
        print("Отрицательное или ноль")
    }
    return 0
}
```

### Циклы

```sup
# While цикл
func countToTen() -> int {
    var i = 1
    while i <= 10 {
        print(str(i))
        i = i + 1
    }
    return 0
}

# For цикл (будущая функция)
func iterate() -> int {
    for i in range(0, 10) {
        print(str(i))
    }
    return 0
}
```

---

## 📦 Стандартная библиотека

### Математика (lib/math.sup)

```sup
# Копируйте функции из lib/math.sup в свой файл

func sqrt(x: float) -> float {
    # ... реализация ...
}

func main() -> int {
    var result = sqrt(16.0)
    print("Корень из 16: " + str(result))  # 4.0
    return 0
}
```

**Доступные функции:**
- `abs(x)` - абсолютное значение
- `min(a, b)`, `max(a, b)` - минимум/максимум
- `pow(base, exp)` - возведение в степень
- `sqrt(x)` - квадратный корень
- `factorial(n)` - факториал
- `fibonacci(n)` - числа Фибоначчи

### Строки (lib/string.sup)

```sup
func repeat(s: string, n: int) -> string {
    # ... реализация ...
}

func main() -> int {
    var stars = repeat("*", 20)
    print(stars)  # ********************
    return 0
}
```

**Доступные функции:**
- `repeat(s, n)` - повторить строку
- `separator(char, len)` - создать разделитель
- `header(text)` - красивый заголовок
- `box(text, width)` - рамка вокруг текста

### Полная документация

Смотрите [lib/README.md](lib/README.md) для полного списка функций с примерами.

---

## 🛠️ Команды компилятора

### Компиляция

```bash
./sup.exe compile examples/calculator.sup
```

Создаст файл `calculator.exe`

### Режим разработки (компиляция + запуск)

```bash
./sup.exe dev examples/calculator.sup
```

Автоматически скомпилирует и запустит программу.

### Версия компилятора

```bash
./sup.exe version
```

---

## 🎨 VS Code расширение

### Установка

1. Откройте VS Code
2. `Ctrl+Shift+P` → "Extensions: Install from VSIX"
3. Выберите `vscode-extension/sup-language-0.2.0.vsix`
4. Перезапустите VS Code

### Активация иконок файлов

1. `Ctrl+,` → найдите "File Icon Theme"
2. Выберите "Sup File Icons"
3. Файлы `.sup` теперь с иконкой!

### Возможности

- ✅ Подсветка синтаксиса
- ✅ Автозакрытие скобок и кавычек
- ✅ Комментирование строк (`Ctrl+/`)
- ✅ Сворачивание кода
- ✅ Иконки файлов

Подробнее: [vscode-extension/INSTALL_VSIX.md](vscode-extension/INSTALL_VSIX.md)

---

## 📖 Примеры программ

### 1. Hello World
```bash
./sup.exe dev examples/hello.sup
```

### 2. Математические операции
```bash
./sup.exe dev examples/math.sup
```

### 3. Калькулятор
```bash
./sup.exe dev examples/calculator.sup
```

### 4. Telegram бот
```bash
./sup.exe dev examples/telegram_bot_advanced.sup
```

### 5. Тест библиотек
```bash
./sup.exe dev examples/library_test.sup
```

Все примеры с описанием: [examples/README.md](examples/README.md)

---

## 🔧 Создание своей программы

### Шаг 1: Создайте файл

Создайте файл `myprogram.sup`:

```sup
func main() -> int {
    print("Моя первая программа на Sup!")
    return 0
}
```

### Шаг 2: Запустите

```bash
./sup.exe dev myprogram.sup
```

### Шаг 3: Скомпилируйте

```bash
./sup.exe compile myprogram.sup
```

Получите исполняемый файл `myprogram.exe`

---

## 💡 Полезные советы

### 1. Преобразование чисел в строки

Используйте функцию `str()`:

```sup
var age = 25
print("Мне " + str(age) + " лет")
```

### 2. Комментарии

```sup
# Это однострочный комментарий

func add(a: int, b: int) -> int {
    # Складываем два числа
    return a + b
}
```

### 3. Типы данных

- `int` - целые числа (10, -5, 0)
- `float` - дробные числа (3.14, -2.5, 0.0)
- `string` - строки ("Hello", "Привет")
- `bool` - логические значения (true, false)
- `void` - отсутствие значения

### 4. Встроенные функции

- `print(...)` - вывод в консоль
- `str(number)` - преобразование числа в строку

---

## 📚 Дополнительная документация

- [README.md](README.md) - Полная документация компилятора
- [lib/README.md](lib/README.md) - Стандартная библиотека
- [examples/README.md](examples/README.md) - Примеры программ
- [CLI_USAGE.md](CLI_USAGE.md) - Использование CLI
- [BUILD.md](BUILD.md) - Сборка компилятора
- [TELEGRAM_BOT_EXPLANATION.md](TELEGRAM_BOT_EXPLANATION.md) - Объяснение Telegram бота
- [UPDATES_SUMMARY.md](UPDATES_SUMMARY.md) - Последние обновления

---

## 🐛 Возможные проблемы

### Ошибка: "sup.exe не найден"

Убедитесь, что вы находитесь в корневой папке проекта:
```bash
cd path/to/sup-compiler
./sup.exe version
```

### Ошибка компиляции C++

Убедитесь, что g++ установлен и доступен в PATH:
```bash
g++ --version
```

Если нет, установите MinGW-w64.

### Проблемы с кодировкой

Если русские символы отображаются неправильно, используйте UTF-8 кодировку в редакторе.

---

## 🎯 Что дальше?

1. **Изучите примеры** в папке `examples/`
2. **Попробуйте библиотеки** из папки `lib/`
3. **Создайте свою программу**
4. **Установите VS Code расширение** для удобной разработки
5. **Экспериментируйте!**

---

## 🚀 Приятного программирования на Sup!

Если у вас есть вопросы или предложения, создайте issue в репозитории проекта.

**Версия:** 1.0
**Дата:** 2024
**Лицензия:** MIT

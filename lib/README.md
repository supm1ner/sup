# Стандартная библиотека Sup

Коллекция полезных функций для языка программирования Sup.

## Модули

### 📐 math.sup - Математические функции

Математические операции и константы.

**Константы:**
- `PI` - число Пи (3.14159...)
- `E` - число Эйлера (2.71828...)

**Функции:**

```sup
# Базовые операции
abs(x: float) -> float              # Абсолютное значение
min(a: float, b: float) -> float    # Минимум из двух чисел
max(a: float, b: float) -> float    # Максимум из двух чисел
clamp(value, min, max) -> float     # Ограничить значение диапазоном

# Степени и корни
pow(base: float, exp: int) -> float # Возведение в степень
sqrt(x: float) -> float             # Квадратный корень (метод Ньютона)

# Комбинаторика
factorial(n: int) -> int            # Факториал числа
fibonacci(n: int) -> int            # n-ое число Фибоначчи

# Проверки
isEven(n: int) -> bool              # Проверка на четность
isOdd(n: int) -> bool               # Проверка на нечетность
sign(x: float) -> int               # Знак числа (-1, 0, 1)

# Утилиты
lerp(a, b, t: float) -> float       # Линейная интерполяция
percent(value, pct: float) -> float # Процент от числа
average(a, b: float) -> float       # Среднее арифметическое
```

**Примеры использования:**

```sup
# Квадратный корень
var num = 16.0
var result = sqrt(num)  # 4.0

# Факториал
var fact = factorial(5)  # 120

# Числа Фибоначчи
var fib = fibonacci(10)  # 55

# Площадь круга
var radius = 5.0
var area = PI * radius * radius
```

---

### 📝 string.sup - Работа со строками

Функции для манипуляции строками и форматирования.

**Функции:**

```sup
# Базовые операции
strlen(s: string) -> int                    # Длина строки
repeat(s: string, n: int) -> string         # Повторить строку n раз
fill(char: string, count: int) -> string    # Заполнить символом

# Форматирование
padLeft(s, width, char: string) -> string   # Отступ слева
padRight(s, width, char: string) -> string  # Отступ справа
separator(char, length: string) -> string   # Создать разделитель

# Визуальное оформление
box(text: string, width: int) -> string     # Рамка вокруг текста
header(text: string) -> string              # Заголовок
subheader(text: string) -> string           # Подзаголовок
```

**Примеры использования:**

```sup
# Повторение строки
var stars = repeat("*", 20)  # "********************"

# Разделитель
var line = separator("=", 50)
print(line)

# Заголовок
header("Мое приложение")
# ==================================================
# Мое приложение
# ==================================================

# Рамка
box("Важное сообщение", 30)
# ╔══════════════════════════════╗
# ║ Важное сообщение             ║
# ╚══════════════════════════════╝
```

---

### 📊 array.sup - Работа с массивами

Функции для работы с последовательностями и диапазонами.

**Функции:**

```sup
# Поиск
findMax(start: int, end: int) -> int    # Максимум в диапазоне
findMin(start: int, end: int) -> int    # Минимум в диапазоне

# Генерация
range(start, end, step: int) -> int     # Генерация последовательности
countRange(start, end: int) -> int      # Количество элементов
```

**Примеры использования:**

```sup
# Найти максимум в диапазоне
var maxVal = findMax(1, 100)  # 100

# Генерация последовательности
range(0, 10, 2)
# Выведет: 0, 2, 4, 6, 8, 10

# Подсчет элементов
var count = countRange(1, 10)  # 10
```

---

## Использование библиотек

### Способ 1: Копирование функций

Скопируйте нужные функции из библиотеки в свой файл:

```sup
# Копируем функцию из lib/math.sup
func sqrt(x: float) -> float {
    # ... код функции ...
}

func main() -> int {
    var result = sqrt(16.0)
    print("Корень: " + str(result))
    return 0
}
```

### Способ 2: Полный импорт (будущая функция)

В будущих версиях Sup будет поддержка импорта:

```sup
# Будущий синтаксис (пока не реализован)
import "lib/math.sup"
import "lib/string.sup"

func main() -> int {
    var result = sqrt(25.0)
    print(result)
    return 0
}
```

---

## Тестирование библиотек

Запустите тестовый файл для проверки всех функций:

```bash
./sup.exe dev examples/library_test.sup
```

Этот файл демонстрирует использование всех функций из библиотеки.

---

## Примеры практического применения

### Пример 1: Расчет площади круга

```sup
const PI = 3.14159265359

func circleArea(radius: float) -> float {
    return PI * radius * radius
}

func main() -> int {
    var r = 5.0
    var area = circleArea(r)
    print("Площадь круга: " + str(area))
    return 0
}
```

### Пример 2: Теорема Пифагора

```sup
func sqrt(x: float) -> float {
    # ... реализация из lib/math.sup ...
}

func hypotenuse(a: float, b: float) -> float {
    var sumSquares = a * a + b * b
    return sqrt(sumSquares)
}

func main() -> int {
    var c = hypotenuse(3.0, 4.0)
    print("Гипотенуза: " + str(c))  # 5.0
    return 0
}
```

### Пример 3: Красивый вывод

```sup
func repeat(s: string, n: int) -> string {
    # ... реализация из lib/string.sup ...
}

func printBox(title: string) -> int {
    var line = repeat("=", 50)
    print(line)
    print(title)
    print(line)
    return 0
}

func main() -> int {
    printBox("Мое приложение v1.0")
    return 0
}
```

---

## Расширение библиотеки

Вы можете добавлять свои функции в библиотеку:

1. Создайте новый файл в папке `lib/`
2. Напишите функции с документацией
3. Добавьте примеры использования
4. Обновите этот README

---

## Планы развития

- ✅ Математические функции
- ✅ Строковые операции
- ✅ Работа с диапазонами
- 🔄 Поддержка массивов
- 🔄 Файловый ввод/вывод
- 🔄 Работа с датой и временем
- 🔄 HTTP запросы
- 🔄 JSON парсинг

---

## Лицензия

MIT License - свободное использование для любых целей.

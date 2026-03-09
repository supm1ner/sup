# Telegram Bot на языке Sup

Этот пример демонстрирует, как можно написать простого Telegram бота на языке программирования Sup.

## Файлы

### 1. `telegram_bot_simple.sup`
Упрощенная версия бота с симуляцией работы. Демонстрирует:
- Функции для обработки команд
- Условные операторы (if/else)
- Работу со строками
- Вывод в консоль

### 2. `telegram_bot.sup`
Более полная версия с структурой реального бота. Включает:
- Конфигурацию API
- Функции для работы с Telegram API
- Обработку различных команд (/start, /help, /echo)
- Главный цикл бота
- Обработку обновлений

## Запуск

### Упрощенная версия (симуляция)

```bash
# Компиляция
sup compile examples/telegram_bot_simple.sup -o telegram_bot_simple

# Запуск
./telegram_bot_simple

# Или сразу компиляция и запуск
sup dev examples/telegram_bot_simple.sup
```

### Полная версия

```bash
sup dev examples/telegram_bot.sup
```

## Пример вывода

```
╔════════════════════════════════════╗
║  Telegram Bot на языке Sup v1.0   ║
╚════════════════════════════════════╝

=== Симуляция работы Telegram бота ===

Получено сообщение от Алексей
Текст: start
Ответ: Добро пожаловать! Используйте команды: start, help, about

Получено сообщение от Мария
Текст: help
Ответ: Доступные команды: start, help, about, echo

Получено сообщение от Иван
Текст: about
Ответ: Я простой бот, написанный на языке программирования Sup!

Получено сообщение от Ольга
Текст: Привет, бот!
Ответ: Вы написали: Привет, бот!

Получено сообщение от Петр
Текст: Как дела?
Ответ: Вы написали: Как дела?

Бот завершил работу
```

## Возможности языка Sup, продемонстрированные в примере

### 1. Функции
```sup
func greet(name: string) -> string {
    return "Привет, " + name + "!"
}
```

### 2. Условные операторы
```sup
if message == "start" {
    response = processCommand("start")
} else {
    response = echoMessage(message)
}
```

### 3. Константы
```sup
const BOT_TOKEN = "YOUR_BOT_TOKEN_HERE"
```

### 4. Переменные
```sup
var response = ""
var iteration = 0
```

### 5. Циклы
```sup
while iteration < 100 {
    print("Итерация " + iteration)
    iteration = iteration + 1
}
```

### 6. Работа со строками
```sup
var message = "Привет, " + username + "!"
```

### 7. Типизация
```sup
func handleMessage(chat_id: int, text: string) -> int {
    # ...
}
```

## Реальная реализация

Для создания реального Telegram бота на Sup потребуется:

1. **HTTP библиотека** для запросов к Telegram Bot API
2. **JSON парсер** для обработки ответов API
3. **Функции для работы со строками** (startsWith, substring, split)
4. **Функция sleep** для задержки между запросами
5. **Обработка ошибок** и переподключение при сбоях

### Пример структуры реального бота:

```sup
# Подключение библиотек (когда будет пакетный менеджер)
import http
import json
import strings

const BOT_TOKEN = "YOUR_REAL_TOKEN"

func getUpdates(offset: int) -> list {
    var url = "https://api.telegram.org/bot" + BOT_TOKEN + "/getUpdates"
    var params = {"offset": offset, "timeout": 30}
    
    var response = http.get(url, params)
    var data = json.parse(response.body)
    
    return data.result
}

func sendMessage(chat_id: int, text: string) -> bool {
    var url = "https://api.telegram.org/bot" + BOT_TOKEN + "/sendMessage"
    var payload = {
        "chat_id": chat_id,
        "text": text
    }
    
    var response = http.post(url, payload)
    return response.ok
}

func main() -> int {
    var offset = 0
    
    while true {
        var updates = getUpdates(offset)
        
        for update in updates {
            var message = update.message
            var chat_id = message.chat.id
            var text = message.text
            
            # Обработка сообщения
            if strings.startsWith(text, "/") {
                handleCommand(chat_id, text)
            } else {
                handleMessage(chat_id, text)
            }
            
            offset = update.update_id + 1
        }
    }
    
    return 0
}
```

## Следующие шаги

1. Реализовать HTTP библиотеку для Sup
2. Добавить JSON парсер
3. Создать пакетный менеджер для установки библиотек
4. Расширить стандартную библиотеку функциями для работы со строками
5. Добавить поддержку словарей (dict) и списков (list)

## Заключение

Этот пример показывает, что язык Sup уже сейчас поддерживает основные конструкции, необходимые для создания ботов:
- ✅ Функции с параметрами и возвращаемыми значениями
- ✅ Условные операторы
- ✅ Циклы
- ✅ Переменные и константы
- ✅ Работа со строками
- ✅ Типизация

С добавлением библиотек для HTTP и JSON, на Sup можно будет создавать полноценных Telegram ботов!

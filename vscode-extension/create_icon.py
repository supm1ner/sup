#!/usr/bin/env python3
"""
Создание PNG иконки для VS Code расширения Sup Language
"""

try:
    from PIL import Image, ImageDraw, ImageFont
    PIL_AVAILABLE = True
except ImportError:
    PIL_AVAILABLE = False
    print("PIL (Pillow) не установлен. Установите: pip install Pillow")

def create_icon():
    """Создает PNG иконку 128x128 для расширения"""
    if not PIL_AVAILABLE:
        print("Невозможно создать иконку без Pillow")
        return False
    
    # Создаем изображение 128x128
    size = 128
    img = Image.new('RGB', (size, size), color='white')
    draw = ImageDraw.Draw(img)
    
    # Рисуем синий круг (фон)
    circle_color = (74, 144, 226)  # #4A90E2
    border_color = (46, 92, 138)   # #2E5C8A
    
    # Фон круга
    draw.ellipse([4, 4, size-4, size-4], fill=circle_color, outline=border_color, width=4)
    
    # Рисуем букву "S" белым цветом
    try:
        # Пытаемся использовать системный шрифт
        font = ImageFont.truetype("arial.ttf", 80)
    except:
        # Если не получилось, используем стандартный
        font = ImageFont.load_default()
    
    # Текст "S"
    text = "S"
    
    # Получаем размер текста для центрирования
    bbox = draw.textbbox((0, 0), text, font=font)
    text_width = bbox[2] - bbox[0]
    text_height = bbox[3] - bbox[1]
    
    # Центрируем текст
    x = (size - text_width) // 2
    y = (size - text_height) // 2 - 5
    
    # Рисуем белую букву S
    draw.text((x, y), text, fill='white', font=font)
    
    # Добавляем декоративные точки
    dot_color = 'white'
    dot_radius = 4
    
    # Три точки справа
    draw.ellipse([95-dot_radius, 35-dot_radius, 95+dot_radius, 35+dot_radius], fill=dot_color)
    draw.ellipse([95-dot_radius, 50-dot_radius, 95+dot_radius, 50+dot_radius], fill=dot_color)
    draw.ellipse([95-dot_radius, 65-dot_radius, 95+dot_radius, 65+dot_radius], fill=dot_color)
    
    # Сохраняем
    img.save('icon.png', 'PNG')
    print("✓ Иконка создана: icon.png (128x128)")
    return True

if __name__ == '__main__':
    if create_icon():
        print("\nИконка успешно создана!")
        print("Теперь можно пересобрать VSIX: vsce package")
    else:
        print("\nУстановите Pillow: pip install Pillow")

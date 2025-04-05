import os
import django
from django.utils.timezone import make_aware
from faker import Faker
from mainapp.models import Articles  # Замените `your_app` на название вашего приложения

# Настроим Django, если запускаем скрипт отдельно
os.environ.setdefault("DJANGO_SETTINGS_MODULE", "lab1.settings")
django.setup()

fake = Faker()


def create_fake_articles(n=1000):
    articles = []
    for _ in range(n):
        article = Articles(
            title=fake.sentence(nb_words=6)[:50],
            full_text=fake.paragraph(nb_sentences=10),
            date=make_aware(fake.date_time_this_year()),
            author=fake.name(),
            is_publish=fake.boolean()
        )
        articles.append(article)

    Articles.objects.bulk_create(articles)
    print(f"Добавлено {n} записей в базу данных")


def clear_database():
    Articles.objects.all().delete()
    print("База данных очищена")


def reset_pk():
    from django.db import connection
    with connection.cursor() as cursor:
        cursor.execute("DELETE FROM sqlite_sequence WHERE name='mainapp_articles'")  # Замените `your_app_articles` на правильное имя таблицы
    print("Счетчик первичного ключа сброшен")


if __name__ == "__main__":
    create_fake_articles()

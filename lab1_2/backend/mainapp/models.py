from django.db import models


# Create your models here.
class Articles(models.Model):
    title = models.CharField("Название", max_length=50)
    full_text = models.TextField("Текст")
    date = models.DateTimeField("Дата публикаций")
    author = models.CharField("Автор",max_length=150)
    is_publish = models.BooleanField("Опубликовано ли?", default=False)

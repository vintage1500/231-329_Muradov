from django.contrib import admin
from django.urls import path    

from django.conf import settings
from django.conf.urls.static import static
from rest_framework import routers

from mainapp.views import ArticleViewSet
    
urlpatterns = [
    path('admin/', admin.site.urls),
    path('article', ArticleViewSet.as_view({'get': 'list', 'post': 'create'})),
    path('article/<pk>', ArticleViewSet.as_view({'get': 'retrieve', 'patch': 'update', 'delete': 'destroy'})),
]

urlpatterns += static(settings.STATIC_URL, document_root=settings.STATIC_ROOT)
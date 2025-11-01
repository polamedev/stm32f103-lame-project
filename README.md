# stm32f103-lame-project
Проект для stm32f103 bluepill 

Что нужно сделать с проектом, чтобы заработала генерация


### Файл gen-stm32f103-lame-project/CMakeLists.txt 

* приравнять CMAKE_SOURCE_DIR на CMAKE_CURRENT_SOURCE_DIR в начале файла. Нужно так как cubeMX генерирует список включаемых файлов относительно CMAKE_SOURCE_DIR, а мы находимся в подпроекте. По выходу из файла CMAKE_SOURCE_DIR вернется на прежнее значение

```cmake
set(CMAKE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
```

* Заменить add_subdirectory(cmake/stm32cubemx/CMakeLists.txt) на include(cmake/stm32cubemx/CMakeLists.txt)

* Убрать подключение include("cmake/gcc-arm-none-eabi.cmake"). gcc-arm-none-eabi.cmake будет подключаться в cmake файле корня

### Добавить gen-stm32f103-lame-project/Core/Inc/cubemx.h

### Файл gen-stm32f103-lame-project/Core/Src/main.c

* Добавить функцию MX_Init
* Использовать weak вызовы для main и Error_Handler


### Добавить файл cmake/gcc-arm-none-eabi.cmake


## Генерация векторов прерываний

В CubeMX можно отключить генерацию векторов, если нужны какие то уникальные

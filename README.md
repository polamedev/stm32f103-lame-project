# stm32f103-lame-project
Проект для stm32f103 bluepill 

Что нужно сделать с проектом, чтобы заработала генерация

### Файл gen-stm32f103-lame-project/cmake/stm32cubemx/CMakeLists.txt

заменить CMAKE_SOURCE_DIR на CMAKE_CURRENT_SOURCE_DIR

set(CMAKE_C_LINK_FLAGS "${CMAKE_C_LINK_FLAGS} -T \"${CMAKE_CURRENT_SOURCE_DIR}/STM32F103XX_FLASH.ld\"")


### Файл gen-stm32f103-lame-project/CMakeLists.txt 

* Сделать замену CMAKE_SOURCE_DIR на CMAKE_CURRENT_SOURCE_DIR, Нужно так как cubeMX генерирует список включаемых файлов относительно CMAKE_SOURCE_DIR, а мы находимся в подпроекте

set(OLD_CMAKE_SOURCE_DIR ${CMAKE_SOURCE_DIR})
set(CMAKE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}")

* Заменить add_subdirectory(cmake/stm32cubemx/CMakeLists.txt) на include(cmake/stm32cubemx/CMakeLists.txt)

### Файл gen-stm32f103-lame-project/Core/Inc/cubemx.h

### Файл gen-stm32f103-lame-project/Core/Src/main.c

* Добавить функцию MX_Init
* Использовать weak вызовы для main и Error_Handler


### Добавить файл cmake/gcc-arm-none-eabi.cmake


## Генерация векторов прерываний

В CubeMX можно отключить генерацию векторов, если нужны какие то уникальные
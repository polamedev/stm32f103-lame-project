cmake_minimum_required(VERSION 3.21)

option(BUILD_TESTS "Build tests" OFF) # Нужно ли собирать тесты

if(NOT BUILD_TESTS)
    # Если не нужен тестовый таргет, то нужно будет собрат основной таргет, для это определим необходимый набор 
    # Инструментов для stm

    # Подключаем файл toolchain нужно делать тоже до объявления  project(), чтобы сообщить основные настройки
    include(cmake/gcc-arm-none-eabi.cmake)
endif()




# Основные настройки проекта
project(
    stm32f103-lame-project
    VERSION 1.0.0
    DESCRIPTION
    "Шаблонный проект для stm32f103 используя библиотеку lame и генерацию cubeMX"
    LANGUAGES C
)

# Include toolchain file
# project(${CMAKE_PROJECT_NAME})
# Определяем является ли текущий проектом верхнего уровня. Для fetch проектов, gitsubmodule или просто вложенных проектов это неверно
# string(COMPARE EQUAL "${CMAKE_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}" is_top_level)
# Но в новых версиях 3.21 можно использовать ${PROJECT_IS_TOP_LEVEL}

# -----------------------------------------------------------------------------------------------------------------------------------
# Настройка сборки библиотеки
# -----------------------------------------------------------------------------------------------------------------------------------

# # Опции сборки
# option(LAME_BUILD_MOCKS       "Build  lame mocks lib"       OFF)  # Нужно ли собирать мок-объекты библиотеки
# option(LAME_BUILD_MOCKS_TESTS "Build tests lame::mocks lib" OFF)  # Нужно ли собирать тесты для библиотеки мок-объектов, также опция определяется в самой библиотеки тестов

# Установка типа сборки
if(NOT CMAKE_BUILD_TYPE)
    # Установить переменную CMAKE_BUILD_TYPE и сохранить в кэше
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type")
    # Устанавливаем для CMAKE_BUILD_TYPE возможные значения, которые можно будет выбрать через cmake-gui
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()


# Добавление суфикса в имя дебажной библиотеки, нужно чтобы установить различия в названии. Возможно от этого стоит отказаться
# set(CMAKE_DEBUG_POSTFIX -dev)

# -----------------------------------------------------------------------------------------------------------------------------------
# Настройка таргета
# -----------------------------------------------------------------------------------------------------------------------------------

if(NOT BUILD_TESTS)
    # Если не определена сборка тестов, то собираем обычный проект для stm32

    # Подключаем подпроект cubeMX c генерацией исходников
    add_subdirectory(gen-stm32f103-lame-project)

    add_executable(app_lame)

    target_sources(app_lame
        PRIVATE
        core/main.c
        core/interrupt.c
    )

    # TODO: Важно: Подключить библиотеку lame нужно перед lame-stm32, не знаю почему
    target_link_libraries(app_lame cubemx STM32_Drivers lame::lame lame::lame-stm32)

    target_link_options(app_lame PRIVATE "-T${CMAKE_SOURCE_DIR}/gen-stm32f103-lame-project/STM32F103XX_FLASH.ld")
    target_link_options(app_lame PRIVATE "-Wl,-Map=${CMAKE_PROJECT_NAME}.map")

    add_subdirectory(lib/lame-portable-stm32)

else()
    # Иначе собираем таргет с тестами

    # Включение тестирования необходимо в корневом файле
    enable_testing()
    add_subdirectory(tests)
endif()

# -----------------------------------------------------------------------------------------------------------------------------------
# Добавление других таргетов
# -----------------------------------------------------------------------------------------------------------------------------------

# Подключаем библиотеку lame в качестве подмодуля
add_subdirectory(lib/lame)


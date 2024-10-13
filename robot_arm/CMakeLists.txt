cmake_minimum_required(VERSION 3.16)

project(test3 VERSION 0.1 LANGUAGES CXX)

# Qt 관련 자동 설정
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# C++17 표준 설정
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Qt 라이브러리 찾기
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

# 소스 파일 리스트
set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui  # UI 파일 포함
)

# 실행 파일 설정
add_executable(test3
    ${PROJECT_SOURCES}
)

# 라이브러리 링크
target_link_libraries(test3 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# 설치 설정
install(TARGETS test3
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Qt 6에서만 필요한 추가 처리
if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(test3)
endif()

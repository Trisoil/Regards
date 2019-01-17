TARGET = opengl_tone_mapping

QT += core
QT += gui
QT += opengl
QT += widgets

SOURCES += main.cpp

CONFIG   += C++11
QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.7

INCLUDEPATH += ../../include

win32-msvc*{
    DEFINES += _CRT_SECURE_NO_DEPRECATE
    SOURCES += ../opengl_common_code/gl_core_4_0.c
}

win32{
        DEFINES += NOMINMAX
}


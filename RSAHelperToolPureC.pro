
QT += core gui
TEMPLATE = app
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    applink.c \
    helper.cpp \
    main.cpp \
    dialog.cpp \
    algdialog.cpp

#LIBS += -L"D:/OpenSSL-Win32/lib/MinGW" -llibeay32
#LIBS += -L"D:/OpenSSL-Win32/lib/MinGW" -lssleay32
LIBS += -L"D:\OpenSSL-Win32-1.1.0\lib\MinGW" -llibssl-1_1
LIBS += -L"D:\OpenSSL-Win32-1.1.0\lib\MinGW" -llibcrypto-1_1

#LIBS+= $${PWD}/libeay32.a
#LIBS+= $${PWD}/ssleay32.a

INCLUDEPATH += $$quote(D:\OpenSSL-Win32-1.1.0\include)
#INCLUDEPATH += $$quote(D:\OpenSSL-Win32\include)

HEADERS += \
    helper.h \
    dialog.h \
    algdialog.h

TRANSLATIONS += translations/language_zh.ts

RESOURCES += \
    resource.qrc

RC_ICONS = images/kls.ico #现在设置图标直接这么写就可以了，不用rc文件



TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    applink.c \
    helper.cpp \
    main.cpp

#LIBS += -L"D:/OpenSSL-Win32/lib/MinGW" -llibeay32
#LIBS += -L"D:/OpenSSL-Win32/lib/MinGW" -lssleay32
LIBS += -L"D:/OpenSSL-Win32/lib/MinGW" -llibssl-1_1
LIBS += -L"D:/OpenSSL-Win32/lib/MinGW" -llibcrypto-1_1

#LIBS+= $${PWD}/libeay32.a
#LIBS+= $${PWD}/ssleay32.a

INCLUDEPATH += $$quote(D:/OpenSSL-Win32/include)

HEADERS += \
    helper.h


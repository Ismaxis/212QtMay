QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    2modules/capacitycalc.cpp \
    2modules/duringcalc.cpp \
    2modules/endcalc.cpp \
    2modules/funcs.cpp \
    2modules/tempcalc.cpp \
    3modules/funcsthermalcapacity.cpp \
    3modules/thermalcapacity.cpp \
    4modules/alfa.cpp \
    4modules/excessairratio.cpp \
    Sheet.cpp \
    main.cpp \
    mainwindow.cpp \
    storage.cpp

HEADERS += \
    2modules/capacitycalc.h \
    2modules/duringcalc.h \
    2modules/endcalc.h \
    2modules/funcs.h \
    2modules/tableData.h \
    2modules/tempcalc.h \
    3modules/funcsthermalcapacity.h \
    3modules/thermalcapacity.h \
    4modules/alfa.h \
    4modules/excessairratio.h \
    Sheet.h \
    Table.h \
    mainwindow.h \
    storage.h

FORMS += \
    2modules/capacitycalc.ui \
    2modules/duringcalc.ui \
    2modules/endcalc.ui \
    2modules/tempcalc.ui \
    3modules/ThermalCapacity.ui \
    4modules/excessairratio.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

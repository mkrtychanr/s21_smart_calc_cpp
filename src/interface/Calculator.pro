QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../model/dataprocessing.cc \
    ../model/datarecognizer.cc \
    calculator.cc \
    ../controller/controller.cc \
    graphic.cc \
    main.cc \
    ../model/model.cc \
    qcustomplot.cc

HEADERS += \
    ../model/dataprocessing.h \
    ../model/datarecognizer.h \
    calculator.h \
    ../controller/controller.h \
    graphic.h \
    ../model/model.h \
    qcustomplot.h

FORMS += \
    calculator.ui \
    graphic.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

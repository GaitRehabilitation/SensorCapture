QT += quick
QT += widgets
QT += bluetooth
QT += charts
CONFIG += c++11

FORMS += forms/mainwindow.ui \
    forms/devicepanel.ui \
    forms/devicediscoverywizardpage.ui

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += main.cpp \
    forms/mainwindow.cpp \
    gui/devicehandler.cpp \
    gui/devicemanager.cpp \
    gui/device.cpp \
    gui/device_wizard/deviceconnectpage.cpp \
    gui/device_wizard/devicediscoverypage.cpp \
    forms/devicewizard.cpp \
    forms/devicediscoverywizardpage.cpp

RESOURCES += qml.qrc \
    icons.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH = gui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    forms/mainwindow.h \
    gui/devicehandler.h \
    gui/devicemanager.h \
    gui/device.h \
    common/devices/graillabpackets.h \
    gui/device_wizard/deviceconnectpage.h \
    gui/device_wizard/devicediscoverypage.h \
    forms/devicewizard.h \
    forms/devicediscoverywizardpage.h

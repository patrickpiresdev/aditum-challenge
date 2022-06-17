QT += quick

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        src/main/app.cpp \
        src/main/service/availablerestaurants.cpp \
        src/main/model/restaurant.cpp \
        src/main/model/hour.cpp \
        src/main/controller/restaurantcontroller.cpp \
        src/main/dao/restaurantdao.cpp

HEADERS += \
    src/main/service/availablerestaurants.h \
    src/main/model/restaurant.h \
    src/main/model/hour.h \
    src/main/controller/restaurantcontroller.h \
    src/main/dao/restaurantdao.h

RESOURCES += src/main/view/qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

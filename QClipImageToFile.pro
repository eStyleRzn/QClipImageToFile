TARGET = QClipImageToFile
TEMPLATE = app

CONFIG -= debug_and_release
CONFIG += rtti exceptions
CONFIG += c++14
CONFIG -= app_bundle

QT       += core gui widgets

# Set up output folder
DESTDIR = $$absolute_path($$PWD/build/)

# Windows logic
# Attention!!! The folders below will affect the logic of installer builder, since they define binaries ouput folder
win32{
    CONFIG(debug, debug|release){
      DESTDIR = $$DESTDIR/WinDebug

      MY_PLATFORM_PLUGINS += $$[QT_INSTALL_PLUGINS]/platforms/qwindowsd.dll

      MY_LIB_FILES += $$[QT_INSTALL_BINS]/Qt5Cored.dll
      MY_LIB_FILES += $$[QT_INSTALL_BINS]/Qt5Guid.dll
      MY_LIB_FILES += $$[QT_INSTALL_BINS]/Qt5Widgetsd.dll
   } else {
      DESTDIR = $$DESTDIR/WinRelease
   }

}

DEFINES += _UNICODE UNICODE

MOC_DIR     = $${DESTDIR}/gen/moc
OBJECTS_DIR = $${DESTDIR}/gen/obj
RCC_DIR     = $${DESTDIR}/gen/res
UI_DIR      = $${DESTDIR}/gen/uic

## Define what files are 'extra_libs' and where to put them
ExtraLibs.files = $$MY_LIB_FILES
ExtraLibs.path = $${DESTDIR}

ExtraPlatforms.files += $$MY_PLATFORM_PLUGINS
ExtraPlatforms.path += $${DESTDIR}/platforms

## Tell qmake to add the moving of them to the 'install' target
INSTALLS += ExtraLibs \
    ExtraPlatforms \

SOURCES += $$PWD/src/main.cpp \
        $$PWD/src/MainWindow.cpp \
    src/LineEdit.cpp \
    src/TemporaryImageFile.cpp

HEADERS  += $$PWD/src/MainWindow.h \
    src/LineEdit.h \
    src/TemporaryImageFile.h

FORMS    += $$PWD/src/MainWindow.ui

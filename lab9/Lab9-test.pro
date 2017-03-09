
### BEGIN setup for CxxTest test program
TEMPLATE = app

TARGET = cxxtest

cxxtest.target = testrunner.cpp
cxxtest.commands = $$PWD/../cxxtest/bin/cxxtestgen \
  --error-printer --have-eh --have-std --abort-on-fail \
  -o testrunner.cpp $$PWD/phoneBook_test.h
cxxtest.depends = $$PWD/phoneBook_test.h

QMAKE_EXTRA_TARGETS += cxxtest

HEADERS += *_test*.h

SOURCES += $$OUT_PWD/testrunner.cpp

INCLUDEPATH += $$PWD/../cxxtest
DEPENDPATH += $$PWD/../cxxtest


### END setup for CxxTest test program



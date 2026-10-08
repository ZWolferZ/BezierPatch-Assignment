qmake -project "QT+=core gui opengl widgets openglwidgets" "QMAKE_CXXFLAGS+= -fopenmp -Wall" "LIBS += -lGL -lGLU -fopenmp"
qmake
make

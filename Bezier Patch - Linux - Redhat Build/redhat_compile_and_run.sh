qmake RedhatProjectFile.pro
qmake
make
cd release
export QT_QPA_PLATFORM=xcb
./BezierPatchWindowRelease patch.txt

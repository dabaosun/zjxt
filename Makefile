#/***************************************************************
# * Name:      Makefile
# * Purpose:   Manage buidling process
# * Author:    sunzhenbao (suzhenbao@live.com)
# * Copyright: sunzhenbao ()
# * License:
# **************************************************************/

WORKDIR = %cd%

CC = gcc.exe
CXX = g++.exe
AR = ar.exe
LD = g++.exe
WINDRES = windres.exe

INC = -IwxWidgets-3.1.1\\include -Iopencv-3.4.1\\build\\x64\\mingw\\include
CFLAGS = -Wall -std=c++11 -pipe -mthreads -D__GNUWIN32__ -D__WXMSW__ -DwxUSE_UNICODE
RESINC =
LIBDIR = -LwxWidgets-3.1.1\\lib\\gcc_lib -Lopencv-3.4.1\\build\\x64\\mingw\\bin
LIB = -lkernel32 -luser32 -lgdi32 -lwinspool -lcomdlg32 -ladvapi32 -lshell32 -lole32 -loleaut32 -luuid -lcomctl32 -lwsock32 -lodbc32 -lshlwapi -lversion
LDFLAGS = -mthreads

INC_DEBUG = $(INC) -IwxWidgets-3.1.1\lib\gcc_lib\mswud -Iopencv\build\install\include -Idetector -Iinclude
CFLAGS_DEBUG = $(CFLAGS) -std=c++11 -g
RESINC_DEBUG = $(RESINC) -IwxWidgets-3.1.1\lib\gcc_lib\mswud
RCFLAGS_DEBUG = $(RCFLAGS)
LIBDIR_DEBUG = $(LIBDIR) -LwxWidgets-3.1.1\lib\gcc_lib -Lopencv\build\install\x64\mingw\bin -Lopencv\build\install\x64\mingw\lib
LIB_DEBUG = $(LIB) -lwxmsw31u_core -lwxbase31u -lwxpng -lwxzlib -lopencv_img_hash341.dll -lopencv_world341.dll
LDFLAGS_DEBUG = $(LDFLAGS)
OBJDIR_DEBUG = obj\\Debug
DEP_DEBUG =
OUT_DEBUG = bin\\Debug\\Signin.exe

INC_RELEASE = $(INC) -IwxWidgets-3.1.1\lib\gcc_lib\mswu -Iopencv\build\install\include -Idetector -Iinclude
CFLAGS_RELEASE = $(CFLAGS) -O2 -std=c++11
RESINC_RELEASE = $(RESINC) -IwxWidgets-3.1.1\lib\gcc_lib\mswu
RCFLAGS_RELEASE = $(RCFLAGS)
LIBDIR_RELEASE = $(LIBDIR) -LwxWidgets-3.1.1\lib\gcc_lib -Lopencv\build\install\x64\mingw\lib -Lopencv\build\install\x64\mingw\bin
LIB_RELEASE = $(LIB) -lwxmsw31u_core -lwxbase31u -lwxpng -lwxzlib -lopencv_world341.dll -lopencv_img_hash341.dll
LDFLAGS_RELEASE =  -s $(LDFLAGS)
OBJDIR_RELEASE = obj\\Release
DEP_RELEASE =
OUT_RELEASE = bin\\Release\\Signin.exe

OBJ_DEBUG = $(OBJDIR_DEBUG)\\SigninApp.o $(OBJDIR_DEBUG)\\SigninMain.o $(OBJDIR_DEBUG)\\camera\\CameraView.o $(OBJDIR_DEBUG)\\detector\\Detector.o $(OBJDIR_DEBUG)\\resource.o

OBJ_RELEASE = $(OBJDIR_RELEASE)\\SigninApp.o $(OBJDIR_RELEASE)\\SigninMain.o $(OBJDIR_RELEASE)\\camera\\CameraView.o $(OBJDIR_RELEASE)\\detector\\Detector.o $(OBJDIR_RELEASE)\\resource.o

all: debug release

clean: clean_debug clean_release

before_debug:
	cmd /c if not exist bin\\Debug md bin\\Debug
	cmd /c if not exist $(OBJDIR_DEBUG) md $(OBJDIR_DEBUG)
	cmd /c if not exist $(OBJDIR_DEBUG)\\camera md $(OBJDIR_DEBUG)\\camera
	cmd /c if not exist $(OBJDIR_DEBUG)\\detector md $(OBJDIR_DEBUG)\\detector

after_debug:
	cp wxWidgets-3.1.1/lib/gcc_lib/wxbase311u_gcc510TDM_x64.dll bin/Debug/
	cp wxWidgets-3.1.1/lib/gcc_lib/wxmsw311u_core_gcc510TDM_x64.dll bin/Debug/
	cp opencv/build/install/x64/mingw/bin/libopencv_world341.dll bin/Debug/
	cp opencv/build/install/x64/mingw/bin/libopencv_world341.dll bin/Debug/
	cp opencv/build/install/x64/mingw/bin/libopencv_img_hash341.dll bin/Debug/
	cp opencv/build/install/x64/mingw/bin/opencv_ffmpeg341_64.dll bin/Debug/

debug: before_debug out_debug after_debug

out_debug: before_debug $(OBJ_DEBUG) $(DEP_DEBUG)
	$(LD) $(LIBDIR_DEBUG) -o $(OUT_DEBUG) $(OBJ_DEBUG)  $(LDFLAGS_DEBUG) -mwindows $(LIB_DEBUG)

$(OBJDIR_DEBUG)\\SigninApp.o: SigninApp.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c SigninApp.cpp -o $(OBJDIR_DEBUG)\\SigninApp.o

$(OBJDIR_DEBUG)\\SigninMain.o: SigninMain.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c SigninMain.cpp -o $(OBJDIR_DEBUG)\\SigninMain.o

$(OBJDIR_DEBUG)\\camera\\CameraView.o: camera\\CameraView.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c camera\\CameraView.cpp -o $(OBJDIR_DEBUG)\\camera\\CameraView.o

$(OBJDIR_DEBUG)\\detector\\Detector.o: detector\\Detector.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c detector\\Detector.cpp -o $(OBJDIR_DEBUG)\\detector\\Detector.o

$(OBJDIR_DEBUG)\\resource.o: resource.rc
	$(WINDRES) -i resource.rc -J rc -o $(OBJDIR_DEBUG)\\resource.o -O coff $(INC_DEBUG)

clean_debug:
	cmd /c del /f $(OBJ_DEBUG) $(OUT_DEBUG)
	cmd /c rd bin\\Debug
	cmd /c rd $(OBJDIR_DEBUG)
	cmd /c rd $(OBJDIR_DEBUG)\\camera
	cmd /c rd $(OBJDIR_DEBUG)\\detector

before_release:
	cmd /c if not exist bin\\Release md bin\\Release
	cmd /c if not exist $(OBJDIR_RELEASE) md $(OBJDIR_RELEASE)
	cmd /c if not exist $(OBJDIR_RELEASE)\\camera md $(OBJDIR_RELEASE)\\camera
	cmd /c if not exist $(OBJDIR_RELEASE)\\detector md $(OBJDIR_RELEASE)\\detector

after_release:
	cp wxWidgets-3.1.1/lib/gcc_lib/wxbase311u_gcc510TDM_x64.dll bin/Release/
	cp wxWidgets-3.1.1/lib/gcc_lib/wxmsw311u_core_gcc510TDM_x64.dll bin/Release/
	cp opencv/build/install/x64/mingw/bin/libopencv_world341.dll bin/Release/
	cp opencv/build/install/x64/mingw/bin/libopencv_world341.dll bin/Release/
	cp opencv/build/install/x64/mingw/bin/libopencv_img_hash341.dll bin/Release/
	cp opencv/build/install/x64/mingw/bin/opencv_ffmpeg341_64.dll bin/Release/

release: before_release out_release after_release

out_release: before_release $(OBJ_RELEASE) $(DEP_RELEASE)
	$(LD) $(LIBDIR_RELEASE) -o $(OUT_RELEASE) $(OBJ_RELEASE)  $(LDFLAGS_RELEASE) -mwindows $(LIB_RELEASE)

$(OBJDIR_RELEASE)\\SigninApp.o: SigninApp.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c SigninApp.cpp -o $(OBJDIR_RELEASE)\\SigninApp.o

$(OBJDIR_RELEASE)\\SigninMain.o: SigninMain.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c SigninMain.cpp -o $(OBJDIR_RELEASE)\\SigninMain.o

$(OBJDIR_RELEASE)\\camera\\CameraView.o: camera\\CameraView.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c camera\\CameraView.cpp -o $(OBJDIR_RELEASE)\\camera\\CameraView.o

$(OBJDIR_RELEASE)\\detector\\Detector.o: detector\\Detector.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c detector\\Detector.cpp -o $(OBJDIR_RELEASE)\\detector\\Detector.o

$(OBJDIR_RELEASE)\\resource.o: resource.rc
	$(WINDRES) -i resource.rc -J rc -o $(OBJDIR_RELEASE)\\resource.o -O coff $(INC_RELEASE)

clean_release:
	cmd /c del /f $(OBJ_RELEASE) $(OUT_RELEASE)
	cmd /c rd bin\\Release
	cmd /c rd $(OBJDIR_RELEASE)
	cmd /c rd $(OBJDIR_RELEASE)\\camera
	cmd /c rd $(OBJDIR_RELEASE)\\detector

.PHONY: before_debug after_debug clean_debug before_release after_release clean_release


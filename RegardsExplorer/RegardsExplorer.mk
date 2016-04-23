##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=RegardsExplorer
ConfigurationName      :=Debug
WorkspacePath          := "/home/figuinha/dev/Regards"
ProjectPath            := "/home/figuinha/dev/Regards/RegardsExplorer"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=root
Date                   :=22/09/15
CodeLitePath           :="/home/figuinha/.codelite"
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=$(PreprocessorSwitch)__WXGTK__ $(PreprocessorSwitch)GLEW_MX $(PreprocessorSwitch)GLEW_STATIC 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="RegardsExplorer.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)../libSqlite $(IncludeSwitch)../libTheme $(IncludeSwitch)../../libextern/libRapidXML $(IncludeSwitch)../../libextern/ffmpeg-2.6.2 $(IncludeSwitch)../../libextern/SDL2-2.0.3/include $(IncludeSwitch)../../libextern/wxWidgets-3.0.2/include $(IncludeSwitch)../../libextern/wxWidgets-3.0.2/lib/wx/include/gtk2-unicode-static-3.0 $(IncludeSwitch)../libGeolocalisation $(IncludeSwitch)../libParameter $(IncludeSwitch)../../libextern/exiv2-0.24/src $(IncludeSwitch)../../libextern/exiv2-0.24/xmpsdk/include $(IncludeSwitch)../libUtility $(IncludeSwitch)../libFiltreInterface $(IncludeSwitch)../include $(IncludeSwitch)../libDataStructure $(IncludeSwitch)../libResource $(IncludeSwitch)../libSqlData $(IncludeSwitch)../libOpenGL $(IncludeSwitch)../libRenderBitmap $(IncludeSwitch)../libSqlEngine $(IncludeSwitch)../libSqlite $(IncludeSwitch)../../libextern/glew-1.13.0/include $(IncludeSwitch)../libFiltre $(IncludeSwitch)../include $(IncludeSwitch)../libDataStructure $(IncludeSwitch)../Otherlib/wxSVG/include $(IncludeSwitch)../libWindow $(IncludeSwitch)../libPrint $(IncludeSwitch)../libPicture $(IncludeSwitch)../libTheme $(IncludeSwitch)../libGeolocalisation $(IncludeSwitch)../libControl $(IncludeSwitch)../libIntro $(IncludeSwitch)../libDialog $(IncludeSwitch)../libViewer $(IncludeSwitch)../libExplorer $(IncludeSwitch)../libOpenCL $(IncludeSwitch)../libWindowMain $(IncludeSwitch)../libVideoFFMpeg 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)Explorer $(LibrarySwitch)Viewer $(LibrarySwitch)Intro $(LibrarySwitch)VideoFFMpeg $(LibrarySwitch)Control $(LibrarySwitch)Exif $(LibrarySwitch)Email $(LibrarySwitch)Picture $(LibrarySwitch)Window $(LibrarySwitch)WindowMain $(LibrarySwitch)Geolocalisation $(LibrarySwitch)Utility $(LibrarySwitch)Dialog $(LibrarySwitch)Resource $(LibrarySwitch)SqlData $(LibrarySwitch)DataStructure $(LibrarySwitch)SqlEngine $(LibrarySwitch)Sqlite $(LibrarySwitch)dl $(LibrarySwitch)Compress $(LibrarySwitch)Utility $(LibrarySwitch)Picture $(LibrarySwitch)VideoThumbnail $(LibrarySwitch)Dialog $(LibrarySwitch)Geolocalisation $(LibrarySwitch)Exif $(LibrarySwitch)SqlData $(LibrarySwitch)Print $(LibrarySwitch)Filtre $(LibrarySwitch)RenderBitmap $(LibrarySwitch)Theme $(LibrarySwitch)DataStructure $(LibrarySwitch)Utility $(LibrarySwitch)Resource $(LibrarySwitch)Parameter $(LibrarySwitch)RegardsCL $(LibrarySwitch)OpenCL $(LibrarySwitch)cl_logger $(LibrarySwitch)task_executor $(LibrarySwitch)intelocl $(LibrarySwitch)cpu_device $(LibrarySwitch)tbb $(LibrarySwitch)OpenGL $(LibrarySwitch)GLEWmx $(LibrarySwitch)CxImage $(LibrarySwitch)wxSVG $(LibrarySwitch)GL $(LibrarySwitch)SDL2 $(LibrarySwitch)wx_gtk2u_gl-3.0 $(LibrarySwitch)wx_gtk2u-3.0 $(LibrarySwitch)X11 $(LibrarySwitch)gtk-x11-2.0 $(LibrarySwitch)gdk-x11-2.0 $(LibrarySwitch)GLU $(LibrarySwitch)pango-1.0 $(LibrarySwitch)pangocairo-1.0 $(LibrarySwitch)cairo $(LibrarySwitch)gobject-2.0 $(LibrarySwitch)exiv2 $(LibrarySwitch)expat $(LibrarySwitch)Jbig $(LibrarySwitch)Psd $(LibrarySwitch)jasper $(LibrarySwitch)mng $(LibrarySwitch)wxtiff-3.0 $(LibrarySwitch)wxpng-3.0 $(LibrarySwitch)RegardsRaw $(LibrarySwitch)raw_r $(LibrarySwitch)z $(LibrarySwitch)gomp $(LibrarySwitch)avcodec $(LibrarySwitch)avformat $(LibrarySwitch)avdevice $(LibrarySwitch)avfilter $(LibrarySwitch)avutil $(LibrarySwitch)swresample $(LibrarySwitch)swscale $(LibrarySwitch)xcb $(LibrarySwitch)xcb-shm $(LibrarySwitch)Xxf86vm $(LibrarySwitch)pthread $(LibrarySwitch)gdk_pixbuf-2.0 $(LibrarySwitch)glib-2.0 $(LibrarySwitch)SM $(LibrarySwitch)webkitgtk-1.0 $(LibrarySwitch)wxjpeg-3.0 $(LibrarySwitch)jpeg $(LibrarySwitch)png12 
ArLibs                 :=  "Explorer" "Viewer" "Intro" "VideoFFMpeg" "Control" "Exif" "Email" "Picture" "Window" "WindowMain" "Geolocalisation" "Utility" "Dialog" "Resource" "SqlData" "DataStructure" "SqlEngine" "Sqlite" "dl" "Compress" "Utility" "Picture" "VideoThumbnail" "Dialog" "Geolocalisation" "Exif" "SqlData" "Print" "Filtre" "RenderBitmap" "Theme" "DataStructure" "Utility" "Resource" "Parameter" "RegardsCL" "OpenCL" "cl_logger" "task_executor" "intelocl" "cpu_device" "tbb" "OpenGL" "GLEWmx" "CxImage" "wxSVG" "GL" "SDL2" "wx_gtk2u_gl-3.0" "wx_gtk2u-3.0" "X11" "gtk-x11-2.0" "gdk-x11-2.0" "GLU" "pango-1.0" "pangocairo-1.0" "cairo" "gobject-2.0" "exiv2" "expat" "Jbig" "Psd" "jasper" "mng" "wxtiff-3.0" "wxpng-3.0" "RegardsRaw" "raw_r" "z" "gomp" "avcodec" "avformat" "avdevice" "avfilter" "avutil" "swresample" "swscale" "xcb" "xcb-shm" "Xxf86vm" "pthread" "gdk_pixbuf-2.0" "glib-2.0" "SM" "webkitgtk-1.0" "wxjpeg-3.0" "jpeg" "png12" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)../../../developpement/Framework $(LibraryPathSwitch)../../libextern/wxWidgets-3.0.2/lib $(LibraryPathSwitch)../../libextern/glew-1.13.0/lib $(LibraryPathSwitch)../../libextern/LibRaw-0.17.0/lib $(LibraryPathSwitch)../../libextern/SDL2-2.0.3/build $(LibraryPathSwitch)../libPrint/Debug $(LibraryPathSwitch)../CxImage/Debug $(LibraryPathSwitch)../libSqlite/Debug $(LibraryPathSwitch)../libViewer/Debug $(LibraryPathSwitch)../libExplorer/Debug $(LibraryPathSwitch)../libIntro/Debug $(LibraryPathSwitch)../libSqlEngine/Debug $(LibraryPathSwitch)../libResource/Debug $(LibraryPathSwitch)../libCompress/Debug $(LibraryPathSwitch)../libDialog/Debug $(LibraryPathSwitch)../libDataStructure/Debug $(LibraryPathSwitch)../libPicture/Debug $(LibraryPathSwitch)../libUtility/Debug $(LibraryPathSwitch)../libGeolocalisation/Debug $(LibraryPathSwitch)../libSqlData/Debug $(LibraryPathSwitch)../../libextern/exiv2-0.24/lib $(LibraryPathSwitch)../Otherlib/wxSVG/Debug $(LibraryPathSwitch)../libVideoThumbnail/Debug $(LibraryPathSwitch)../libFiltre/Debug $(LibraryPathSwitch)../libWindow/Debug $(LibraryPathSwitch)../libControl/Debug $(LibraryPathSwitch)../libTheme/Debug $(LibraryPathSwitch)../libParameter/Debug $(LibraryPathSwitch)../libOpenGL/Debug $(LibraryPathSwitch)../Otherlib/RegardsRaw/Debug $(LibraryPathSwitch)../libRenderBitmap/Debug $(LibraryPathSwitch)../libOpenCL/Debug $(LibraryPathSwitch)/opt/intel/intel-opencl-1.2-5.0.0.43/opencl/lib64 $(LibraryPathSwitch)../../libextern/LibRaw-0.17.0/Debug $(LibraryPathSwitch)../libVideoFFMpeg/Debug $(LibraryPathSwitch)../libEmail/Debug $(LibraryPathSwitch)../libExif/Debug $(LibraryPathSwitch)../libWindowMain/Debug 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -O0 -fopenmp -std=c++11 -Wall  $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/Regards_Regards.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

PostBuild:
	@echo Executing Post Build commands ...
	cp -R ../Regards/Resources ./Debug/Resources
	@echo Done

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/Regards_Regards.cpp$(ObjectSuffix): ../Regards/Regards.cpp $(IntermediateDirectory)/Regards_Regards.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/figuinha/dev/Regards/Regards/Regards.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Regards_Regards.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Regards_Regards.cpp$(DependSuffix): ../Regards/Regards.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Regards_Regards.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Regards_Regards.cpp$(DependSuffix) -MM "../Regards/Regards.cpp"

$(IntermediateDirectory)/Regards_Regards.cpp$(PreprocessSuffix): ../Regards/Regards.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Regards_Regards.cpp$(PreprocessSuffix) "../Regards/Regards.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


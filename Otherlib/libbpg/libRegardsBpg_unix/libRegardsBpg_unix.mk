##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Release
ProjectName            :=libRegardsBpg_unix
ConfigurationName      :=Release
WorkspacePath          :=/home/figuinha/developpement/Regards
ProjectPath            :=/home/figuinha/developpement/Regards/Otherlib/libbpg/libRegardsBpg_unix
IntermediateDirectory  :=./Release
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=figuinha
Date                   :=14/02/19
CodeLitePath           :=/home/figuinha/.codelite
LinkerName             :=/usr/bin/ccache /usr/bin/g++
SharedObjectLinkerName :=/usr/bin/ccache /usr/bin/g++ -shared -fPIC
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
OutputFile             :=$(IntermediateDirectory)/libRegardsBpg.so
Preprocessors          :=$(PreprocessorSwitch)USE_VAR_BIT_DEPTH $(PreprocessorSwitch)_ISOC99_SOURCE $(PreprocessorSwitch)HAVE_AV_CONFIG_H $(PreprocessorSwitch)_FILE_OFFSET_BITS=64 $(PreprocessorSwitch)_LARGEFILE_SOURCE $(PreprocessorSwitch)CONFIG_BPG_VERSION=0.9.7 $(PreprocessorSwitch)USE_X265 $(PreprocessorSwitch)NDEBUG 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="libRegardsBpg_unix.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            := -Wl,-rpath,'$$ORIGIN' -Wl,-z,origin  -Os
IncludePath            := $(IncludeSwitch)/opt/AMDAPPSDK-3.0/include $(IncludeSwitch)/usr/include/OpenEXR $(IncludeSwitch)/usr/include/pango-1.0 $(IncludeSwitch)/usr/include/glib-2.0 $(IncludeSwitch)/usr/lib/x86_64-linux-gnu/glib-2.0/include $(IncludeSwitch)/usr/include/cairo $(IncludeSwitch)/usr/include/SDL2 $(IncludeSwitch)/usr/include/libxml2 $(IncludeSwitch)/usr/include/libexif  $(IncludeSwitch). $(IncludeSwitch)../ $(IncludeSwitch)../libbpg $(IncludeSwitch)../../../libextern/x265_2.5/source $(IncludeSwitch)../../../libextern/x265_2.5//build/linux/8bit/ $(IncludeSwitch)../../../libextern/dlib-19.7/dlib/external/libpng $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)x265 $(LibrarySwitch)bpg $(LibrarySwitch)avcodec $(LibrarySwitch)avutil $(LibrarySwitch)gomp 
ArLibs                 :=  "x265" "bpg" "avcodec" "avutil" "gomp" 
LibPath                :=$(LibraryPathSwitch)/opt/AMDAPPSDK-3.0/lib  $(LibraryPathSwitch). $(LibraryPathSwitch)../../../libextern/x265_2.5/build/linux/8bit/ $(LibraryPathSwitch)../libbpg/Release $(LibraryPathSwitch)../libavutil/Release $(LibraryPathSwitch)../libavcodec/Release 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/ccache /usr/bin/g++
CC       := /usr/bin/ccache /usr/bin/gcc
CXXFLAGS := -fopenmp -std=gnu++11 -Wall -fPIC -pthread -O2 -msse4.1 $(Preprocessors)
CFLAGS   := -std=c99 -Wall -fPIC -pthread -fopenmp  -O2 -msse4.1 $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/yasm


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/up_libRegardsBpg_bpgdec.c$(ObjectSuffix) $(IntermediateDirectory)/up_libRegardsBpg_bpgenc.c$(ObjectSuffix) $(IntermediateDirectory)/up_libRegardsBpg_x265_glue.c$(ObjectSuffix) $(IntermediateDirectory)/up_libRegardsBpg_DllBpg.cpp$(ObjectSuffix) 



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
	$(SharedObjectLinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)
	@$(MakeDirCommand) "/home/figuinha/developpement/Regards/.build-release"
	@echo rebuilt > "/home/figuinha/developpement/Regards/.build-release/libRegardsBpg_unix"

MakeIntermediateDirs:
	@test -d ./Release || $(MakeDirCommand) ./Release


$(IntermediateDirectory)/.d:
	@test -d ./Release || $(MakeDirCommand) ./Release

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/up_libRegardsBpg_bpgdec.c$(ObjectSuffix): ../libRegardsBpg/bpgdec.c $(IntermediateDirectory)/up_libRegardsBpg_bpgdec.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/figuinha/developpement/Regards/Otherlib/libbpg/libRegardsBpg/bpgdec.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_libRegardsBpg_bpgdec.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_libRegardsBpg_bpgdec.c$(DependSuffix): ../libRegardsBpg/bpgdec.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_libRegardsBpg_bpgdec.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_libRegardsBpg_bpgdec.c$(DependSuffix) -MM ../libRegardsBpg/bpgdec.c

$(IntermediateDirectory)/up_libRegardsBpg_bpgdec.c$(PreprocessSuffix): ../libRegardsBpg/bpgdec.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_libRegardsBpg_bpgdec.c$(PreprocessSuffix) ../libRegardsBpg/bpgdec.c

$(IntermediateDirectory)/up_libRegardsBpg_bpgenc.c$(ObjectSuffix): ../libRegardsBpg/bpgenc.c $(IntermediateDirectory)/up_libRegardsBpg_bpgenc.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/figuinha/developpement/Regards/Otherlib/libbpg/libRegardsBpg/bpgenc.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_libRegardsBpg_bpgenc.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_libRegardsBpg_bpgenc.c$(DependSuffix): ../libRegardsBpg/bpgenc.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_libRegardsBpg_bpgenc.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_libRegardsBpg_bpgenc.c$(DependSuffix) -MM ../libRegardsBpg/bpgenc.c

$(IntermediateDirectory)/up_libRegardsBpg_bpgenc.c$(PreprocessSuffix): ../libRegardsBpg/bpgenc.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_libRegardsBpg_bpgenc.c$(PreprocessSuffix) ../libRegardsBpg/bpgenc.c

$(IntermediateDirectory)/up_libRegardsBpg_x265_glue.c$(ObjectSuffix): ../libRegardsBpg/x265_glue.c $(IntermediateDirectory)/up_libRegardsBpg_x265_glue.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/figuinha/developpement/Regards/Otherlib/libbpg/libRegardsBpg/x265_glue.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_libRegardsBpg_x265_glue.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_libRegardsBpg_x265_glue.c$(DependSuffix): ../libRegardsBpg/x265_glue.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_libRegardsBpg_x265_glue.c$(ObjectSuffix) -MF$(IntermediateDirectory)/up_libRegardsBpg_x265_glue.c$(DependSuffix) -MM ../libRegardsBpg/x265_glue.c

$(IntermediateDirectory)/up_libRegardsBpg_x265_glue.c$(PreprocessSuffix): ../libRegardsBpg/x265_glue.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_libRegardsBpg_x265_glue.c$(PreprocessSuffix) ../libRegardsBpg/x265_glue.c

$(IntermediateDirectory)/up_libRegardsBpg_DllBpg.cpp$(ObjectSuffix): ../libRegardsBpg/DllBpg.cpp $(IntermediateDirectory)/up_libRegardsBpg_DllBpg.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/figuinha/developpement/Regards/Otherlib/libbpg/libRegardsBpg/DllBpg.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/up_libRegardsBpg_DllBpg.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/up_libRegardsBpg_DllBpg.cpp$(DependSuffix): ../libRegardsBpg/DllBpg.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/up_libRegardsBpg_DllBpg.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/up_libRegardsBpg_DllBpg.cpp$(DependSuffix) -MM ../libRegardsBpg/DllBpg.cpp

$(IntermediateDirectory)/up_libRegardsBpg_DllBpg.cpp$(PreprocessSuffix): ../libRegardsBpg/DllBpg.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/up_libRegardsBpg_DllBpg.cpp$(PreprocessSuffix) ../libRegardsBpg/DllBpg.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Release/


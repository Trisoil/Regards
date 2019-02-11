##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Release
ProjectName            :=libCompress
ConfigurationName      :=Release
WorkspacePath          :=C:/Regards
ProjectPath            :=C:/Regards/libCompress
IntermediateDirectory  :=./Release
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=jfigu_000
Date                   :=11/02/2019
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/msys64/usr/bin/ccache.exe C:/msys64/mingw64/bin/g++.exe
SharedObjectLinkerName :=C:/msys64/mingw64/bin/g++.exe -shared -fPIC
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
OutputFile             :=$(IntermediateDirectory)/$(ProjectName).a
Preprocessors          :=$(PreprocessorSwitch)NDEBUG 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="libCompress.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/msys64/mingw64/bin/windres.exe
LinkOptions            :=  -s 
IncludePath            := $(IncludeSwitch)"C:\Program Files (x86)\AMD APP SDK\3.0_mingw\include" $(IncludeSwitch)/mingw64/include/libxml2 $(IncludeSwitch)/mingw64/include/OpenEXR  $(IncludeSwitch). $(IncludeSwitch)../libCompress 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                :=$(LibraryPathSwitch)"C:\Program Files (x86)\AMD APP SDK\3.0_mingw\lib\x86_64"  $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/msys64/mingw64/bin/ar.exe rcu
CXX      := C:/msys64/usr/bin/ccache.exe C:/msys64/mingw64/bin/g++.exe
CC       := C:/msys64/usr/bin/ccache.exe  C:/msys64/mingw64/bin/gcc.exe
CXXFLAGS := $(shell ../libextern/wxWidgets-master/wx-config --cppflags) -Wall -pthread -fopenmp -std=gnu++11 -fpermissive -O2 -msse4.1 $(Preprocessors)
CFLAGS   := $(shell ../libextern/wxWidgets-master/wx-config --cflags) -Wall  -O2 -msse4.1 $(Preprocessors)
ASFLAGS  := 
AS       := C:/msys64/mingw64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
PATH:=C:\msys64\usr\bin;$PATH
WXWIN:=C:\Regards\libextern\wxwidgets-3.1.2
WXCFG:=lib/mswud
Objects0=$(IntermediateDirectory)/lz4.c$(ObjectSuffix) $(IntermediateDirectory)/jpgd.cpp$(ObjectSuffix) $(IntermediateDirectory)/jpge.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(IntermediateDirectory) $(OutputFile)

$(OutputFile): $(Objects)
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(AR) $(ArchiveOutputSwitch)$(OutputFile) @$(ObjectsFileList) $(ArLibs)
	@$(MakeDirCommand) "C:\Regards/.build-release"
	@echo rebuilt > "C:\Regards/.build-release/libCompress"

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Release"


./Release:
	@$(MakeDirCommand) "./Release"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/lz4.c$(ObjectSuffix): lz4.c $(IntermediateDirectory)/lz4.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/Regards/libCompress/lz4.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/lz4.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/lz4.c$(DependSuffix): lz4.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/lz4.c$(ObjectSuffix) -MF$(IntermediateDirectory)/lz4.c$(DependSuffix) -MM lz4.c

$(IntermediateDirectory)/lz4.c$(PreprocessSuffix): lz4.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/lz4.c$(PreprocessSuffix) lz4.c

$(IntermediateDirectory)/jpgd.cpp$(ObjectSuffix): jpgd.cpp $(IntermediateDirectory)/jpgd.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Regards/libCompress/jpgd.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/jpgd.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/jpgd.cpp$(DependSuffix): jpgd.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/jpgd.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/jpgd.cpp$(DependSuffix) -MM jpgd.cpp

$(IntermediateDirectory)/jpgd.cpp$(PreprocessSuffix): jpgd.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/jpgd.cpp$(PreprocessSuffix) jpgd.cpp

$(IntermediateDirectory)/jpge.cpp$(ObjectSuffix): jpge.cpp $(IntermediateDirectory)/jpge.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Regards/libCompress/jpge.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/jpge.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/jpge.cpp$(DependSuffix): jpge.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/jpge.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/jpge.cpp$(DependSuffix) -MM jpge.cpp

$(IntermediateDirectory)/jpge.cpp$(PreprocessSuffix): jpge.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/jpge.cpp$(PreprocessSuffix) jpge.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Release/



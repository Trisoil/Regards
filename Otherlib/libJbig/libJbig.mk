##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=libJbig
ConfigurationName      :=Debug
WorkspacePath          :=C:/developpement/git/Regards
ProjectPath            :=C:/developpement/git/Regards/Otherlib/libJbig
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=jfigu
Date                   :=06/03/2019
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/msys64/usr/bin/ccache.exe C:/msys64/mingw64/bin/g++.exe
SharedObjectLinkerName :=C:/msys64/usr/bin/ccache.exe C:/msys64/mingw64/bin/g++.exe -shared -fPIC
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
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="libJbig.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/msys64/mingw64/bin/windres.exe
LinkOptions            :=  
IncludePath            := $(IncludeSwitch)"C:\Program Files (x86)\AMD APP SDK\3.0_mingw\include" $(IncludeSwitch)/mingw64/include/libxml2 $(IncludeSwitch)/mingw64/include/OpenEXR  $(IncludeSwitch). $(IncludeSwitch). 
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
CC       := C:/msys64/usr/bin/ccache.exe C:/msys64/mingw64/bin/gcc.exe
CXXFLAGS := $(shell ../../libextern/wxWidgets-master/wx-config --cppflags) -Wall -pthread  -g $(Preprocessors)
CFLAGS   := $(shell ../../libextern/wxWidgets-master/wx-config --cflags) -pthread -g $(Preprocessors)
ASFLAGS  := 
AS       := C:/msys64/usr/bin/ccache.exe C:/msys64/mingw64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
PATH:=C:\msys64\usr\bin;$PATH
WXWIN:=C:\Regards\libextern\wxwidgets-3.1.2
WXCFG:=lib/mswud
Objects0=$(IntermediateDirectory)/jbig.c$(ObjectSuffix) $(IntermediateDirectory)/jbig_tab.c$(ObjectSuffix) 



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
	@$(MakeDirCommand) "C:\developpement\git\Regards/.build-debug"
	@echo rebuilt > "C:\developpement\git\Regards/.build-debug/libJbig"

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


./Debug:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/jbig.c$(ObjectSuffix): jbig.c $(IntermediateDirectory)/jbig.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/developpement/git/Regards/Otherlib/libJbig/jbig.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/jbig.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/jbig.c$(DependSuffix): jbig.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/jbig.c$(ObjectSuffix) -MF$(IntermediateDirectory)/jbig.c$(DependSuffix) -MM jbig.c

$(IntermediateDirectory)/jbig.c$(PreprocessSuffix): jbig.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/jbig.c$(PreprocessSuffix) jbig.c

$(IntermediateDirectory)/jbig_tab.c$(ObjectSuffix): jbig_tab.c $(IntermediateDirectory)/jbig_tab.c$(DependSuffix)
	$(CC) $(SourceSwitch) "C:/developpement/git/Regards/Otherlib/libJbig/jbig_tab.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/jbig_tab.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/jbig_tab.c$(DependSuffix): jbig_tab.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/jbig_tab.c$(ObjectSuffix) -MF$(IntermediateDirectory)/jbig_tab.c$(DependSuffix) -MM jbig_tab.c

$(IntermediateDirectory)/jbig_tab.c$(PreprocessSuffix): jbig_tab.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/jbig_tab.c$(PreprocessSuffix) jbig_tab.c


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/



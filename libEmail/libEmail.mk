##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=libEmail
ConfigurationName      :=Debug
WorkspacePath          :=/home/figuinha/Developpement/Regards
ProjectPath            :=/home/figuinha/Developpement/Regards/libEmail
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=figuinha
Date                   :=20/01/19
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
OutputFile             :=$(IntermediateDirectory)/$(ProjectName).a
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="libEmail.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            := $(IncludeSwitch)/opt/AMDAPPSDK-3.0/include $(IncludeSwitch)/usr/include/OpenEXR $(IncludeSwitch)/usr/include/pango-1.0 $(IncludeSwitch)/usr/include/glib-2.0 $(IncludeSwitch)/usr/lib/x86_64-linux-gnu/glib-2.0/include $(IncludeSwitch)/usr/include/cairo $(IncludeSwitch)/usr/include/SDL2 $(IncludeSwitch)/usr/include/libxml2  $(IncludeSwitch). $(IncludeSwitch)../include $(IncludeSwitch)../libUtility 
IncludePCH             :=  -include ../include/Debug/header.h 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                :=$(LibraryPathSwitch)/opt/AMDAPPSDK-3.0/lib  $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/ccache /usr/bin/g++
CC       := /usr/bin/ccache /usr/bin/gcc
CXXFLAGS := $(shell ../libextern/wxWidgets-master/wx-config --cppflags) -Wall -pthread -fopenmp -std=gnu++11 -ggdb -O0 $(Preprocessors)
CFLAGS   :=  -Wall  -ggdb -O0 $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/LocalMapi.cpp$(ObjectSuffix) $(IntermediateDirectory)/email.cpp$(ObjectSuffix) $(IntermediateDirectory)/mime.cpp$(ObjectSuffix) 



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
	@$(MakeDirCommand) "/home/figuinha/Developpement/Regards/.build-debug"
	@echo rebuilt > "/home/figuinha/Developpement/Regards/.build-debug/libEmail"

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


./Debug:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:

# PreCompiled Header
../include/Debug/header.h.gch: ../include/Debug/header.h
	$(CXX) $(SourceSwitch) ../include/Debug/header.h $(PCHCompileFlags) $(CXXFLAGS) $(IncludePath)



##
## Objects
##
$(IntermediateDirectory)/LocalMapi.cpp$(ObjectSuffix): LocalMapi.cpp $(IntermediateDirectory)/LocalMapi.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/figuinha/Developpement/Regards/libEmail/LocalMapi.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/LocalMapi.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/LocalMapi.cpp$(DependSuffix): LocalMapi.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/LocalMapi.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/LocalMapi.cpp$(DependSuffix) -MM LocalMapi.cpp

$(IntermediateDirectory)/LocalMapi.cpp$(PreprocessSuffix): LocalMapi.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/LocalMapi.cpp$(PreprocessSuffix) LocalMapi.cpp

$(IntermediateDirectory)/email.cpp$(ObjectSuffix): email.cpp $(IntermediateDirectory)/email.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/figuinha/Developpement/Regards/libEmail/email.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/email.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/email.cpp$(DependSuffix): email.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/email.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/email.cpp$(DependSuffix) -MM email.cpp

$(IntermediateDirectory)/email.cpp$(PreprocessSuffix): email.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/email.cpp$(PreprocessSuffix) email.cpp

$(IntermediateDirectory)/mime.cpp$(ObjectSuffix): mime.cpp $(IntermediateDirectory)/mime.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/figuinha/Developpement/Regards/libEmail/mime.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/mime.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/mime.cpp$(DependSuffix): mime.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/mime.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/mime.cpp$(DependSuffix) -MM mime.cpp

$(IntermediateDirectory)/mime.cpp$(PreprocessSuffix): mime.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/mime.cpp$(PreprocessSuffix) mime.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/
	$(RM) ../include/Debug/header.h.gch



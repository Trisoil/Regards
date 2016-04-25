##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Release
ProjectName            :=libWindowMain
ConfigurationName      :=Release
WorkspacePath          := "/home/figuinha/dev/Regards"
ProjectPath            := "/home/figuinha/dev/Regards/libWindowMain"
IntermediateDirectory  :=./Release
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=figuinha
Date                   :=24/04/16
CodeLitePath           :="/home/figuinha/.codelite"
LinkerName             :=/usr/bin/g++-4.8
SharedObjectLinkerName :=/usr/bin/g++-4.8 -shared -fPIC
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
Preprocessors          :=$(PreprocessorSwitch)NDEBUG $(PreprocessorSwitch)__WXGTK__ 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="libWindowMain.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  -s 
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)../libTheme $(IncludeSwitch)../libextern/libRapidXML $(IncludeSwitch)../libextern/wxWidgets-3.0.2/include $(IncludeSwitch)../libextern/wxWidgets-3.0.2/lib/wx/include/gtk2-unicode-static-3.0 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++-4.8
CC       := /usr/bin/gcc-4.8
CXXFLAGS :=  -fopenmp -std=c++11 -Wall  $(Preprocessors)
CFLAGS   :=  -O2 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/WindowUtility.cpp$(ObjectSuffix) 



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
	@$(MakeDirCommand) "/home/figuinha/dev/Regards/.build-release"
	@echo rebuilt > "/home/figuinha/dev/Regards/.build-release/libWindowMain"

MakeIntermediateDirs:
	@test -d ./Release || $(MakeDirCommand) ./Release


./Release:
	@test -d ./Release || $(MakeDirCommand) ./Release

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/WindowUtility.cpp$(ObjectSuffix): WindowUtility.cpp $(IntermediateDirectory)/WindowUtility.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/figuinha/dev/Regards/libWindowMain/WindowUtility.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/WindowUtility.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/WindowUtility.cpp$(DependSuffix): WindowUtility.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/WindowUtility.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/WindowUtility.cpp$(DependSuffix) -MM "WindowUtility.cpp"

$(IntermediateDirectory)/WindowUtility.cpp$(PreprocessSuffix): WindowUtility.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/WindowUtility.cpp$(PreprocessSuffix) "WindowUtility.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Release/



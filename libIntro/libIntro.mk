##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=libIntro
ConfigurationName      :=Debug
WorkspacePath          := "/home/figuinha/dev/Regards"
ProjectPath            := "/home/figuinha/dev/Regards/libIntro"
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
OutputFile             :=$(IntermediateDirectory)/$(ProjectName).a
Preprocessors          :=$(PreprocessorSwitch)__WXGTK__ 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="libIntro.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)../libSqlite $(IncludeSwitch)../libTheme $(IncludeSwitch)../../libextern/libRapidXML $(IncludeSwitch)../../libextern/ffmpeg-2.6.2 $(IncludeSwitch)../../libextern/SDL2-2.0.3/include $(IncludeSwitch)../libGeolocalisation $(IncludeSwitch)../libParameter $(IncludeSwitch)../../libextern/exiv2-0.24/src $(IncludeSwitch)../../libextern/exiv2-0.24/xmpsdk/include $(IncludeSwitch)../libUtility $(IncludeSwitch)../libFiltreInterface $(IncludeSwitch)../include $(IncludeSwitch)../libDataStructure $(IncludeSwitch)../libResource $(IncludeSwitch)../libSqlData $(IncludeSwitch)../libOpenGL $(IncludeSwitch)../libRenderBitmap $(IncludeSwitch)../libSqlEngine $(IncludeSwitch)../libSqlite $(IncludeSwitch)../Otherlib/lew-1.13.0/include $(IncludeSwitch)../libFiltre $(IncludeSwitch)../include $(IncludeSwitch)../libDataStructure $(IncludeSwitch)../Otherlib/wxSVG/include $(IncludeSwitch)../libWindow $(IncludeSwitch)../libPrint $(IncludeSwitch)../libPicture $(IncludeSwitch)../libTheme $(IncludeSwitch)../libGeolocalisation $(IncludeSwitch)../libControl $(IncludeSwitch)../libIntro $(IncludeSwitch)../libWindowMain $(IncludeSwitch)../../libextern/wxWidgets-3.0.2/include $(IncludeSwitch)../../libextern/wxWidgets-3.0.2/lib/wx/include/gtk2-unicode-static-3.0 
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
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -O0 -fopenmp -std=c++11 -Wall  $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall  $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/IntroTheme.cpp$(ObjectSuffix) $(IntermediateDirectory)/MyCentralWindowIntro.cpp$(ObjectSuffix) $(IntermediateDirectory)/MyFrameIntro.cpp$(ObjectSuffix) $(IntermediateDirectory)/TitleIntro.cpp$(ObjectSuffix) $(IntermediateDirectory)/InfoAbout.cpp$(ObjectSuffix) 



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
	@$(MakeDirCommand) "/home/figuinha/dev/Regards/.build-debug"
	@echo rebuilt > "/home/figuinha/dev/Regards/.build-debug/libIntro"

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


./Debug:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/IntroTheme.cpp$(ObjectSuffix): IntroTheme.cpp $(IntermediateDirectory)/IntroTheme.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/figuinha/dev/Regards/libIntro/IntroTheme.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/IntroTheme.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/IntroTheme.cpp$(DependSuffix): IntroTheme.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/IntroTheme.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/IntroTheme.cpp$(DependSuffix) -MM "IntroTheme.cpp"

$(IntermediateDirectory)/IntroTheme.cpp$(PreprocessSuffix): IntroTheme.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/IntroTheme.cpp$(PreprocessSuffix) "IntroTheme.cpp"

$(IntermediateDirectory)/MyCentralWindowIntro.cpp$(ObjectSuffix): MyCentralWindowIntro.cpp $(IntermediateDirectory)/MyCentralWindowIntro.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/figuinha/dev/Regards/libIntro/MyCentralWindowIntro.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/MyCentralWindowIntro.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/MyCentralWindowIntro.cpp$(DependSuffix): MyCentralWindowIntro.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/MyCentralWindowIntro.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/MyCentralWindowIntro.cpp$(DependSuffix) -MM "MyCentralWindowIntro.cpp"

$(IntermediateDirectory)/MyCentralWindowIntro.cpp$(PreprocessSuffix): MyCentralWindowIntro.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/MyCentralWindowIntro.cpp$(PreprocessSuffix) "MyCentralWindowIntro.cpp"

$(IntermediateDirectory)/MyFrameIntro.cpp$(ObjectSuffix): MyFrameIntro.cpp $(IntermediateDirectory)/MyFrameIntro.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/figuinha/dev/Regards/libIntro/MyFrameIntro.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/MyFrameIntro.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/MyFrameIntro.cpp$(DependSuffix): MyFrameIntro.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/MyFrameIntro.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/MyFrameIntro.cpp$(DependSuffix) -MM "MyFrameIntro.cpp"

$(IntermediateDirectory)/MyFrameIntro.cpp$(PreprocessSuffix): MyFrameIntro.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/MyFrameIntro.cpp$(PreprocessSuffix) "MyFrameIntro.cpp"

$(IntermediateDirectory)/TitleIntro.cpp$(ObjectSuffix): TitleIntro.cpp $(IntermediateDirectory)/TitleIntro.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/figuinha/dev/Regards/libIntro/TitleIntro.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/TitleIntro.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/TitleIntro.cpp$(DependSuffix): TitleIntro.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/TitleIntro.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/TitleIntro.cpp$(DependSuffix) -MM "TitleIntro.cpp"

$(IntermediateDirectory)/TitleIntro.cpp$(PreprocessSuffix): TitleIntro.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/TitleIntro.cpp$(PreprocessSuffix) "TitleIntro.cpp"

$(IntermediateDirectory)/InfoAbout.cpp$(ObjectSuffix): InfoAbout.cpp $(IntermediateDirectory)/InfoAbout.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/figuinha/dev/Regards/libIntro/InfoAbout.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/InfoAbout.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/InfoAbout.cpp$(DependSuffix): InfoAbout.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/InfoAbout.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/InfoAbout.cpp$(DependSuffix) -MM "InfoAbout.cpp"

$(IntermediateDirectory)/InfoAbout.cpp$(PreprocessSuffix): InfoAbout.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/InfoAbout.cpp$(PreprocessSuffix) "InfoAbout.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


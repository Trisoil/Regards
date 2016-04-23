##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=CxImage
ConfigurationName      :=Debug
WorkspacePath          := "/home/figuinha/dev/Regards"
ProjectPath            := "/home/figuinha/dev/Regards/CxImage"
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
OutputFile             :=$(IntermediateDirectory)/lib$(ProjectName).a
Preprocessors          :=$(PreprocessorSwitch)__WXGTK__ $(PreprocessorSwitch)_LINUX 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="CxImage.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)../../libextern/libmng-2.0.3 $(IncludeSwitch)../../libextern/jasper-1.900.1/src/libjasper/include $(IncludeSwitch)../Otherlib/libJbig $(IncludeSwitch)../Otherlib/libPsd $(IncludeSwitch)../../libextern/wxWidgets-3.0.2/src/jpeg $(IncludeSwitch)../../libextern/wxWidgets-3.0.2/src/tiff/libtiff $(IncludeSwitch)../../libextern/wxWidgets-3.0.2/src/png $(IncludeSwitch)../../libextern/wxWidgets-3.0.2/include $(IncludeSwitch)../../libextern/wxWidgets-3.0.2/lib/wx/include/gtk2-unicode-static-3.0 
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
CXXFLAGS :=  -g -O0 -fopenmp -std=c++11 -Wall -msse4 $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/tif_xfile.cpp$(ObjectSuffix) $(IntermediateDirectory)/ximabmp.cpp$(ObjectSuffix) $(IntermediateDirectory)/ximadsp.cpp$(ObjectSuffix) $(IntermediateDirectory)/ximaenc.cpp$(ObjectSuffix) $(IntermediateDirectory)/ximaexif.cpp$(ObjectSuffix) $(IntermediateDirectory)/ximage.cpp$(ObjectSuffix) $(IntermediateDirectory)/ximagif.cpp$(ObjectSuffix) $(IntermediateDirectory)/ximahist.cpp$(ObjectSuffix) $(IntermediateDirectory)/ximaico.cpp$(ObjectSuffix) $(IntermediateDirectory)/ximainfo.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/ximaint.cpp$(ObjectSuffix) $(IntermediateDirectory)/ximajas.cpp$(ObjectSuffix) $(IntermediateDirectory)/ximajbg.cpp$(ObjectSuffix) $(IntermediateDirectory)/ximajpg.cpp$(ObjectSuffix) $(IntermediateDirectory)/ximalpha.cpp$(ObjectSuffix) $(IntermediateDirectory)/ximalyr.cpp$(ObjectSuffix) $(IntermediateDirectory)/ximamng.cpp$(ObjectSuffix) $(IntermediateDirectory)/ximapal.cpp$(ObjectSuffix) $(IntermediateDirectory)/ximapcx.cpp$(ObjectSuffix) $(IntermediateDirectory)/ximapng.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/ximapsd.cpp$(ObjectSuffix) $(IntermediateDirectory)/ximaraw.cpp$(ObjectSuffix) $(IntermediateDirectory)/ximasel.cpp$(ObjectSuffix) $(IntermediateDirectory)/ximaska.cpp$(ObjectSuffix) $(IntermediateDirectory)/ximatga.cpp$(ObjectSuffix) $(IntermediateDirectory)/ximath.cpp$(ObjectSuffix) $(IntermediateDirectory)/ximatif.cpp$(ObjectSuffix) $(IntermediateDirectory)/ximatran.cpp$(ObjectSuffix) $(IntermediateDirectory)/ximawbmp.cpp$(ObjectSuffix) $(IntermediateDirectory)/ximawmf.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/ximawnd.cpp$(ObjectSuffix) $(IntermediateDirectory)/xmemfile.cpp$(ObjectSuffix) 



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
	@echo rebuilt > "/home/figuinha/dev/Regards/.build-debug/CxImage"

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


./Debug:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/tif_xfile.cpp$(ObjectSuffix): tif_xfile.cpp $(IntermediateDirectory)/tif_xfile.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/figuinha/dev/Regards/CxImage/tif_xfile.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/tif_xfile.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/tif_xfile.cpp$(DependSuffix): tif_xfile.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/tif_xfile.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/tif_xfile.cpp$(DependSuffix) -MM "tif_xfile.cpp"

$(IntermediateDirectory)/tif_xfile.cpp$(PreprocessSuffix): tif_xfile.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/tif_xfile.cpp$(PreprocessSuffix) "tif_xfile.cpp"

$(IntermediateDirectory)/ximabmp.cpp$(ObjectSuffix): ximabmp.cpp $(IntermediateDirectory)/ximabmp.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/figuinha/dev/Regards/CxImage/ximabmp.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ximabmp.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ximabmp.cpp$(DependSuffix): ximabmp.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ximabmp.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ximabmp.cpp$(DependSuffix) -MM "ximabmp.cpp"

$(IntermediateDirectory)/ximabmp.cpp$(PreprocessSuffix): ximabmp.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ximabmp.cpp$(PreprocessSuffix) "ximabmp.cpp"

$(IntermediateDirectory)/ximadsp.cpp$(ObjectSuffix): ximadsp.cpp $(IntermediateDirectory)/ximadsp.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/figuinha/dev/Regards/CxImage/ximadsp.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ximadsp.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ximadsp.cpp$(DependSuffix): ximadsp.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ximadsp.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ximadsp.cpp$(DependSuffix) -MM "ximadsp.cpp"

$(IntermediateDirectory)/ximadsp.cpp$(PreprocessSuffix): ximadsp.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ximadsp.cpp$(PreprocessSuffix) "ximadsp.cpp"

$(IntermediateDirectory)/ximaenc.cpp$(ObjectSuffix): ximaenc.cpp $(IntermediateDirectory)/ximaenc.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/figuinha/dev/Regards/CxImage/ximaenc.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ximaenc.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ximaenc.cpp$(DependSuffix): ximaenc.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ximaenc.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ximaenc.cpp$(DependSuffix) -MM "ximaenc.cpp"

$(IntermediateDirectory)/ximaenc.cpp$(PreprocessSuffix): ximaenc.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ximaenc.cpp$(PreprocessSuffix) "ximaenc.cpp"

$(IntermediateDirectory)/ximaexif.cpp$(ObjectSuffix): ximaexif.cpp $(IntermediateDirectory)/ximaexif.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/figuinha/dev/Regards/CxImage/ximaexif.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ximaexif.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ximaexif.cpp$(DependSuffix): ximaexif.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ximaexif.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ximaexif.cpp$(DependSuffix) -MM "ximaexif.cpp"

$(IntermediateDirectory)/ximaexif.cpp$(PreprocessSuffix): ximaexif.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ximaexif.cpp$(PreprocessSuffix) "ximaexif.cpp"

$(IntermediateDirectory)/ximage.cpp$(ObjectSuffix): ximage.cpp $(IntermediateDirectory)/ximage.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/figuinha/dev/Regards/CxImage/ximage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ximage.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ximage.cpp$(DependSuffix): ximage.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ximage.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ximage.cpp$(DependSuffix) -MM "ximage.cpp"

$(IntermediateDirectory)/ximage.cpp$(PreprocessSuffix): ximage.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ximage.cpp$(PreprocessSuffix) "ximage.cpp"

$(IntermediateDirectory)/ximagif.cpp$(ObjectSuffix): ximagif.cpp $(IntermediateDirectory)/ximagif.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/figuinha/dev/Regards/CxImage/ximagif.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ximagif.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ximagif.cpp$(DependSuffix): ximagif.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ximagif.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ximagif.cpp$(DependSuffix) -MM "ximagif.cpp"

$(IntermediateDirectory)/ximagif.cpp$(PreprocessSuffix): ximagif.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ximagif.cpp$(PreprocessSuffix) "ximagif.cpp"

$(IntermediateDirectory)/ximahist.cpp$(ObjectSuffix): ximahist.cpp $(IntermediateDirectory)/ximahist.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/figuinha/dev/Regards/CxImage/ximahist.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ximahist.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ximahist.cpp$(DependSuffix): ximahist.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ximahist.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ximahist.cpp$(DependSuffix) -MM "ximahist.cpp"

$(IntermediateDirectory)/ximahist.cpp$(PreprocessSuffix): ximahist.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ximahist.cpp$(PreprocessSuffix) "ximahist.cpp"

$(IntermediateDirectory)/ximaico.cpp$(ObjectSuffix): ximaico.cpp $(IntermediateDirectory)/ximaico.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/figuinha/dev/Regards/CxImage/ximaico.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ximaico.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ximaico.cpp$(DependSuffix): ximaico.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ximaico.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ximaico.cpp$(DependSuffix) -MM "ximaico.cpp"

$(IntermediateDirectory)/ximaico.cpp$(PreprocessSuffix): ximaico.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ximaico.cpp$(PreprocessSuffix) "ximaico.cpp"

$(IntermediateDirectory)/ximainfo.cpp$(ObjectSuffix): ximainfo.cpp $(IntermediateDirectory)/ximainfo.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/figuinha/dev/Regards/CxImage/ximainfo.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ximainfo.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ximainfo.cpp$(DependSuffix): ximainfo.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ximainfo.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ximainfo.cpp$(DependSuffix) -MM "ximainfo.cpp"

$(IntermediateDirectory)/ximainfo.cpp$(PreprocessSuffix): ximainfo.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ximainfo.cpp$(PreprocessSuffix) "ximainfo.cpp"

$(IntermediateDirectory)/ximaint.cpp$(ObjectSuffix): ximaint.cpp $(IntermediateDirectory)/ximaint.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/figuinha/dev/Regards/CxImage/ximaint.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ximaint.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ximaint.cpp$(DependSuffix): ximaint.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ximaint.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ximaint.cpp$(DependSuffix) -MM "ximaint.cpp"

$(IntermediateDirectory)/ximaint.cpp$(PreprocessSuffix): ximaint.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ximaint.cpp$(PreprocessSuffix) "ximaint.cpp"

$(IntermediateDirectory)/ximajas.cpp$(ObjectSuffix): ximajas.cpp $(IntermediateDirectory)/ximajas.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/figuinha/dev/Regards/CxImage/ximajas.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ximajas.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ximajas.cpp$(DependSuffix): ximajas.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ximajas.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ximajas.cpp$(DependSuffix) -MM "ximajas.cpp"

$(IntermediateDirectory)/ximajas.cpp$(PreprocessSuffix): ximajas.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ximajas.cpp$(PreprocessSuffix) "ximajas.cpp"

$(IntermediateDirectory)/ximajbg.cpp$(ObjectSuffix): ximajbg.cpp $(IntermediateDirectory)/ximajbg.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/figuinha/dev/Regards/CxImage/ximajbg.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ximajbg.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ximajbg.cpp$(DependSuffix): ximajbg.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ximajbg.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ximajbg.cpp$(DependSuffix) -MM "ximajbg.cpp"

$(IntermediateDirectory)/ximajbg.cpp$(PreprocessSuffix): ximajbg.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ximajbg.cpp$(PreprocessSuffix) "ximajbg.cpp"

$(IntermediateDirectory)/ximajpg.cpp$(ObjectSuffix): ximajpg.cpp $(IntermediateDirectory)/ximajpg.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/figuinha/dev/Regards/CxImage/ximajpg.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ximajpg.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ximajpg.cpp$(DependSuffix): ximajpg.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ximajpg.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ximajpg.cpp$(DependSuffix) -MM "ximajpg.cpp"

$(IntermediateDirectory)/ximajpg.cpp$(PreprocessSuffix): ximajpg.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ximajpg.cpp$(PreprocessSuffix) "ximajpg.cpp"

$(IntermediateDirectory)/ximalpha.cpp$(ObjectSuffix): ximalpha.cpp $(IntermediateDirectory)/ximalpha.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/figuinha/dev/Regards/CxImage/ximalpha.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ximalpha.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ximalpha.cpp$(DependSuffix): ximalpha.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ximalpha.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ximalpha.cpp$(DependSuffix) -MM "ximalpha.cpp"

$(IntermediateDirectory)/ximalpha.cpp$(PreprocessSuffix): ximalpha.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ximalpha.cpp$(PreprocessSuffix) "ximalpha.cpp"

$(IntermediateDirectory)/ximalyr.cpp$(ObjectSuffix): ximalyr.cpp $(IntermediateDirectory)/ximalyr.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/figuinha/dev/Regards/CxImage/ximalyr.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ximalyr.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ximalyr.cpp$(DependSuffix): ximalyr.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ximalyr.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ximalyr.cpp$(DependSuffix) -MM "ximalyr.cpp"

$(IntermediateDirectory)/ximalyr.cpp$(PreprocessSuffix): ximalyr.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ximalyr.cpp$(PreprocessSuffix) "ximalyr.cpp"

$(IntermediateDirectory)/ximamng.cpp$(ObjectSuffix): ximamng.cpp $(IntermediateDirectory)/ximamng.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/figuinha/dev/Regards/CxImage/ximamng.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ximamng.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ximamng.cpp$(DependSuffix): ximamng.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ximamng.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ximamng.cpp$(DependSuffix) -MM "ximamng.cpp"

$(IntermediateDirectory)/ximamng.cpp$(PreprocessSuffix): ximamng.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ximamng.cpp$(PreprocessSuffix) "ximamng.cpp"

$(IntermediateDirectory)/ximapal.cpp$(ObjectSuffix): ximapal.cpp $(IntermediateDirectory)/ximapal.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/figuinha/dev/Regards/CxImage/ximapal.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ximapal.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ximapal.cpp$(DependSuffix): ximapal.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ximapal.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ximapal.cpp$(DependSuffix) -MM "ximapal.cpp"

$(IntermediateDirectory)/ximapal.cpp$(PreprocessSuffix): ximapal.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ximapal.cpp$(PreprocessSuffix) "ximapal.cpp"

$(IntermediateDirectory)/ximapcx.cpp$(ObjectSuffix): ximapcx.cpp $(IntermediateDirectory)/ximapcx.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/figuinha/dev/Regards/CxImage/ximapcx.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ximapcx.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ximapcx.cpp$(DependSuffix): ximapcx.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ximapcx.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ximapcx.cpp$(DependSuffix) -MM "ximapcx.cpp"

$(IntermediateDirectory)/ximapcx.cpp$(PreprocessSuffix): ximapcx.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ximapcx.cpp$(PreprocessSuffix) "ximapcx.cpp"

$(IntermediateDirectory)/ximapng.cpp$(ObjectSuffix): ximapng.cpp $(IntermediateDirectory)/ximapng.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/figuinha/dev/Regards/CxImage/ximapng.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ximapng.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ximapng.cpp$(DependSuffix): ximapng.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ximapng.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ximapng.cpp$(DependSuffix) -MM "ximapng.cpp"

$(IntermediateDirectory)/ximapng.cpp$(PreprocessSuffix): ximapng.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ximapng.cpp$(PreprocessSuffix) "ximapng.cpp"

$(IntermediateDirectory)/ximapsd.cpp$(ObjectSuffix): ximapsd.cpp $(IntermediateDirectory)/ximapsd.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/figuinha/dev/Regards/CxImage/ximapsd.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ximapsd.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ximapsd.cpp$(DependSuffix): ximapsd.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ximapsd.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ximapsd.cpp$(DependSuffix) -MM "ximapsd.cpp"

$(IntermediateDirectory)/ximapsd.cpp$(PreprocessSuffix): ximapsd.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ximapsd.cpp$(PreprocessSuffix) "ximapsd.cpp"

$(IntermediateDirectory)/ximaraw.cpp$(ObjectSuffix): ximaraw.cpp $(IntermediateDirectory)/ximaraw.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/figuinha/dev/Regards/CxImage/ximaraw.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ximaraw.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ximaraw.cpp$(DependSuffix): ximaraw.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ximaraw.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ximaraw.cpp$(DependSuffix) -MM "ximaraw.cpp"

$(IntermediateDirectory)/ximaraw.cpp$(PreprocessSuffix): ximaraw.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ximaraw.cpp$(PreprocessSuffix) "ximaraw.cpp"

$(IntermediateDirectory)/ximasel.cpp$(ObjectSuffix): ximasel.cpp $(IntermediateDirectory)/ximasel.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/figuinha/dev/Regards/CxImage/ximasel.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ximasel.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ximasel.cpp$(DependSuffix): ximasel.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ximasel.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ximasel.cpp$(DependSuffix) -MM "ximasel.cpp"

$(IntermediateDirectory)/ximasel.cpp$(PreprocessSuffix): ximasel.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ximasel.cpp$(PreprocessSuffix) "ximasel.cpp"

$(IntermediateDirectory)/ximaska.cpp$(ObjectSuffix): ximaska.cpp $(IntermediateDirectory)/ximaska.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/figuinha/dev/Regards/CxImage/ximaska.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ximaska.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ximaska.cpp$(DependSuffix): ximaska.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ximaska.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ximaska.cpp$(DependSuffix) -MM "ximaska.cpp"

$(IntermediateDirectory)/ximaska.cpp$(PreprocessSuffix): ximaska.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ximaska.cpp$(PreprocessSuffix) "ximaska.cpp"

$(IntermediateDirectory)/ximatga.cpp$(ObjectSuffix): ximatga.cpp $(IntermediateDirectory)/ximatga.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/figuinha/dev/Regards/CxImage/ximatga.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ximatga.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ximatga.cpp$(DependSuffix): ximatga.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ximatga.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ximatga.cpp$(DependSuffix) -MM "ximatga.cpp"

$(IntermediateDirectory)/ximatga.cpp$(PreprocessSuffix): ximatga.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ximatga.cpp$(PreprocessSuffix) "ximatga.cpp"

$(IntermediateDirectory)/ximath.cpp$(ObjectSuffix): ximath.cpp $(IntermediateDirectory)/ximath.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/figuinha/dev/Regards/CxImage/ximath.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ximath.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ximath.cpp$(DependSuffix): ximath.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ximath.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ximath.cpp$(DependSuffix) -MM "ximath.cpp"

$(IntermediateDirectory)/ximath.cpp$(PreprocessSuffix): ximath.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ximath.cpp$(PreprocessSuffix) "ximath.cpp"

$(IntermediateDirectory)/ximatif.cpp$(ObjectSuffix): ximatif.cpp $(IntermediateDirectory)/ximatif.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/figuinha/dev/Regards/CxImage/ximatif.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ximatif.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ximatif.cpp$(DependSuffix): ximatif.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ximatif.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ximatif.cpp$(DependSuffix) -MM "ximatif.cpp"

$(IntermediateDirectory)/ximatif.cpp$(PreprocessSuffix): ximatif.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ximatif.cpp$(PreprocessSuffix) "ximatif.cpp"

$(IntermediateDirectory)/ximatran.cpp$(ObjectSuffix): ximatran.cpp $(IntermediateDirectory)/ximatran.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/figuinha/dev/Regards/CxImage/ximatran.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ximatran.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ximatran.cpp$(DependSuffix): ximatran.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ximatran.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ximatran.cpp$(DependSuffix) -MM "ximatran.cpp"

$(IntermediateDirectory)/ximatran.cpp$(PreprocessSuffix): ximatran.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ximatran.cpp$(PreprocessSuffix) "ximatran.cpp"

$(IntermediateDirectory)/ximawbmp.cpp$(ObjectSuffix): ximawbmp.cpp $(IntermediateDirectory)/ximawbmp.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/figuinha/dev/Regards/CxImage/ximawbmp.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ximawbmp.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ximawbmp.cpp$(DependSuffix): ximawbmp.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ximawbmp.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ximawbmp.cpp$(DependSuffix) -MM "ximawbmp.cpp"

$(IntermediateDirectory)/ximawbmp.cpp$(PreprocessSuffix): ximawbmp.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ximawbmp.cpp$(PreprocessSuffix) "ximawbmp.cpp"

$(IntermediateDirectory)/ximawmf.cpp$(ObjectSuffix): ximawmf.cpp $(IntermediateDirectory)/ximawmf.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/figuinha/dev/Regards/CxImage/ximawmf.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ximawmf.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ximawmf.cpp$(DependSuffix): ximawmf.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ximawmf.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ximawmf.cpp$(DependSuffix) -MM "ximawmf.cpp"

$(IntermediateDirectory)/ximawmf.cpp$(PreprocessSuffix): ximawmf.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ximawmf.cpp$(PreprocessSuffix) "ximawmf.cpp"

$(IntermediateDirectory)/ximawnd.cpp$(ObjectSuffix): ximawnd.cpp $(IntermediateDirectory)/ximawnd.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/figuinha/dev/Regards/CxImage/ximawnd.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ximawnd.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ximawnd.cpp$(DependSuffix): ximawnd.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ximawnd.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ximawnd.cpp$(DependSuffix) -MM "ximawnd.cpp"

$(IntermediateDirectory)/ximawnd.cpp$(PreprocessSuffix): ximawnd.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ximawnd.cpp$(PreprocessSuffix) "ximawnd.cpp"

$(IntermediateDirectory)/xmemfile.cpp$(ObjectSuffix): xmemfile.cpp $(IntermediateDirectory)/xmemfile.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/figuinha/dev/Regards/CxImage/xmemfile.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/xmemfile.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/xmemfile.cpp$(DependSuffix): xmemfile.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/xmemfile.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/xmemfile.cpp$(DependSuffix) -MM "xmemfile.cpp"

$(IntermediateDirectory)/xmemfile.cpp$(PreprocessSuffix): xmemfile.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/xmemfile.cpp$(PreprocessSuffix) "xmemfile.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


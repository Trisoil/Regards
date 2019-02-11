##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Release
ProjectName            :=libDialog
ConfigurationName      :=Release
WorkspacePath          :=C:/Regards
ProjectPath            :=C:/Regards/libDialog
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
Preprocessors          :=$(PreprocessorSwitch)EXIV2 $(PreprocessorSwitch)NDEBUG 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="libDialog.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/msys64/mingw64/bin/windres.exe
LinkOptions            :=  -s 
IncludePath            := $(IncludeSwitch)"C:\Program Files (x86)\AMD APP SDK\3.0_mingw\include" $(IncludeSwitch)/mingw64/include/libxml2 $(IncludeSwitch)/mingw64/include/OpenEXR  $(IncludeSwitch). $(IncludeSwitch)../libSqlite $(IncludeSwitch)../libUtility $(IncludeSwitch)../libResource $(IncludeSwitch)../libDataStructure $(IncludeSwitch)../libOpenCL $(IncludeSwitch)../libPicture $(IncludeSwitch)../libParameter $(IncludeSwitch)../libextern/libRapidXML $(IncludeSwitch)../include $(IncludeSwitch)../libSqlData $(IncludeSwitch)../libSqlEngine $(IncludeSwitch)../libSqlite $(IncludeSwitch)../libExif $(IncludeSwitch)../libAppleFunction $(IncludeSwitch)../include $(IncludeSwitch)../libextern/OpenCL-Headers 
IncludePCH             :=  -include ../include/Release/header.h 
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
CXXFLAGS := $(shell ../libextern/wxWidgets-master/wx-config --cppflags) -Wall -pthread -fopenmp -std=gnu++11 -O2 -msse4.1 $(Preprocessors)
CFLAGS   :=  -Wall  -O2 -msse4.1 $(Preprocessors)
ASFLAGS  := 
AS       := C:/msys64/mingw64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
PATH:=C:\msys64\usr\bin;$PATH
WXWIN:=C:\Regards\libextern\wxwidgets-3.1.2
WXCFG:=lib/mswud
Objects0=$(IntermediateDirectory)/MoveFaceDialog.cpp$(ObjectSuffix) $(IntermediateDirectory)/GifOption.cpp$(ObjectSuffix) $(IntermediateDirectory)/JpegOption.cpp$(ObjectSuffix) $(IntermediateDirectory)/ExportFile.cpp$(ObjectSuffix) $(IntermediateDirectory)/CopyFileDlg.cpp$(ObjectSuffix) $(IntermediateDirectory)/CompressionOption.cpp$(ObjectSuffix) $(IntermediateDirectory)/TiffOption.cpp$(ObjectSuffix) $(IntermediateDirectory)/ChangeLabel.cpp$(ObjectSuffix) $(IntermediateDirectory)/PertinenceValue.cpp$(ObjectSuffix) $(IntermediateDirectory)/IndexGenerator.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/OpenCLDialog.cpp$(ObjectSuffix) $(IntermediateDirectory)/ConfigRegards.cpp$(ObjectSuffix) $(IntermediateDirectory)/PngOption.cpp$(ObjectSuffix) $(IntermediateDirectory)/bpgoption.cpp$(ObjectSuffix) $(IntermediateDirectory)/webpOption.cpp$(ObjectSuffix) $(IntermediateDirectory)/SavePicture.cpp$(ObjectSuffix) 



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
	@echo rebuilt > "C:\Regards/.build-release/libDialog"

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Release"


./Release:
	@$(MakeDirCommand) "./Release"

PreBuild:

# PreCompiled Header
../include/Release/header.h.gch: ../include/Release/header.h
	$(CXX) $(SourceSwitch) ../include/Release/header.h $(PCHCompileFlags) $(CXXFLAGS) $(IncludePath)



##
## Objects
##
$(IntermediateDirectory)/MoveFaceDialog.cpp$(ObjectSuffix): MoveFaceDialog.cpp $(IntermediateDirectory)/MoveFaceDialog.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Regards/libDialog/MoveFaceDialog.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/MoveFaceDialog.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/MoveFaceDialog.cpp$(DependSuffix): MoveFaceDialog.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/MoveFaceDialog.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/MoveFaceDialog.cpp$(DependSuffix) -MM MoveFaceDialog.cpp

$(IntermediateDirectory)/MoveFaceDialog.cpp$(PreprocessSuffix): MoveFaceDialog.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/MoveFaceDialog.cpp$(PreprocessSuffix) MoveFaceDialog.cpp

$(IntermediateDirectory)/GifOption.cpp$(ObjectSuffix): GifOption.cpp $(IntermediateDirectory)/GifOption.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Regards/libDialog/GifOption.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/GifOption.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/GifOption.cpp$(DependSuffix): GifOption.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/GifOption.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/GifOption.cpp$(DependSuffix) -MM GifOption.cpp

$(IntermediateDirectory)/GifOption.cpp$(PreprocessSuffix): GifOption.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/GifOption.cpp$(PreprocessSuffix) GifOption.cpp

$(IntermediateDirectory)/JpegOption.cpp$(ObjectSuffix): JpegOption.cpp $(IntermediateDirectory)/JpegOption.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Regards/libDialog/JpegOption.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/JpegOption.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/JpegOption.cpp$(DependSuffix): JpegOption.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/JpegOption.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/JpegOption.cpp$(DependSuffix) -MM JpegOption.cpp

$(IntermediateDirectory)/JpegOption.cpp$(PreprocessSuffix): JpegOption.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/JpegOption.cpp$(PreprocessSuffix) JpegOption.cpp

$(IntermediateDirectory)/ExportFile.cpp$(ObjectSuffix): ExportFile.cpp $(IntermediateDirectory)/ExportFile.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Regards/libDialog/ExportFile.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ExportFile.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ExportFile.cpp$(DependSuffix): ExportFile.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ExportFile.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ExportFile.cpp$(DependSuffix) -MM ExportFile.cpp

$(IntermediateDirectory)/ExportFile.cpp$(PreprocessSuffix): ExportFile.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ExportFile.cpp$(PreprocessSuffix) ExportFile.cpp

$(IntermediateDirectory)/CopyFileDlg.cpp$(ObjectSuffix): CopyFileDlg.cpp $(IntermediateDirectory)/CopyFileDlg.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Regards/libDialog/CopyFileDlg.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/CopyFileDlg.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CopyFileDlg.cpp$(DependSuffix): CopyFileDlg.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/CopyFileDlg.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/CopyFileDlg.cpp$(DependSuffix) -MM CopyFileDlg.cpp

$(IntermediateDirectory)/CopyFileDlg.cpp$(PreprocessSuffix): CopyFileDlg.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/CopyFileDlg.cpp$(PreprocessSuffix) CopyFileDlg.cpp

$(IntermediateDirectory)/CompressionOption.cpp$(ObjectSuffix): CompressionOption.cpp $(IntermediateDirectory)/CompressionOption.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Regards/libDialog/CompressionOption.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/CompressionOption.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CompressionOption.cpp$(DependSuffix): CompressionOption.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/CompressionOption.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/CompressionOption.cpp$(DependSuffix) -MM CompressionOption.cpp

$(IntermediateDirectory)/CompressionOption.cpp$(PreprocessSuffix): CompressionOption.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/CompressionOption.cpp$(PreprocessSuffix) CompressionOption.cpp

$(IntermediateDirectory)/TiffOption.cpp$(ObjectSuffix): TiffOption.cpp $(IntermediateDirectory)/TiffOption.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Regards/libDialog/TiffOption.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/TiffOption.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/TiffOption.cpp$(DependSuffix): TiffOption.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/TiffOption.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/TiffOption.cpp$(DependSuffix) -MM TiffOption.cpp

$(IntermediateDirectory)/TiffOption.cpp$(PreprocessSuffix): TiffOption.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/TiffOption.cpp$(PreprocessSuffix) TiffOption.cpp

$(IntermediateDirectory)/ChangeLabel.cpp$(ObjectSuffix): ChangeLabel.cpp $(IntermediateDirectory)/ChangeLabel.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Regards/libDialog/ChangeLabel.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ChangeLabel.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ChangeLabel.cpp$(DependSuffix): ChangeLabel.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ChangeLabel.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ChangeLabel.cpp$(DependSuffix) -MM ChangeLabel.cpp

$(IntermediateDirectory)/ChangeLabel.cpp$(PreprocessSuffix): ChangeLabel.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ChangeLabel.cpp$(PreprocessSuffix) ChangeLabel.cpp

$(IntermediateDirectory)/PertinenceValue.cpp$(ObjectSuffix): PertinenceValue.cpp $(IntermediateDirectory)/PertinenceValue.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Regards/libDialog/PertinenceValue.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/PertinenceValue.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/PertinenceValue.cpp$(DependSuffix): PertinenceValue.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/PertinenceValue.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/PertinenceValue.cpp$(DependSuffix) -MM PertinenceValue.cpp

$(IntermediateDirectory)/PertinenceValue.cpp$(PreprocessSuffix): PertinenceValue.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/PertinenceValue.cpp$(PreprocessSuffix) PertinenceValue.cpp

$(IntermediateDirectory)/IndexGenerator.cpp$(ObjectSuffix): IndexGenerator.cpp $(IntermediateDirectory)/IndexGenerator.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Regards/libDialog/IndexGenerator.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/IndexGenerator.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/IndexGenerator.cpp$(DependSuffix): IndexGenerator.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/IndexGenerator.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/IndexGenerator.cpp$(DependSuffix) -MM IndexGenerator.cpp

$(IntermediateDirectory)/IndexGenerator.cpp$(PreprocessSuffix): IndexGenerator.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/IndexGenerator.cpp$(PreprocessSuffix) IndexGenerator.cpp

$(IntermediateDirectory)/OpenCLDialog.cpp$(ObjectSuffix): OpenCLDialog.cpp $(IntermediateDirectory)/OpenCLDialog.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Regards/libDialog/OpenCLDialog.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/OpenCLDialog.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/OpenCLDialog.cpp$(DependSuffix): OpenCLDialog.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/OpenCLDialog.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/OpenCLDialog.cpp$(DependSuffix) -MM OpenCLDialog.cpp

$(IntermediateDirectory)/OpenCLDialog.cpp$(PreprocessSuffix): OpenCLDialog.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/OpenCLDialog.cpp$(PreprocessSuffix) OpenCLDialog.cpp

$(IntermediateDirectory)/ConfigRegards.cpp$(ObjectSuffix): ConfigRegards.cpp $(IntermediateDirectory)/ConfigRegards.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Regards/libDialog/ConfigRegards.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ConfigRegards.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ConfigRegards.cpp$(DependSuffix): ConfigRegards.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ConfigRegards.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ConfigRegards.cpp$(DependSuffix) -MM ConfigRegards.cpp

$(IntermediateDirectory)/ConfigRegards.cpp$(PreprocessSuffix): ConfigRegards.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ConfigRegards.cpp$(PreprocessSuffix) ConfigRegards.cpp

$(IntermediateDirectory)/PngOption.cpp$(ObjectSuffix): PngOption.cpp $(IntermediateDirectory)/PngOption.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Regards/libDialog/PngOption.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/PngOption.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/PngOption.cpp$(DependSuffix): PngOption.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/PngOption.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/PngOption.cpp$(DependSuffix) -MM PngOption.cpp

$(IntermediateDirectory)/PngOption.cpp$(PreprocessSuffix): PngOption.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/PngOption.cpp$(PreprocessSuffix) PngOption.cpp

$(IntermediateDirectory)/bpgoption.cpp$(ObjectSuffix): bpgoption.cpp $(IntermediateDirectory)/bpgoption.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Regards/libDialog/bpgoption.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/bpgoption.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/bpgoption.cpp$(DependSuffix): bpgoption.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/bpgoption.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/bpgoption.cpp$(DependSuffix) -MM bpgoption.cpp

$(IntermediateDirectory)/bpgoption.cpp$(PreprocessSuffix): bpgoption.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/bpgoption.cpp$(PreprocessSuffix) bpgoption.cpp

$(IntermediateDirectory)/webpOption.cpp$(ObjectSuffix): webpOption.cpp $(IntermediateDirectory)/webpOption.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Regards/libDialog/webpOption.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/webpOption.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/webpOption.cpp$(DependSuffix): webpOption.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/webpOption.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/webpOption.cpp$(DependSuffix) -MM webpOption.cpp

$(IntermediateDirectory)/webpOption.cpp$(PreprocessSuffix): webpOption.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/webpOption.cpp$(PreprocessSuffix) webpOption.cpp

$(IntermediateDirectory)/SavePicture.cpp$(ObjectSuffix): SavePicture.cpp $(IntermediateDirectory)/SavePicture.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Regards/libDialog/SavePicture.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/SavePicture.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/SavePicture.cpp$(DependSuffix): SavePicture.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/SavePicture.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/SavePicture.cpp$(DependSuffix) -MM SavePicture.cpp

$(IntermediateDirectory)/SavePicture.cpp$(PreprocessSuffix): SavePicture.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/SavePicture.cpp$(PreprocessSuffix) SavePicture.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Release/
	$(RM) ../include/Release/header.h.gch



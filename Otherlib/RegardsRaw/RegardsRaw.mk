##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Release
ProjectName            :=RegardsRaw
ConfigurationName      :=Release
WorkspacePath          :=C:/Regards
ProjectPath            :=C:/Regards/Otherlib/RegardsRaw
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
OutputFile             :=$(IntermediateDirectory)/lib$(ProjectName).a
Preprocessors          :=$(PreprocessorSwitch)LIBRAW $(PreprocessorSwitch)LIBRAW_NODLL $(PreprocessorSwitch)_USE_MATH_DEFINES $(PreprocessorSwitch)NDEBUG $(PreprocessorSwitch)LIBRAW_DEMOSAIC_PACK_GPL2 $(PreprocessorSwitch)LIBRAW_DEMOSAIC_PACK_GPL3 $(PreprocessorSwitch)NDEBUG 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="RegardsRaw.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/msys64/mingw64/bin/windres.exe
LinkOptions            :=  -Os
IncludePath            := $(IncludeSwitch)"C:\Program Files (x86)\AMD APP SDK\3.0_mingw\include" $(IncludeSwitch)/mingw64/include/libxml2 $(IncludeSwitch)/mingw64/include/OpenEXR  $(IncludeSwitch)../ $(IncludeSwitch)../RegardsRaw $(IncludeSwitch). $(IncludeSwitch)../../libOpenCL $(IncludeSwitch)../../libDataStructure $(IncludeSwitch)../../libUtility $(IncludeSwitch)../../CxImage $(IncludeSwitch)../../libextern/jasper-1.900.1/src/libjasper/include $(IncludeSwitch)demoisaic_pack/gpl2 $(IncludeSwitch)demoisaic_pack/gpl3 $(IncludeSwitch)../../libextern/wxWidgets-master/src/jpeg $(IncludeSwitch)../../libFiltre 
IncludePCH             :=  -include ../../include/Release/header.h 
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
CXXFLAGS := -fopenmp -std=gnu++11 -Wall $(shell ../../libextern/wxWidgets-master/wx-config --cppflags) -Wall -pthread -fopenmp -Wno-narrowing -O2 -msse4.1 $(Preprocessors)
CFLAGS   := $(shell ../../libextern/wxWidgets-master/wx-config --cppflags) -Wall -pthread  -O2 -Os -msse4.1 $(Preprocessors)
ASFLAGS  := 
AS       := C:/msys64/mingw64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
PATH:=C:\msys64\usr\bin;$PATH
WXWIN:=C:\Regards\libextern\wxwidgets-3.1.2
WXCFG:=lib/mswud
Objects0=$(IntermediateDirectory)/internal_dcraw_fileio.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_libraw_datastream.cpp$(ObjectSuffix) $(IntermediateDirectory)/internal_dcraw_common.cpp$(ObjectSuffix) $(IntermediateDirectory)/RegardsRaw.cpp$(ObjectSuffix) $(IntermediateDirectory)/DecodeRawPicture.cpp$(ObjectSuffix) $(IntermediateDirectory)/internal_demosaic_packs.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_libraw_cxx.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_libraw_c_api.cpp$(ObjectSuffix) 



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
	@echo rebuilt > "C:\Regards/.build-release/RegardsRaw"

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Release"


./Release:
	@$(MakeDirCommand) "./Release"

PreBuild:
	@echo Executing Pre Build commands ...
	
	@echo Done

# PreCompiled Header
../../include/Release/header.h.gch: ../../include/Release/header.h
	$(CXX) $(SourceSwitch) ../../include/Release/header.h $(PCHCompileFlags) $(CXXFLAGS) $(IncludePath)



##
## Objects
##
$(IntermediateDirectory)/internal_dcraw_fileio.cpp$(ObjectSuffix): internal/dcraw_fileio.cpp $(IntermediateDirectory)/internal_dcraw_fileio.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Regards/Otherlib/RegardsRaw/internal/dcraw_fileio.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/internal_dcraw_fileio.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/internal_dcraw_fileio.cpp$(DependSuffix): internal/dcraw_fileio.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/internal_dcraw_fileio.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/internal_dcraw_fileio.cpp$(DependSuffix) -MM internal/dcraw_fileio.cpp

$(IntermediateDirectory)/internal_dcraw_fileio.cpp$(PreprocessSuffix): internal/dcraw_fileio.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/internal_dcraw_fileio.cpp$(PreprocessSuffix) internal/dcraw_fileio.cpp

$(IntermediateDirectory)/src_libraw_datastream.cpp$(ObjectSuffix): src/libraw_datastream.cpp $(IntermediateDirectory)/src_libraw_datastream.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Regards/Otherlib/RegardsRaw/src/libraw_datastream.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_libraw_datastream.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_libraw_datastream.cpp$(DependSuffix): src/libraw_datastream.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_libraw_datastream.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_libraw_datastream.cpp$(DependSuffix) -MM src/libraw_datastream.cpp

$(IntermediateDirectory)/src_libraw_datastream.cpp$(PreprocessSuffix): src/libraw_datastream.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_libraw_datastream.cpp$(PreprocessSuffix) src/libraw_datastream.cpp

$(IntermediateDirectory)/internal_dcraw_common.cpp$(ObjectSuffix): internal/dcraw_common.cpp $(IntermediateDirectory)/internal_dcraw_common.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Regards/Otherlib/RegardsRaw/internal/dcraw_common.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/internal_dcraw_common.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/internal_dcraw_common.cpp$(DependSuffix): internal/dcraw_common.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/internal_dcraw_common.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/internal_dcraw_common.cpp$(DependSuffix) -MM internal/dcraw_common.cpp

$(IntermediateDirectory)/internal_dcraw_common.cpp$(PreprocessSuffix): internal/dcraw_common.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/internal_dcraw_common.cpp$(PreprocessSuffix) internal/dcraw_common.cpp

$(IntermediateDirectory)/RegardsRaw.cpp$(ObjectSuffix): RegardsRaw.cpp $(IntermediateDirectory)/RegardsRaw.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Regards/Otherlib/RegardsRaw/RegardsRaw.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/RegardsRaw.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/RegardsRaw.cpp$(DependSuffix): RegardsRaw.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/RegardsRaw.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/RegardsRaw.cpp$(DependSuffix) -MM RegardsRaw.cpp

$(IntermediateDirectory)/RegardsRaw.cpp$(PreprocessSuffix): RegardsRaw.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/RegardsRaw.cpp$(PreprocessSuffix) RegardsRaw.cpp

$(IntermediateDirectory)/DecodeRawPicture.cpp$(ObjectSuffix): DecodeRawPicture.cpp $(IntermediateDirectory)/DecodeRawPicture.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Regards/Otherlib/RegardsRaw/DecodeRawPicture.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/DecodeRawPicture.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/DecodeRawPicture.cpp$(DependSuffix): DecodeRawPicture.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/DecodeRawPicture.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/DecodeRawPicture.cpp$(DependSuffix) -MM DecodeRawPicture.cpp

$(IntermediateDirectory)/DecodeRawPicture.cpp$(PreprocessSuffix): DecodeRawPicture.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/DecodeRawPicture.cpp$(PreprocessSuffix) DecodeRawPicture.cpp

$(IntermediateDirectory)/internal_demosaic_packs.cpp$(ObjectSuffix): internal/demosaic_packs.cpp $(IntermediateDirectory)/internal_demosaic_packs.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Regards/Otherlib/RegardsRaw/internal/demosaic_packs.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/internal_demosaic_packs.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/internal_demosaic_packs.cpp$(DependSuffix): internal/demosaic_packs.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/internal_demosaic_packs.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/internal_demosaic_packs.cpp$(DependSuffix) -MM internal/demosaic_packs.cpp

$(IntermediateDirectory)/internal_demosaic_packs.cpp$(PreprocessSuffix): internal/demosaic_packs.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/internal_demosaic_packs.cpp$(PreprocessSuffix) internal/demosaic_packs.cpp

$(IntermediateDirectory)/src_libraw_cxx.cpp$(ObjectSuffix): src/libraw_cxx.cpp $(IntermediateDirectory)/src_libraw_cxx.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Regards/Otherlib/RegardsRaw/src/libraw_cxx.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_libraw_cxx.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_libraw_cxx.cpp$(DependSuffix): src/libraw_cxx.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_libraw_cxx.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_libraw_cxx.cpp$(DependSuffix) -MM src/libraw_cxx.cpp

$(IntermediateDirectory)/src_libraw_cxx.cpp$(PreprocessSuffix): src/libraw_cxx.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_libraw_cxx.cpp$(PreprocessSuffix) src/libraw_cxx.cpp

$(IntermediateDirectory)/src_libraw_c_api.cpp$(ObjectSuffix): src/libraw_c_api.cpp $(IntermediateDirectory)/src_libraw_c_api.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Regards/Otherlib/RegardsRaw/src/libraw_c_api.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_libraw_c_api.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_libraw_c_api.cpp$(DependSuffix): src/libraw_c_api.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_libraw_c_api.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_libraw_c_api.cpp$(DependSuffix) -MM src/libraw_c_api.cpp

$(IntermediateDirectory)/src_libraw_c_api.cpp$(PreprocessSuffix): src/libraw_c_api.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_libraw_c_api.cpp$(PreprocessSuffix) src/libraw_c_api.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Release/
	$(RM) ../../include/Release/header.h.gch



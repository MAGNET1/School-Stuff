##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=STL_Set_Lab6
ConfigurationName      :=Debug
WorkspacePath          :=C:/Users/Adminek/Desktop/CodeLiteMine
ProjectPath            :=C:/Users/Adminek/Desktop/CodeLiteMine/STL_Set_Lab6
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Adminek
Date                   :=22/01/2018
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/TDM-GCC-64/bin/g++.exe
SharedObjectLinkerName :=C:/TDM-GCC-64/bin/g++.exe -shared -fPIC
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
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="STL_Set_Lab6.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/TDM-GCC-64/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/TDM-GCC-64/bin/ar.exe rcu
CXX      := C:/TDM-GCC-64/bin/g++.exe
CC       := C:/TDM-GCC-64/bin/gcc.exe
CXXFLAGS :=  -g -O0 -std=c++11 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := C:/TDM-GCC-64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/TimeCounter.cpp$(ObjectSuffix) $(IntermediateDirectory)/FileDownloader.cpp$(ObjectSuffix) $(IntermediateDirectory)/SetOperations.cpp$(ObjectSuffix) $(IntermediateDirectory)/main.cpp$(ObjectSuffix) 



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

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/TimeCounter.cpp$(ObjectSuffix): TimeCounter.cpp $(IntermediateDirectory)/TimeCounter.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Adminek/Desktop/CodeLiteMine/STL_Set_Lab6/TimeCounter.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/TimeCounter.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/TimeCounter.cpp$(DependSuffix): TimeCounter.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/TimeCounter.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/TimeCounter.cpp$(DependSuffix) -MM TimeCounter.cpp

$(IntermediateDirectory)/TimeCounter.cpp$(PreprocessSuffix): TimeCounter.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/TimeCounter.cpp$(PreprocessSuffix) TimeCounter.cpp

$(IntermediateDirectory)/FileDownloader.cpp$(ObjectSuffix): FileDownloader.cpp $(IntermediateDirectory)/FileDownloader.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Adminek/Desktop/CodeLiteMine/STL_Set_Lab6/FileDownloader.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/FileDownloader.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/FileDownloader.cpp$(DependSuffix): FileDownloader.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/FileDownloader.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/FileDownloader.cpp$(DependSuffix) -MM FileDownloader.cpp

$(IntermediateDirectory)/FileDownloader.cpp$(PreprocessSuffix): FileDownloader.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/FileDownloader.cpp$(PreprocessSuffix) FileDownloader.cpp

$(IntermediateDirectory)/SetOperations.cpp$(ObjectSuffix): SetOperations.cpp $(IntermediateDirectory)/SetOperations.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Adminek/Desktop/CodeLiteMine/STL_Set_Lab6/SetOperations.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/SetOperations.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/SetOperations.cpp$(DependSuffix): SetOperations.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/SetOperations.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/SetOperations.cpp$(DependSuffix) -MM SetOperations.cpp

$(IntermediateDirectory)/SetOperations.cpp$(PreprocessSuffix): SetOperations.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/SetOperations.cpp$(PreprocessSuffix) SetOperations.cpp

$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Adminek/Desktop/CodeLiteMine/STL_Set_Lab6/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/



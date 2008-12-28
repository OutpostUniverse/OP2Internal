# Microsoft Developer Studio Project File - Name="ForcedExports" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=ForcedExports - Win32 Release
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "ForcedExports.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "ForcedExports.mak" CFG="ForcedExports - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "ForcedExports - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe
# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O1 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"..\ForcedExports.lib"
# Begin Target

# Name "ForcedExports - Win32 Release"
# Begin Group "Game"

# PROP Default_Filter ""
# Begin Group "GameStartInfo"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Game\GameStartInfo\EnumGameTermReasons.h
# End Source File
# Begin Source File

SOURCE=.\Game\GameStartInfo\EnumGameType.h
# End Source File
# Begin Source File

SOURCE=.\Game\GameStartInfo\GameStartInfo.h
# End Source File
# Begin Source File

SOURCE=.\Game\GameStartInfo\MoraleStartInfo.h
# End Source File
# Begin Source File

SOURCE=.\Game\GameStartInfo\PlayerStartInfo.h
# End Source File
# Begin Source File

SOURCE=.\Game\GameStartInfo\ResearchStartInfo.h
# End Source File
# Begin Source File

SOURCE=.\Game\GameStartInfo\StartFlags.h
# End Source File
# End Group
# Begin Group "Unit"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Game\Unit\Unit.h
# End Source File
# Begin Source File

SOURCE=.\Game\Unit\UnitBuilding.h
# End Source File
# Begin Source File

SOURCE=.\Game\Unit\UnitVehicle.h
# End Source File
# Begin Source File

SOURCE=.\Game\Unit\UnitWeapon.h
# End Source File
# End Group
# Begin Group "UnitTypeInfo"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Game\UnitTypeInfo\UnitTypeInfo.h
# End Source File
# Begin Source File

SOURCE=.\Game\UnitTypeInfo\UnitTypeInfoBuilding.h
# End Source File
# Begin Source File

SOURCE=.\Game\UnitTypeInfo\UnitTypeInfoVehicle.h
# End Source File
# Begin Source File

SOURCE=.\Game\UnitTypeInfo\UnitTypeInfoWeapon.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\Game\CommandPacket.h
# End Source File
# Begin Source File

SOURCE=.\Game\GameOpt.h
# End Source File
# Begin Source File

SOURCE=.\Game\LevelDLL.h
# End Source File
# Begin Source File

SOURCE=.\Game\Map.h
# End Source File
# Begin Source File

SOURCE=.\Game\MiniMap.h
# End Source File
# Begin Source File

SOURCE=.\Game\Morale.h
# End Source File
# Begin Source File

SOURCE=.\Game\Player.h
# End Source File
# Begin Source File

SOURCE=.\Game\RandomNumberGenerator.h
# End Source File
# Begin Source File

SOURCE=.\Game\Research.h
# End Source File
# Begin Source File

SOURCE=.\Game\ScStub.h
# End Source File
# Begin Source File

SOURCE=.\Game\ScStubCreator.h
# End Source File
# Begin Source File

SOURCE=.\Game\Sheet.h
# End Source File
# Begin Source File

SOURCE=.\Game\TApp.h
# End Source File
# Begin Source File

SOURCE=.\Game\TethysGame.h
# End Source File
# Begin Source File

SOURCE=.\Game\UnitGroup.h
# End Source File
# End Group
# Begin Group "Network"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Network\GurManager.h
# End Source File
# Begin Source File

SOURCE=.\Network\NetGameProtocol.h
# End Source File
# Begin Source File

SOURCE=.\Network\NetTransportLayer.h
# End Source File
# Begin Source File

SOURCE=.\Network\Packet.h
# End Source File
# End Group
# Begin Group "ResourceManagement"

# PROP Default_Filter ""
# Begin Group "Streams"

# PROP Default_Filter ""
# Begin Group "BasicStreams"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\ResourceManagement\Streams\BasicStreams\FileRStream.h
# End Source File
# Begin Source File

SOURCE=.\ResourceManagement\Streams\BasicStreams\FileRWStream.h
# End Source File
# Begin Source File

SOURCE=.\ResourceManagement\Streams\BasicStreams\FileWStream.h
# End Source File
# Begin Source File

SOURCE=.\ResourceManagement\Streams\BasicStreams\MemRWStream.h
# End Source File
# End Group
# Begin Group "VBlkStreams"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\ResourceManagement\Streams\VBlkStreams\HeaderVBlkRWStream.h
# End Source File
# Begin Source File

SOURCE=.\ResourceManagement\Streams\VBlkStreams\VBlkRWStream.h
# End Source File
# End Group
# Begin Group "VolFileStreams"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\ResourceManagement\Streams\VolFileStreams\VolFileRStream.h
# End Source File
# Begin Source File

SOURCE=.\ResourceManagement\Streams\VolFileStreams\VolFileWStream.h
# End Source File
# End Group
# Begin Group "WrapperStreams"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\ResourceManagement\Streams\WrapperStreams\LZHRStream.h
# End Source File
# Begin Source File

SOURCE=.\ResourceManagement\Streams\WrapperStreams\LZHWStream.h
# End Source File
# Begin Source File

SOURCE=.\ResourceManagement\Streams\WrapperStreams\LZRStream.h
# End Source File
# Begin Source File

SOURCE=.\ResourceManagement\Streams\WrapperStreams\LZWStream.h
# End Source File
# Begin Source File

SOURCE=.\ResourceManagement\Streams\WrapperStreams\RLERStream.h
# End Source File
# Begin Source File

SOURCE=.\ResourceManagement\Streams\WrapperStreams\RLEWStream.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\ResourceManagement\Streams\StreamIO.h
# End Source File
# Begin Source File

SOURCE=.\ResourceManagement\Streams\StreamIOBaseVBlkRWStream.h
# End Source File
# Begin Source File

SOURCE=.\ResourceManagement\Streams\StreamIOBaseVolFileStream.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\ResourceManagement\AdaptiveHuffmanTree.h
# End Source File
# Begin Source File

SOURCE=.\ResourceManagement\Bitmap.h
# End Source File
# Begin Source File

SOURCE=.\ResourceManagement\BitmapLightAdjustedBitmap.h
# End Source File
# Begin Source File

SOURCE=.\ResourceManagement\BitmapLightAdjustedBitmapMemoryMappedBitmap.h
# End Source File
# Begin Source File

SOURCE=.\ResourceManagement\BitmapLightAdjustedBitmapTileSet.h
# End Source File
# Begin Source File

SOURCE=.\ResourceManagement\CConfig.h
# End Source File
# Begin Source File

SOURCE=.\ResourceManagement\MusicManager.h
# End Source File
# Begin Source File

SOURCE=.\ResourceManagement\Palette.h
# End Source File
# Begin Source File

SOURCE=.\ResourceManagement\PrtGraphics.h
# End Source File
# Begin Source File

SOURCE=.\ResourceManagement\SoundEffectsManager.h
# End Source File
# Begin Source File

SOURCE=.\ResourceManagement\TextStreamParser.h
# End Source File
# End Group
# Begin Group "UserInterface"

# PROP Default_Filter ""
# Begin Group "CommandPaneView"

# PROP Default_Filter ""
# Begin Group "ReportViews"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\UserInterface\CommandPaneView\ReportViews\LabReportView.h
# End Source File
# End Group
# Begin Group "Views"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\UserInterface\CommandPaneView\Views\BuildingStorageBayView.h
# End Source File
# Begin Source File

SOURCE=.\UserInterface\CommandPaneView\Views\UnitView.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\UserInterface\CommandPaneView\CommandPaneView.h
# End Source File
# Begin Source File

SOURCE=.\UserInterface\CommandPaneView\ReportView.h
# End Source File
# End Group
# Begin Group "Filter"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\UserInterface\Filter\Filter.h
# End Source File
# Begin Source File

SOURCE=.\UserInterface\Filter\FilterGroupFilter.h
# End Source File
# Begin Source File

SOURCE=.\UserInterface\Filter\FilterGroupFilterDetailPaneFilter.h
# End Source File
# Begin Source File

SOURCE=.\UserInterface\Filter\FilterHotKeyFilter.h
# End Source File
# Begin Source File

SOURCE=.\UserInterface\Filter\FilterNode.h
# End Source File
# Begin Source File

SOURCE=.\UserInterface\Filter\FilterSubFilter.h
# End Source File
# Begin Source File

SOURCE=.\UserInterface\Filter\FilterSubFilterMouseCommandFilter.h
# End Source File
# Begin Source File

SOURCE=.\UserInterface\Filter\FilterUIElementFilter.h
# End Source File
# End Group
# Begin Group "Graphics"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\UserInterface\Graphics\Font.h
# End Source File
# Begin Source File

SOURCE=.\UserInterface\Graphics\GFXSurface.h
# End Source File
# Begin Source File

SOURCE=.\UserInterface\Graphics\GFXSurfaceGFXCDSSurface.h
# End Source File
# Begin Source File

SOURCE=.\UserInterface\Graphics\GFXSurfaceGFXCDSSurfaceGFXClippedSurface.h
# End Source File
# Begin Source File

SOURCE=.\UserInterface\Graphics\GFXSurfaceGFXMemSurface.h
# End Source File
# Begin Source File

SOURCE=.\UserInterface\Graphics\Viewport.h
# End Source File
# End Group
# Begin Group "IWnd"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\UserInterface\IWnd\IWnd.h
# End Source File
# Begin Source File

SOURCE=.\UserInterface\IWnd\IWndIDlgWnd.h
# End Source File
# Begin Source File

SOURCE=.\UserInterface\IWnd\IWndIDlgWndMessageBoxWnd.h
# End Source File
# Begin Source File

SOURCE=.\UserInterface\IWnd\IWndIDlgWndMultiplayerPreGameSetupWnd.h
# End Source File
# Begin Source File

SOURCE=.\UserInterface\IWnd\IWndPane.h
# End Source File
# Begin Source File

SOURCE=.\UserInterface\IWnd\IWndPaneCommand.h
# End Source File
# Begin Source File

SOURCE=.\UserInterface\IWnd\IWndPaneDetail.h
# End Source File
# Begin Source File

SOURCE=.\UserInterface\IWnd\IWndPaneMiniMap.h
# End Source File
# Begin Source File

SOURCE=.\UserInterface\IWnd\IWndTFrame.h
# End Source File
# Begin Source File

SOURCE=.\UserInterface\IWnd\IWndTFrameDans_RULE_UIFrame.h
# End Source File
# End Group
# Begin Group "UICommand"

# PROP Default_Filter ""
# Begin Group "Commands"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\UserInterface\UICommand\Commands\CommandProduce.h
# End Source File
# End Group
# Begin Group "MouseCommands"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\UserInterface\UICommand\MouseCommands\CommandAttack.h
# End Source File
# Begin Source File

SOURCE=.\UserInterface\UICommand\MouseCommands\CommandBuild.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\UserInterface\UICommand\UICommand.h
# End Source File
# Begin Source File

SOURCE=.\UserInterface\UICommand\UICommandMouseCommand.h
# End Source File
# End Group
# Begin Group "UIElement"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\UserInterface\UIElement\UIElement.h
# End Source File
# Begin Source File

SOURCE=.\UserInterface\UIElement\UIElementButton.h
# End Source File
# Begin Source File

SOURCE=.\UserInterface\UIElement\UIElementButtonGraphicalButton.h
# End Source File
# Begin Source File

SOURCE=.\UserInterface\UIElement\UIElementButtonGraphicalButtonBayButton.h
# End Source File
# Begin Source File

SOURCE=.\UserInterface\UIElement\UIElementButtonGraphicalButtonMiscButton.h
# End Source File
# Begin Source File

SOURCE=.\UserInterface\UIElement\UIElementButtonGraphicalButtonUICommandButton.h
# End Source File
# Begin Source File

SOURCE=.\UserInterface\UIElement\UIElementButtonGraphicalButtonViewButton.h
# End Source File
# Begin Source File

SOURCE=.\UserInterface\UIElement\UIElementButtonGraphicalButtonViewButtonBuildButton.h
# End Source File
# Begin Source File

SOURCE=.\UserInterface\UIElement\UIElementButtonGraphicalButtonViewButtonReportPageButton.h
# End Source File
# Begin Source File

SOURCE=.\UserInterface\UIElement\UIElementListBox.h
# End Source File
# End Group
# End Group
# Begin Source File

SOURCE=.\ForcedExports.asm
# Begin Custom Build
IntDir=.\Release
InputPath=.\ForcedExports.asm
InputName=ForcedExports

"$(IntDir)\$(InputName).obj" : $(SOURCE) "$(INTDIR)" "$(OUTDIR)"
	NASMw -f win32 -o "$(IntDir)\$(InputName).obj" "$(InputPath)"

# End Custom Build
# End Source File
# Begin Source File

SOURCE=.\ForcedExports.h
# End Source File
# Begin Source File

SOURCE=.\PointTypes.h
# End Source File
# Begin Source File

SOURCE=.\WinTypes.h
# End Source File
# End Target
# End Project

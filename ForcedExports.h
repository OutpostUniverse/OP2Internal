
// ForcedExports.h
// ---------------
// Master include file for this API. This includes everything.
// Just including this main header files is for convenience.
// You can also selectively include just the headers you want.
// Selective inclusion will allow for a slightly faster compile
// time, and a possibly cleaner namespace (for IntelliSense maybe?).


#ifndef ForcedExports_H
#define ForcedExports_H


// Add reference to the import library
#pragma comment(lib, "../../API/ForcedExports/Lib/ForcedExports")


// Used for sanity checking in DLLMain
extern "C" void* desiredLoadAddress;



#include "Network\NetGameProtocol.h"
#include "Network\GurManager.h"
#include "Network\NetTransportLayer.h"
#include "Network\Packet.h"


#include "ResourceManagement\CConfig.h"
#include "ResourceManagement\TextStreamParser.h"
#include "ResourceManagement\PrtGraphics.h"
#include "ResourceManagement\Palette.h"
#include "ResourceManagement\AdaptiveHuffmanTree.h"
#include "ResourceManagement\SoundEffectsManager.h"
#include "ResourceManagement\MusicManager.h"
#include "ResourceManagement\Bitmap.h"
#include "ResourceManagement\BitmapLightAdjustedBitmap.h"
#include "ResourceManagement\BitmapLightAdjustedBitmapTileSet.h"
#include "ResourceManagement\BitmapLightAdjustedBitmapMemoryMappedBitmap.h"

#include "ResourceManagement\Streams\StreamIO.h"
#include "ResourceManagement\Streams\StreamIOBaseVblkRWStream.h"
#include "ResourceManagement\Streams\StreamIOBaseVolFileStream.h"

#include "ResourceManagement\Streams\BasicStreams\FileRStream.h"
#include "ResourceManagement\Streams\BasicStreams\FileRWStream.h"
#include "ResourceManagement\Streams\BasicStreams\FileWStream.h"
#include "ResourceManagement\Streams\BasicStreams\MemRWStream.h"

#include "ResourceManagement\Streams\WrapperStreams\LZHRStream.h"
#include "ResourceManagement\Streams\WrapperStreams\LZHWStream.h"
#include "ResourceManagement\Streams\WrapperStreams\LZRStream.h"
#include "ResourceManagement\Streams\WrapperStreams\LZWStream.h"
#include "ResourceManagement\Streams\WrapperStreams\RLERStream.h"
#include "ResourceManagement\Streams\WrapperStreams\RLEWStream.h"

#include "ResourceManagement\Streams\VBlkStreams\VBlkRWStream.h"
#include "ResourceManagement\Streams\VBlkStreams\HeaderVBlkRWStream.h"

#include "ResourceManagement\Streams\VolFileStreams\VolFileRStream.h"
#include "ResourceManagement\Streams\VolFileStreams\VolFileWStream.h"


#include "UserInterface\Graphics\Font.h"
#include "UserInterface\Graphics\GFXSurface.h"
#include "UserInterface\Graphics\GFXSurfaceGFXCDSSurface.h"
#include "UserInterface\Graphics\GFXSurfaceGFXCDSSurfaceGFXClippedSurface.h"
#include "UserInterface\Graphics\GFXSurfaceGFXMemSurface.h"

#include "UserInterface\IWnd\IWnd.h"
#include "UserInterface\IWnd\IWndTFrame.h"
#include "UserInterface\IWnd\IWndTFrameDans_RULE_UIFrame.h"
#include "UserInterface\IWnd\IWndIDlgWnd.h"
#include "UserInterface\IWnd\IWndIDlgWndMessageBoxWnd.h"
#include "UserInterface\IWnd\IWndIDlgWndMultiplayerPreGameSetupWnd.h"
#include "UserInterface\IWnd\IWndPane.h"
#include "UserInterface\IWnd\IWndPaneCommand.h"
#include "UserInterface\IWnd\IWndPaneDetail.h"
#include "UserInterface\IWnd\IWndPaneMiniMap.h"

#include "UserInterface\CommandPaneView\CommandPaneView.h"
#include "UserInterface\CommandPaneView\ReportView.h"

#include "UserInterface\CommandPaneView\Views\BuildingStorageBayView.h"
#include "UserInterface\CommandPaneView\Views\UnitView.h"

#include "UserInterface\CommandPaneView\ReportViews\LabReportView.h"

#include "UserInterface\UIElement\UIElement.h"
#include "UserInterface\UIElement\UIElementButton.h"
#include "UserInterface\UIElement\UIElementButtonGraphicalButton.h"
#include "UserInterface\UIElement\UIElementButtonGraphicalButtonBayButton.h"
#include "UserInterface\UIElement\UIElementButtonGraphicalButtonMiscButton.h"
#include "UserInterface\UIElement\UIElementButtonGraphicalButtonUICommandButton.h"
#include "UserInterface\UIElement\UIElementButtonGraphicalButtonViewButton.h"
#include "UserInterface\UIElement\UIElementButtonGraphicalButtonViewButtonBuildButton.h"
#include "UserInterface\UIElement\UIElementButtonGraphicalButtonViewButtonReportPageButton.h"
#include "UserInterface\UIElement\UIElementListBox.h"

#include "UserInterface\UICommand\UICommand.h"
#include "UserInterface\UICommand\UICommandMouseCommand.h"

#include "UserInterface\UICommand\Commands\CommandProduce.h"

#include "UserInterface\UICommand\MouseCommands\CommandAttack.h"
#include "UserInterface\UICommand\MouseCommands\CommandBuild.h"

#include "UserInterface\Filter\FilterNode.h"
#include "UserInterface\Filter\Filter.h"
#include "UserInterface\Filter\FilterSubFilter.h"
#include "UserInterface\Filter\FilterSubFilterMouseCommandFilter.h"
#include "UserInterface\Filter\FilterGroupFilter.h"
#include "UserInterface\Filter\FilterGroupFilterDetailPaneFilter.h"
#include "UserInterface\Filter\FilterHotKeyFilter.h"
#include "UserInterface\Filter\FilterUIElementFilter.h"


#include "Game\TethysGame.h"
#include "Game\Player.h"
#include "Game\CommandPacket.h"
#include "Game\TApp.h"
#include "Game\Map.h"
#include "Game\LevelDLL.h"
#include "Game\Sheet.h"
#include "Game\Unit\Unit.h"
#include "Game\Unit\UnitVehicle.h"
#include "Game\Unit\UnitBuilding.h"
#include "Game\Unit\UnitWeapon.h"
#include "Game\UnitTypeInfo\UnitTypeInfo.h"
#include "Game\UnitTypeInfo\UnitTypeInfoVehicle.h"
#include "Game\UnitTypeInfo\UnitTypeInfoBuilding.h"
#include "Game\UnitTypeInfo\UnitTypeInfoWeapon.h"
#include "Game\Research.h"
#include "Game\RandomNumberGenerator.h"



namespace OP2ForcedExport
{
	int scr_snprintf(char* dest, unsigned int bufferSize, char const * format, ...);


	// Operators New/Delete
	// --------------------
	// [stdcall]
	//void* MemAlloc(int numBytesToAlloc);								// 0x004C0F40
	//void Free(void* memToFree);										// 0x004C0F30
	// [cdecl]
	// void* __cdecl __nh_malloc(int numBytesToAlloc, int flags);		// 0x004C2210
	// void* malloc(int numBytesToAlloc);								// 0x004C21F0
	// void __cdecl _free(void* memToFree);								// 0x004C1380
	// [cdecl]


}	// End namespace


#endif

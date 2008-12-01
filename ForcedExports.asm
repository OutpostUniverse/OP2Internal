[BITS 32]

; -------------------------------------------------------------------
; This file is the little bit of magic glue that makes this all work.
; It defines the symbols for the "missing" class members and global
; variables, which are defined in the header files, but actually
; exist within Outpost2.exe
; -------------------------------------------------------------------


; ** IMPORTANT **
; You must set the following to the load address of the DLL
; to ensure proper linking to the functions in Outpost2.exe
; *********************
LoadAddr EQU 0x14020000
; *********************


; ---------------------
; Allow for sanity checking in DLLMain
section .data
global _desiredLoadAddress
_desiredLoadAddress DD LoadAddr
; ---------------------



; Macros to make the exporting easier
; ***********************************

%macro	Export 2
	global %2
	section .data
	%2 EQU %1-LoadAddr
%endmacro

%macro	ExportData 2
	global %2
	section .data
	%2 EQU %1
%endmacro

%macro	ExportVirt 2
	global %2
	section .data
	%2 EQU %1
%endmacro



;  | *********************  |
;  | ** Here be Dragons **  |
; \/ ********************* \/


; Forced Exports from Outpost2.exe
; ********************************


; ****************
; ****************
; Global functions
; ****************
; ****************

Export 0x00475930, ?scr_snprintf@OP2ForcedExport@@YAHPADIPBDZZ


; **********************
; **********************
; Class Member Functions
; **********************
; **********************


; **************
; User Interface
; **************


; IWnd
; ----
; Virtual member functions
ExportVirt 0x004314D0, ?RegisterClassA@IWnd@OP2ForcedExport@@EAEPBDXZ
;ExportVirt 0x00431E20, ??1IWnd@OP2ForcedExport@@UAE@XZ
ExportVirt 0x004318A0, ?Destroy@IWnd@OP2ForcedExport@@UAEXXZ
ExportVirt 0x004315D0, ?CreateEx@IWnd@OP2ForcedExport@@UAEHKPBDKHHHHPAUHWND__@@PAUHMENU__@@PAXPAUHINSTANCE__@@@Z
ExportVirt 0x004316B0, ?WndProc@IWnd@OP2ForcedExport@@UAEJIIJ@Z
ExportVirt 0x00431740, ?CallFilters@IWnd@OP2ForcedExport@@UAEHIIJ@Z
; Constructor/Destructor
Export 0x00431310, ??0IWnd@OP2ForcedExport@@QAE@XZ
Export 0x00431330, ??1IWnd@OP2ForcedExport@@UAE@XZ
; Other member functions
Export 0x004314A0, ?FindNode@IWnd@OP2ForcedExport@@QAEPAVFilterNode@2@PAVFilter@2@H@Z
Export 0x00431380, ?InstallFilter@IWnd@OP2ForcedExport@@QAEXPAVFilter@2@HW4FilterPositions@2@W4FilterOptions@2@@Z
Export 0x00431420, ?RemoveFilter@IWnd@OP2ForcedExport@@QAEXPAVFilter@2@H@Z



; IWnd:IDlgWnd
; ------------
; Virtual member functions
;ExportVirt 0x00431ED0, ??1IDlgWnd@OP2ForcedExport@@UAE@XZ
ExportVirt 0x00431A80, ?DoModal@IDlgWnd@OP2ForcedExport@@UAEHPBDPAUHINSTANCE__@@@Z
ExportVirt 0x00431BF0, ?DoModeless@IDlgWnd@OP2ForcedExport@@UAEHPBDPAUHINSTANCE__@@PAUHWND__@@@Z
ExportVirt 0x00431DB0, ?DlgProc@IDlgWnd@OP2ForcedExport@@UAEHIIJ@Z
; Constructor/Destructor
Export 0x004318B0, ??0IDlgWnd@OP2ForcedExport@@QAE@XZ
Export 0x004318D0, ??1IDlgWnd@OP2ForcedExport@@UAE@XZ

; Global IWnd:IDlgWnd helper function
Export 0x0041E0E0, ?MsgBox@OP2ForcedExport@@YIHPAUHWND__@@PBD1H@Z



; IWnd:IDlgWnd:MultiplayerPreGameSetupWnd
; ---------------------------------------
; Virtual member functions
ExportVirt 0x0045F080, ??_EMultiplayerPreGameSetupWnd@OP2ForcedExport@@UAEPAXI@Z
ExportVirt 0x00460BC0, ?DlgProc@MultiplayerPreGameSetupWnd@OP2ForcedExport@@UAEHIIJ@Z
; Constructor/Destructor
Export 0x0045F050, ??0MultiplayerPreGameSetupWnd@OP2ForcedExport@@QAE@XZ
; Member functions
Export 0x0045F0D0, ?ShowHostGame@MultiplayerPreGameSetupWnd@OP2ForcedExport@@QAE_NPAUHostGameParameters@2@@Z
Export 0x0045F2F0, ?ShowJoinGame@MultiplayerPreGameSetupWnd@OP2ForcedExport@@QAE_NPADH_N@Z



; IWnd:Pane
; ---------
; Virtual member functions
ExportVirt 0x0049CE20, ??1Pane@OP2ForcedExport@@UAE@XZ
ExportVirt 0x0049CE60, ?WndProc@Pane@OP2ForcedExport@@UAEJIIJ@Z
ExportVirt 0x0049D010, ?ReleaseSurface@Pane@OP2ForcedExport@@UAEXXZ
ExportVirt 0x0049D030, ?ReallocSurface@Pane@OP2ForcedExport@@UAEXH@Z
ExportVirt 0x0049D120, ?Draw@Pane@OP2ForcedExport@@UAEXXZ
ExportVirt 0x00408950, ?F1@Pane@OP2ForcedExport@@UAEXXZ
ExportVirt 0x0045D290, ?GetAbsolutePos@Pane@OP2ForcedExport@@UAE_NHHPAVPoint@2@@Z
; Other member functions
Export 0x0049D1A0, ?AddControl@Pane@OP2ForcedExport@@QAEXPAVUIElement@2@@Z
Export 0x0049D1C0, ?RemoveControl@Pane@OP2ForcedExport@@QAEXPAVUIElement@2@@Z
Export 0x0049D220, ?SetNumControls@Pane@OP2ForcedExport@@QAEXH@Z
Export 0x0049D130, ?GetControlFromPos@Pane@OP2ForcedExport@@QAEPAVUIElement@2@HH@Z


; IWnd:Pane:DetailPane
; --------------------
; Virtual member functions
ExportVirt 0x00407810, ??1DetailPane@OP2ForcedExport@@UAE@XZ
ExportVirt 0x00407FA0, ?WndProc@DetailPane@OP2ForcedExport@@UAEJIIJ@Z
ExportVirt 0x00407A50, ?CallFilters@DetailPane@OP2ForcedExport@@UAEHIIJ@Z
ExportVirt 0x00407900, ?ReallocSurface@DetailPane@OP2ForcedExport@@UAEXH@Z
ExportVirt 0x00407E50, ?Draw@DetailPane@OP2ForcedExport@@UAEXXZ
ExportVirt 0x00408070, ?GetAbsolutePos@DetailPane@OP2ForcedExport@@UAE_NHHPAUPoint@2@@Z
ExportVirt 0x004080E0, ?GetViewportRelativePos@DetailPane@OP2ForcedExport@@UAEXHHPAUPoint@2@@Z
ExportVirt 0x00408370, ?GetViewportTilePositionAndSize@DetailPane@OP2ForcedExport@@UAEXPAUPoint@2@0@Z
; Other member functions
Export 0x004082F0, ?GetViewCenter@DetailPane@OP2ForcedExport@@QAEXPAUPoint@2@@Z


; IWnd:Pane:CommandPane
; ---------------------
; Virtual member functions
ExportVirt 0x0045C860, ??1CommandPane@OP2ForcedExport@@UAE@XZ
ExportVirt 0x0045C970, ?WndProc@CommandPane@OP2ForcedExport@@UAEJIIJ@Z
ExportVirt 0x0045CC60, ?ReallocSurface@CommandPane@OP2ForcedExport@@UAEXH@Z
ExportVirt 0x0045CCE0, ?Draw@CommandPane@OP2ForcedExport@@UAEXXZ
ExportVirt 0x0045CF30, ?MarkRectToRedraw@CommandPane@OP2ForcedExport@@UAEXPAURect@2@@Z
ExportVirt 0x0045CE30, ?DrawBackBuffer@CommandPane@OP2ForcedExport@@UAEXPAURect@2@@Z
; Other member functions
Export 0x0045D160, ?SetNewView@CommandPane@OP2ForcedExport@@QAEXPAVCommandPaneView@2@@Z
Export 0x0045CD70, ?UpdateUnitSelection@CommandPane@OP2ForcedExport@@QAEXXZ



; UIElement
; ---------
; Virtual member functions
;ExportVirt 0x0040A770, ?Release@UIElement@OP2ForcedExport@@UAEXH@Z
ExportVirt 0x0040B580, ?Draw@UIElement@OP2ForcedExport@@UAEXPAVGFXClippedSurface@2@@Z
ExportVirt 0x0040B590, ?OnUIEvent@UIElement@OP2ForcedExport@@UAEHPAVIWnd@2@IIJ@Z
ExportVirt 0x0040A7E0, ?OnAdd@UIElement@OP2ForcedExport@@UAEXPAVIWnd@2@@Z
ExportVirt 0x0040A7F0, ?OnRemove@UIElement@OP2ForcedExport@@UAEXPAVIWnd@2@@Z
ExportVirt 0x0040B5A0, ?SetEnabledState@UIElement@OP2ForcedExport@@UAEX_N@Z
ExportVirt 0x0040A830, ?InvalidateRect@UIElement@OP2ForcedExport@@UAEXPAVIWnd@2@@Z
; Constructor/Destructor
Export 0x0040A760, ??0UIElement@OP2ForcedExport@@QAE@XZ
Export 0x0040A790, ??1UIElement@OP2ForcedExport@@UAE@XZ
; Other member functions
Export 0x0040A7A0, ?SetCapture@UIElement@OP2ForcedExport@@QAEXPAVIWnd@2@@Z
Export 0x0040A7C0, ?ReleaseCapture@UIElement@OP2ForcedExport@@QAEXPAVIWnd@2@@Z
Export 0x0040A880, ?SetFlagsState@UIElement@OP2ForcedExport@@QAEXH_N@Z


; UIElement:Button
; ----------------
; Virtual member functions
;ExportVirt 0x0040A8F0, ?Release@Button@OP2ForcedExport@@UAEXH@Z
ExportVirt 0x0040AA50, ?OnUIEvent@Button@OP2ForcedExport@@UAEHPAVIWnd@2@IIJ@Z
ExportVirt 0x0040A920, ?OnAdd@Button@OP2ForcedExport@@UAEXPAVIWnd@2@@Z
ExportVirt 0x0040A950, ?OnRemove@Button@OP2ForcedExport@@UAEXPAVIWnd@2@@Z
ExportVirt 0x0040A9B0, ?SetEnabledState@Button@OP2ForcedExport@@UAEX_N@Z
; Constructor/Destructor
Export 0x0040A8D0, ??0Button@OP2ForcedExport@@QAE@XZ
Export 0x0040A910, ??1Button@OP2ForcedExport@@UAE@XZ
; Other member functions
Export 0x0040A9F0, ?SetHotKey@Button@OP2ForcedExport@@QAEXH@Z


; UIElement:Button:GraphicalButton
; --------------------------------
; Virtual member functions
;ExportVirt 0x004666D0, ?Release@GraphicalButton@OP2ForcedExport@@UAEXH@Z
ExportVirt 0x0040AFD0, ?Draw@GraphicalButton@OP2ForcedExport@@UAEXPAVGFXClippedSurface@2@@Z
ExportVirt 0x0040B2B0, ?GetHelpText@GraphicalButton@OP2ForcedExport@@UAEXPADH@Z
; Constructor/Destructor
Export 0x004666B0, ??0GraphicalButton@OP2ForcedExport@@QAE@XZ
Export 0x004666F0, ??1GraphicalButton@OP2ForcedExport@@UAE@XZ
; Other member functions
Export 0x0040AF40, ?SetDisplayInfo@GraphicalButton@OP2ForcedExport@@QAEXPAUButtonDisplayInfo@2@HHH@Z
Export 0x0040AD70, ?SetDisplayInfo@GraphicalButton@OP2ForcedExport@@QAEXPAUButtonDisplayInfo@2@PAURect@2@H@Z


; UIElement:Button:GraphicalButton:BayButton
; ------------------------------------------
; Virtual member functions
;ExportVirt 0x00462C30, ?Release@BayButton@OP2ForcedExport@@UAEXH@Z
ExportVirt 0x00462940, ?GetHelpText@BayButton@OP2ForcedExport@@UAEXPADH@Z
ExportVirt 0x004627C0, ?OnClick@BayButton@OP2ForcedExport@@UAEXXZ


; UIElement:Button:GraphicalButton:UICommandButton
; ------------------------------------------------
; Virtual member functions
;ExportVirt 0x00459EF0, ??1UICommandButton@OP2ForcedExport@@UAE@XZ
ExportVirt 0x00458E00, ?OnClick@UICommandButton@OP2ForcedExport@@UAEXXZ
; Constructor/Destructor
Export 0x459EC0, ??0UICommandButton@OP2ForcedExport@@QAE@XZ


; UIElement:Button:GraphicalButton:ViewButton
; -------------------------------------------
; Virtual member functions
;ExportVirt 0x0045C5D0, ?Release@ViewButton@OP2ForcedExport@@UAEXH@Z
ExportVirt 0x0045C760, ?OnClick@ViewButton@OP2ForcedExport@@UAEXXZ
ExportVirt 0x0045C7F0, ?F1@ViewButton@OP2ForcedExport@@UAEXXZ
; Constructor/Destructor
Export 0x0045D2A0, ??0ViewButton@OP2ForcedExport@@QAE@XZ
Export 0x0045D2D0, ??1ViewButton@OP2ForcedExport@@UAE@XZ

; Useful related global/static function
Export 0x00458E50, ?AddButtons@OP2ForcedExport@@YAXPAVCommandPaneView@1@HZZ


; UIElement:Button:GraphicalButton:ViewButton:ReportPageButton
; ------------------------------------------------------------
; Virtual member functions
;ExportVirt 0x0045A090, ?Release@ReportPageButton@OP2ForcedExport@@UAEXH@Z
ExportVirt 0x0045C5A0, ?OnClick@ReportPageButton@OP2ForcedExport@@UAEXXZ

; UIElement:Button:GraphicalButton:ViewButton:BuildButton
; -------------------------------------------------------
; Virtual member functions
;ExportVirt 0x00468100, ?Release@BuildButton@OP2ForcedExport@@UAEXH@Z
ExportVirt 0x00467E80, ?OnClick@BuildButton@OP2ForcedExport@@UAEXXZ

; UIElement:Button:GraphicalButton:MiniMapButton
; ----------------------------------------------
; Virtual member functions
;ExportVirt 0x00458430, ?Release@MiniMapButton@OP2ForcedExport@@UAEXH@Z
ExportVirt 0x00458360, ?OnClick@MiniMapButton@OP2ForcedExport@@UAEXXZ



; UIElement:Button:GraphicalButton:MiniMapButton
; ----------------------------------------------
; Virtual member functions
ExportVirt 0x00459F10, ?UpdateView@CommandPaneView@OP2ForcedExport@@UAEXXZ
ExportVirt 0x00459F20, ?OnAddView@CommandPaneView@OP2ForcedExport@@UAEXXZ
ExportVirt 0x00459F30, ?OnRemoveView@CommandPaneView@OP2ForcedExport@@UAEXXZ
ExportVirt 0x00459F40, ?IsNewView@CommandPaneView@OP2ForcedExport@@UAE_NXZ
ExportVirt 0x00459F50, ?SetReportPageIndex@CommandPaneView@OP2ForcedExport@@UAEXXZ
ExportVirt 0x00459F60, ?DoesUnitSelectionChangeCauseUpdate@CommandPaneView@OP2ForcedExport@@UAE_NXZ
ExportVirt 0x0046D960, ?OnAction@CommandPaneView@OP2ForcedExport@@UAEXXZ
ExportVirt 0x00459F70, ?GetSelectedReportButtonIndex@CommandPaneView@OP2ForcedExport@@UAEHXZ



; Filter
; ------
; Virtual member functions
;ExportVirt 0x00483CA0, 
; Constructor
Export 0x00483CB0, ??0Filter@OP2ForcedExport@@QAE@XZ
; Other Member functions



; Filter:SubFilter:MouseCommandFilter
; -----------------------------------
; Virtual member functions
; Other Member functions
Export 0x0041B670, ?SetMouseCommand@MouseCommandFilter@OP2ForcedExport@@QAEXW4BehaviorType@2@PAVMouseCommand@2@HHH@Z


; Filter:HoyKeyFilter
; -------------------
; Virtual member functions
;ExportVirt 0x0040A710, 
; Other Member functions
Export 0x0040A6A0, ?SetHotKeyButton@HotKeyFilter@OP2ForcedExport@@QAE_NPAVUIElement@2@H@Z
Export 0x0040A6D0, ?RemoveHotKey@HotKeyFilter@OP2ForcedExport@@QAEXH@Z
Export 0x0040A6E0, ?SetPauseCount@HotKeyFilter@OP2ForcedExport@@QAEH_N@Z


; Font
; ----
; Virtual member functions
;ExportVirt 0x415CB0, ??_EFont@OP2ForcedExport@@UAE@XZ
ExportVirt 0x415F60, ?GetTextSize@Font@OP2ForcedExport@@UAEPAUSize@2@PAU32@PADH@Z
; Constructor/Destructor
Export 0x415C80, ??0Font@OP2ForcedExport@@QAE@XZ
Export 0x415CF0, ??1Font@OP2ForcedExport@@UAE@XZ
; Member functions


; *******************
; Resource Management
; *******************


; SoundEffectsManager
; -------------------
; Member functions
Export 0x0047EFD0, ?AddGameSound@SoundEffectsManager@OP2ForcedExport@@QAEXHH@Z



; CConfig
; -------
; Member functions
Export 0x004108B0, ?GetString@CConfig@OP2ForcedExport@@QAEHPBD0PADI0@Z
Export 0x00410890, ?SetString@CConfig@OP2ForcedExport@@QAEHPBD00@Z
Export 0x00410870, ?GetInt@CConfig@OP2ForcedExport@@QAEHPBD0H@Z
Export 0x00410830, ?SetInt@CConfig@OP2ForcedExport@@QAEHPBD0H@Z




; Global resource management functions
; ------------------------------------
Export 0x0047C380, ?GetPlayerName@OP2ForcedExport@@YIXPAD_N@Z



; ****
; Game
; ****


; TApp
; ----
; Member functions
Export 0x00487E30, ?NetShutdown@TApp@OP2ForcedExport@@QAEHH@Z



; TethysGame
; ----------
; Member functions
Export 0x004893B0, ?StartGame@TethysGame@OP2ForcedExport@@QAE_NPAUGameStartInfo@2@@Z
; Static functions
Export 0x00478710, ?AddMessage@TethysGame@OP2ForcedExport@@SIXHHPBDHH@Z



; Player
; ------
; Member functions
Export 0x00490810, ?GetNextCommandPacketAddress@Player@OP2ForcedExport@@QAEPAUCommandPacket@2@XZ
Export 0x0040E300, ?ProcessCommandPacket@Player@OP2ForcedExport@@QAEXPAUCommandPacket@2@@Z



; Sheet
; -----
; Member functions
Export 0x004467C0, ?CreateUnit@Sheet@OP2ForcedExport@@QAEPAVUnit@2@W4map_id@2@HHH0H_N@Z



; Research
; --------
; Member functions
Export 0x00472D90, ?GetTechNum@Research@OP2ForcedExport@@QAEHH@Z
Export 0x00472D10, ?HasTech@Research@OP2ForcedExport@@QAE_NHH@Z
Export 0x004733C0, ?CanResearchTech@Research@OP2ForcedExport@@QAE_NHH@Z
Export 0x004738F0, ?MarkResearchComplete@Research@OP2ForcedExport@@QAEXHH@Z
Export 0x00473030, ?SetTechLevel@Research@OP2ForcedExport@@QAEXHH@Z
Export 0x00472E40, ?GiveClosureOfTech@Research@OP2ForcedExport@@QAEXHH@Z
Export 0x00473920, ?GiveTechUpgrades@Research@OP2ForcedExport@@QAEXHH@Z
Export 0x00473470, ?LoadAndProcessTechFile@Research@OP2ForcedExport@@QAEXPBDH@Z
Export 0x00472940, ?LoadTechFile@Research@OP2ForcedExport@@QAEXPBDH@Z
Export 0x00473700, ?SaveStartState@Research@OP2ForcedExport@@QAE_NPAUGameStartInfo@2@@Z
Export 0x00473830, ?LoadStartState@Research@OP2ForcedExport@@QAE_NPAUGameStartInfo@2@@Z
Export 0x00473580, ?Save@Research@OP2ForcedExport@@QAE_NPAVStreamIO@2@@Z
Export 0x00473630, ?Load@Research@OP2ForcedExport@@QAE_NPAVStreamIO@2@@Z
Export 0x00472CF0, ?GiveInitialTechs@Research@OP2ForcedExport@@QAEXXZ
Export 0x00472FF0, ?Checksum@Research@OP2ForcedExport@@QAEHXZ



; RandomNumberGenerator
; ---------------------
; Member functions
Export 0x0046F000, ?Rand@RandomNumberGenerator@OP2ForcedExport@@QAEHXZ
Export 0x0046F060, ?Rand@RandomNumberGenerator@OP2ForcedExport@@QAEHH@Z
Export 0x0046EFB0, ?SetSeed@RandomNumberGenerator@OP2ForcedExport@@QAEXH@Z
Export 0x0046EFF0, ?SetSeed@RandomNumberGenerator@OP2ForcedExport@@QAEXKK@Z
Export 0x0046EF90, ?GetSeed@RandomNumberGenerator@OP2ForcedExport@@QAEXPAK0@Z



; *******
; Network
; *******


; NetTransportLayer
; -----------------
; Vritual member functions
;ExportVirt 0x00412BC0, ??1NetTransportLayer@OP2ForcedExport@@UAE@XZ
;Export 0x00412BC0, ??1NetTransportLayer@OP2ForcedExport@@UAE@XZ



; GurManager
; ----------
; Member functions
Export 0x0042D710, ??0GurManager@OP2ForcedExport@@QAE@XZ
Export 0x0042D760, ?Initialize@GurManager@OP2ForcedExport@@QAEHPAVNetTransportLayer@2@@Z
; Operator New/Delete  (must use heap from exe)
Export 0x004C21F0, ??2GurManager@OP2ForcedExport@@SAPAXI@Z		; operator New
Export 0x004C1380, ??3GurManager@OP2ForcedExport@@SAXPAX@Z		; operator Delete



; Packet
; ------
; Member functions
Export 0x00490F10, ?Checksum@Packet@OP2ForcedExport@@QAEHXZ




; *********************
; *********************
; Global Data Variables
; *********************
; *********************


; User Interface
; --------------
ExportData 0x005756C0, ?dansFrame@OP2ForcedExport@@3VDans_RULE_UIFrame@1@A
ExportData 0x005471B0, ?mouseCommandFilter@OP2ForcedExport@@3VMouseCommandFilter@1@A
ExportData 0x0056EA08, ?mouseCursorTable@OP2ForcedExport@@3PAPAUHICON__@@A
ExportData 0x00546BB0, ?hotKeyFilter@OP2ForcedExport@@3VHotKeyFilter@1@A
ExportData 0x00546BA8, ?controlFilter@OP2ForcedExport@@3VUIElementFilter@1@A


; Resource Management
; -------------------
ExportData 0x0056D250, ?soundEffectsManager@OP2ForcedExport@@3VSoundEffectsManager@1@A
ExportData 0x00547090, ?config@OP2ForcedExport@@3VCConfig@1@A

; Game
; ----
ExportData 0x0056E868, ?app@OP2ForcedExport@@3VTApp@1@A
ExportData 0x0056EA98, ?tethysGame@OP2ForcedExport@@3VTethysGame@1@A
ExportData 0x0054F7F8, ?map@OP2ForcedExport@@3VMap@1@A
ExportData 0x0055B780, ?sheet@OP2ForcedExport@@3VSheet@1@A
ExportData 0x0056C230, ?research@OP2ForcedExport@@3VResearch@1@A
ExportData 0x0056BE20, ?randNumGen@OP2ForcedExport@@3VRandomNumberGenerator@1@A
ExportData 0x00574428, ?thorsNumGen@OP2ForcedExport@@3VRandomNumberGenerator@1@A
ExportData 0x004E1348, ?unitTypeInfo@OP2ForcedExport@@3PAPAVUnitTypeInfo@1@A


; Network
; -------
ExportData 0x004D6450, ?protocolNameLookupTable@OP2ForcedExport@@3PAPAVNetGameProtocol@1@A
ExportData 0x004DF380, ?protocolList@OP2ForcedExport@@3PAUProtocolEntry@1@A
ExportData 0x004E9B18, ?gameIdentifier@OP2ForcedExport@@3U_GUID@@A


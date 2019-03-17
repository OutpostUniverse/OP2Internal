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
LoadAddr EQU 0x14000000
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

Export 0x00475930, ?scr_snprintf@OP2Internal@@YAHPADIPBDZZ


; **********************
; **********************
; Class Member Functions
; **********************
; **********************


; **************
; User Interface
; **************


; GFXClippedSurface
; -----------------
; Member functions
Export 0x0041EFF0, ?DrawLine@GFXClippedSurface@OP2Internal@@QAEXAAUPoint@2@0H@Z
; Global functions
Export 0x0040B2F0, ?DrawBorder@OP2Internal@@YIXAAVGFXClippedSurface@1@AAURect@1@FFH@Z
Export 0x0040B4D0, ?DrawBox@OP2Internal@@YIXPAVGFXClippedSurface@1@PAURect@1@F@Z
Export 0x0045C3A0, ?DrawHpBar@OP2Internal@@YIXPAURect@1@PAVGFXClippedSurface@1@HHFFHFHF@Z


; IWnd
; ----
; Virtual member functions
ExportVirt 0x004314D0, ?RegisterClassA@IWnd@OP2Internal@@EAEPBDXZ
;ExportVirt 0x00431E20, ??1IWnd@OP2Internal@@UAE@XZ
ExportVirt 0x004318A0, ?Destroy@IWnd@OP2Internal@@UAEXXZ
ExportVirt 0x004315D0, ?CreateEx@IWnd@OP2Internal@@UAEHKPBDKHHHHPAUHWND__@@PAUHMENU__@@PAXPAUHINSTANCE__@@@Z
ExportVirt 0x004316B0, ?WndProc@IWnd@OP2Internal@@UAEJIIJ@Z
ExportVirt 0x00431740, ?CallFilters@IWnd@OP2Internal@@UAEHIIJ@Z
; Constructor/Destructor
Export 0x00431310, ??0IWnd@OP2Internal@@QAE@XZ
Export 0x00431330, ??1IWnd@OP2Internal@@UAE@XZ
; Other member functions
Export 0x004314A0, ?FindNode@IWnd@OP2Internal@@QAEPAVFilterNode@2@PAVFilter@2@H@Z
Export 0x00431380, ?InstallFilter@IWnd@OP2Internal@@QAEXPAVFilter@2@HW4FilterPositions@2@W4FilterOptions@2@@Z
Export 0x00431420, ?RemoveFilter@IWnd@OP2Internal@@QAEXPAVFilter@2@H@Z



; IWnd:IDlgWnd
; ------------
; Virtual member functions
;ExportVirt 0x00431ED0, ??1IDlgWnd@OP2Internal@@UAE@XZ
ExportVirt 0x00431A80, ?DoModal@IDlgWnd@OP2Internal@@UAEHPBDPAUHINSTANCE__@@@Z
ExportVirt 0x00431BF0, ?DoModeless@IDlgWnd@OP2Internal@@UAEHPBDPAUHINSTANCE__@@PAUHWND__@@@Z
ExportVirt 0x00431DB0, ?DlgProc@IDlgWnd@OP2Internal@@UAEHIIJ@Z
; Constructor/Destructor
Export 0x004318B0, ??0IDlgWnd@OP2Internal@@QAE@XZ
Export 0x004318D0, ??1IDlgWnd@OP2Internal@@UAE@XZ

; Global IWnd:IDlgWnd helper function
Export 0x0041E0E0, ?MsgBox@OP2Internal@@YIHPAUHWND__@@PBD1H@Z



; IWnd:IDlgWnd:MultiplayerPreGameSetupWnd
; ---------------------------------------
; Virtual member functions
ExportVirt 0x0045F080, ??_EMultiplayerPreGameSetupWnd@OP2Internal@@UAEPAXI@Z
ExportVirt 0x00460BC0, ?DlgProc@MultiplayerPreGameSetupWnd@OP2Internal@@UAEHIIJ@Z
; Constructor/Destructor
Export 0x0045F050, ??0MultiplayerPreGameSetupWnd@OP2Internal@@QAE@XZ
; Member functions
Export 0x0045F0D0, ?ShowHostGame@MultiplayerPreGameSetupWnd@OP2Internal@@QAE_NAAUHostGameParameters@2@@Z
Export 0x0045F2F0, ?ShowJoinGame@MultiplayerPreGameSetupWnd@OP2Internal@@QAE_NPADH_N@Z



; IWnd:Pane
; ---------
; Virtual member functions
ExportVirt 0x0049CE20, ??1Pane@OP2Internal@@UAE@XZ
ExportVirt 0x0049CE60, ?WndProc@Pane@OP2Internal@@UAEJIIJ@Z
ExportVirt 0x0049D010, ?ReleaseSurface@Pane@OP2Internal@@UAEXXZ
ExportVirt 0x0049D030, ?ReallocSurface@Pane@OP2Internal@@UAEXH@Z
ExportVirt 0x0049D120, ?Draw@Pane@OP2Internal@@UAEXXZ
ExportVirt 0x00408950, ?F1@Pane@OP2Internal@@UAEXXZ
ExportVirt 0x0045D290, ?GetAbsolutePos@Pane@OP2Internal@@UAE_NHHPAVPoint@2@@Z
; Other member functions
Export 0x0049D1A0, ?AddControl@Pane@OP2Internal@@QAEXPAVUIElement@2@@Z
Export 0x0049D1C0, ?RemoveControl@Pane@OP2Internal@@QAEXPAVUIElement@2@@Z
Export 0x0049D220, ?SetNumControls@Pane@OP2Internal@@QAEXH@Z
Export 0x0049D130, ?GetControlFromPos@Pane@OP2Internal@@QAEPAVUIElement@2@HH@Z


; IWnd:Pane:DetailPane
; --------------------
; Virtual member functions
ExportVirt 0x00407810, ??1DetailPane@OP2Internal@@UAE@XZ
ExportVirt 0x00407FA0, ?WndProc@DetailPane@OP2Internal@@UAEJIIJ@Z
ExportVirt 0x00407A50, ?CallFilters@DetailPane@OP2Internal@@UAEHIIJ@Z
ExportVirt 0x00407900, ?ReallocSurface@DetailPane@OP2Internal@@UAEXH@Z
ExportVirt 0x00407E50, ?Draw@DetailPane@OP2Internal@@UAEXXZ
ExportVirt 0x00408070, ?GetAbsolutePos@DetailPane@OP2Internal@@UAE_NHHPAUPoint@2@@Z
ExportVirt 0x004080E0, ?GetViewportRelativePos@DetailPane@OP2Internal@@UAEXHHPAUPoint@2@@Z
ExportVirt 0x00408370, ?GetViewportTilePositionAndSize@DetailPane@OP2Internal@@UAEXPAUPoint@2@0@Z
; Other member functions
Export 0x004082F0, ?GetViewCenter@DetailPane@OP2Internal@@QAEXPAUPoint@2@@Z


; IWnd:Pane:CommandPane
; ---------------------
; Virtual member functions
ExportVirt 0x0045C860, ??1CommandPane@OP2Internal@@UAE@XZ
ExportVirt 0x0045C970, ?WndProc@CommandPane@OP2Internal@@UAEJIIJ@Z
ExportVirt 0x0045CC60, ?ReallocSurface@CommandPane@OP2Internal@@UAEXH@Z
ExportVirt 0x0045CCE0, ?Draw@CommandPane@OP2Internal@@UAEXXZ
ExportVirt 0x0045CF30, ?MarkRectToRedraw@CommandPane@OP2Internal@@UAEXPAURect@2@@Z
ExportVirt 0x0045CE30, ?DrawBackBuffer@CommandPane@OP2Internal@@UAEXPAURect@2@@Z
; Other member functions
Export 0x0045D160, ?SetNewView@CommandPane@OP2Internal@@QAEXPAVCommandPaneView@2@@Z
Export 0x0045CD70, ?UpdateUnitSelection@CommandPane@OP2Internal@@QAEXXZ



; UIElement
; ---------
; Virtual member functions
;ExportVirt 0x0040A770, ?Release@UIElement@OP2Internal@@UAEXH@Z
ExportVirt 0x0040B580, ?Draw@UIElement@OP2Internal@@UAEXPAVGFXClippedSurface@2@@Z
ExportVirt 0x0040B590, ?OnUIEvent@UIElement@OP2Internal@@UAEHPAVIWnd@2@IIJ@Z
ExportVirt 0x0040A7E0, ?OnAdd@UIElement@OP2Internal@@UAEXPAVIWnd@2@@Z
ExportVirt 0x0040A7F0, ?OnRemove@UIElement@OP2Internal@@UAEXPAVIWnd@2@@Z
ExportVirt 0x0040B5A0, ?SetEnabledState@UIElement@OP2Internal@@UAEX_N@Z
ExportVirt 0x0040A830, ?InvalidateRect@UIElement@OP2Internal@@UAEXPAVIWnd@2@@Z
; Constructor/Destructor
Export 0x0040A760, ??0UIElement@OP2Internal@@QAE@XZ
Export 0x0040A790, ??1UIElement@OP2Internal@@UAE@XZ
; Other member functions
Export 0x0040A7A0, ?SetCapture@UIElement@OP2Internal@@QAEXPAVIWnd@2@@Z
Export 0x0040A7C0, ?ReleaseCapture@UIElement@OP2Internal@@QAEXPAVIWnd@2@@Z
Export 0x0040A880, ?SetFlagsState@UIElement@OP2Internal@@QAEXH_N@Z


; UIElement:Button
; ----------------
; Virtual member functions
;ExportVirt 0x0040A8F0, ?Release@Button@OP2Internal@@UAEXH@Z
ExportVirt 0x0040AA50, ?OnUIEvent@Button@OP2Internal@@UAEHPAVIWnd@2@IIJ@Z
ExportVirt 0x0040A920, ?OnAdd@Button@OP2Internal@@UAEXPAVIWnd@2@@Z
ExportVirt 0x0040A950, ?OnRemove@Button@OP2Internal@@UAEXPAVIWnd@2@@Z
ExportVirt 0x0040A9B0, ?SetEnabledState@Button@OP2Internal@@UAEX_N@Z
; Constructor/Destructor
Export 0x0040A8D0, ??0Button@OP2Internal@@QAE@XZ
Export 0x0040A910, ??1Button@OP2Internal@@UAE@XZ
; Other member functions
Export 0x0040A9F0, ?SetHotKey@Button@OP2Internal@@QAEXH@Z


; UIElement:Button:GraphicalButton
; --------------------------------
; Virtual member functions
;ExportVirt 0x004666D0, ?Release@GraphicalButton@OP2Internal@@UAEXH@Z
ExportVirt 0x0040AFD0, ?Draw@GraphicalButton@OP2Internal@@UAEXPAVGFXClippedSurface@2@@Z
ExportVirt 0x0040B2B0, ?GetHelpText@GraphicalButton@OP2Internal@@UAEXPADH@Z
; Constructor/Destructor
Export 0x004666B0, ??0GraphicalButton@OP2Internal@@QAE@XZ
Export 0x004666F0, ??1GraphicalButton@OP2Internal@@UAE@XZ
; Other member functions
Export 0x0040AF40, ?SetDisplayInfo@GraphicalButton@OP2Internal@@QAEXPAUButtonDisplayInfo@2@HHH@Z
Export 0x0040AD70, ?SetDisplayInfo@GraphicalButton@OP2Internal@@QAEXPAUButtonDisplayInfo@2@PAURect@2@H@Z


; UIElement:Button:GraphicalButton:BayButton
; ------------------------------------------
; Virtual member functions
;ExportVirt 0x00462C30, ?Release@BayButton@OP2Internal@@UAEXH@Z
ExportVirt 0x00462940, ?GetHelpText@BayButton@OP2Internal@@UAEXPADH@Z
ExportVirt 0x004627C0, ?OnClick@BayButton@OP2Internal@@UAEXXZ


; UIElement:Button:GraphicalButton:UICommandButton
; ------------------------------------------------
; Virtual member functions
;ExportVirt 0x00459EF0, ??1UICommandButton@OP2Internal@@UAE@XZ
ExportVirt 0x00458E00, ?OnClick@UICommandButton@OP2Internal@@UAEXXZ
; Constructor/Destructor
Export 0x459EC0, ??0UICommandButton@OP2Internal@@QAE@XZ


; UIElement:Button:GraphicalButton:ViewButton
; -------------------------------------------
; Virtual member functions
;ExportVirt 0x0045C5D0, ?Release@ViewButton@OP2Internal@@UAEXH@Z
ExportVirt 0x0045C760, ?OnClick@ViewButton@OP2Internal@@UAEXXZ
ExportVirt 0x0045C7F0, ?F1@ViewButton@OP2Internal@@UAEXXZ
; Constructor/Destructor
Export 0x0045D2A0, ??0ViewButton@OP2Internal@@QAE@XZ
Export 0x0045D2D0, ??1ViewButton@OP2Internal@@UAE@XZ

; Useful related global/static function
Export 0x00458E50, ?AddButtons@OP2Internal@@YAXPAVCommandPaneView@1@HZZ


; UIElement:Button:GraphicalButton:ViewButton:ReportPageButton
; ------------------------------------------------------------
; Virtual member functions
;ExportVirt 0x0045A090, ?Release@ReportPageButton@OP2Internal@@UAEXH@Z
ExportVirt 0x0045C5A0, ?OnClick@ReportPageButton@OP2Internal@@UAEXXZ

; UIElement:Button:GraphicalButton:ViewButton:BuildButton
; -------------------------------------------------------
; Virtual member functions
;ExportVirt 0x00468100, ?Release@BuildButton@OP2Internal@@UAEXH@Z
ExportVirt 0x00467E80, ?OnClick@BuildButton@OP2Internal@@UAEXXZ

; UIElement:Button:GraphicalButton:MiniMapButton
; ----------------------------------------------
; Virtual member functions
;ExportVirt 0x00458430, ?Release@MiniMapButton@OP2Internal@@UAEXH@Z
ExportVirt 0x00458360, ?OnClick@MiniMapButton@OP2Internal@@UAEXXZ



; UIElement:Button:GraphicalButton:MiniMapButton
; ----------------------------------------------
; Virtual member functions
ExportVirt 0x00459F10, ?UpdateView@CommandPaneView@OP2Internal@@UAEXXZ
ExportVirt 0x00459F20, ?OnAddView@CommandPaneView@OP2Internal@@UAEXXZ
ExportVirt 0x00459F30, ?OnRemoveView@CommandPaneView@OP2Internal@@UAEXXZ
ExportVirt 0x00459F40, ?IsNewView@CommandPaneView@OP2Internal@@UAE_NXZ
ExportVirt 0x00459F50, ?SetReportPageIndex@CommandPaneView@OP2Internal@@UAEXXZ
ExportVirt 0x00459F60, ?DoesUnitSelectionChangeCauseUpdate@CommandPaneView@OP2Internal@@UAE_NXZ
ExportVirt 0x0046D960, ?OnAction@CommandPaneView@OP2Internal@@UAEXXZ
ExportVirt 0x00459F70, ?GetSelectedReportButtonIndex@CommandPaneView@OP2Internal@@UAEHXZ



; UICommand:MouseCommand
; ----------------------
ExportVirt 0x00455C50, ?OnClick@MouseCommand@OP2Internal@@UAEXXZ
ExportVirt 0x00455C60, ?GetMouseCursor@MouseCommand@OP2Internal@@UAEHHHPAPAUHICON__@@@Z
ExportVirt 0x00455C70, ?GetBuildCursor@MouseCommand@OP2Internal@@UAEHHHHHPAPAUHICON__@@QAHPAVVehicle@2@@Z
ExportVirt 0x004512B0, ?OnCancel@MouseCommand@OP2Internal@@UAEXXZ
ExportVirt 0x004512D0, ?OnChangeCommand@MouseCommand@OP2Internal@@UAEXXZ
ExportVirt 0x00455C80, ?IsDefaultCommand@MouseCommand@OP2Internal@@UAEHHH@Z
ExportVirt 0x00455C90, ?GetCursor@MouseCommand@OP2Internal@@UAEPAUHICON__@@HH@Z



; Filter
; ------
; Virtual member functions
;ExportVirt 0x00483CA0, 
; Constructor
Export 0x00483CB0, ??0Filter@OP2Internal@@QAE@XZ
; Other Member functions



; Filter:SubFilter:MouseCommandFilter
; -----------------------------------
; Virtual member functions
; Other Member functions
Export 0x0041B670, ?SetMouseCommand@MouseCommandFilter@OP2Internal@@QAEXW4BehaviorType@2@PAVMouseCommand@2@HHH@Z
Export 0x0041B6D0, ?SetOverlaySize@MouseCommandFilter@OP2Internal@@QAEXHH@Z
Export 0x0041B6F0, ?GetHighlightRect@MouseCommandFilter@OP2Internal@@QAEXPAURect@2@@Z


; Filter:HoyKeyFilter
; -------------------
; Virtual member functions
;ExportVirt 0x0040A710, 
; Other Member functions
Export 0x0040A6A0, ?SetHotKeyButton@HotKeyFilter@OP2Internal@@QAE_NPAVUIElement@2@H@Z
Export 0x0040A6D0, ?RemoveHotKey@HotKeyFilter@OP2Internal@@QAEXH@Z
Export 0x0040A6E0, ?SetPauseCount@HotKeyFilter@OP2Internal@@QAEH_N@Z


; Font
; ----
; Virtual member functions
;ExportVirt 0x415CB0, ??_EFont@OP2Internal@@UAE@XZ
ExportVirt 0x415F60, ?GetTextSize@Font@OP2Internal@@UAEPAUSize@2@PAU32@PADH@Z
; Constructor/Destructor
Export 0x415C80, ??0Font@OP2Internal@@QAE@XZ
Export 0x415CF0, ??1Font@OP2Internal@@UAE@XZ
; Member functions


; *******************
; Resource Management
; *******************


; SoundEffectsManager
; -------------------
; Member functions
Export 0x0047EFD0, ?AddGameSound@SoundEffectsManager@OP2Internal@@QAEXHH@Z



; CConfig
; -------
; Member functions
Export 0x004108B0, ?GetString@CConfig@OP2Internal@@QAEHPBD0PADI0@Z
Export 0x00410890, ?SetString@CConfig@OP2Internal@@QAEHPBD00@Z
Export 0x00410870, ?GetInt@CConfig@OP2Internal@@QAEHPBD0H@Z
Export 0x00410830, ?SetInt@CConfig@OP2Internal@@QAEHPBD0H@Z




; Global resource management functions
; ------------------------------------
Export 0x0047C380, ?GetPlayerName@OP2Internal@@YIXPAD_N@Z



; ****
; Game
; ****


; TApp
; ----
; Member functions
Export 0x00487E30, ?NetShutdown@TApp@OP2Internal@@QAEXH@Z



; TethysGame
; ----------
; Member functions
Export 0x004893B0, ?StartGame@TethysGame@OP2Internal@@QAE_NPAUGameStartInfo@2@@Z
; Static functions
Export 0x00478710, ?AddMessage@TethysGame@OP2Internal@@SIXHHPBDHH@Z



; Map
; ---
; Member functions
; Global functions
Export 0x00438C80, ?IsBuildable@OP2Internal@@YIHHH@Z
Export 0x004383C0, ?IsTilePassable@OP2Internal@@YIHHH@Z
Export 0x00438B70, ?IsDockLocation@OP2Internal@@YIHHH@Z



; Player
; ------
; Member functions
Export 0x00490810, ?GetNextCommandPacketAddress@Player@OP2Internal@@QAEPAUCommandPacket@2@XZ
Export 0x0040E300, ?ProcessCommandPacket@Player@OP2Internal@@QAEXPAUCommandPacket@2@@Z



; Sheet
; -----
; Member functions
Export 0x004467C0, ?CreateUnit@Sheet@OP2Internal@@QAEPAVUnit@2@W4map_id@2@HHH0HH@Z



; Unit
; ----
; Member functions
Export 0x00438360, ?SetCurrentUnitAndTrackTypeAndAttackType@Vehicle@OP2Internal@@QAEXXZ



; Research
; --------
; Member functions
Export 0x00472D90, ?GetTechNum@Research@OP2Internal@@QAEHH@Z
Export 0x00472D10, ?HasTech@Research@OP2Internal@@QAE_NHH@Z
Export 0x004733C0, ?CanResearchTech@Research@OP2Internal@@QAE_NHH@Z
Export 0x004738F0, ?MarkResearchComplete@Research@OP2Internal@@QAEXHH@Z
Export 0x00473030, ?SetTechLevel@Research@OP2Internal@@QAEXHH@Z
Export 0x00472E40, ?GiveClosureOfTech@Research@OP2Internal@@QAEXHH@Z
Export 0x00473920, ?GiveTechUpgrades@Research@OP2Internal@@QAEXHH@Z
Export 0x00473470, ?LoadAndProcessTechFile@Research@OP2Internal@@QAEXPBDH@Z
Export 0x00472940, ?LoadTechFile@Research@OP2Internal@@QAEXPBDH@Z
Export 0x00473700, ?SaveStartState@Research@OP2Internal@@QAE_NPAUGameStartInfo@2@@Z
Export 0x00473830, ?LoadStartState@Research@OP2Internal@@QAE_NPAUGameStartInfo@2@@Z
Export 0x00473580, ?Save@Research@OP2Internal@@QAE_NPAVStreamIO@2@@Z
Export 0x00473630, ?Load@Research@OP2Internal@@QAE_NPAVStreamIO@2@@Z
Export 0x00472CF0, ?GiveInitialTechs@Research@OP2Internal@@QAEXXZ
Export 0x00472FF0, ?Checksum@Research@OP2Internal@@QAEHXZ



; RandomNumberGenerator
; ---------------------
; Member functions
Export 0x0046F000, ?Rand@RandomNumberGenerator@OP2Internal@@QAEHXZ
Export 0x0046F060, ?Rand@RandomNumberGenerator@OP2Internal@@QAEHH@Z
Export 0x0046EFB0, ?SetSeed@RandomNumberGenerator@OP2Internal@@QAEXH@Z
Export 0x0046EFF0, ?SetSeed@RandomNumberGenerator@OP2Internal@@QAEXKK@Z
Export 0x0046EF90, ?GetSeed@RandomNumberGenerator@OP2Internal@@QAEXPAK0@Z



; *******
; Network
; *******


; NetTransportLayer
; -----------------
; Vritual member functions
;ExportVirt 0x00412BC0, ??1NetTransportLayer@OP2Internal@@UAE@XZ
;Export 0x00412BC0, ??1NetTransportLayer@OP2Internal@@UAE@XZ



; GurManager
; ----------
; Member functions
Export 0x0042D710, ??0GurManager@OP2Internal@@QAE@XZ
Export 0x0042D760, ?Initialize@GurManager@OP2Internal@@QAEHPAVNetTransportLayer@2@@Z
; Operator New/Delete  (must use heap from exe)
Export 0x004C21F0, ??2GurManager@OP2Internal@@SAPAXI@Z		; operator New
Export 0x004C1380, ??3GurManager@OP2Internal@@SAXPAX@Z		; operator Delete



; Packet
; ------
; Member functions
Export 0x00490F10, ?Checksum@Packet@OP2Internal@@QBEHXZ




; *********************
; *********************
; Global Data Variables
; *********************
; *********************


; User Interface
; --------------
ExportData 0x005756C0, ?dansFrame@OP2Internal@@3VDans_RULE_UIFrame@1@A
ExportData 0x005471B0, ?mouseCommandFilter@OP2Internal@@3VMouseCommandFilter@1@A
ExportData 0x0056EA08, ?mouseCursorTable@OP2Internal@@3PAPAUHICON__@@A
ExportData 0x00546BB0, ?hotKeyFilter@OP2Internal@@3VHotKeyFilter@1@A
ExportData 0x00546BA8, ?controlFilter@OP2Internal@@3VUIElementFilter@1@A


; Resource Management
; -------------------
ExportData 0x0056D250, ?soundEffectsManager@OP2Internal@@3VSoundEffectsManager@1@A
ExportData 0x00547090, ?config@OP2Internal@@3VCConfig@1@A

; Game
; ----
ExportData 0x0056E868, ?app@OP2Internal@@3VTApp@1@A
ExportData 0x0056EA98, ?tethysGame@OP2Internal@@3VTethysGame@1@A
ExportData 0x0054F7F8, ?map@OP2Internal@@3VMap@1@A
ExportData 0x0055B780, ?sheet@OP2Internal@@3AAVSheet@1@A
ExportData 0x0056C230, ?research@OP2Internal@@3VResearch@1@A
ExportData 0x0056BE20, ?randNumGen@OP2Internal@@3VRandomNumberGenerator@1@A
ExportData 0x00574428, ?thorsNumGen@OP2Internal@@3VRandomNumberGenerator@1@A
ExportData 0x004E1348, ?unitTypeInfo@OP2Internal@@3PAPAVUnitTypeInfo@1@A
ExportData 0x004DEBA8, ?cellTypeInfo@OP2Internal@@3PAUCellTypeInfo@1@A


; Network
; -------
ExportData 0x004D6450, ?protocolNameLookupTable@OP2Internal@@3PAPAVNetGameProtocol@1@A
ExportData 0x004DF380, ?protocolList@OP2Internal@@3PAUProtocolEntry@1@A
ExportData 0x004E9B18, ?gameIdentifier@OP2Internal@@3U_GUID@@A


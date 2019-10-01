#pragma once




#ifdef _USE_MESSAGES_
///  Hex		Decimal		Symbolic									                                        
0000		0		WM_NULL										                                        
0001		1		WM_CREATE									                                        
0002		2		WM_DESTROY									                                        
0003		3		WM_MOVE										                                        
0005		5		WM_SIZE										                                        
0006		6		WM_ACTIVATE									                                        
0007		7		WM_SETFOCUS									                                        
0008		8		WM_KILLFOCUS								                                        
000a		10		WM_ENABLE									                                        
000b		11		WM_SETREDRAW								                                        
000c		12		WM_SETTEXT									                                        
000d		13		WM_GETTEXT									                                        
000e		14		WM_GETTEXTLENGTH							                                        
000f		15		WM_PAINT									                                        
0010		16		WM_CLOSE									                                        
0011		17		WM_QUERYENDSESSION							                                        
0012		18		WM_QUIT										                                        
0013		19		WM_QUERYOPEN								                                        
0014		20		WM_ERASEBKGND								                                        
0015		21		WM_SYSCOLORCHANGE							                                        
0016		22		WM_ENDSESSION								                                        
0018		24		WM_SHOWWINDOW								                                        
0019		25		WM_CTLCOLOR									                                        
001a		26		WM_WININICHANGE								                                        
001b		27		WM_DEVMODECHANGE							                                        
001c		28		WM_ACTIVATEAPP								                                        
001d		29		WM_FONTCHANGE								                                        
001e		30		WM_TIMECHANGE								                                        
001f		31		WM_CANCELMODE								                                        
0020		32		WM_SETCURSOR								                                        
0021		33		WM_MOUSEACTIVATE							                                        
0022		34		WM_CHILDACTIVATE							                                        
0023		35		WM_QUEUESYNC								                                        
0024		36		WM_GETMINMAXINFO							                                        
0026		38		WM_PAINTICON								                                        
0027		39		WM_ICONERASEBKGND							                                        
0028		40		WM_NEXTDLGCTL								                                        
002a		42		WM_SPOOLERSTATUS							                                        
002b		43		WM_DRAWITEM									                                        
002c		44		WM_MEASUREITEM								                                        
002d		45		WM_DELETEITEM								                                        
002e		46		WM_VKEYTOITEM								                                        
002f		47		WM_CHARTOITEM								                                        
0030		48		WM_SETFONT									                                        
0031		49		WM_GETFONT									                                        
0032		50		WM_SETHOTKEY								                                        
0033		51		WM_GETHOTKEY								                                        
0037		55		WM_QUERYDRAGICON							                                        
0039		57		WM_COMPAREITEM								                                        
003d		61		WM_GETOBJECT								                                        
0041		65		WM_COMPACTING								                                        
0044		68		WM_COMMNOTIFY								                                        
0046		70		WM_WINDOWPOSCHANGING						                                        
0047		71		WM_WINDOWPOSCHANGED							                                        
0048		72		WM_POWER									                                        
0049		73		WM_COPYGLOBALDATA							                                        
004a		74		WM_COPYDATA									                                        
004b		75		WM_CANCELJOURNAL							                                        
004e		78		WM_NOTIFY									                                        
0050		80		WM_INPUTLANGCHANGEREQUEST					                                        
0051		81		WM_INPUTLANGCHANGE							                                        
0052		82		WM_TCARD									                                        
0053		83		WM_HELP										                                        
0054		84		WM_USERCHANGED								                                        
0055		85		WM_NOTIFYFORMAT								                                        
007b		123		WM_CONTEXTMENU								                                        
007c		124		WM_STYLECHANGING							                                        
007d		125		WM_STYLECHANGED								                                        
007e		126		WM_DISPLAYCHANGE							                                        
007f		127		WM_GETICON									                                        
0080		128		WM_SETICON									                                        
0081		129		WM_NCCREATE									                                        
0082		130		WM_NCDESTROY								                                        
0083		131		WM_NCCALCSIZE								                                        
0084		132		WM_NCHITTEST								                                        
0085		133		WM_NCPAINT									                                        
0086		134		WM_NCACTIVATE								                                        
0087		135		WM_GETDLGCODE								                                        
0088		136		WM_SYNCPAINT								                                        
00a0		160		WM_NCMOUSEMOVE								                                        
00a1		161		WM_NCLBUTTONDOWN							                                        
00a2		162		WM_NCLBUTTONUP								                                        
00a3		163		WM_NCLBUTTONDBLCLK							                                        
00a4		164		WM_NCRBUTTONDOWN							                                        
00a5		165		WM_NCRBUTTONUP								                                        
00a6		166		WM_NCRBUTTONDBLCLK							                                        
00a7		167		WM_NCMBUTTONDOWN							                                        
00a8		168		WM_NCMBUTTONUP								                                        
00a9		169		WM_NCMBUTTONDBLCLK							                                        
00ab		171		WM_NCXBUTTONDOWN							                                        
00ac		172		WM_NCXBUTTONUP								                                        
00ad		173		WM_NCXBUTTONDBLCLK							                                        
00b0		176		EM_GETSEL									                                        
00b1		177		EM_SETSEL									                                        
00b2		178		EM_GETRECT									                                        
00b3		179		EM_SETRECT									                                        
00b4		180		EM_SETRECTNP								                                        
00b5		181		EM_SCROLL									                                        
00b6		182		EM_LINESCROLL								                                        
00b7		183		EM_SCROLLCARET								                                        
00b8		185		EM_GETMODIFY								                                        
00b9		187		EM_SETMODIFY								                                        
00ba		188		EM_GETLINECOUNT								                                        
00bb		189		EM_LINEINDEX								                                        
00bc		190		EM_SETHANDLE								                                        
00bd		191		EM_GETHANDLE								                                        
00be		192		EM_GETTHUMB									                                        
00c1		193		EM_LINELENGTH								                                        
00c2		194		EM_REPLACESEL								                                        
00c3		195		EM_SETFONT									                                        
00c4		196		EM_GETLINE									                                        
00c5		197		EM_LIMITTEXT								                                        
00c5		197		EM_SETLIMITTEXT								                                        
00c6		198		EM_CANUNDO									                                        
00c7		199		EM_UNDO										                                        
00c8		200		EM_FMTLINES									                                        
00c9		201		EM_LINEFROMCHAR								                                        
00ca		202		EM_SETWORDBREAK								                                        
00cb		203		EM_SETTABSTOPS								                                        
00cc		204		EM_SETPASSWORDCHAR							                                        
00cd		205		EM_EMPTYUNDOBUFFER							                                        
00ce		206		EM_GETFIRSTVISIBLELINE						                                        
00cf		207		EM_SETREADONLY								                                        
00d0		209		EM_SETWORDBREAKPROC							                                        
00d1		209		EM_GETWORDBREAKPROC							                                        
00d2		210		EM_GETPASSWORDCHAR							                                        
00d3		211		EM_SETMARGINS								                                        
00d4		212		EM_GETMARGINS								                                        
00d5		213		EM_GETLIMITTEXT								                                        
00d6		214		EM_POSFROMCHAR								                                        
00d7		215		EM_CHARFROMPOS								                                        
00d8		216		EM_SETIMESTATUS								                                        
00d9		217		EM_GETIMESTATUS								                                        
00e0		224		SBM_SETPOS									                                        
00e1		225		SBM_GETPOS									                                        
00e2		226		SBM_SETRANGE								                                        
00e3		227		SBM_GETRANGE								                                        
00e4		228		SBM_ENABLE_ARROWS							                                        
00e6		230		SBM_SETRANGEREDRAW							                                        
00e9		233		SBM_SETSCROLLINFO							                                        
00ea		234		SBM_GETSCROLLINFO							                                        
00eb		235		SBM_GETSCROLLBARINFO						                                        
00f0		240		BM_GETCHECK									                                        
00f1		241		BM_SETCHECK									                                        
00f2		242		BM_GETSTATE									                                        
00f3		243		BM_SETSTATE									                                        
00f4		244		BM_SETSTYLE									                                        
00f5		245		BM_CLICK									                                        
00f6		246		BM_GETIMAGE									                                        
00f7		247		BM_SETIMAGE									                                        
00f8		248		BM_SETDONTCLICK								                                        
00ff		255		WM_INPUT									                                        
0100		256		WM_KEYDOWN									                                        
0100		256		WM_KEYFIRST									                                        
0101		257		WM_KEYUP									                                        
0102		258		WM_CHAR										                                        
0103		259		WM_DEADCHAR									                                        
0104		260		WM_SYSKEYDOWN								                                        
0105		261		WM_SYSKEYUP									                                        
0106		262		WM_SYSCHAR									                                        
0107		263		WM_SYSDEADCHAR								                                        
0108		264		WM_KEYLAST									                                        
0109		265		WM_UNICHAR									                                        
0109		265		WM_WNT_CONVERTREQUESTEX						                                        
010a		266		WM_CONVERTREQUEST							                                        
010b		267		WM_CONVERTRESULT							                                        
010c		268		WM_INTERIM									                                        
010d		269		WM_IME_STARTCOMPOSITION						                                        
010e		270		WM_IME_ENDCOMPOSITION						                                        
010f		271		WM_IME_COMPOSITION							                                        
010f		271		WM_IME_KEYLAST								                                        
0110		272		WM_INITDIALOG								                                        
0111		273		WM_COMMAND									                                        
0112		274		WM_SYSCOMMAND								                                        
0113		275		WM_TIMER									                                        
0114		276		WM_HSCROLL									                                        
0115		277		WM_VSCROLL									                                        
0116		278		WM_INITMENU									                                        
0117		279		WM_INITMENUPOPUP							                                        
0118		280		WM_SYSTIMER									                                        
011f		287		WM_MENUSELECT								                                        
0120		288		WM_MENUCHAR									                                        
0121		289		WM_ENTERIDLE								                                        
0122		290		WM_MENURBUTTONUP							                                        
0123		291		WM_MENUDRAG									                                        
0124		292		WM_MENUGETOBJECT							                                        
0125		293		WM_UNINITMENUPOPUP							                                        
0126		294		WM_MENUCOMMAND								                                        
0127		295		WM_CHANGEUISTATE							                                        
0128		296		WM_UPDATEUISTATE							                                        
0129		297		WM_QUERYUISTATE								                                        
0132		306		WM_CTLCOLORMSGBOX							                                        
0133		307		WM_CTLCOLOREDIT								                                        
0134		308		WM_CTLCOLORLISTBOX							                                        
0135		309		WM_CTLCOLORBTN								                                        
0136		310		WM_CTLCOLORDLG								                                        
0137		311		WM_CTLCOLORSCROLLBAR						                                        
0138		312		WM_CTLCOLORSTATIC							                                        
0200		512		WM_MOUSEFIRST								                                        
0200		512		WM_MOUSEMOVE								                                        
0201		513		WM_LBUTTONDOWN								                                        
0202		514		WM_LBUTTONUP								                                        
0203		515		WM_LBUTTONDBLCLK							                                        
0204		516		WM_RBUTTONDOWN								                                        
0205		517		WM_RBUTTONUP								                                        
0206		518		WM_RBUTTONDBLCLK							                                        
0207		519		WM_MBUTTONDOWN								                                        
0208		520		WM_MBUTTONUP								                                        
0209		521		WM_MBUTTONDBLCLK							                                        
0209		521		WM_MOUSELAST								                                        
020a		522		WM_MOUSEWHEEL								                                        
020b		523		WM_XBUTTONDOWN								                                        
020c		524		WM_XBUTTONUP								                                        
020d		525		WM_XBUTTONDBLCLK							                                        
0210		528		WM_PARENTNOTIFY								                                        
0211		529		WM_ENTERMENULOOP							                                        
0212		530		WM_EXITMENULOOP								                                        
0213		531		WM_NEXTMENU									                                        
0214		532		WM_SIZING									                                        
0215		533		WM_CAPTURECHANGED							                                        
0216		534		WM_MOVING									                                        
0218		536		WM_POWERBROADCAST							                                        
0219		537		WM_DEVICECHANGE								                                        
0220		544		WM_MDICREATE								                                        
0221		545		WM_MDIDESTROY								                                        
0222		546		WM_MDIACTIVATE								                                        
0223		547		WM_MDIRESTORE								                                        
0224		548		WM_MDINEXT									                                        
0225		549		WM_MDIMAXIMIZE								                                        
0226		550		WM_MDITILE									                                        
0227		551		WM_MDICASCADE								                                        
0228		552		WM_MDIICONARRANGE							                                        
0229		553		WM_MDIGETACTIVE								                                        
0230		560		WM_MDISETMENU								                                        
0231		561		WM_ENTERSIZEMOVE							                                        
0232		562		WM_EXITSIZEMOVE								                                        
0233		563		WM_DROPFILES								                                        
0234		564		WM_MDIREFRESHMENU							                                        
0280		640		WM_IME_REPORT								                                        
0281		641		WM_IME_SETCONTEXT							                                        
0282		642		WM_IME_NOTIFY								                                        
0283		643		WM_IME_CONTROL								                                        
0284		644		WM_IME_COMPOSITIONFULL						                                        
0285		645		WM_IME_SELECT								                                        
0286		646		WM_IME_CHAR									                                        
0288		648		WM_IME_REQUEST								                                        
0290		656		WM_IMEKEYDOWN								                                        
0290		656		WM_IME_KEYDOWN								                                        
0291		657		WM_IMEKEYUP									                                        
0291		657		WM_IME_KEYUP								                                        
02a0		672		WM_NCMOUSEHOVER								                                        
02a1		673		WM_MOUSEHOVER								                                        
02a2		674		WM_NCMOUSELEAVE								                                        
02a3		675		WM_MOUSELEAVE								                                        
0300		768		WM_CUT										                                        
0301		769		WM_COPY										                                        
0302		770		WM_PASTE									                                        
0303		771		WM_CLEAR									                                        
0304		772		WM_UNDO										                                        
0305		773		WM_RENDERFORMAT								                                        
0306		774		WM_RENDERALLFORMATS							                                        
0307		775		WM_DESTROYCLIPBOARD							                                        
0308		776		WM_DRAWCLIPBOARD							                                        
0309		777		WM_PAINTCLIPBOARD							                                        
030a		778		WM_VSCROLLCLIPBOARD							                                        
030b		779		WM_SIZECLIPBOARD							                                        
030c		780		WM_ASKCBFORMATNAME							                                        
030d		781		WM_CHANGECBCHAIN							                                        
030e		782		WM_HSCROLLCLIPBOARD							                                        
030f		783		WM_QUERYNEWPALETTE							                                        
0310		784		WM_PALETTEISCHANGING						                                        
0311		785		WM_PALETTECHANGED							                                        
0312		786		WM_HOTKEY									                                        
0317		791		WM_PRINT									                                        
0318		792		WM_PRINTCLIENT								                                        
0319		793		WM_APPCOMMAND								                                        
0358		856		WM_HANDHELDFIRST							                                        
035f		863		WM_HANDHELDLAST								                                        
0360		864		WM_AFXFIRST									                                        
037f		895		WM_AFXLAST									                                        
0380		896		WM_PENWINFIRST								                                        
0381		897		WM_RCRESULT									                                        
0382		898		WM_HOOKRCRESULT								                                        
0383		899		WM_GLOBALRCCHANGE							                                        
0383		899		WM_PENMISCINFO								                                        
0384		900		WM_SKB										                                        
0385		901		WM_HEDITCTL									                                        
0385		901		WM_PENCTL									                                        
0386		902		WM_PENMISC									                                        
0387		903		WM_CTLINIT									                                        
0388		904		WM_PENEVENT									                                        
038f		911		WM_PENWINLAST								                                        
0400		1024		DDM_SETFMT								                                        
0400		1024		DM_GETDEFID								                                        
0400		1024		NIN_SELECT								                                        
0400		1024		TBM_GETPOS								                                        
0400		1024		WM_PSD_PAGESETUPDLG						                                        
0400		1024		WM_USER									                                        
0401		1025		CBEM_INSERTITEMA						                                        
0401		1025		DDM_DRAW								                                        
0401		1025		DM_SETDEFID								                                        
0401		1025		HKM_SETHOTKEY							                                        
0401		1025		PBM_SETRANGE							                                        
0401		1025		RB_INSERTBANDA							                                        
0401		1025		SB_SETTEXTA								                                        
0401		1025		TB_ENABLEBUTTON							                                        
0401		1025		TBM_GETRANGEMIN							                                        
0401		1025		TTM_ACTIVATE							                                        
0401		1025		WM_CHOOSEFONT_GETLOGFONT				                                        
0401		1025		WM_PSD_FULLPAGERECT						                                        
0402		1026		CBEM_SETIMAGELIST						                                        
0402		1026		DDM_CLOSE								                                        
0402		1026		DM_REPOSITION							                                        
0402		1026		HKM_GETHOTKEY							                                        
0402		1026		PBM_SETPOS								                                        
0402		1026		RB_DELETEBAND							                                        
0402		1026		SB_GETTEXTA								                                        
0402		1026		TB_CHECKBUTTON							                                        
0402		1026		TBM_GETRANGEMAX							                                        
0402		1026		WM_PSD_MINMARGINRECT					                                        
0403		1027		CBEM_GETIMAGELIST						                                        
0403		1027		DDM_BEGIN								                                        
0403		1027		HKM_SETRULES							                                        
0403		1027		PBM_DELTAPOS							                                        
0403		1027		RB_GETBARINFO							                                        
0403		1027		SB_GETTEXTLENGTHA						                                        
0403		1027		TBM_GETTIC								                                        
0403		1027		TB_PRESSBUTTON							                                        
0403		1027		TTM_SETDELAYTIME						                                        
0403		1027		WM_PSD_MARGINRECT						                                        
0404		1028		CBEM_GETITEMA							                                        
0404		1028		DDM_END									                                        
0404		1028		PBM_SETSTEP								                                        
0404		1028		RB_SETBARINFO							                                        
0404		1028		SB_SETPARTS								                                        
0404		1028		TB_HIDEBUTTON							                                        
0404		1028		TBM_SETTIC								                                        
0404		1028		TTM_ADDTOOLA							                                        
0404		1028		WM_PSD_GREEKTEXTRECT					                                        
0405		1029		CBEM_SETITEMA							                                        
0405		1029		PBM_STEPIT								                                        
0405		1029		TB_INDETERMINATE						                                        
0405		1029		TBM_SETPOS								                                        
0405		1029		TTM_DELTOOLA							                                        
0405		1029		WM_PSD_ENVSTAMPRECT						                                        
0406		1030		CBEM_GETCOMBOCONTROL					                                        
0406		1030		PBM_SETRANGE32							                                        
0406		1030		RB_SETBANDINFOA							                                        
0406		1030		SB_GETPARTS								                                        
0406		1030		TB_MARKBUTTON							                                        
0406		1030		TBM_SETRANGE							                                        
0406		1030		TTM_NEWTOOLRECTA						                                        
0406		1030		WM_PSD_YAFULLPAGERECT					                                        
0407		1031		CBEM_GETEDITCONTROL						                                        
0407		1031		PBM_GETRANGE							                                        
0407		1031		RB_SETPARENT							                                        
0407		1031		SB_GETBORDERS							                                        
0407		1031		TBM_SETRANGEMIN							                                        
0407		1031		TTM_RELAYEVENT							                                        
0408		1032		CBEM_SETEXSTYLE							                                        
0408		1032		PBM_GETPOS								                                        
0408		1032		RB_HITTEST								                                        
0408		1032		SB_SETMINHEIGHT							                                        
0408		1032		TBM_SETRANGEMAX							                                        
0408		1032		TTM_GETTOOLINFOA						                                        
0409		1033		CBEM_GETEXSTYLE							                                        
0409		1033		CBEM_GETEXTENDEDSTYLE					                                        
0409		1033		PBM_SETBARCOLOR							                                        
0409		1033		RB_GETRECT								                                        
0409		1033		SB_SIMPLE								                                        
0409		1033		TB_ISBUTTONENABLED						                                        
0409		1033		TBM_CLEARTICS							                                        
0409		1033		TTM_SETTOOLINFOA						                                        
040a		1034		CBEM_HASEDITCHANGED						                                        
040a		1034		RB_INSERTBANDW							                                        
040a		1034		SB_GETRECT								                                        
040a		1034		TB_ISBUTTONCHECKED						                                        
040a		1034		TBM_SETSEL								                                        
040a		1034		TTM_HITTESTA							                                        
040a		1034		WIZ_QUERYNUMPAGES						                                        
040b		1035		CBEM_INSERTITEMW						                                        
040b		1035		RB_SETBANDINFOW							                                        
040b		1035		SB_SETTEXTW								                                        
040b		1035		TB_ISBUTTONPRESSED						                                        
040b		1035		TBM_SETSELSTART							                                        
040b		1035		TTM_GETTEXTA							                                        
040b		1035		WIZ_NEXT								                                        
040c		1036		CBEM_SETITEMW							                                        
040c		1036		RB_GETBANDCOUNT							                                        
040c		1036		SB_GETTEXTLENGTHW						                                        
040c		1036		TB_ISBUTTONHIDDEN						                                        
040c		1036		TBM_SETSELEND							                                        
040c		1036		TTM_UPDATETIPTEXTA						                                        
040c		1036		WIZ_PREV								                                        
040d		1037		CBEM_GETITEMW							                                        
040d		1037		RB_GETROWCOUNT							                                        
040d		1037		SB_GETTEXTW								                                        
040d		1037		TB_ISBUTTONINDETERMINATE				                                        
040d		1037		TTM_GETTOOLCOUNT						                                        
040e		1038		CBEM_SETEXTENDEDSTYLE					                                        
040e		1038		RB_GETROWHEIGHT							                                        
040e		1038		SB_ISSIMPLE								                                        
040e		1038		TB_ISBUTTONHIGHLIGHTED					                                        
040e		1038		TBM_GETPTICS							                                        
040e		1038		TTM_ENUMTOOLSA							                                        
040f		1039		SB_SETICON								                                        
040f		1039		TBM_GETTICPOS							                                        
040f		1039		TTM_GETCURRENTTOOLA						                                        
0410		1040		RB_IDTOINDEX							                                        
0410		1040		SB_SETTIPTEXTA							                                        
0410		1040		TBM_GETNUMTICS							                                        
0410		1040		TTM_WINDOWFROMPOINT						                                        
0411		1041		RB_GETTOOLTIPS							                                        
0411		1041		SB_SETTIPTEXTW							                                        
0411		1041		TBM_GETSELSTART							                                        
0411		1041		TB_SETSTATE								                                        
0411		1041		TTM_TRACKACTIVATE						                                        
0412		1042		RB_SETTOOLTIPS							                                        
0412		1042		SB_GETTIPTEXTA							                                        
0412		1042		TB_GETSTATE								                                        
0412		1042		TBM_GETSELEND							                                        
0412		1042		TTM_TRACKPOSITION						                                        
0413		1043		RB_SETBKCOLOR							                                        
0413		1043		SB_GETTIPTEXTW							                                        
0413		1043		TB_ADDBITMAP							                                        
0413		1043		TBM_CLEARSEL							                                        
0413		1043		TTM_SETTIPBKCOLOR						                                        
0414		1044		RB_GETBKCOLOR							                                        
0414		1044		SB_GETICON								                                        
0414		1044		TB_ADDBUTTONSA							                                        
0414		1044		TBM_SETTICFREQ							                                        
0414		1044		TTM_SETTIPTEXTCOLOR						                                        
0415		1045		RB_SETTEXTCOLOR							                                        
0415		1045		TB_INSERTBUTTONA						                                        
0415		1045		TBM_SETPAGESIZE							                                        
0415		1045		TTM_GETDELAYTIME						                                        
0416		1046		RB_GETTEXTCOLOR							                                        
0416		1046		TB_DELETEBUTTON							                                        
0416		1046		TBM_GETPAGESIZE							                                        
0416		1046		TTM_GETTIPBKCOLOR						                                        
0417		1047		RB_SIZETORECT							                                        
0417		1047		TB_GETBUTTON							                                        
0417		1047		TBM_SETLINESIZE							                                        
0417		1047		TTM_GETTIPTEXTCOLOR						                                        
0418		1048		RB_BEGINDRAG							                                        
0418		1048		TB_BUTTONCOUNT							                                        
0418		1048		TBM_GETLINESIZE							                                        
0418		1048		TTM_SETMAXTIPWIDTH						                                        
0419		1049		RB_ENDDRAG								                                        
0419		1049		TB_COMMANDTOINDEX						                                        
0419		1049		TBM_GETTHUMBRECT						                                        
0419		1049		TTM_GETMAXTIPWIDTH						                                        
041a		1050		RB_DRAGMOVE								                                        
041a		1050		TBM_GETCHANNELRECT						                                        
041a		1050		TB_SAVERESTOREA							                                        
041a		1050		TTM_SETMARGIN							                                        
041b		1051		RB_GETBARHEIGHT							                                        
041b		1051		TB_CUSTOMIZE							                                        
041b		1051		TBM_SETTHUMBLENGTH						                                        
041b		1051		TTM_GETMARGIN							                                        
041c		1052		RB_GETBANDINFOW							                                        
041c		1052		TB_ADDSTRINGA							                                        
041c		1052		TBM_GETTHUMBLENGTH						                                        
041c		1052		TTM_POP									                                        
041d		1053		RB_GETBANDINFOA							                                        
041d		1053		TB_GETITEMRECT							                                        
041d		1053		TBM_SETTOOLTIPS							                                        
041d		1053		TTM_UPDATE								                                        
041e		1054		RB_MINIMIZEBAND							                                        
041e		1054		TB_BUTTONSTRUCTSIZE						                                        
041e		1054		TBM_GETTOOLTIPS							                                        
041e		1054		TTM_GETBUBBLESIZE						                                        
041f		1055		RB_MAXIMIZEBAND							                                        
041f		1055		TBM_SETTIPSIDE							                                        
041f		1055		TB_SETBUTTONSIZE						                                        
041f		1055		TTM_ADJUSTRECT							                                        
0420		1056		TBM_SETBUDDY							                                        
0420		1056		TB_SETBITMAPSIZE						                                        
0420		1056		TTM_SETTITLEA							                                        
0421		1057		MSG_FTS_JUMP_VA							                                        
0421		1057		TB_AUTOSIZE								                                        
0421		1057		TBM_GETBUDDY							                                        
0421		1057		TTM_SETTITLEW							                                        
0422		1058		RB_GETBANDBORDERS						                                        
0423		1059		MSG_FTS_JUMP_QWORD						                                        
0423		1059		RB_SHOWBAND								                                        
0423		1059		TB_GETTOOLTIPS							                                        
0424		1060		MSG_REINDEX_REQUEST						                                        
0424		1060		TB_SETTOOLTIPS							                                        
0425		1061		MSG_FTS_WHERE_IS_IT						                                        
0425		1061		RB_SETPALETTE							                                        
0425		1061		TB_SETPARENT							                                        
0426		1062		RB_GETPALETTE							                                        
0427		1063		RB_MOVEBAND								                                        
0427		1063		TB_SETROWS								                                        
0428		1064		TB_GETROWS								                                        
0429		1065		TB_GETBITMAPFLAGS						                                        
042a		1066		TB_SETCMDID								                                        
042b		1067		RB_PUSHCHEVRON							                                        
042b		1067		TB_CHANGEBITMAP							                                        
042c		1068		TB_GETBITMAP							                                        
042d		1069		MSG_GET_DEFFONT							                                        
042d		1069		TB_GETBUTTONTEXTA						                                        
042e		1070		TB_REPLACEBITMAP						                                        
042f		1071		TB_SETINDENT							                                        
0430		1072		TB_SETIMAGELIST							                                        
0431		1073		TB_GETIMAGELIST							                                        
0432		1074		TB_LOADIMAGES							                                        
0432		1074		EM_CANPASTE								                                        
0432		1074		TTM_ADDTOOLW							                                        
0433		1075		EM_DISPLAYBAND							                                        
0433		1075		TB_GETRECT								                                        
0433		1075		TTM_DELTOOLW							                                        
0434		1076		EM_EXGETSEL								                                        
0434		1076		TB_SETHOTIMAGELIST						                                        
0434		1076		TTM_NEWTOOLRECTW						                                        
0435		1077		EM_EXLIMITTEXT							                                        
0435		1077		TB_GETHOTIMAGELIST						                                        
0435		1077		TTM_GETTOOLINFOW						                                        
0436		1078		EM_EXLINEFROMCHAR						                                        
0436		1078		TB_SETDISABLEDIMAGELIST					                                        
0436		1078		TTM_SETTOOLINFOW						                                        
0437		1079		EM_EXSETSEL								                                        
0437		1079		TB_GETDISABLEDIMAGELIST					                                        
0437		1079		TTM_HITTESTW							                                        
0438		1080		EM_FINDTEXT								                                        
0438		1080		TB_SETSTYLE								                                        
0438		1080		TTM_GETTEXTW							                                        
0439		1081		EM_FORMATRANGE							                                        
0439		1081		TB_GETSTYLE								                                        
0439		1081		TTM_UPDATETIPTEXTW						                                        
043a		1082		EM_GETCHARFORMAT						                                        
043a		1082		TB_GETBUTTONSIZE						                                        
043a		1082		TTM_ENUMTOOLSW							                                        
043b		1083		EM_GETEVENTMASK							                                        
043b		1083		TB_SETBUTTONWIDTH						                                        
043b		1083		TTM_GETCURRENTTOOLW						                                        
043c		1084		EM_GETOLEINTERFACE						                                        
043c		1084		TB_SETMAXTEXTROWS						                                        
043d		1085		EM_GETPARAFORMAT						                                        
043d		1085		TB_GETTEXTROWS							                                        
043e		1086		EM_GETSELTEXT							                                        
043e		1086		TB_GETOBJECT							                                        
043f		1087		EM_HIDESELECTION						                                        
043f		1087		TB_GETBUTTONINFOW						                                        
0440		1088		EM_PASTESPECIAL							                                        
0440		1088		TB_SETBUTTONINFOW						                                        
0441		1089		EM_REQUESTRESIZE						                                        
0441		1089		TB_GETBUTTONINFOA						                                        
0442		1090		EM_SELECTIONTYPE						                                        
0442		1090		TB_SETBUTTONINFOA						                                        
0443		1091		EM_SETBKGNDCOLOR						                                        
0443		1091		TB_INSERTBUTTONW						                                        
0444		1092		EM_SETCHARFORMAT						                                        
0444		1092		TB_ADDBUTTONSW							                                        
0445		1093		EM_SETEVENTMASK							                                        
0445		1093		TB_HITTEST								                                        
0446		1094		EM_SETOLECALLBACK						                                        
0446		1094		TB_SETDRAWTEXTFLAGS						                                        
0447		1095		EM_SETPARAFORMAT						                                        
0447		1095		TB_GETHOTITEM							                                        
0448		1096		EM_SETTARGETDEVICE						                                        
0448		1096		TB_SETHOTITEM							                                        
0449		1097		EM_STREAMIN								                                        
0449		1097		TB_SETANCHORHIGHLIGHT					                                        
044a		1098		EM_STREAMOUT							                                        
044a		1098		TB_GETANCHORHIGHLIGHT					                                        
044b		1099		EM_GETTEXTRANGE							                                        
044b		1099		TB_GETBUTTONTEXTW						                                        
044c		1100		EM_FINDWORDBREAK						                                        
044c		1100		TB_SAVERESTOREW							                                        
044d		1101		EM_SETOPTIONS							                                        
044d		1101		TB_ADDSTRINGW							                                        
044e		1102		EM_GETOPTIONS							                                        
044e		1102		TB_MAPACCELERATORA						                                        
044f		1103		EM_FINDTEXTEX							                                        
044f		1103		TB_GETINSERTMARK						                                        
0450		1104		EM_GETWORDBREAKPROCEX					                                        
0450		1104		TB_SETINSERTMARK						                                        
0451		1105		EM_SETWORDBREAKPROCEX					                                        
0451		1105		TB_INSERTMARKHITTEST					                                        
0452		1106		EM_SETUNDOLIMIT							                                        
0452		1106		TB_MOVEBUTTON							                                        
0453		1107		TB_GETMAXSIZE							                                        
0454		1108		EM_REDO									                                        
0454		1108		TB_SETEXTENDEDSTYLE						                                        
0455		1109		EM_CANREDO								                                        
0455		1109		TB_GETEXTENDEDSTYLE						                                        
0456		1110		EM_GETUNDONAME							                                        
0456		1110		TB_GETPADDING							                                        
0457		1111		EM_GETREDONAME							                                        
0457		1111		TB_SETPADDING							                                        
0458		1112		EM_STOPGROUPTYPING						                                        
0458		1112		TB_SETINSERTMARKCOLOR					                                        
0459		1113		EM_SETTEXTMODE							                                        
0459		1113		TB_GETINSERTMARKCOLOR					                                        
045a		1114		EM_GETTEXTMODE							                                        
045a		1114		TB_MAPACCELERATORW						                                        
045b		1115		EM_AUTOURLDETECT						                                        
045b		1115		TB_GETSTRINGW							                                        
045c		1116		EM_GETAUTOURLDETECT						                                        
045c		1116		TB_GETSTRINGA							                                        
045d		1117		EM_SETPALETTE							                                        
045e		1118		EM_GETTEXTEX							                                        
045f		1119		EM_GETTEXTLENGTHEX						                                        
0460		1120		EM_SHOWSCROLLBAR						                                        
0461		1121		EM_SETTEXTEX							                                        
0463		1123		TAPI_REPLY								                                        
0464		1124		ACM_OPENA								                                        
0464		1124		BFFM_SETSTATUSTEXTA						                                        
0464		1124		CDM_FIRST								                                        
0464		1124		CDM_GETSPEC								                                        
0464		1124		EM_SETPUNCTUATION						                                        
0464		1124		IPM_CLEARADDRESS						                                        
0464		1124		WM_CAP_UNICODE_START					                                        
0465		1125		ACM_PLAY								                                        
0465		1125		BFFM_ENABLEOK							                                        
0465		1125		CDM_GETFILEPATH							                                        
0465		1125		EM_GETPUNCTUATION						                                        
0465		1125		IPM_SETADDRESS							                                        
0465		1125		PSM_SETCURSEL							                                        
0465		1125		UDM_SETRANGE							                                        
0465		1125		WM_CHOOSEFONT_SETLOGFONT				                                        
0466		1126		ACM_STOP								                                        
0466		1126		BFFM_SETSELECTIONA						                                        
0466		1126		CDM_GETFOLDERPATH						                                        
0466		1126		EM_SETWORDWRAPMODE						                                        
0466		1126		IPM_GETADDRESS							                                        
0466		1126		PSM_REMOVEPAGE							                                        
0466		1126		UDM_GETRANGE							                                        
0466		1126		WM_CAP_SET_CALLBACK_ERRORW				                                        
0466		1126		WM_CHOOSEFONT_SETFLAGS					                                        
0467		1127		ACM_OPENW								                                        
0467		1127		BFFM_SETSELECTIONW						                                        
0467		1127		CDM_GETFOLDERIDLIST						                                        
0467		1127		EM_GETWORDWRAPMODE						                                        
0467		1127		IPM_SETRANGE							                                        
0467		1127		PSM_ADDPAGE								                                        
0467		1127		UDM_SETPOS								                                        
0467		1127		WM_CAP_SET_CALLBACK_STATUSW				                                        
0468		1128		BFFM_SETSTATUSTEXTW						                                        
0468		1128		CDM_SETCONTROLTEXT						                                        
0468		1128		EM_SETIMECOLOR							                                        
0468		1128		IPM_SETFOCUS							                                        
0468		1128		PSM_CHANGED								                                        
0468		1128		UDM_GETPOS								                                        
0469		1129		CDM_HIDECONTROL							                                        
0469		1129		EM_GETIMECOLOR							                                        
0469		1129		IPM_ISBLANK								                                        
0469		1129		PSM_RESTARTWINDOWS						                                        
0469		1129		UDM_SETBUDDY							                                        
046a		1130		CDM_SETDEFEXT							                                        
046a		1130		EM_SETIMEOPTIONS						                                        
046a		1130		PSM_REBOOTSYSTEM						                                        
046a		1130		UDM_GETBUDDY							                                        
046b		1131		EM_GETIMEOPTIONS						                                        
046b		1131		PSM_CANCELTOCLOSE						                                        
046b		1131		UDM_SETACCEL							                                        
046c		1132		EM_CONVPOSITION							                                        
046c		1132		EM_CONVPOSITION							                                        
046c		1132		PSM_QUERYSIBLINGS						                                        
046c		1132		UDM_GETACCEL							                                        
046d		1133		MCIWNDM_GETZOOM							                                        
046d		1133		PSM_UNCHANGED							                                        
046d		1133		UDM_SETBASE								                                        
046e		1134		PSM_APPLY								                                        
046e		1134		UDM_GETBASE								                                        
046f		1135		PSM_SETTITLEA							                                        
046f		1135		UDM_SETRANGE32							                                        
0470		1136		PSM_SETWIZBUTTONS						                                        
0470		1136		UDM_GETRANGE32							                                        
0470		1136		WM_CAP_DRIVER_GET_NAMEW					                                        
0471		1137		PSM_PRESSBUTTON							                                        
0471		1137		UDM_SETPOS32							                                        
0471		1137		WM_CAP_DRIVER_GET_VERSIONW				                                        
0472		1138		PSM_SETCURSELID							                                        
0472		1138		UDM_GETPOS32							                                        
0473		1139		PSM_SETFINISHTEXTA						                                        
0474		1140		PSM_GETTABCONTROL						                                        
0475		1141		PSM_ISDIALOGMESSAGE						                                        
0476		1142		MCIWNDM_REALIZE							                                        
0476		1142		PSM_GETCURRENTPAGEHWND					                                        
0477		1143		MCIWNDM_SETTIMEFORMATA					                                        
0477		1143		PSM_INSERTPAGE							                                        
0478		1144		EM_SETLANGOPTIONS						                                        
0478		1144		MCIWNDM_GETTIMEFORMATA					                                        
0478		1144		PSM_SETTITLEW							                                        
0478		1144		WM_CAP_FILE_SET_CAPTURE_FILEW			                                        
0479		1145		EM_GETLANGOPTIONS						                                        
0479		1145		MCIWNDM_VALIDATEMEDIA					                                        
0479		1145		PSM_SETFINISHTEXTW						                                        
0479		1145		WM_CAP_FILE_GET_CAPTURE_FILEW			                                        
047a		1146		EM_GETIMECOMPMODE						                                        
047b		1147		EM_FINDTEXTW							                                        
047b		1147		MCIWNDM_PLAYTO							                                        
047b		1147		WM_CAP_FILE_SAVEASW						                                        
047c		1148		EM_FINDTEXTEXW							                                        
047c		1148		MCIWNDM_GETFILENAMEA					                                        
047d		1149		EM_RECONVERSION							                                        
047d		1149		MCIWNDM_GETDEVICEA						                                        
047d		1149		PSM_SETHEADERTITLEA						                                        
047d		1149		WM_CAP_FILE_SAVEDIBW					                                        
047e		1150		EM_SETIMEMODEBIAS						                                        
047e		1150		MCIWNDM_GETPALETTE						                                        
047e		1150		PSM_SETHEADERTITLEW						                                        
047f		1151		EM_GETIMEMODEBIAS						                                        
047f		1151		MCIWNDM_SETPALETTE						                                        
047f		1151		PSM_SETHEADERSUBTITLEA					                                        
0480		1152		MCIWNDM_GETERRORA						                                        
0480		1152		PSM_SETHEADERSUBTITLEW					                                        
0481		1153		PSM_HWNDTOINDEX							                                        
0482		1154		PSM_INDEXTOHWND							                                        
0483		1155		MCIWNDM_SETINACTIVETIMER				                                        
0483		1155		PSM_PAGETOINDEX							                                        
0484		1156		PSM_INDEXTOPAGE							                                        
0485		1157		DL_BEGINDRAG							                                        
0485		1157		MCIWNDM_GETINACTIVETIMER				                                        
0485		1157		PSM_IDTOINDEX							                                        
0486		1158		DL_DRAGGING								                                        
0486		1158		PSM_INDEXTOID							                                        
0487		1159		DL_DROPPED								                                        
0487		1159		PSM_GETRESULT							                                        
0488		1160		DL_CANCELDRAG							                                        
0488		1160		PSM_RECALCPAGESIZES						                                        
048c		1164		MCIWNDM_GET_SOURCE						                                        
048d		1165		MCIWNDM_PUT_SOURCE						                                        
048e		1166		MCIWNDM_GET_DEST						                                        
048f		1167		MCIWNDM_PUT_DEST						                                        
0490		1168		MCIWNDM_CAN_PLAY						                                        
0491		1169		MCIWNDM_CAN_WINDOW						                                        
0492		1170		MCIWNDM_CAN_RECORD						                                        
0493		1171		MCIWNDM_CAN_SAVE						                                        
0494		1172		MCIWNDM_CAN_EJECT						                                        
0495		1173		MCIWNDM_CAN_CONFIG						                                        
0496		1174		IE_GETINK								                                        
0496		1174		IE_MSGFIRST								                                        
0496		1174		MCIWNDM_PALETTEKICK						                                        
0497		1175		IE_SETINK								                                        
0498		1176		IE_GETPENTIP							                                        
0499		1177		IE_SETPENTIP							                                        
049a		1178		IE_GETERASERTIP							                                        
049b		1179		IE_SETERASERTIP							                                        
049c		1180		IE_GETBKGND								                                        
049d		1181		IE_SETBKGND								                                        
049e		1182		IE_GETGRIDORIGIN						                                        
049f		1183		IE_SETGRIDORIGIN						                                        
04a0		1184		IE_GETGRIDPEN							                                        
04a1		1185		IE_SETGRIDPEN							                                        
04a2		1186		IE_GETGRIDSIZE							                                        
04a3		1187		IE_SETGRIDSIZE							                                        
04a4		1188		IE_GETMODE								                                        
04a5		1189		IE_SETMODE								                                        
04a6		1190		IE_GETINKRECT							                                        
04a6		1190		WM_CAP_SET_MCI_DEVICEW					                                        
04a7		1191		WM_CAP_GET_MCI_DEVICEW					                                        
04b4		1204		WM_CAP_PAL_OPENW						                                        
04b5		1205		WM_CAP_PAL_SAVEW						                                        
04b8		1208		IE_GETAPPDATA							                                        
04b9		1209		IE_SETAPPDATA							                                        
04ba		1210		IE_GETDRAWOPTS							                                        
04bb		1211		IE_SETDRAWOPTS							                                        
04bc		1212		IE_GETFORMAT							                                        
04bd		1213		IE_SETFORMAT							                                        
04be		1214		IE_GETINKINPUT							                                        
04bf		1215		IE_SETINKINPUT							                                        
04c0		1216		IE_GETNOTIFY							                                        
04c1		1217		IE_SETNOTIFY							                                        
04c2		1218		IE_GETRECOG								                                        
04c3		1219		IE_SETRECOG								                                        
04c4		1220		IE_GETSECURITY							                                        
04c5		1221		IE_SETSECURITY							                                        
04c6		1222		IE_GETSEL								                                        
04c7		1223		IE_SETSEL								                                        
04c8		1224		CDM_LAST								                                        
04c8		1224		EM_SETBIDIOPTIONS						                                        
04c8		1224		IE_DOCOMMAND							                                        
04c8		1224		MCIWNDM_NOTIFYMODE						                                        
04c9		1225		EM_GETBIDIOPTIONS						                                        
04c9		1225		IE_GETCOMMAND							                                        
04ca		1226		EM_SETTYPOGRAPHYOPTIONS					                                        
04ca		1226		IE_GETCOUNT								                                        
04cb		1227		EM_GETTYPOGRAPHYOPTIONS					                                        
04cb		1227		IE_GETGESTURE							                                        
04cb		1227		MCIWNDM_NOTIFYMEDIA						                                        
04cc		1228		EM_SETEDITSTYLE							                                        
04cc		1228		IE_GETMENU								                                        
04cd		1229		EM_GETEDITSTYLE							                                        
04cd		1229		IE_GETPAINTDC							                                        
04cd		1229		MCIWNDM_NOTIFYERROR						                                        
04ce		1230		IE_GETPDEVENT							                                        
04cf		1231		IE_GETSELCOUNT							                                        
04d0		1232		IE_GETSELITEMS							                                        
04d1		1233		IE_GETSTYLE								                                        
04db		1243		MCIWNDM_SETTIMEFORMATW					                                        
04dc		1244		EM_OUTLINE								                                        
04dc		1244		MCIWNDM_GETTIMEFORMATW					                                        
04dd		1245		EM_GETSCROLLPOS							                                        
04de		1246		EM_SETSCROLLPOS							                                        
04de		1246		EM_SETSCROLLPOS							                                        
04df		1247		EM_SETFONTSIZE							                                        
04e0		1248		EM_GETZOOM								                                        
04e0		1248		MCIWNDM_GETFILENAMEW					                                        
04e1		1249		EM_SETZOOM								                                        
04e1		1249		MCIWNDM_GETDEVICEW						                                        
04e2		1250		EM_GETVIEWKIND							                                        
04e3		1251		EM_SETVIEWKIND							                                        
04e4		1252		EM_GETPAGE								                                        
04e4		1252		MCIWNDM_GETERRORW						                                        
																                                        
04e5		1253		EM_SETPAGE								                                        
04e6		1254		EM_GETHYPHENATEINFO						                                        
04e7		1255		EM_SETHYPHENATEINFO						                                        
04eb		1259		EM_GETPAGEROTATE						                                        
04ec		1260		EM_SETPAGEROTATE						                                        
04ed		1261		EM_GETCTFMODEBIAS						                                        
04ee		1262		EM_SETCTFMODEBIAS						                                        
04f0		1264		EM_GETCTFOPENSTATUS						                                        
04f1		1265		EM_SETCTFOPENSTATUS						                                        
04f2		1266		EM_GETIMECOMPTEXT						                                        
04f3		1267		EM_ISIME								                                        
04f4		1268		EM_GETIMEPROPERTY						                                        
050d		1293		EM_GETQUERYRTFOBJ						                                        
050e		1294		EM_SETQUERYRTFOBJ						                                        
0600		1536		FM_GETFOCUS								                                        
0601		1537		FM_GETDRIVEINFOA						                                        
0602		1538		FM_GETSELCOUNT							                                        
0603		1539		FM_GETSELCOUNTLFN						                                        
0604		1540		FM_GETFILESELA							                                        
0605		1541		FM_GETFILESELLFNA						                                        
0606		1542		FM_REFRESH_WINDOWS						                                        
0607		1543		FM_RELOAD_EXTENSIONS					                                        
0611		1553		FM_GETDRIVEINFOW						                                        
0614		1556		FM_GETFILESELW							                                        
0615		1557		FM_GETFILESELLFNW						                                        
																                                        
0659		1625		WLX_WM_SAS								                                        
																                                        
07e8		2024		SM_GETSELCOUNT							                                        
07e8		2024		UM_GETSELCOUNT							                                        
07e8		2024		WM_CPL_LAUNCH							                                        
07e9		2025		SM_GETSERVERSELA						                                        
07e9		2025		UM_GETUSERSELA							                                        
07e9		2025		WM_CPL_LAUNCHED							                                        
07ea		2026		SM_GETSERVERSELW						                                        
07ea		2026		UM_GETUSERSELW							                                        
07eb		2027		SM_GETCURFOCUSA							                                        
07eb		2027		UM_GETGROUPSELA							                                        
07ec		2028		SM_GETCURFOCUSW							                                        
07ec		2028		UM_GETGROUPSELW							                                        
07ed		2029		SM_GETOPTIONS							                                        
07ed		2029		UM_GETCURFOCUSA							                                        
07ee		2030		UM_GETCURFOCUSW							                                        
07ef		2031		UM_GETOPTIONS							                                        
07f0		2032		UM_GETOPTIONS2							                                        
																                                        
#define MYSTIC_FIRST             				1000		4096		LVM_FIRST
#define MYSTIC_GETBKCOLOR						1000		4096		LVM_GETBKCOLOR
#define MYSTIC_SETBKCOLOR						1001		4097		LVM_SETBKCOLOR
#define MYSTIC_GETIMAGELIST					1002		4098		LVM_GETIMAGELIST
#define MYSTIC_SETIMAGELIST					1003		4099		LVM_SETIMAGELIST
#define MYSTIC_GETITEMCOUNT					1004		4100		LVM_GETITEMCOUNT
#define MYSTIC_GETITEMA						1005		4101		LVM_GETITEMA
#define MYSTIC_SETITEMA						1006		4102		LVM_SETITEMA
#define MYSTIC_INSERTITEMA					1007		4103		LVM_INSERTITEMA
#define MYSTIC_DELETEITEM						1008		4104		LVM_DELETEITEM
#define MYSTIC_DELETEALLITEMS					1009		4105		LVM_DELETEALLITEMS
#define MYSTIC_GETCALLBACKMASK				100a		4106		LVM_GETCALLBACKMASK
#define MYSTIC_SETCALLBACKMASK				100b		4107		LVM_SETCALLBACKMASK
#define MYSTIC_GETNEXTITEM					100c		4108		LVM_GETNEXTITEM
#define MYSTIC_FINDITEMA						100d		4109		LVM_FINDITEMA
#define MYSTIC_GETITEMRECT				   	100e		4110		LVM_GETITEMRECT
#define MYSTIC_SETITEMPOSITION			   100f		4111		LVM_SETITEMPOSITION
#define MYSTIC_GETITEMPOSITION			   1010		4112		LVM_GETITEMPOSITION
#define MYSTIC_GETSTRINGWIDTHA			   1011		4113		LVM_GETSTRINGWIDTHA
#define MYSTIC_HITTEST					   1012		4114		LVM_HITTEST
#define MYSTIC_ENSUREVISIBLE			   	1013		4115		LVM_ENSUREVISIBLE
#define MYSTIC_SCROLL					   	1014		4116		LVM_SCROLL
#define MYSTIC_REDRAWITEMS				   1015		4117		LVM_REDRAWITEMS
#define MYSTIC_ARRANGE					   1016		4118		LVM_ARRANGE
#define MYSTIC_EDITLABELA				   	1017		4119		LVM_EDITLABELA
#define MYSTIC_GETEDITCONTROL			   	1018		4120		LVM_GETEDITCONTROL
#define MYSTIC_GETCOLUMNA				   	1019		4121		LVM_GETCOLUMNA
#define MYSTIC_SETCOLUMNA				   	101a		4122		LVM_SETCOLUMNA
#define MYSTIC_INSERTCOLUMNA			   	101b		4123		LVM_INSERTCOLUMNA
#define MYSTIC_DELETECOLUMN				   101c		4124		LVM_DELETECOLUMN
#define MYSTIC_GETCOLUMNWIDTH			   	101d		4125		LVM_GETCOLUMNWIDTH
#define MYSTIC_SETCOLUMNWIDTH			   	101e		4126		LVM_SETCOLUMNWIDTH
#define MYSTIC_GETHEADER				   	101f		4127		LVM_GETHEADER
#define MYSTIC_CREATEDRAGIMAGE			   1021		4129		LVM_CREATEDRAGIMAGE
#define MYSTIC_GETVIEWRECT				   1022		4130		LVM_GETVIEWRECT
#define MYSTIC_GETTEXTCOLOR				   1023		4131		LVM_GETTEXTCOLOR
#define MYSTIC_SETTEXTCOLOR				   1024		4132		LVM_SETTEXTCOLOR
#define MYSTIC_GETTEXTBKCOLOR			   	1025		4133		LVM_GETTEXTBKCOLOR
#define MYSTIC_SETTEXTBKCOLOR			   	1026		4134		LVM_SETTEXTBKCOLOR
#define MYSTIC_GETTOPINDEX				   1027		4135		LVM_GETTOPINDEX
#define MYSTIC_GETCOUNTPERPAGE			   1028		4136		LVM_GETCOUNTPERPAGE
#define MYSTIC_GETORIGIN				   	1029		4137		LVM_GETORIGIN
#define MYSTIC_UPDATE					   	102a		4138		LVM_UPDATE
#define MYSTIC_SETITEMSTATE				   102b		4139		LVM_SETITEMSTATE
#define MYSTIC_GETITEMSTATE				   102c		4140		LVM_GETITEMSTATE
#define MYSTIC_GETITEMTEXTA				   102d		4141		LVM_GETITEMTEXTA
#define MYSTIC_SETITEMTEXTA				   102e		4142		LVM_SETITEMTEXTA
#define MYSTIC_SETITEMCOUNT				   102f		4143		LVM_SETITEMCOUNT
#define MYSTIC_SORTITEMS				   	1030		4144		LVM_SORTITEMS
#define MYSTIC_SETITEMPOSITION32		   	1031		4145		LVM_SETITEMPOSITION32
#define MYSTIC_GETSELECTEDCOUNT			   1032		4146		LVM_GETSELECTEDCOUNT
#define MYSTIC_GETITEMSPACING			   	1033		4147		LVM_GETITEMSPACING
#define MYSTIC_GETISEARCHSTRINGA		   	1034		4148		LVM_GETISEARCHSTRINGA
#define MYSTIC_SETICONSPACING			   	1035		4149		LVM_SETICONSPACING
#define MYSTIC_SETEXTENDEDLISTVIEWSTYLE      1036		4150		LVM_SETEXTENDEDLISTVIEWSTYLE
#define MYSTIC_GETEXTENDEDLISTVIEWSTYLE      1037		4151		LVM_GETEXTENDEDLISTVIEWSTYLE
#define MYSTIC_GETSUBITEMRECT			     1038		4152		LVM_GETSUBITEMRECT
#define MYSTIC_SUBITEMHITTEST			     1039		4153		LVM_SUBITEMHITTEST
#define MYSTIC_SETCOLUMNORDERARRAY	         103a		4154		LVM_SETCOLUMNORDERARRAY
#define MYSTIC_GETCOLUMNORDERARRAY	         103b		4155		LVM_GETCOLUMNORDERARRAY
#define MYSTIC_SETHOTITEM		             103c		4156		LVM_SETHOTITEM
#define MYSTIC_GETHOTITEM		             103d		4157		LVM_GETHOTITEM
#define MYSTIC_SETHOTCURSOR			         103e		4158		LVM_SETHOTCURSOR
#define MYSTIC_GETHOTCURSOR			         103f		4159		LVM_GETHOTCURSOR
#define MYSTIC_APPROXIMATEVIEWRECT	         1040		4160		LVM_APPROXIMATEVIEWRECT
#define MYSTIC_SETWORKAREAS			         1041		4161		LVM_SETWORKAREAS
#define MYSTIC_GETSELECTIONMARK		         1042		4162		LVM_GETSELECTIONMARK
#define MYSTIC_SETSELECTIONMARK		         1043		4163		LVM_SETSELECTIONMARK
#define MYSTIC_SETBKIMAGEA			         1044		4164		LVM_SETBKIMAGEA
#define MYSTIC_GETBKIMAGEA			         1045		4165		LVM_GETBKIMAGEA
#define MYSTIC_GETWORKAREAS			         1046		4166		LVM_GETWORKAREAS
#define MYSTIC_SETHOVERTIME			         1047		4167		LVM_SETHOVERTIME
#define MYSTIC_GETHOVERTIME			         1048		4168		LVM_GETHOVERTIME
#define MYSTIC_GETNUMBEROFWORKAREAS	         1049		4169		LVM_GETNUMBEROFWORKAREAS
#define MYSTIC_SETTOOLTIPS			         104a		4170		LVM_SETTOOLTIPS
#define MYSTIC_GETITEMW				         104b		4171		LVM_GETITEMW
#define MYSTIC_SETITEMW				         104c		4172		LVM_SETITEMW
#define MYSTIC_INSERTITEMW			         104d		4173		LVM_INSERTITEMW
#define MYSTIC_GETTOOLTIPS			         104e		4174		LVM_GETTOOLTIPS
#define MYSTIC_FINDITEMW			         1053		4179		LVM_FINDITEMW
#define MYSTIC_GETSTRINGWIDTHW		         1057		4183		LVM_GETSTRINGWIDTHW
#define MYSTIC_GETCOLUMNW			         105f		4191		LVM_GETCOLUMNW
#define MYSTIC_SETCOLUMNW			         1060		4192		LVM_SETCOLUMNW
#define MYSTIC_INSERTCOLUMNW		         1061		4193		LVM_INSERTCOLUMNW
#define MYSTIC_GETITEMTEXTW			         1073		4211		LVM_GETITEMTEXTW
#define MYSTIC_SETITEMTEXTW			         1074		4212		LVM_SETITEMTEXTW
#define MYSTIC_GETISEARCHSTRINGW		     1075		4213		LVM_GETISEARCHSTRINGW
#define MYSTIC_EDITLABELW			         1076		4214		LVM_EDITLABELW
#define MYSTIC_GETBKIMAGEW			         108b		4235		LVM_GETBKIMAGEW
#define MYSTIC_SETSELECTEDCOLUMN	         108c		4236		LVM_SETSELECTEDCOLUMN
#define MYSTIC_SETTILEWIDTH			         108d		4237		LVM_SETTILEWIDTH
#define MYSTIC_SETVIEW				         108e		4238		LVM_SETVIEW
#define MYSTIC_GETVIEW				         108f		4239		LVM_GETVIEW
#define MYSTIC_INSERTGROUP			         1091		4241		LVM_INSERTGROUP
#define MYSTIC_SETGROUPINFO			         1093		4243		LVM_SETGROUPINFO
#define MYSTIC_GETGROUPINFO			         1095		4245		LVM_GETGROUPINFO
#define MYSTIC_REMOVEGROUP			         1096		4246		LVM_REMOVEGROUP
#define MYSTIC_MOVEGROUP				          1097		4247		LVM_MOVEGROUP
#define MYSTIC_MOVEITEMTOGROUP		         109a		4250		LVM_MOVEITEMTOGROUP
#define MYSTIC_SETGROUPMETRICS		         109b		4251		LVM_SETGROUPMETRICS
#define MYSTIC_GETGROUPMETRICS		         109c		4252		LVM_GETGROUPMETRICS
#define MYSTIC_ENABLEGROUPVIEW		         109d		4253		LVM_ENABLEGROUPVIEW
#define MYSTIC_SORTGROUPS				          109e		4254		LVM_SORTGROUPS
#define MYSTIC_INSERTGROUPSORTED		          109f		4255		LVM_INSERTGROUPSORTED
#define MYSTIC_REMOVEALLGROUPS		         10a0		4256		LVM_REMOVEALLGROUPS
#define MYSTIC_HASGROUP				         10a1		4257		LVM_HASGROUP
#define MYSTIC_SETTILEVIEWINFO			      10a2		4258		LVM_SETTILEVIEWINFO
#define MYSTIC_GETTILEVIEWINFO			      10a3		4259		LVM_GETTILEVIEWINFO
#define MYSTIC_SETTILEINFO			         10a4		4260		LVM_SETTILEINFO
#define MYSTIC_GETTILEINFO				      10a5		4261		LVM_GETTILEINFO
#define MYSTIC_SETINSERTMARK			          10a6		4262		LVM_SETINSERTMARK
#define MYSTIC_GETINSERTMARK			          10a7		4263		LVM_GETINSERTMARK
#define MYSTIC_INSERTMARKHITTEST		          10a8		4264		LVM_INSERTMARKHITTEST
#define MYSTIC_GETINSERTMARKRECT		          10a9		4265		LVM_GETINSERTMARKRECT
#define MYSTIC_SETINSERTMARKCOLOR		          10aa		4266		LVM_SETINSERTMARKCOLOR
#define MYSTIC_GETINSERTMARKCOLOR		          10ab		4267		LVM_GETINSERTMARKCOLOR
#define MYSTIC_SETINFOTIP				          10ad		4269		LVM_SETINFOTIP
#define MYSTIC_GETSELECTEDCOLUMN		          10ae		4270		LVM_GETSELECTEDCOLUMN
#define MYSTIC_ISGROUPVIEWENABLED		          10af		4271		LVM_ISGROUPVIEWENABLED
#define MYSTIC_GETOUTLINECOLOR		         10b0		4272		LVM_GETOUTLINECOLOR
#define MYSTIC_SETOUTLINECOLOR		         10b1		4273		LVM_SETOUTLINECOLOR
#define MYSTIC_CANCELEDITLABEL		         10b3		4275		LVM_CANCELEDITLABEL
#define MYSTIC_MAPINDEXTOID			         10b4		4276		LVM_MAPINDEXTOID
#define MYSTIC_MAPIDTOINDEX			         10b5		4277		LVM_MAPIDTOINDEX
#define MYSTIC_ISITEMVISIBLE			          10b6		4278		LVM_ISITEMVISIBLE
#define MYSTIC__BASE					          2000		8192		OCM__BASE
#define MYSTIC_SETUNICODEFORMAT		         2005		8197		LVM_SETUNICODEFORMAT
#define MYSTIC_GETUNICODEFORMAT		         2006		8198		LVM_GETUNICODEFORMAT
#define MYSTIC_CTLCOLOR				         2019		8217		OCM_CTLCOLOR
#define MYSTIC_DRAWITEM				         202b		8235		OCM_DRAWITEM
#define MYSTIC_MEASUREITEM			         202c		8236		OCM_MEASUREITEM
#define MYSTIC_DELETEITEM				          202d		8237		OCM_DELETEITEM
#define MYSTIC_VKEYTOITEM				          202e		8238		OCM_VKEYTOITEM
#define MYSTIC_CHARTOITEM				          202f		8239		OCM_CHARTOITEM
#define MYSTIC_COMPAREITEM			         2039		8249		OCM_COMPAREITEM
#define MYSTIC_NOTIFY					          204e		8270		OCM_NOTIFY
#define MYSTIC_COMMAND				         2111		8465		OCM_COMMAND
#define MYSTIC_HSCROLL				         2114		8468		OCM_HSCROLL
#define MYSTIC_VSCROLL				         2115		8469		OCM_VSCROLL
#define MYSTIC_CTLCOLORMSGBOX			          2132		8498		OCM_CTLCOLORMSGBOX
#define MYSTIC_CTLCOLOREDIT			         2133		8499		OCM_CTLCOLOREDIT
#define MYSTIC_CTLCOLORLISTBOX		         2134		8500		OCM_CTLCOLORLISTBOX
#define MYSTIC_CTLCOLORBTN			         2135		8501		OCM_CTLCOLORBTN
#define MYSTIC_CTLCOLORDLG				      2136		8502		OCM_CTLCOLORDLG
#define MYSTIC_CTLCOLORSCROLLBAR		          2137		8503		OCM_CTLCOLORSCROLLBAR
#define MYSTIC_CTLCOLORSTATIC			          2138		8504		OCM_CTLCOLORSTATIC
#define MYSTIC_PARENTNOTIFY			         2210		8720		OCM_PARENTNOTIFY
#define MYSTIC_APP						      8000		32768		 WM_APP
#define MYSTIC_RASDIALEVENT			         cccd		52429		 WM_RASDIALEVENT



#endif
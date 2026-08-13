#include "includes.h"
#pragma hdrstop

#include <stdlib.h>
#include <string.h>

#include <dialog.h>


#include "winutil\wutil.h"
#include "about.h"

#include "mainwind.h"
#include "version.h"   // generated from VERSION by tools\build.bat

class AboutDialog : public TDialog {
  typedef TDialog Inherited;
 public:
   AboutDialog(PTWindowsObject AParent, int ResourceId, PTModule AModule = NULL)
    : TDialog(AParent, ResourceId, AModule)
    {
    }
 protected:
  virtual void SetupWindow();
};


static const unsigned long code_number = 0
#if INTERNAL()
+3UL // internal+internal_rc
#endif

#if OVEN_EQ_INJ()
  + (1UL<<2)
#endif

#if DEMO()
  + (1UL<<3)
#endif

#if GC321() //??
  + (1UL<<12)
#endif

#if STAND_ALONE()
  + (1UL<<13)
#endif

#if CBW()
  + (1UL<<14)
#endif

#if Get_Data_Bipolar() // this is not feature?
  + (1UL<<16)
#endif

#if ANALOG_OUTPUT()
  + (1UL<<17)
#endif

#if ANALOG_MIX()
  + (1UL<<18)
#endif

#if RAMPING()
  + (1UL<<19)
#endif

#if HV_501()
  + (1UL<<20)
#endif

#if CONCENTRATOR()
  + (1UL<<21)
#endif

#if FLAME()
  + (1UL<<22)
#endif

#if USE_TOTAL()
  + (1UL<<24)
#endif

#if FLOW()
  + (1UL<<25)
#endif

#if REMOTE_CAL()
  + (1UL<<26)
#endif

#if DIAGNOSTICS()
  + (1UL<<27)
#endif

#if GC501()
  + (1UL<<28)
#endif
   
#if ALL_ERR_CAL()
  + (1UL<<29)
#endif

#if NO_CAL_START()
  + (1UL<<31)
#endif
;


static const unsigned long high_code_part = 0
#if SAMPLE_AHEAD()
  + 1UL
#endif

#if ANALOG_DELAYED()
  + (1UL<<1)  // add in front of code_number
#endif

#if OPTICS()
  + (1UL<<2)
#endif

#if USE_DIFFERENCE()
  + (1UL<<4)
#endif

#if SHIFT_REPORT() // added. P.P. 08/18/04
  + (1UL<<6)
#endif 

#if OLIN() // added. P.P. 10/24/04
  + (1UL<<7)
#endif

#if PMD_16FS()  // added. P.P. 11/07/04
  + (1UL<<8)
#endif

#if PMD_12LS()  // added. P.P. 11/07/04
  + (1UL<<9)
#endif

#if ALARM_NC()  // bit 42 added. P.P. 12/05/04
  + (1UL<<10)
#endif

#if X1_VALVE()  // bit 43 added. P.P. 12/10/04
  + (1UL<<11)
#endif

#if NOISE_REDUCT()     // bit 44 added. P.P. 12/11/04
  + (1UL<<12)
#endif

#if COMMON_HIGH()      // bit 45 added. P.P. 01/11/05
  + (1UL<<13)
#endif

#if MODBUS()      // bit 46 added.
  + (1UL<<14)
#endif

#if PMD_12FS()    // bits 47-49 added. P.P. 04/10/05
  + (1UL<<15)
#endif

#if CBWUSB_IO()    // bits 47-49 added. P.P. 04/10/05
  + (1UL<<16)
#endif


#if FID()         // bit 52. Added. P.P. 08/02/05
  + (1UL<<20)
#endif

#if GC312()       // bit 58. 03/19/06
  + (1UL<<26)
#endif

#if USB_3112()	  // bit 59. P.P. 04/16/06
  + (1UL<<27)
#endif

#if USB_3101()      // bit 60. 05/20/07
  + (1UL<<28)
#endif

#if USB_3103()      // bit 61. 05/20/07
  + (1UL<<29)
#endif

#if MANUAL_INJ()  // bit 62. P.P. 05/20/06
  + (1UL<<30)
#endif

#if USB_3106()
  + (1UL<<31)      // bit 63. P.P. 09/15/06
#endif
;


static char _far ABOUT_APP_DESCR[]=""
#if DEMO()
  "DEMO program, to view and analyze GC data\r\n"
#endif
#if !STAND_ALONE() // cond added. P.P. 11/07/04
#if OVEN_EQ_INJ()
//  "Oven and injector temperatures are equal\r\n"
  "Single temperature zone for oven and injector\r\n"
#else  
#if FID() // using second temp setting for monitoring FID
  "Single temperature zone for oven and injector\r\n"
  "Flame Ionization Detector\r\n"
#else
  "Separate temperature zones for oven and injector\r\n"
#endif // fid
#endif
#if RAMPING()
  "Temperature ramping\r\n"
#endif
#endif // !stand_alone

#if INTERNAL() // added. P.P. 09/12/04
#if !DEMO() // cond added. P.P. 10/09/04
#if PMD_16FS() 				// P.P. 11/07/04
  "USB 1608FS A/D & DIO board\r\n"  // P.P. 06/22/10
#endif                                  //
#if PMD_12LS()                        //
  "USB-1208LS A/D, D/A, & DIO board\r\n"  //
#endif
#if PMD_12FS()
  "USB 1208FS A/D, D/A, & DIO board\r\n"  //
#endif
//#if USB_DIO24()
#if USB_DIO24()||CBWUSB_IO() // P.P. 09/05/18
  "USB DIO24 DIO board\r\n"  // added. P.P. 05/03/11
#endif
#if USB_3112()               // added. P.P. 04/16/06
  "USB-3112 D/A board\r\n"
#endif
#if USB_3106()               // P.P. 09/15/06
  "USB-3106 D/A board\r\n"
#endif
#if USB_3101()               // 2 boards added. P.P. 05/20/07
  "USB-3101 D/A board\r\n"
#endif
#if USB_3103()
  "USB-3103 D/A board\r\n"
#endif

#endif // !demo. P.P. 10/09/04
#endif // internal. added P.P. 09/12/04

#if X1_VALVE()   // now in all GCs. P.P. 11/12/10
//  "GC321 - work with valves\r\n"
   "User-programmable relays for process controls\r\n"
#endif

#if !DEMO() // cond added. P.P. 10/09/04
#if ANALOG_OUTPUT()
  "Analog outputs for concentrations measured\r\n"
#if (!ANALOG_DELAYED())
      "are updated in real time\r\n"
#endif // !delayed
#endif // analog output
#endif // !demo

#if USE_TOTAL()
  "Total concentration of analytes computed\r\n"
#endif

#if ANALOG_MIX()
//  "Analog mix - multipoint but all\r\n"
#endif

#if CONCENTRATOR()
//  "CONCENTRATOR\r\n"
#endif

#if FLAME()
//  "Flame detector\r\n"
#endif

#if !DEMO() // cond added. P.P. 10/09/04
#if FLOW()
//  "Carrier gas flow is monitored\r\n"  
#if GC501()                                    // added. P.P. 08/22/04
  "Column and sample flows are monitored\r\n"  //
#else                                          //
//  "Sample flow is monitored\r\n"       // replacement. P.P. 08/14/04 
  "Column flow is monitored\r\n"       // replacement. P.P. 08/14/04
#endif // gc501
#endif // flow

//#if REMOTE_CAL()
#if REMOTE_CAL()
  "Remote analysis and calibration start\r\n"
#else
//#if INTERNAL() // added. P.P. 09/12/04
#if INTERNAL()&&(!GC312())&&(!GC321()) // changed. P.P. 06/18/06
#if !STAND_ALONE() // 01/14/09
//  "Remote analysis start\r\n" // removed, not needed anymore
#endif // !stand_alone
#endif // internal
#endif

#if INTERNAL() // added. P.P. 09/12/04
//#if (!GC312())&&(!GC321()) // changed. P.P. 06/18/06
#if !STAND_ALONE() // 01/14/09
 // remove next line for 301 without XP+network card. P.P. 09/05/04
  "Full control via Ethernet is possible\r\n" // added. P.P. 08/14/04
#endif // !stand_alone
//#endif // not 312 or 322
#else
  "Data transfer via serial port between GC311 and PC\r\n"
#endif

#if MODBUS()                            // added. P.P. 01/21/05
  "Data can be read using Modbus\r\n"
#endif
  "Data can be sent to Excel spreadsheet\r\n" // added. P.P. 02/24/12

#if INTERNAL() // cond added. P.P. 09/12/04
//#if (!GC312())&&(!GC321()) // changed. P.P. 06/18/06
#if !(GC312()||GC321()||GC326()) // P.P. 12/07/18
  "Diagnostics messages and alarm\r\n"
#else
#if !STAND_ALONE() // 07/18/08
  "Diagnostics messages\r\n"
#endif // !stand_alone
#endif // 312 or 321/322
#endif // internal

#endif // !demo. P.P. 10/09/04

#if GC501()||SHIFT_REPORT() // changed. P.P. 08/18/04
  "Shift Report printout\r\n"   // can be in 301 also.
#endif
   
#if ALL_ERR_CAL()
//  "ALL_ERR_CAL\r\n"
#endif

#if !DEMO() // cond added. P.P. 10/09/04
//#if NO_CAL_START()
//#if !NO_CAL_START()
#if (!NO_CAL_START())&&INTERNAL() // changed. P.P. 09/12/04
  "Calibration auto start on power ON\r\n"
#else
#endif

#if SAMPLE_AHEAD()
  "Next point sampling ahead\r\n"
#endif

#if MODBUS()
//  "ModBus Slave\r\n" // removed. P.P. 11/12/10
#endif

#endif // !demo

#if OPTICS()
  "Peak Works for optical spectra\r\n"
#endif
;

/* The model and the version are not typed in here any more.

   MODEL_CODE and DEVICE_NAME come from config\<model>.h; PW_VERSION_STR
   comes from the VERSION file at the top of the tree. tools\build.bat
   turns both into headers before the compiler runs, so the About box
   always shows what was actually built. If you want to change the
   version, edit VERSION - there is nothing to change in this file.

   Every release used to leave its old line commented out above this one;
   the history is in git now (git log VERSION) and in CHANGELOG.md.

   Keep this to ten lines. The CTEXT control it goes into is 80 dialog
   units tall in an 8pt font (see ID_ABOUTDIALOG in WPEAK.RC) and an
   eleventh line is clipped without warning. */

#define ABOUT_APP_NAME (                            \
  DEVICE_NAME "\r\n"                                \
  " S/N ... \r\n"                                   \
  "\n"                                              \
  APP_NAME " for Windows\n"                         \
  MODEL_CODE "  " PW_VERSION_STR "\n"               \
  "built " __DATE__ "\n"                            \
  "\n"                                              \
  "PID Analyzers (HNU Technology)\n"                \
  "1999-2026\n"                                     \
  " Warning: Only exit PW via File/Exit")

#ifndef WS_EX_STATICEDGE
#define WS_EX_STATICEDGE        0x00020000L
#endif

void AboutDialog::SetupWindow()
{
  Inherited::SetupWindow();
  Centralize(this);


  char program_code[45];
  wsprintf(program_code, "%lx-%08lx",high_code_part,code_number);

  Str descr=ABOUT_APP_DESCR;

  char buff[30];
  wsprintf(buff, "%d-point%s\r\n", POINTS()>1? POINTS(): 1, POINTS()>1? "s": "");
  descr+=buff;


#if POINTS()>1
  ultoa(POINTS(), buff, 10);
  strcat(program_code, "-");
  strcat(program_code, buff);
#endif


  descr+="\r\nProgram Code: ";
  descr+=program_code;


  SetDlgItemText(HWindow, IDD_ABOUT_APP_NAME, ABOUT_APP_NAME);
  SetDlgItemText(HWindow, IDD_ABOUT_APP_DESCR, descr);

  SetWindowLong( GetDlgItem(HWindow, IDD_ABOUT_APP_DESCR), GWL_EXSTYLE,
    GetWindowLong( GetDlgItem(HWindow, IDD_ABOUT_APP_DESCR), GWL_EXSTYLE)|WS_EX_STATICEDGE);

}

/*  - - - - - - - - - - - - - - - - - - */
PTWindowsObject newAboutDialog(PTWindowsObject AParent, int ResourceId, PTModule AModule)
{
  return new AboutDialog(AParent, ResourceId, AModule);
}









/* =====================================================================
   GC301c - build configuration.

       tools\build.bat gc301

   See config\gc323.h for what each section means; the layout is the
   same in every model file and every switch must be defined in all of
   them.

   !! REVIEW BEFORE THE FIRST 301 RELEASE !!
   Only the identity and the model-family switches below are known to be
   right for the 301 - they come from the DEVICE_NAME selection that used
   to live in src\MAINWIND.H (the 301c is the case where no other family
   flag is set). Everything from "sampling" down was seeded from
   config\gc323.h because the 301 settings were never written down
   anywhere; they lived only in whatever copy of INTERNAL.H the last 301
   was built from. Diff this file against that copy and correct it before
   shipping a 301 build. Known differences to check first:
     - POINTS()       the 301B ran 8-point and the 301c 12-point builds
     - OVEN_EQ_INJ()  was 1 on the 301B (one zone for oven and injector)
     - the board list - the 301 may not have the same USB hardware fitted
   ===================================================================== */

#ifndef  _MODELCFG_H
#define  _MODELCFG_H 1

/* --- product identity ------------------------------------------------- */

#define MODEL_CODE        "GC301"
#define MODEL_DEVICE_NAME "GC301c Process Gas Chromatograph"

/* --- how the PC talks to the instrument -------------------------------- */

#define INTERNAL()   1
#define INTERNAL_RC  1

/* --- model family switches ---------------------------------------------
   The 301c is the "none of the others" case: every family flag is 0. */

#define GC312()      0   /*                                     bit 58 */
#define GC321()      0   /*                                     bit 12 */
#define GC326()      0   /* GC323                                      */
#define GC501()      0   /*                                     bit 28 */
#define STAND_ALONE() 0  /*                                     bit 13 */
#define OPTICS()     0   /*                                     bit 34 */
#define OLIN()       0   /*                                     bit 39 */
#define DEMO()       0   /*                                     bit  3 */

/* --- sampling ---------------------------------------------------------- */

#define POINTS()             1   /* REVIEW: 8 on 301B, 12 on 301c */
#define HIGH_CONC_POINTS()   0
#define SAMPLE_AHEAD()       0   /*                             bit 32 */
#define QUICK_SCAN()         0
#define SCAN_CHANNELS()      0

/* --- oven, injector, temperature ---------------------------------------- */

#define OVEN_EQ_INJ()        0   /* REVIEW: was 1 on the 301B    bit  2 */
#define PULSING_OVEN()       1
#define RAMPING()            1   /*                             bit 19 */
#define TEMP_GRAPH()         0
#define HEATED_LINE()        0
#define TWO_COLUMNS()        0
#define WATER_PUMP()         0

/* --- detector ----------------------------------------------------------- */

#define FID()                0   /*                             bit 52 */
#define FLAME()              0   /*                             bit 22 */
#define TCD()                0   /*                             bit 35 */
#define CONCENTRATOR()       0   /*                             bit 21 */
#define HV_501()             1   /*                             bit 20 */

/* --- sensors ------------------------------------------------------------ */

#define IN_4_20()            0
#define PRESSURE_SENSOR()    0
#define H2_PRESSURE_SENSOR() 0
#define HUMIDITY_SENSOR()    0
#define FLOW()               1   /*                             bit 25 */
#define FLOW_RATE()          0

/* --- valves and relays -------------------------------------------------- */

#define X1_VALVE()           1   /*                             bit 43 */
#define MANUAL_INJ()         1   /*                             bit 62 */
#define TIME_MULT()          0

/* --- calibration and alarms --------------------------------------------- */

#define NO_CAL_START()       1   /*                             bit 31 */
#define REMOTE_CAL()         0   /*                             bit 26 */
#define ALL_ERR_CAL()        0   /*                             bit 29 */
#define NO_ALARMS()          1
#define ALARM_NC()           1   /*                             bit 42 */
#define COMMON_HIGH()        0   /*                             bit 45 */
#define DIAGNOSTICS()        0   /*                             bit 27 */

/* --- results and reporting ---------------------------------------------- */

#define USE_TOTAL()          0   /*                             bit 24 */
#define USE_DIFFERENCE()     0   /*                             bit 36 */
#define TOTAL_SUMMARY()      0
#define AREA_ALL()           0
#define BTU()                0
#define SHIFT_REPORT()       0   /* can be on in a 301          bit 38 */
#define SERIAL_NUMBER()      0
#define NOISE_REDUCT()       8   /*                             bit 44 */

/* --- analog outputs ------------------------------------------------------ */

#define ANALOG_OUTPUT()      0   /*                             bit 17 */
#define ANALOG_MIX()         0   /*                             bit 18 */
#define ANALOG_DELAYED()     0   /*                             bit 33 */

/* --- fieldbus ------------------------------------------------------------ */

#define MODBUS()             0   /*                             bit 46 */

/* --- data acquisition boards fitted -------------------------------------- */

#define Get_Data_Bipolar()   1   /*                             bit 16 */
#define CBW()                1   /*                             bit 14 */
#define PMD_16FS()           1   /*                             bit 40 */
#define PMD_12LS()           0   /*                             bit 41 */
#define PMD_12FS()           0   /*                             bit 47 */
#define CBWUSB_IO()          1   /*                             bit 48 */
#define USB_1024LS()         0
#define USB_DIO24()          0
#define USB_1024LS_2()       0
#define USB_DIO24_2()        0
#define USB_3101()           0   /*                             bit 60 */
#define USB_3103()           0   /*                             bit 61 */
#define USB_3106()           0   /*                             bit 63 */
#define USB_3112()           0   /*                             bit 59 */

#endif /* _MODELCFG_H */

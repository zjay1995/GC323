/* =====================================================================
   GC323 - build configuration.

   This file is the whole configuration for one product. Nothing here is
   edited before a build: pick the model on the command line instead.

       tools\build.bat gc323

   build.bat copies this file to src\MODELCFG.H, which src\INTERNAL.H
   includes. src\INTERNAL.H then derives everything that follows from
   these switches (board numbers, _NOCOMM, MAX_POINTS and so on) - keep
   derived values there, keep choices here.

   The bit numbers in the comments are the positions in the Program Code
   shown in the About box (see src\ABOUT.CPP). Do not renumber them; a
   customer reading a code back over the phone relies on them.

   Values were taken from the GC323 settings that were live in
   src\INTERNAL.H as of 2026-08-07 (WPEAK.EXE built 2026-08-10).
   ===================================================================== */

#ifndef  _MODELCFG_H
#define  _MODELCFG_H 1

/* --- product identity ------------------------------------------------
   MODEL_CODE is what a customer reads out of the About box.
   MODEL_DEVICE_NAME is the full name shown on the first About line. */

#define MODEL_CODE        "GC323"
#define MODEL_DEVICE_NAME "GC323 Gas Chromatograph"

/* --- how the PC talks to the instrument ------------------------------
   INTERNAL() 0 = external, over COM (GC311). 1 = internal, USB or an
   internal card. INTERNAL_RC must be defined when INTERNAL() is 1 and
   left undefined when it is 0 - the resource compiler cannot evaluate
   the () form. src\INTERNAL.H checks the two agree. */

#define INTERNAL()   1
#define INTERNAL_RC  1

/* --- model family switches -------------------------------------------
   Exactly one of these selects the instrument family. GC326() is the
   GC323 flag: the name is historical (the GC323 oven door behaves
   differently from the GC321/322) and the code still reads GC326(), so
   it stays. MODEL_CODE above is the name we actually publish. */

#define GC312()      0   /*                                     bit 58 */
#define GC321()      0   /* GC321/GC322, works with valves      bit 12 */
#define GC326()      1   /* GC323                                      */
#define GC501()      0   /*                                     bit 28 */
#define STAND_ALONE() 0  /* Wpeak Integrator                    bit 13 */
#define OPTICS()     0   /* Optics Works                        bit 34 */
#define OLIN()       0   /*                                     bit 39 */
#define DEMO()       0   /* view/analyse only, no hardware      bit  3 */

/* --- sampling --------------------------------------------------------- */

#define POINTS()             1   /* sample points; appended to the code */
#define HIGH_CONC_POINTS()   0
#define SAMPLE_AHEAD()       0   /*                             bit 32 */
#define QUICK_SCAN()         0
#define SCAN_CHANNELS()      0

/* --- oven, injector, temperature -------------------------------------- */

#define OVEN_EQ_INJ()        0   /* 1 = one zone for oven+injector bit 2 */
#define PULSING_OVEN()       1
#define RAMPING()            1   /* temperature ramping         bit 19 */
#define TEMP_GRAPH()         0
#define HEATED_LINE()        0
#define TWO_COLUMNS()        0
#define WATER_PUMP()         0

/* --- detector --------------------------------------------------------- */

#define FID()                0   /* flame ionization detector   bit 52 */
#define FLAME()              0   /*                             bit 22 */
#define TCD()                0   /*                             bit 35 */
#define CONCENTRATOR()       0   /*                             bit 21 */
#define HV_501()             1   /* lamp control via 501 HV board bit 20 */

/* --- sensors ---------------------------------------------------------- */

#define IN_4_20()            0   /* shift for a 4-20 mA input          */
#define PRESSURE_SENSOR()    0
#define H2_PRESSURE_SENSOR() 0
#define HUMIDITY_SENSOR()    0
#define FLOW()               1   /* show carrier/column flow    bit 25 */
#define FLOW_RATE()          0   /* switch flow rate high/low          */

/* --- valves and relays ------------------------------------------------ */

#define X1_VALVE()           1   /* user-programmable relays    bit 43 */
#define MANUAL_INJ()         1   /* no valves, manual injection bit 62 */
#define TIME_MULT()          0   /* allow injection time < 1 s         */

/* --- calibration and alarms ------------------------------------------- */

#define NO_CAL_START()       1   /* 1 = no auto calibration on power ON bit 31 */
#define REMOTE_CAL()         0   /*                             bit 26 */
#define ALL_ERR_CAL()        0   /*                             bit 29 */
#define NO_ALARMS()          1
#define ALARM_NC()           1   /* NC relays for HL alarms     bit 42 */
#define COMMON_HIGH()        0   /*                             bit 45 */
#define DIAGNOSTICS()        0   /*                             bit 27 */

/* --- results and reporting -------------------------------------------- */

#define USE_TOTAL()          0   /* total concentration         bit 24 */
#define USE_DIFFERENCE()     0   /*                             bit 36 */
#define TOTAL_SUMMARY()      0
#define AREA_ALL()           0
#define BTU()                0
#define SHIFT_REPORT()       0   /*                             bit 38 */
#define SERIAL_NUMBER()      0
#define NOISE_REDUCT()       8   /* noise divider, known peaks  bit 44 */

/* --- analog outputs --------------------------------------------------- */

#define ANALOG_OUTPUT()      0   /*                             bit 17 */
#define ANALOG_MIX()         0   /* multipoint, one output set  bit 18 */
#define ANALOG_DELAYED()     0   /*                             bit 33 */

/* --- fieldbus --------------------------------------------------------- */

#define MODBUS()             0   /*                             bit 46 */

/* --- data acquisition boards fitted -----------------------------------
   src\INTERNAL.H turns these into the CBWDEVICE_* board numbers the
   Universal Library is opened with. Change them only to match the
   hardware actually in the instrument. */

#define Get_Data_Bipolar()   1   /*                             bit 16 */
#define CBW()                1   /* Universal Library in use    bit 14 */
#define PMD_16FS()           1   /* USB-1608FS A/D + DIO        bit 40 */
#define PMD_12LS()           0   /* USB-1208LS                  bit 41 */
#define PMD_12FS()           0   /* USB-1208FS                  bit 47 */
#define CBWUSB_IO()          1   /* USB DIO24 digital I/O       bit 48 */
#define USB_1024LS()         0
#define USB_DIO24()          0
#define USB_1024LS_2()       0
#define USB_DIO24_2()        0
#define USB_3101()           0   /* USB-3101 D/A                bit 60 */
#define USB_3103()           0   /* USB-3103 D/A                bit 61 */
#define USB_3106()           0   /* USB-3106 D/A                bit 63 */
#define USB_3112()           0   /* USB-3112 D/A                bit 59 */

#endif /* _MODELCFG_H */

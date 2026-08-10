/* =====================================================================
   M30 - build configuration.

       tools\build.bat m30

   !! STUB - NOT SHIPPABLE YET !!
   The source tree has no M30 anywhere in it: no M30() switch, no M30
   branch in the old DEVICE_NAME selection, nothing. So there is no
   previous configuration to copy and nothing here has been verified
   against a real instrument.

   What is real:
     - MODEL_CODE / MODEL_DEVICE_NAME below. Because the product name now
       comes from this file rather than from a #elif chain in
       src\MAINWIND.H, an M30 build already identifies itself correctly
       in the About box without any code change.

   What is not real:
     - every switch from "sampling" down. They are copied from
       config\gc323.h so that the file compiles, not because the M30 is
       a GC323.

   Before the first M30 release, someone who knows the instrument must
   go through the switches below. If the M30 needs behaviour none of the
   existing flags cover, add an M30() switch here and use it in the code
   the same way GC326() is used - do not overload another model's flag.

   VERSION starts this product at 0.1.0 to make it obvious it has not
   shipped. Bump it to 1.0.0 with the first release.
   ===================================================================== */

#ifndef  _MODELCFG_H
#define  _MODELCFG_H 1

/* --- product identity ------------------------------------------------- */

#define MODEL_CODE        "M30"
#define MODEL_DEVICE_NAME "M30 Gas Chromatograph"

/* --- how the PC talks to the instrument -------------------------------- */

#define INTERNAL()   1
#define INTERNAL_RC  1

/* --- model family switches ---------------------------------------------- */

#define GC312()      0   /*                                     bit 58 */
#define GC321()      0   /*                                     bit 12 */
#define GC326()      0   /* GC323                                      */
#define GC501()      0   /*                                     bit 28 */
#define STAND_ALONE() 0  /*                                     bit 13 */
#define OPTICS()     0   /*                                     bit 34 */
#define OLIN()       0   /*                                     bit 39 */
#define DEMO()       0   /*                                     bit  3 */

/* --- sampling ------------------------------------------- UNVERIFIED --- */

#define POINTS()             1
#define HIGH_CONC_POINTS()   0
#define SAMPLE_AHEAD()       0   /*                             bit 32 */
#define QUICK_SCAN()         0
#define SCAN_CHANNELS()      0

/* --- oven, injector, temperature ------------------------ UNVERIFIED --- */

#define OVEN_EQ_INJ()        0   /*                             bit  2 */
#define PULSING_OVEN()       1
#define RAMPING()            1   /*                             bit 19 */
#define TEMP_GRAPH()         0
#define HEATED_LINE()        0
#define TWO_COLUMNS()        0
#define WATER_PUMP()         0

/* --- detector ------------------------------------------- UNVERIFIED --- */

#define FID()                0   /*                             bit 52 */
#define FLAME()              0   /*                             bit 22 */
#define TCD()                0   /*                             bit 35 */
#define CONCENTRATOR()       0   /*                             bit 21 */
#define HV_501()             1   /*                             bit 20 */

/* --- sensors -------------------------------------------- UNVERIFIED --- */

#define IN_4_20()            0
#define PRESSURE_SENSOR()    0
#define H2_PRESSURE_SENSOR() 0
#define HUMIDITY_SENSOR()    0
#define FLOW()               1   /*                             bit 25 */
#define FLOW_RATE()          0

/* --- valves and relays ---------------------------------- UNVERIFIED --- */

#define X1_VALVE()           1   /*                             bit 43 */
#define MANUAL_INJ()         1   /*                             bit 62 */
#define TIME_MULT()          0

/* --- calibration and alarms ----------------------------- UNVERIFIED --- */

#define NO_CAL_START()       1   /*                             bit 31 */
#define REMOTE_CAL()         0   /*                             bit 26 */
#define ALL_ERR_CAL()        0   /*                             bit 29 */
#define NO_ALARMS()          1
#define ALARM_NC()           1   /*                             bit 42 */
#define COMMON_HIGH()        0   /*                             bit 45 */
#define DIAGNOSTICS()        0   /*                             bit 27 */

/* --- results and reporting ------------------------------ UNVERIFIED --- */

#define USE_TOTAL()          0   /*                             bit 24 */
#define USE_DIFFERENCE()     0   /*                             bit 36 */
#define TOTAL_SUMMARY()      0
#define AREA_ALL()           0
#define BTU()                0
#define SHIFT_REPORT()       0   /*                             bit 38 */
#define SERIAL_NUMBER()      0
#define NOISE_REDUCT()       8   /*                             bit 44 */

/* --- analog outputs ------------------------------------- UNVERIFIED --- */

#define ANALOG_OUTPUT()      0   /*                             bit 17 */
#define ANALOG_MIX()         0   /*                             bit 18 */
#define ANALOG_DELAYED()     0   /*                             bit 33 */

/* --- fieldbus ------------------------------------------- UNVERIFIED --- */

#define MODBUS()             0   /*                             bit 46 */

/* --- data acquisition boards fitted --------------------- UNVERIFIED --- */

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

void Acquire::AutoZero(BOOL on) // P.P. modified 06/07/03 to work with DAQ + REL_16.
{
  char pbuf[127];
  sprintf(pbuf, "Acquire::AutoZero(%d)", on ); logit(pbuf);

#if !STAND_ALONE() // added. P.P. 08/02/03
#if CBW() // the must for PMD
int err_code = 0; // added error handling. P.P. 10/16/05
#if PMD_12LS()||CBWUSB_IO()
#if PMD_16FS()  // case added, 2 boards + relays. P.P. 11/25/06
  err_code = My_cbDBitOut (CBWDEVICE_16FS, AUXPORT, 0, on? 1: 0); // out bit 7 in PMD_1608FS, P.P. 11/28/04
  if(err_code) { // DEBUG
    Str str="USB_1608FS error";
//    MessageBox(NULL,str, "wPeak: USB relay board error", MB_OK); // rem. P.P. 11/25/06
  }
#else // only pmd_12ls
#if PMD_12LS()
  err_code = My_cbDBitOut (CBWDEVICE_12LS, FIRSTPORTA, 0, on? TRUE: FALSE);
  sprintf(pbuf, "PMD_12LS Acquire::AutoZero(%d)", on ); logit(pbuf);
out bit 0 in PMD_1208LS, P.P. 10/16/05
  if(err_code) { // DEBUG
    Str str="USB_1208LS error";
//    MessageBox(NULL,str, "wPeak: USB relay board error", MB_OK); // rem. P.P. 11/25/06
  }
#elif USB_IO()
  err_code = My_cbDBitOut (USB_IO, FIRSTPORTA, 0, on? TRUE: FALSE); // out bit 0 in PMD_1208LS, P.P. 10/16/05
  sprintf(pbuf, "USB_IO Acquire::AutoZero(%d)", on ); logit(pbuf);
#endif
#endif // pmd_16fs
#elif PMD_16FS()
  err_code = My_cbDBitOut (CBWDEVICE_16FS, AUXPORT, 0, on? 1: 0); // out bit 0 in PMD_1608FS, P.P. 11/28/04
  sprintf(pbuf, "PMD_16fs() Acquire::AutoZero(%d)", on ); logit(pbuf);
  if(err_code) { // DEBUG
    Str str="USB_1608FS error";
//    MessageBox(NULL,str, "wPeak: USB relay board error", MB_OK); // rem. P.P. 11/25/06
  }
#endif // PMD_16 vs 12. P.P. 11/07/04
#endif // cbw
#else //stand-alone case. P.P. 11/01/15
#if PMD_16FS()
  int err_code = 0; // added error handling. P.P. 10/16/05
  err_code = My_cbDBitOut (CBWDEVICE_16FS, AUXPORT, 0, on? 1: 0); // out bit 0 in PMD_1608FS, P.P. 11/28/04
  sprintf(pbuf, "PMD_16FS() Acquire::AutoZero(%d)", on ); logit(pbuf);
  if(err_code) { // DEBUG
    Str str="USB_1608FS error";
//    MessageBox(NULL,str, "wPeak: USB relay board error", MB_OK); // rem. P.P. 11/25/06
  }
#endif // 1608 board
#endif // !stand_alone. P.P. 08/02/03
}


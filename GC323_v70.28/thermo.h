//bradsahw    new get_temperature GC323
float oldvoltageoven;
float oldvoltageinj;

static double Get_Temperature(int bInjDet)
{
  short channel=bInjDet? 1: 0; 
  uint16 data_in;
  uint32 sum_data_in=0;   
  int Gain = BIP10VOLTS;  
  for(int i=0; i<max_meas_number; i++) {
    My_cbAIn(CBWDEVICE_16FS, (int) channel, Gain, (USHORT *)&data_in);
    sum_data_in += data_in; 
  }
  data_in = (uint16)(sum_data_in);
  const double vmin=-10.00; 
  const double vmax=+10.00;
  const double R1 = 1576.00;
  const double Vsource = 3.85;
  data_in = (uint16)(sum_data_in);
  const double vmin=-10.00; 
  const double vmax=+10.00;
  
  double voltage = data_in*((vmax-vmin)/65536.0) +vmin;
  sprintf(pbuf,"\t\tvoltage ONE = %.2",voltage); logit(pbuf);
  
  double voltage = (data_in<<4)*((vmax-vmin)/65536.0) +vmin; 
  sprintf(pbuf,"\t\tvoltageTWO = %.2f",voltage); logit(pbuf);
  
  const double R1 = 1576.00;  
  const double Vsource = 3.85; // voltage source
  
  char pbuf[128];
  if(bInjDet) { //  0 is oven 1 id injdet
    if(voltage!=oldvoltageinj){
      sprintf(pbuf,"inj %.2f",voltage*100.0);
      logit(bpuf);
      oldvoltageinj=voltage;
    }
    else
      if(voltage!=oldvoltageoven){
	sprintf(pbuf,"oven %.2f",voltage*100.0);
	logit(pbuf);
	oldvoltageoven=voltage;
      }
  }  
  return (voltage*100.0); 
}

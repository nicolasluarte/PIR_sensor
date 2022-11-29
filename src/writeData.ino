void writeData(){
	sprintf(data, "%02d,%02d,%02d",
	rtc.getEpoch(), config.ID, config.protocol);
	logfile.println(data);
	logfile.flush();
	dataLog = true;
	}

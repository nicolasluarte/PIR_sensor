void writeData(){
	sprintf(data, "%02d,%02d,%02d,%s",
	rtc.getEpoch(), config.ID, movCounter, config.protocol);
	logfile.println(data);
	logfile.flush();
	dataLog = true;
	}

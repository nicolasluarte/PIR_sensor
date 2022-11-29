void displayChar(char *msg){
	display.clearDisplay();
	display.setRotation(3);
	display.setTextColor(BLACK);
	display.setCursor(0, 10);
	display.setTextSize(3);
	display.println(msg);
	display.refresh();
}

void displayInt(int msg){
	display.clearDisplay();
	display.setRotation(3);
	display.setTextColor(BLACK);
	display.setCursor(0, 10);
	display.setTextSize(3);
	display.println(msg);
	display.refresh();
}

void displayExperimentInfo(){
	display.clearDisplay();
	display.setRotation(3);
	display.setTextColor(BLACK);
	display.setCursor(0, 10);
	display.setTextSize(3);
	// contains all relevant info with format
	// mora then enough bytes
	char experimentalInfo[80];
	unsigned long epoch = rtc.getEpoch();

	sprintf(experimentalInfo,
		"ID: %02d\n\Cond: %s\nTime: %02d:%02d:%02d\nBattery: %d",
		config.ID,
		config.protocol,
		hour(epoch),
		minute(epoch),
		second(epoch),
		batt
	);

	display.println(experimentalInfo);
	display.refresh();
	// no need to refresh if there is no new data
	blockDisplay = true;
	}

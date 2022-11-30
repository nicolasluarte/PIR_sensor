#include "headers.h"

// config file path
const char *configurationFile = "/config.txt";
// create Config instance
Config config;

// movement cumulative counter
int movCounter = 0;
// pir block
bool pirBlock = false;
// screen bool so it does not refresh every tick
bool screen = true;

void setup(){
	// sharmem setup
	display.begin();
	display.clearDisplay();

	rtc.begin();
	Wire.begin();

	// 1 min calibration
	// during this time avoid movement detection
	for(int i = 0; i <= CALIBRATION_TIME; i++){
		displayChar("Calibrating...");
		delay(1000);
		}
	displayChar("Calibration done!");
	delay(1000);


	// pins
	pinMode(PIR, INPUT);
	displayChar("PIR sensor up!");
	delay(1000);

	// SD
	sdSetup();
	delay(1000);

	// read config file
	loadConfiguration(configurationFile, config);
	printFile(configurationFile);
	displayChar("Config file loaded!");
	delay(1000);

	// create the logfile
	sprintf(PIRLog, "%02d.csv", config.ID);
	logfile = SD.open(PIRLog, FILE_WRITE);
	displayChar("Logfile created!");
	delay(1000);

	// clear screen
	display.clearDisplay();

}

void loop(){
	// create headers
	createHeaders();
	// read PIR sensor
	val = digitalRead(PIR);
	if (val == HIGH){
		if (!pirBlock){
			movCounter++;
			displayChar("Movement detected!");
			delay(250);
			displayInt(movCounter);
			delay(250);
			// save to SD
			writeData();
			// just to be sure that data is written properly
			// no problem to add delay here as the sensor
			// take about ~5 seconds to get another signal
			delay(100);
			// make only 1 count every detection round
			pirBlock = true;
			// wait for sensor to reload
			delay(5000);
			// set screen to refresh again
			screen = true;
			}
	}
	else{
		pirBlock = false;
		if (screen){
			display.clearDisplay();
			displayChar("Detecting...");
			screen = false;
		}
		delay(100);
		}
}

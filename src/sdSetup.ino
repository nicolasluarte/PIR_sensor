void sdSetup(){
	if (SD.begin(4)){
		displayChar("SD SUCCESS!");
		delay(1000);
		}
	else{
		while(true){
			displayChar("SD ERROR!");
			delay(1000);
			}
			}
		}

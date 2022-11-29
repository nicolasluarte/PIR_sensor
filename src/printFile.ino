void printFile(const char *filename){
// open file for reading
	File file = SD.open(filename);
	if (!file) {
		Serial.println(F("Failed to read file"));
		return;
	}

	while (file.available()){
		Serial.print((char)file.read());
	}
	Serial.println();

	file.close();
}

void loadConfiguration(const char *filename, Config &config){
	// Open file for reading
	// configuration is on a json format
	File file = SD.open(filename);

	// Allocate a temporary JsonDocument
	// change capacity accordingly
	StaticJsonDocument<1028> doc;

	// Deserialize the JSON document
	// Desrialize: go from file into objects
	DeserializationError error = deserializeJson(doc, file);
	if (error)
	  Serial.println(F("Fail, using default config"));
		

	// Copy values from the JsonDocument to the config
	config.ID = doc["ID"] | 000;
	// protocol can be of variable length
	// with this we set the correct amount of bytes
	strlcpy(
		config.protocol,
		doc["protocol"] | "default",
		sizeof(config.protocol)
		);
	file.close();
}

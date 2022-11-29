// included libs
//
//
#include <Wire.h>

// SD
#include <SD.h>
#include <SPI.h>

// configuration file
#include <ArduinoJson.h>

// sharpmem
#include <Adafruit_SharpMem.h>
#include <Fonts/FreeSans9pt7b.h>
#include <stdio.h>
bool blockDisplay = false;

// PIR
#define CALIBRATION_TIME 60

// time related libs
#include <RTCZero.h>
#include <TimeLib.h>

// time related variables
int tmonth, tday, tyear, thour, tminute, tsecond;
char s_month[5];
static const char month_names[] = "JanFebMarAprMayJunJulAugSepOctNovDec";
byte months = 1;
byte days = 1;
byte years = 1;
byte hours = 1;
byte minutes = 1;
byte seconds = 1;

// feather m0 pins
#define VBATPIN A7
#define cardSelect 4
#define PIR 9
#define SHARP_SCK  13
#define SHARP_MOSI 11
#define SHARP_SS   10
#define BLACK 0
#define WHITE 1
Adafruit_SharpMem display(SHARP_SCK, SHARP_MOSI, SHARP_SS, 144, 168);
int minorHalfSize;

// relevant objects
RTCZero rtc;
File logfile;
char timeStampString[30];

// write data
bool dataLog = false;
char data[60];
char PIRLog[30];

// battery
float measuredvbat = 1.00;
int batt;

// configuration structure
struct Config{
	char protocol[64];
	int ID;
};

// PIR variable
int val;

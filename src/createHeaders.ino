void createHeaders(){
	if (logfile.size() ==0){
		logfile.println("time,ID,count,protocol");
		}
	logfile.flush();
		}

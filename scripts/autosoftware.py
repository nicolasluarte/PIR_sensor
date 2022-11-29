import os
import pyfiglet


print(pyfiglet.figlet_format("PIR CLOCK SYNC"))
cmdClock = 'sudo pio run -d ~/repos/RTC_clock -t upload'
os.system(cmdClock)
print(pyfiglet.figlet_format("CLOCK SYNC DONE!"))

print(pyfiglet.figlet_format("PIR CONTROL"))
cmdDelayControl = 'sudo pio run -d ~/repos/PIR_sensor -t upload'
os.system(cmdDelayControl)
print(pyfiglet.figlet_format("PIR CONTROL UPLOADED!"))


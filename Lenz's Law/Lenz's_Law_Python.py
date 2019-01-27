# Import dependencies
import serial
import matplotlib.pyplot as plt
import numpy as np

# Variable Declaration
analogData=[]   # create buffer to store analog values
num_val=0         # maintain number of analog values read
data=0
ref=0
flag=True

# Setup connection with arduino
# Don't forget to update com port
arduinoData=serial.Serial('com5',115200)

# Function to ommit out garbage value
# Only pass integer values
def is_Int(s):
    try: 
        int(s)
        return True
    except ValueError:
        return False


while(flag):
    while(arduinoData.inWaiting==0):  # Waiting until arduino didn't send any data
        pass
    data=arduinoData.readline()     # Read Data from arduino
    print data                                        # Print data
    data=data[:-2:]                              # Remove new line and carriage return character
    if(is_Int(data)) :                            # Check for garbage value
		if(int(data)==3000):         # Stop reading data
			break
		else:                                      # Conversion of 10-bit ADC value into our original value
			data=float(data)
			data=(data*5)/1023
			data=data-2.5
			data=(data*1068)/68
			if(num_val==0) :    # set first value as refrence
				ref=data
				data=data-ref
			else:
				data=data-ref
			analogData.append(data) # add analog values in buffer
			print num_val                                 
			num_val=num_val+1
# arduino send time at which magnet interact with hall sensor
# Read time intervals
n=0
timeInterval=[]  #buffer to store time intervals
while(n<2):       # two magnet-sensor interaction
	while(arduinoData.inWaiting==0):     # Waiting until arduino didn't send any data
		pass
	data=arduinoData.readline()               # Read Data from arduino
	data=data[:-2:]                                         # Remove new line and carriage return character
	if(is_Int(data)) :
		timeInterval.append(int(data))  # add value in time interval buffer
		n=n+1

totalTime=timeInterval[1]-timeInterval[0]  # total time taken by magnet
time=np.linspace(0,totalTime,num_val)   # generating  time array to plot 
plt.plot(time,analogData,'y-')   # ploting analogData vs time
plt.grid(True)                                # enable grid on plot
plt.ylabel('Voltage (in V)')         # Y-axis label
plt.xlabel('Time (in ms) ')          # X-axis label
plt.show()

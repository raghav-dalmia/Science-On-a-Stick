# Science-On-a-Stick
Science on a Stick, as the name suggests, it is an experimental setup based on Python and Arduino, was developed to verify various laws of Physics such as Lenz's Law, Faraday's Law and Laws of Motion.

We have provided schematics of circuits and code for this project.

# Installation

## To install Arduino IDE
Click [here](https://www.arduino.cc/en/Main/Software) to download Arduino IDE.

## To setup up Python Environment
To download Python IDE, click [here](https://www.python.org/downloads/release/python-2715/).

**Note:-** t would be preferable to download the latest version Python2.7.

### To set up environment variables
----
**Windows 10 and Windows 8**

1. In Search, search for and then select: System (Control Panel)

2. Click the Advanced system settings link.

3. Click Environment Variables. In the section System Variables, find the PATH environment variable and select it. Click Edit. If the PATH environment variable does not exist, click New.

4. In the Edit System Variable (or New System Variable) window, specify the value (location of the folder where python installed) of the PATH environment variable. Click OK. Close all remaining windows by clicking OK.

5. Open Command prompt window, and run following command:
    
       python --version
       pip --version
       
 If pip is not installed in your laptop, refer [this.](https://github.com/pypa/get-pip)
## Install dependencies of python code
open Command prompt or terminal and run this command
    
    pip install pyserial
    pip install matplotlib
    pip install numpy

## To Install Eagle
Download Eagle (PCB design software) from this [link.](https://www.autodesk.in/products/eagle/free-download?referrer=%2Fproducts%2Feagle%2Ffree-download)

Open the given board layouts and fabricate them. The schematic folder has three schematics and their board layouts. 

**Images of Fabricated Board and coil**
---------------------------------------
![main_board](https://github.com/raghav-dalmia/Science-On-a-Stick/blob/master/Images/PCB.jpeg)

![sensor](https://github.com/raghav-dalmia/Science-On-a-Stick/blob/master/Images/Sensor.jpg)

![coil](https://github.com/raghav-dalmia/Science-On-a-Stick/blob/master/Images/Coil.jpeg)

**!! More than 1000 turns (36 gauge copper wire) of coil winding can destroy the circuit**

# Usage

## Law's of MOtion

Set the experimental tube as shown in [picture.](https://github.com/raghav-dalmia/Science-On-a-Stick/blob/master/Images/Law's%20of%20Motion%20Setup.jpeg)

1. open Arduino IDE and upload `Laws_of_Motion` code.

2. For law's motion open the serial monitor and enter values asked by monitor.

**Output**
----------
![output](https://github.com/raghav-dalmia/Science-On-a-Stick/blob/master/Images/Picture-12%20(2).jpeg)

## Lenz's Law

Set the experimental setup as shown in [picture.](https://github.com/raghav-dalmia/Science-On-a-Stick/blob/master/Images/Lenz's%20Law%20Setup.jpeg)

1. Open Arduino IDE and upload `Lenz_s_Law_Arduino` code.
2. Open python code and change com port value(in Windows its `com5`, in Linux its `/dev/ttyUSB0`)
    
       arduinoData=serial.Serial('com5',115200)
3. Open Command prompt or terminal and  change current working directory to directory of this python code using
         
       cd <complete-path>
4. Run python code by the following command

       python "Lenz's_Law_Python.py"
   
**Output**
----------
![output1](https://github.com/raghav-dalmia/Science-On-a-Stick/blob/master/Images/Picture-9%20(2).jpeg)

![output2](https://github.com/raghav-dalmia/Science-On-a-Stick/blob/master/Images/Screenshot%20(119).png)
       
# Credits
This experimental setup is developed under the guidance of Prof. D.V. Gadre, Director CEDT, NSUT.



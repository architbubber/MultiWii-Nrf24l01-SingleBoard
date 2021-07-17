# MultiWii-Nrf24l01-SingleBoard
This is MultiWii code modified to work using Nrf24l01 as receiver on a single board and added support for BMP280.
For QuadX the pins are remapped to 3,5,6,9 and the Nrf use 7,10 for CE ,CSN.
After uploadng and connecting to multiwii gui, if no imu values are being received,
then there's an issue with the nrf module or it's wiring.
If you are receiving values and Aux4 is high ,then nrf is connected to transmitter 
else if Aux4 is low then no signal is being recieved from transmitter.
This code is tested and tried 
Happy Flying :)

(P.S. If you are using this code for airplane/flying wing .etc 
better go for the airplane specific version developed for this 
https://github.com/architbubber/Nrf-Multiwii-Airplane )

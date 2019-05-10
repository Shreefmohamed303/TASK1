/********************************************************************************
 * Module : NODEMCU
 *
 * File Name : task1
 *
 * Description : - switch on/ off internal led 
 *               - Get Reading from any anlog sensor and print the result to serial port 
 * Author : Shreef Mohamed
 *
 * Created on: may 9, 2019
 *
 ********************************************************************************/

 
#define LED_BUILTIN D10 
#define ANALOG_PIN A0

 /*******************************************************************************
  *                     FUNCTIONS PROTOTYPE                                     *
  *******************************************************************************/
void SWITCHING_LED (void); 
void SENSOR_READ (void);


int sensor_value=0; 

 /*******************************************************************************
  *                     THE MAIN CODE                                     *
  *******************************************************************************/
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
  Serial.begin(9600);              // initialize serial communications at 9600 bps:
}

// the loop function runs over and over again forever
void loop() {
SWITCHING_LED(); 
SENSOR_READ();
}


 /*******************************************************************************
  *                     FUNCTIONS DEFINATION                                     *
  *******************************************************************************/
  
// FUNCTION TO READ ANALOG SENSOR AND PRINT THE RESULT ON SERIAL PORT 
void SENSOR_READ(void)
{
   sensor_value=analogRead(ANALOG_PIN) ; // Get the value from the sensor 
  delay(100);                          // wait for miliseconds 
  Serial.print("THE Sensor Value is ");
  Serial.println(sensor_value);      // print the result of the sensor to the serial port  
 }


//FUNCTION TO SWITCH THE INTERNAL LED ON/OFF
void SWITCHING_LED (void)
{
   digitalWrite(LED_BUILTIN, LOW);   // Turn the LED on by putting zero(LOW) 
                                    // as it is acive low on 
  delay(1000);                      // Wait for a second
  digitalWrite(LED_BUILTIN, HIGH);  // Turn the LED off by putting one (HIGH)
  delay(1000);                      // Wait for a second 

 }

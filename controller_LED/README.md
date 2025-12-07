**Day 1 of the Master IOT Journey**

*NOTE*
2 types: HIGH and LOW => indicate VOLTAGE LEVEL
digitalRead() is read VOLTAGE LEVEL
digitalWrite() is generate VOLTAGE LEVEL


1. Control 1 LED
<img width="1388" height="601" alt="image" src="https://github.com/user-attachments/assets/17cc91a3-a8dc-4618-950d-97b35c7f5e15" />

2. Control 3 LED
<img width="1428" height="626" alt="image" src="https://github.com/user-attachments/assets/0b45850f-7a78-489c-bc62-d0f3e7930e8e" />

3. Button
<img width="633" height="715" alt="image" src="https://github.com/user-attachments/assets/5b02fcaa-26bf-45fc-a9e0-50fcaa579e58" />

*Operating Principle*

These pins that has the same number (1a, 1b) or (2a, 2b) is always connect. But, these difference pins number (1 - 2) is not connect. They only connect when push the button.
When push the button, the electric move from postive to negative. Example, in above image, I use resistor has value = 10k (Ohm) and supply power 30(V). So, I can calculate value of I based on Ohm's law 

        I = U/R = 30/10000 = 3 (mA)

<img width="1448" height="630" alt="image" src="https://github.com/user-attachments/assets/eab12b60-5c52-4169-a7e5-99ce34620bfd" />

Therefore, only when press the button, the current intensity (I) move from (2b (+)) to (1b (-)), cause difference U -> state of button change from LOW -> HIGH.

*NOTE*
The resistor of pin in Arduino is about 100.000.000 Ohm (very big) -> these pins no draw I (becase follow Ohm's LAW, when R >> -> I ~ 0)
But, when press button, U from 2b -> button -> 1a -> pin2 of arduino.

_Reason of choose resitor 10k Ohm to connect button with GND:_
+ With R = 10.000 -> I = U/R = 5/1000 = 5 (mA) << very small -> safe for board Arduino. If I >>, when I comeback GND of Arduino, it causes hot and danger for board Arduino.
+ Save power :v 


4. INPUT_PULLUP

PULL_UP, it means PULL UP value of register on Arduino -> (20k, 50k Ohm)
<img width="1345" height="629" alt="image" src="https://github.com/user-attachments/assets/8d6e20f4-4e6a-4f56-a3d6-bfdb3b908b31" />

Alternation for resistor 10k Ohm, I can use technical INPUT_PULLUP

When we use PULLUP, the Arduino auto connect VCC (5V) with pin D2 through register, which PULL UP when I declear pinMode(button, INPUT_PULLUP). When I haven't press button, 5V -> Resistor (PULLUP) -> D2, so pin D2 read voltage level HIGH because VCC pull pin D2 up HIGH, but in fact, not have current intensity run in board because I dont have place that for current intensity reduce 0 (which we call GND), but when I haven't press button, board not connect with GND :v 
I can caculate value of Voltage level at pin D2 by:

                V_D2 = I * R2
                V_D2 = (U/R) * R2
                V_D2 = (5/R2 + R_pullup) ~ 5V
                
When I press the button, open board -> close board. Current intensity run 5V -> register -> button (2a) -> button (1b) -> GND. At this time, current intensity from pin from D2 to GND faster than current intensity from 5V -> pin D2 because between D2 and GND dont have rerister, so it cause pull down for pin D2. Now, pin D2 can consider dont have Voltage level, because Voltage output >> Voltage input -> digitalRead(button) return value LOW. 

                

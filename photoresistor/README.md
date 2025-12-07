**Arduino Photoresistor (MS-CDS05)**
-----------------------------------------------------------
This project demonstrates how to use the MS-CDS05 photoresistor module with an Arduino to measure light intensity through the analogRead() function.

📸 Sensor Module: MS-CDS05
<img width="1401" height="623" alt="MS-CDS05" src="https://github.com/user-attachments/assets/1a3f4a00-e249-4484-826a-616a0865be87" />

The MS-CDS05 module outputs an analog voltage corresponding to ambient light:

More light → lower resistance → lower voltage → lower ADC value

Less light → higher resistance → higher voltage → higher ADC value

Explain:

When shine more light into Photoresistor (which has typical components) LDR (Light Dependent Resistor), it causes more freedom electron -> better conductor of electricity -> lower resistor.

**But, why better conductor of electricity, voltage level lower? (do have conflict at here?)**

In fact, the structor of LDR is devider circuit. When resistor of LDR low, it also lead to voltage through it low -> value ADC low.


🔌 Wiring

Connect the module's A0 pin to Arduino A0:
<table>
    <thead>
        <tr>
            <th>MS-CDS05</th>
            <th>Arduino</th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td>VCC</td>
            <td>5V</td>
        </tr>
        <tr>
            <td>GND</td>
            <td>GND</td>
        </tr>
      <tr>
            <td>A0</td>
            <td>A0</td>
        </tr>
      <tr>
            <td>D0</td>
            <td>Pin 2</td>
        </tr>
    </tbody>
</table>


D0 (optional)	Any digital pin (if you want digital threshold output)

For this project, only the A0 → A0 analog connection is used.

📖 Reading ADC Values

Arduino’s analogRead(A0) returns a 10-bit ADC value in the range:

0 – 1023


You can interpret this ADC value using the formula:

ADC = (Voltage_Level / Voltage_Supply) * 1023


Where:

Voltage_Level is the voltage measured at pin A0

Voltage_Supply is typically 5V on Arduino Uno


Strong light → voltage low → ADC low

Weak light → voltage high → ADC high


**Analog combine Digital**
_______________________________________

Circuit
<img width="1596" height="575" alt="image" src="https://github.com/user-attachments/assets/9a02f436-94fd-4c1c-8bb1-4343ffc90865" />

**Operating Principle**
In the module MS-CDS05, it has potentiometer (can adjust value). It can be consider a threshold of value. If value of ADC < Threshold -> state of pin D2 is LOW (= 0), else if value of ADC > Threshold -> state of pin D2 is HIGH (= 1) 

State of pin D2 independent on A0, but pin D2 use ADC which value read from A0 to compare with value Threshold to return value of state.

Conclusion:

+ If more light -> ADC low -> ADC < Threshold -> state = 0

+ If low light -> ADC high -> ADC > Threshold -> state = 1


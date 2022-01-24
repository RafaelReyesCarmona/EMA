/**
 * Example sketch for the EMA library.
 */

 #include <EMA.h>

 #define PIN_READ A0

void setup() {
    pinmode(PIN_READ, INPUT);

}

void loop(){
    uint16_t read;
    uint16_t read_filtered;
    static EMA<2> EMA_filter(250);  // Initial value for EMA filter.

    read = analogRead(PIN_READ);
    read_filtered = EMA_filter(read);

    Serial.print("Read from ADC : ");
    Serial.print(read);
    Serial.print(" , Filtered value: ");
    Serial.print(read_filtered);
    Serial.print("\n");

    delay(250);
}
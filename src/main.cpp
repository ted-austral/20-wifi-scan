/*
 *  Project 20-wifi-scan - main.cpp
 *      Shows all WiFi Access Point available
 *
 *      IntroComp - Austral - 2022 - EAm
 */

/*
 *  Includes
 */

#include <Arduino.h>
 
#include <WiFi.h>

/*
 *  Constants defined in platformio.ini
 *     SERIAL_BAUD  Baud rate del port serie
 */

/*
 *  Private functions
 */

/*
 *  print_network:
 *      Function to print network data of order i
 */

static void
print_network( int i )
{
    Serial.print("\t");
    Serial.print(WiFi.RSSI(i));     //  Received Signal Strength Indicator
    Serial.print( ": ");
    Serial.print(WiFi.SSID(i));     //  Service Set IDentifier (or AP name) 
    Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN) ? " " : "*");     //  Opened or encrypted ?
}

/*
 *  Public functions
 */

void
setup( void )
{
    Serial.begin(SERIAL_BAUD);
    WiFi.mode(WIFI_STA);            // mode to WiFi Station
    WiFi.disconnect();              // disconnect from AP if it was previously connected
    delay(100);
    Serial.println("Setup done");
}


void
loop( void )
{
    int i, n;

    Serial.println("");
    Serial.println("---- Scan begin ----");

    if( ( n = WiFi.scanNetworks() ) == 0 )  //  return number of networks discovered
        Serial.println("No networks found");
    else
    {
        Serial.print(n);
        Serial.println(" networks found");
        Serial.println("---- Scan done ----");
        Serial.println("");

        for( i = 0; i < n; ++i )
            print_network(i);
    }

    delay(3000);
}

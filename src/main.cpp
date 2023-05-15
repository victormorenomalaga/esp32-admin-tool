/* -------------------------------------------------------------------
 * AdminESP - ElectronicIOT 2021
 * Sitio WEB: https://electroniciot.com
 * Correo: admim@electroniciot.com
 * Plataforma ESP32
 * Proyecto Admin Panel Tool para el ESP32
 * -------------------------------------------------------------------
*/

// -------------------------------------------------------------------
// Librerias
// -------------------------------------------------------------------
#include <Arduino.h>
#include <ArduinoJson.h>
#include <SPIFFS.h>

// -------------------------------------------------------------------
// Archivos *.hpp - Fragmentar el Código
// -------------------------------------------------------------------
#include "settings.hpp"
#include "functions.hpp"
#include "settingsReset.hpp"
#include "settingsRead.hpp"
#include "settingsSave.hpp"
#include "esp32_wifi.hpp"

// -------------------------------------------------------------------
// Setup
// -------------------------------------------------------------------
void setup() {
    // Baudrate
    Serial.begin(115200);
    // CPU Freq
    setCpuFrequencyMhz(240);
    // Inicio del Log por serial
    log("\nInfo: Iniciando Setup");
    // Configurar los Pines
    settingPines();

// Inicio del SPIFFS                 
    if (!SPIFFS.begin(true)){
        log(F("Error1: Falló la inicialización del SPIFFS"));
        //while (true);
    }

    // Inicio del SPIFFS                 
    if (!SPIFFS.begin()){
        log(F("Error2: Falló la inicialización del SPIFFS"));
        //while (true);
    }
    // Lee la Configuración WiFi
    settingsReadWiFi();
    // Configuracion WIFI
    WiFi.disconnect(true);
    delay(1000);
    // Setup del WiFI
    wifi_setup(); 
}


// -------------------------------------------------------------------
// Loop Pincipal Nucleo 0
// -------------------------------------------------------------------
void loop() {

    yield();
    // -------------------------------------------------------------------
    // WIFI
    // -------------------------------------------------------------------
    if (wifi_mode == WIFI_STA){
        wifiLoop();
    }else if (wifi_mode == WIFI_AP){
        wifiAPLoop();
    } 


}
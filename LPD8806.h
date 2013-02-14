#ifndef _LPD8806_H_
#define _LPD8806_H_

// Leaflabs Maple port done by Trystan Jones

#include <HardwareSPI.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <WProgram.h>

class LPD8806 {

 public:

  LPD8806(uint16_t n, uint8_t dpin, uint8_t cpin); // Configurable pins
  LPD8806(HardwareSPI &spi, uint16_t n); // Use SPI hardware; specific pins only
  LPD8806(void); // Empty constructor; init pins & strip length later
  void
    begin(void),
    show(void),
    setPixelColor(uint16_t n, uint8_t r, uint8_t g, uint8_t b),
    setPixelColor(uint16_t n, uint32_t c),
    updatePins(uint8_t dpin, uint8_t cpin), // Change pins, configurable
    updatePins(HardwareSPI &spi),           // Change pins, hardware SPI
    updateLength(uint16_t n);               // Change strip length
  uint16_t
    numPixels(void);
  uint32_t
    Color(byte, byte, byte),
    getPixelColor(uint16_t n);

 private:

  uint16_t
    numLEDs,    // Number of RGB LEDs in strip
    numBytes;   // Size of 'pixels' buffer below
  uint8_t
    *pixels,    // Holds LED color values (3 bytes each) + latch
    clkpin    , datapin;     // Clock & data pin numbers
  void
    startBitbang(void),
    startSPI(void);
  boolean
    hardwareSPI, // If 'true', using hardware SPI
    begun;       // If 'true', begin() method was previously invoked
  HardwareSPI
    *port;
};

#endif
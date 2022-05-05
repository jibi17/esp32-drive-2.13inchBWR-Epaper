# esp32-drive-2.13inchBWR-Epaper
This is a project for esp32 to drive 2.13inchBWR Epaper. Using VScode PlatfoemIO based on Arduino

This project is a driver for MH-ET LIVE 2.13 inch E-paper Module.

The model of esp32 I am using is ESP-WROOM-32

![Alt text](https://github.com/jibi17/esp32-drive-2.13inchBWR-Epaper/blob/master/pic/20220504_160540_HDR.jpg)

I rewrite it on the basis of Heltec library.(https://github.com/HelTecAutomation/e-ink)

# Instructions for use

Connect the pins of the esp32 to the pins of the ink screen。

```
# define RST_PIN         16
# define DC_PIN          22
# define CS_PIN          18
# define BUSY_PIN        4  
# define CLK_PIN         5
MOSI  = 23
```
Compile the code and download to esp32
![Alt text](https://github.com/jibi17/esp32-drive-2.13inchBWR-Epaper/blob/master/pic/20220505_123500.jpg)


# Notice
This screen is weird. If you simply use QYEG0213RWS800_BWR to drive the screen, some garbled characters will be displayed.
My solution is to use DEPG0213Bx800FxX_BW to initialize the screen, and then use the functions provided by QYEG0213RWS800_BWR to display.

```
QYEG0213RWS800_BWR epd213bwr2(RST_PIN, DC_PIN, CS_PIN, BUSY_PIN, CLK_PIN);//reset_pin, dc_pin, cs_pin, busy_pin, clk_pin
DEPG0213Bx800FxX_BW epd213bw(RST_PIN, DC_PIN, CS_PIN, BUSY_PIN, CLK_PIN);//reset_pin, dc_pin, cs_pin, busy_pin, clk_pin

epd213bw.EPD_Init(); //use DEPG0213Bx800FxX_BW to initialize the screen
epd213bwr2.EPD_ALL_image(gImage_time_black,gImage_time_red);//use the functions provided by QYEG0213RWS800_BWR to display.
epd213bwr2.EPD_DeepSleep();//to deepsleep mod
```

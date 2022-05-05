
#include <arduino.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <soc/rmt_struct.h>
#include <esp_system.h>
#include <nvs_flash.h>
#include <driver/gpio.h>
#include <stdio.h>
#include <stdlib.h>

#include "QYEG0213RWS800_BWR.h"
#include "DEPG0213Bx800FxX_BW.h"
#include "picture.h"
#include "e_ink_display.h"
#include "epdif.h"




#define UNDEFINED -1
#define RST_PIN         16
#define DC_PIN          22
#define CS_PIN          18
#define BUSY_PIN        4  
#define CLK_PIN         5
QYEG0213RWS800_BWR epd213bwr2(RST_PIN, DC_PIN, CS_PIN, BUSY_PIN, CLK_PIN);//reset_pin, dc_pin, cs_pin, busy_pin, clk_pin
DEPG0213Bx800FxX_BW epd213bw(RST_PIN, DC_PIN, CS_PIN, BUSY_PIN, CLK_PIN);//reset_pin, dc_pin, cs_pin, busy_pin, clk_pin
unsigned char img[1024];
Paint pt(img, 0, 0);
unsigned long time_start_ms;
unsigned long time_now_s;
#define COLORED     0
#define UNCOLORED   1




void setup() {
    Serial.begin(115200);
    epd213bw.EPD_Init(); //Electronic paper initialization
   // epd213bwr2.EPD_WhiteScreen_White();
   // epd213bw.EPD_ALL_image(gImage_213image_bw);	//Refresh the picture in full screen
    epd213bwr2.EPD_ALL_image(gImage_time_black,gImage_time_red);
   // epd213bw.EPD_WhiteScreen_White();
    // delay(2000);
    // pt.Clear(COLORED);
    // pt.SetWidth(100);
    // pt.SetHeight(124);
    // pt.DrawStringAt(10,11, "2.13!", &Font16, UNCOLORED);
    // epd213bw.SetFrameMemory(pt.GetImage(), 0, 0, pt.GetWidth(), pt.GetHeight());
    // epd213bw.HalLcd_Partial_Update();
    // delay(2000);

    // pt.SetWidth(64);
	// pt.SetHeight(64);

	// pt.Clear(UNCOLORED);
	// pt.DrawRectangle(0, 0, 40, 50, COLORED);
	// pt.DrawLine(0, 0, 40, 50, COLORED);
	// pt.DrawLine(40, 0, 0, 50, COLORED);
	// epd213bw.SetFrameMemory(pt.GetImage(), 16, 60, pt.GetWidth(), pt.GetHeight());
    // epd213bw.HalLcd_Partial_Update();
    // delay(100);
    epd213bw.EPD_DeepSleep();  //Enter deep sleep
    epd213bwr2.EPD_DeepSleep();
}
void loop() {

}


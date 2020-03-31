
#ifndef _MAIN_H_
#define _MAIN_H_

#include <avr/io.h>
#include <avr/wdt.h>
#include <avr/power.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <avr/eeprom.h>
#include <string.h>
#include <util/delay.h>

#include <LUFA/Drivers/USB/USB.h>
#include <LUFA/Drivers/Board/Joystick.h>
#include <LUFA/Drivers/Board/LEDs.h>
#include <LUFA/Drivers/Board/Buttons.h>
#include <LUFA/Platform/Platform.h>

#include "Descriptors.h"

#define F_CPU = 16000000

extern char Stopping;
extern char STOP;

#define set_bit(r, b) ((r) |= (1u << (b)))
#define reset_bit(r, b) ((r) &= ~(1u << (b)))
#define read_bit(r, b) ((r) & (1u << (b)))
#define flip_bit(r, b) ((r) ^= (1u << (b)))

#define LOOP_START(x)               \
  for (long i = 0; i < x || !x; i++) \
  {
#define LOOP_END \
  if (Stopping)  \
    return;      \
  }
#define PROGRAM_END            \
  STOP = 1;                    \
  OLED_P8x16Str(88, 5, "100"); \
  OLED_Set_Pos(110, 7);        \
  OLED_WrDat(0b10011001);      \
  OLED_Set_Pos(116, 7);        \
  OLED_WrDat(0b00111100);      \
  OLED_WrDat(0b00111100);      \
  OLED_WrDat(0b00111100);      \
  OLED_WrDat(0b00111100);

typedef enum
{
  SWITCH_Y = 0x01,
  SWITCH_B = 0x02,
  SWITCH_A = 0x04,
  SWITCH_X = 0x08,
  SWITCH_L = 0x10,
  SWITCH_R = 0x20,
  SWITCH_ZL = 0x40,
  SWITCH_ZR = 0x80,
  SWITCH_MINUS = 0x100,
  SWITCH_PLUS = 0x200,
  SWITCH_LCLICK = 0x400,
  SWITCH_RCLICK = 0x800,
  SWITCH_HOME = 0x1000,
  SWITCH_CAPTURE = 0x2000,
} JoystickButtons_t;

#define HAT_TOP 0x00
#define HAT_TOP_RIGHT 0x01
#define HAT_RIGHT 0x02
#define HAT_BOTTOM_RIGHT 0x03
#define HAT_BOTTOM 0x04
#define HAT_BOTTOM_LEFT 0x05
#define HAT_LEFT 0x06
#define HAT_TOP_LEFT 0x07
#define HAT_CENTER 0x08

#define STICK_MIN 0
#define STICK_CENTER 128
#define STICK_MAX 255

// Joystick HID report structure. We have an input and an output.
typedef struct
{
  uint16_t Button; // 16 buttons; see JoystickButtons_t for bit mapping
  uint8_t HAT;     // HAT switch; one nibble w/ unused nibble
  uint8_t LX;      // Left  Stick X
  uint8_t LY;      // Left  Stick Y
  uint8_t RX;      // Right Stick X
  uint8_t RY;      // Right Stick Y
  uint8_t VendorSpec;
} USB_JoystickReport_Input_t;

// The output is structured as a mirror of the input.
// This is based on initial observations of the Pokken Controller.
typedef struct
{
  uint16_t Button; // 16 buttons; see JoystickButtons_t for bit mapping
  uint8_t HAT;     // HAT switch; one nibble w/ unused nibble
  uint8_t LX;      // Left  Stick X
  uint8_t LY;      // Left  Stick Y
  uint8_t RX;      // Right Stick X
  uint8_t RY;      // Right Stick Y
} USB_JoystickReport_Output_t;

typedef enum
{
  UP,
  DOWN,
  LEFT,
  RIGHT,
  UPLEFT, // UP + LEFT
  UPRIGHT,
  DOWNLEFT,
  DOWNRIGHT,
  RLEFT,
  RRIGHT,
  //HATLEFT,
  //HATRIGHT,
  //HATCENTER,
  X,
  Y,
  A,
  B,
  L,
  R,
  ZL,
  ZR,
  PLUS,
  MINUS,
  HOME,
  LCLICK,
  RCLICK,
  SCRIPT_END,
  PAUSE
} Buttons_t;

typedef struct
{
  Buttons_t button;
  uint16_t duration;
} command;

void delay(int ms);
void StopScript(void);
void SwitchScript(void);
void SetupButtons(void);
void SwitchButton(char button);
void PressButton(void);
void SwitchLED(void);
void FlashLED(void);
void RunStep(Buttons_t button, uint16_t duration);
void RunScript(const command script[], int times);
void PgmInit(void);
void ReadEepData(void);
void IsRunning(void);
void SwitchState(void);
void SwitchBox(void);
void SwitchCycle(void);
void SwitchFrame(char x);
void SwitchLastFrame(void);
void SwitchSkipWait(void);
void SwitchDriveWait(void);
void SwitchPassword(char x);
void SwitchInfUsed(void);
void NumToStr(int num, char str[]);
void RefreshProgress(void);
long GetDuration(const command script[]);
// Function Prototypes
// Setup all necessary hardware, including USB initialization.
void SetupHardware(void);
// Process and deliver data from IN and OUT endpoints.
void HID_Task(Buttons_t button);
// USB device event handlers.
void EVENT_USB_Device_Connect(void);
void EVENT_USB_Device_Disconnect(void);
void EVENT_USB_Device_ConfigurationChanged(void);
void EVENT_USB_Device_ControlRequest(void);
// Prepare the next report for the host.
void GetNextReport(USB_JoystickReport_Input_t *const ReportData, Buttons_t button);

#endif

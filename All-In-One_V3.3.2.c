
#include "lib/Main.h"
#include "lib/OLED.h"
#include "lib/Program.h"

char STOP = 1;                  //启停状态
char PlusButton = 0;            //加号键
char MinusButton = 0;           //减号键
char State = 1;                 //切换状态
char ScriptNum = 1;             //脚本编号
signed char CycleNum = 6;       //周期数
char CycleStr[3] = {48, 54, 0}; //周期数字符串形式
int BoxNum = 1;                 //箱数
char BoxStr[3] = {48, 49, 0};   //箱数字符串形式
signed char SkipWaitNum = 5;
char SkipWaitStr[3] = {48, 53, 0};
signed char LastFrameNum = 3;
char LastFrameStr[2] = {51, 0};
int DriveWaitNum = 30;
char DriveWaitStr[4] = {48, 51, 48, 0};
int PasswordNum = 0;
char PasswordStr[5] = {48, 48, 48, 48, 0};
signed char AddNum = 0;
char AddStr[2] = {48, 0};
long FrameNum = 30;                         //帧数
char FrameStr[6] = {48, 48, 48, 51, 48, 0}; //帧数字符串形式
char AutoRelease = 0;
long CopyNum = 1;
char CopyStr[4] = {48, 48, 48, 0};
char InfUsedNum = 1;
char ProgressNum = 0;
char ProgressStr[3] = {48, 48, 0};
char SkipMode = 0; //跳帧模式
char SpeedUp = 0;
char LockMode = 1;
char initialized = 0; //初始化状态
char Stopping = 0;    //停止信号 用于逐层返回主循环并重新选择脚本

long SizeofSync = 0;
long SizeofCollect = 0;
long SizeofHatch = 0;
//long SizeofHatch6 = 0;
//long SizeofHatch11 = 0;
//long SizeofHatch16 = 0;
//long SizeofHatch21 = 0;
//long SizeofHatch26 = 0;
//long SizeofHatch31 = 0;
//long SizeofHatch36 = 0;
//long SizeofHatch41 = 0;
long SizeofRelease = 0;
//long SizeofSkip = 0;
//long SizeofSkipFast = 0;
long SizeofCopy = 0;
long SizeofPgm = 0;
long SizeofPgmNow = 0;

int main(void)
{

  SetupHardware();

  PgmInit();

  for (;;)
  {
    PgmStart();
  }
}

//程序初始化
void PgmInit()
{
  OLED_P8x16Str(36, 1, "Loading");
  OLED_P6x8Str(92, 7, "V3.3.2");
  OLED_Set_Pos(8, 4);
  OLED_WrDat(0b11111111);
  for (char i = 0; i < 110; i++)
    OLED_WrDat(0b10000001);
  OLED_WrDat(0b11111111);
  delay(200);
  OLED_Set_Pos(11, 4);
  for (char i = 0; i < 40; i++)
  {
    OLED_WrDat(0b10011001);
    delay(5);
  }

  SizeofSync = GetDuration(Sync) * 5;
  SizeofCollect = GetDuration(CollectMove) * 3 + GetDuration(GetEgg);
  SizeofHatch = GetDuration(BoxOperation1) + GetDuration(BoxOperation2) + GetDuration(BoxOperation3) + GetDuration(BoxOperation4) + GetDuration(BoxOperation5) + GetDuration(BoxOperation6) + GetDuration(BoxOperation7) + GetDuration(Hatched) * 30 + GetDuration(HatchReset) * 6 + GetDuration(OpenBox) * 7 + GetDuration(CloseBox) * 7;
  //SizeofHatch6 = GetDuration(BoxOperation1) + GetDuration(BoxOperation2) + GetDuration(BoxOperation3) + GetDuration(BoxOperation4) + GetDuration(BoxOperation5) + GetDuration(BoxOperation6) + GetDuration(BoxOperation7) + GetDuration(LastMove6) * 6 + GetDuration(Hatched) * 30 + GetDuration(HatchReset) * 6;
  //SizeofHatch11 = GetDuration(BoxOperation1) + GetDuration(BoxOperation2) + GetDuration(BoxOperation3) + GetDuration(BoxOperation4) + GetDuration(BoxOperation5) + GetDuration(BoxOperation6) + GetDuration(BoxOperation7) + GetDuration(HatchMove) * 6 + GetDuration(LastMove11) * 6 + GetDuration(Hatched) * 30 + GetDuration(HatchReset) * 6;
  //SizeofHatch16 = GetDuration(BoxOperation1) + GetDuration(BoxOperation2) + GetDuration(BoxOperation3) + GetDuration(BoxOperation4) + GetDuration(BoxOperation5) + GetDuration(BoxOperation6) + GetDuration(BoxOperation7) + GetDuration(HatchMove) * 12 + GetDuration(LastMove16) * 6 + GetDuration(Hatched) * 30 + GetDuration(HatchReset) * 6;
  //SizeofHatch21 = GetDuration(BoxOperation1) + GetDuration(BoxOperation2) + GetDuration(BoxOperation3) + GetDuration(BoxOperation4) + GetDuration(BoxOperation5) + GetDuration(BoxOperation6) + GetDuration(BoxOperation7) + GetDuration(HatchMove) * 12 + GetDuration(LastMove21) * 6 + GetDuration(Hatched) * 30 + GetDuration(HatchReset) * 6;
  //SizeofHatch26 = GetDuration(BoxOperation1) + GetDuration(BoxOperation2) + GetDuration(BoxOperation3) + GetDuration(BoxOperation4) + GetDuration(BoxOperation5) + GetDuration(BoxOperation6) + GetDuration(BoxOperation7) + GetDuration(HatchMove) * 18 + GetDuration(LastMove26) * 6 + GetDuration(Hatched) * 30 + GetDuration(HatchReset) * 6;
  //SizeofHatch31 = GetDuration(BoxOperation1) + GetDuration(BoxOperation2) + GetDuration(BoxOperation3) + GetDuration(BoxOperation4) + GetDuration(BoxOperation5) + GetDuration(BoxOperation6) + GetDuration(BoxOperation7) + GetDuration(HatchMove) * 24 + GetDuration(LastMove31) * 6 + GetDuration(Hatched) * 30 + GetDuration(HatchReset) * 6;
  //SizeofHatch36 = GetDuration(BoxOperation1) + GetDuration(BoxOperation2) + GetDuration(BoxOperation3) + GetDuration(BoxOperation4) + GetDuration(BoxOperation5) + GetDuration(BoxOperation6) + GetDuration(BoxOperation7) + GetDuration(HatchMove) * 24 + GetDuration(LastMove36) * 6 + GetDuration(Hatched) * 30 + GetDuration(HatchReset) * 6;
  //SizeofHatch41 = GetDuration(BoxOperation1) + GetDuration(BoxOperation2) + GetDuration(BoxOperation3) + GetDuration(BoxOperation4) + GetDuration(BoxOperation5) + GetDuration(BoxOperation6) + GetDuration(BoxOperation7) + GetDuration(HatchMove) * 30 + GetDuration(LastMove41) * 6 + GetDuration(Hatched) * 30 + GetDuration(HatchReset) * 6;
  SizeofRelease = GetDuration(ReleaseDown) * 12 + GetDuration(ReleaseRight) * 5 + GetDuration(ReleaseUP) * 12 + GetDuration(ReleaseReset);
  //SizeofSkip = GetDuration(Skip) * 31;
  //SizeofSkipFast = GetDuration(SkipFast) * 31;
  SizeofCopy = GetDuration(CollectMove) * 3 + GetDuration(CopyGetEgg);
  SizeofPgm = GetDuration(Sync) * 5;

  STOP = 0;
  RunScript(Sync, 5);
  STOP = 1;

  OLED_Set_Pos(51, 4);
  for (char i = 0; i < 46; i++)
  {
    OLED_WrDat(0b10011001);
    delay(5);
  }

  ReadEepData();

  OLED_Set_Pos(97, 4);
  for (char i = 0; i < 20; i++)
  {
    OLED_WrDat(0b10011001);
    delay(5);
  }
  delay(200);
  OLED_P6x8Str(0, 6, "          ");
  OLED_P6x8Str(0, 7, "  ");
  OLED_P6x8Str(110, 7, "   ");
  //OLED_P6x8Str(48, 0, "  ");
  //OLED_P6x8Str(48, 1, "       ");
  OLED_P8x16Str(36, 1, "       ");
  OLED_P8x16Str(8, 4, "               ");
  OLED_P8x16Str(0, 0, "<");
  OLED_Set_Pos(116, 7);
  OLED_WrDat(0b00111100);
  OLED_WrDat(0b00111100);
  OLED_WrDat(0b00111100);
  OLED_WrDat(0b00111100);
  //OLED_P8x16Str(117,7,"N");
  OLED_P16x16Ch(104, 1, 14);
  OLED_Set_Pos(8, 7);
  OLED_WrDat(0b11111111);
  for (int i = 0; i < 104; i++)
    OLED_WrDat(0b10000001);
  OLED_WrDat(0b11111111);
  OLED_P8x16Str(88, 5, " --%");
  SwitchScript();
  initialized = 1;
}

//读取EEPROM
void ReadEepData()
{
  long eep1 = 0;
  long eep2 = 0;
  cli();
  for (int i = 0; i < 14; i++)
  {
    int x = i * 10 + 250;
    eep1 = eeprom_read_dword(x);
    delay(5);
    eep2 = eeprom_read_dword(x + 5);
    delay(5);
    if (eep1 == (eep2 - 10))
    {
      switch (i)
      {
      case 0:
        ScriptNum = (char)eeprom_read_dword(x);
        break;
      case 1:
        CycleNum = (signed char)eeprom_read_dword(x);
        break;
      case 2:
        BoxNum = (int)eeprom_read_dword(x);
        break;
      case 3:
        FrameNum = (long)eeprom_read_dword(x);
        break;
      case 4:
        SpeedUp = (char)eeprom_read_dword(x);
        break;
      case 5:
        LastFrameNum = (signed char)eeprom_read_dword(x);
        break;
      case 6:
        SkipWaitNum = (signed char)eeprom_read_dword(x);
        break;
      case 7:
        DriveWaitNum = (int)eeprom_read_dword(x);
        break;
      case 8:
        PasswordNum = (int)eeprom_read_dword(x);
        break;
      case 9:
        AddNum = (signed char)eeprom_read_dword(x);
        break;
      case 10:
        LockMode = (char)eeprom_read_dword(x);
        break;
      case 11:
        InfUsedNum = (char)eeprom_read_dword(x);
        break;
      case 12:
        AutoRelease = (char)eeprom_read_dword(x);
        break;
      case 13:
        CopyNum = (long)eeprom_read_dword(x);
        break;
      default:
        break;
      }
      delay(5);
    }
  }
  sei();
  SwitchCycle();
  SwitchBox();
  SwitchFrame(1);
  SwitchLastFrame();
  SwitchSkipWait();
  SwitchDriveWait();
  SwitchPassword(1);
  SwitchAdd();
  SwitchCopy();
}

//写入EEPROM
void WriteEepData(int address, long num)
{
  cli();
  eeprom_write_dword(address, num);
  delay(10);
  eeprom_write_dword(address + 5, num + 10);
  sei();
}

/*
//寄存器置1
void set_bit(char x, char y)
{
  x |= 1u << y;
}

//寄存器置0
void reset_bit(char x, char y)
{
  x &= ~(1u << y);
}

//读取引脚电平
char read_bit(char x, char y)
{
  char i = x & (1u << y);
  return i;
}
*/

//获取脚本时长
long GetDuration(const command script[])
{
  long x = 0;
  for (int i = 0;; i++)
  {
    if (pgm_read_byte(&script[i].button) == SCRIPT_END)
      break;
    x += pgm_read_byte(&script[i].duration);
  }
  return x;
}

//切换脚本
void SwitchScript()
{
  if (State == 1)
  {
    if (PlusButton)
    {
      if (ScriptNum != 9)
        ScriptNum++;
      else
        ScriptNum = 1;
    }
    if (MinusButton)
    {
      if (ScriptNum != 1)
        ScriptNum--;
      else
        ScriptNum = 9;
    }
  }

  switch (ScriptNum)
  {
  case 1: //取孵一体
    OLED_P16x16Ch(8, 0, 0);
    OLED_P16x16Ch(24, 0, 2);
    OLED_P16x16Ch(40, 0, 3);
    OLED_P16x16Ch(56, 0, 4);
    OLED_P8x16Str(72, 0, ">");
    //OLED_P8x16Str(80, 0, "  ");

    OLED_P8x16Str(8, 2, CycleStr);
    OLED_P16x16Ch(24, 2, 7);
    OLED_P16x16Ch(40, 2, 8);
    OLED_P8x16Str(56, 2, "    ");

    OLED_P8x16Str(8, 4, BoxStr);
    OLED_P16x16Ch(24, 4, 9);
    OLED_P8x16Str(40, 4, "   ");
    break;
  case 2: //取蛋
    //OLED_P8x16Str(0,0,"<");
    OLED_P16x16Ch(8, 0, 0);
    OLED_P16x16Ch(24, 0, 1);
    OLED_P8x16Str(40, 0, ">");
    OLED_P8x16Str(48, 0, "    ");

    OLED_P8x16Str(8, 2, "      ");

    OLED_P8x16Str(8, 4, BoxStr);
    OLED_P16x16Ch(24, 4, 9);
    break;
  case 3: //孵蛋
          //OLED_P8x16Str(0,0,"<");
    OLED_P16x16Ch(8, 0, 2);
    OLED_P16x16Ch(24, 0, 1);
    OLED_P8x16Str(40, 0, ">");

    OLED_P8x16Str(8, 2, CycleStr);
    OLED_P16x16Ch(24, 2, 7);
    OLED_P16x16Ch(40, 2, 8);

    OLED_P8x16Str(8, 4, BoxStr);
    OLED_P16x16Ch(24, 4, 9);
    break;
  case 4: //放生
    //OLED_P8x16Str(0,0,"<");
    OLED_P16x16Ch(8, 0, 5);
    OLED_P16x16Ch(24, 0, 6);
    OLED_P8x16Str(40, 0, ">");

    OLED_P8x16Str(8, 2, "      ");

    OLED_P8x16Str(8, 4, BoxStr);
    OLED_P16x16Ch(24, 4, 9);
    OLED_P8x16Str(40, 4, "   ");
    break;
  case 5: //跳帧
    //OLED_P8x16Str(0,0,"<");
    OLED_P16x16Ch(8, 0, 15);
    OLED_P16x16Ch(24, 0, 10);
    OLED_P8x16Str(40, 0, ">");
    OLED_P8x16Str(48, 0, "      ");

    if (SpeedUp)
    {
      OLED_P16x16Ch(8, 2, 63);
      OLED_P16x16Ch(24, 2, 64);
    }
    else
    {
      OLED_P16x16Ch(8, 2, 61);
      OLED_P16x16Ch(24, 2, 62);
    }
    OLED_P8x16Str(40, 2, "    ");

    OLED_P8x16Str(8, 4, FrameStr);
    OLED_P16x16Ch(48, 4, 10);
    //OLED_P8x16Str(64, 4, " ");
    break;
  case 6: //最后N帧
    //OLED_P8x16Str(0,0,"<");
    OLED_P16x16Ch(8, 0, 48);
    OLED_P16x16Ch(24, 0, 49);
    OLED_P8x16Str(40, 0, "N");
    OLED_P16x16Ch(48, 0, 10);
    OLED_P8x16Str(64, 0, ">");
    OLED_P8x16Str(72, 0, " ");

    OLED_P16x16Ch(8, 2, 52);
    OLED_P16x16Ch(24, 2, 53);
    OLED_P8x16Str(40, 2, SkipWaitStr);
    OLED_P16x16Ch(56, 2, 54);
    OLED_P8x16Str(72, 2, " ");

    OLED_P16x16Ch(8, 4, 55);
    OLED_P8x16Str(24, 4, LastFrameStr);
    OLED_P16x16Ch(32, 4, 10);
    OLED_P8x16Str(48, 4, "    ");
    break;
  case 7: //自动驾驶
    OLED_P8x16Str(0, 0, "<");
    OLED_P16x16Ch(8, 0, 21);
    OLED_P16x16Ch(24, 0, 22);
    OLED_P16x16Ch(40, 0, 42);
    OLED_P16x16Ch(56, 0, 43);
    OLED_P8x16Str(72, 0, ">");

    OLED_P16x16Ch(8, 2, 46);
    OLED_P16x16Ch(24, 2, 47);
    if (PasswordNum == 10000)
      OLED_P8x16Str(40, 2, "----");
    else if (PasswordNum == 10001)
      OLED_P8x16Str(40, 2, "????");
    else
      OLED_P8x16Str(40, 2, PasswordStr);

    OLED_P16x16Ch(8, 4, 52);
    OLED_P16x16Ch(24, 4, 53);
    OLED_P8x16Str(40, 4, DriveWaitStr);
    OLED_P16x16Ch(64, 4, 54);
    break;
  case 8: //道具复制
    OLED_P16x16Ch(8, 0, 65);
    OLED_P16x16Ch(24, 0, 66);
    OLED_P16x16Ch(40, 0, 67);
    OLED_P16x16Ch(56, 0, 68);
    OLED_P8x16Str(72, 0, ">");

    OLED_P8x16Str(8, 2, CopyStr);
    OLED_P16x16Ch(32, 2, 69);
    OLED_P8x16Str(48, 2, "     ");

    OLED_P16x16Ch(8, 4, 5);
    OLED_P16x16Ch(24, 4, 6);
    OLED_P8x16Str(40, 4, ":");
    if (AutoRelease == 1)
    {
      OLED_P16x16Ch(48, 4, 73);
      OLED_P16x16Ch(64, 4, 69);
    }
    else if (AutoRelease == 2)
    {
      OLED_P16x16Ch(48, 4, 73);
      OLED_P16x16Ch(64, 4, 9);
    }
    else
    {
      OLED_P16x16Ch(48, 4, 71);
      OLED_P16x16Ch(64, 4, 72);
    }
    break;
  case 9: //其他功能
    if (State == 1)
    {
      OLED_P16x16Ch(8, 0, 16);
      OLED_P16x16Ch(24, 0, 17);
      OLED_P16x16Ch(40, 0, 19);
      OLED_P16x16Ch(56, 0, 20);
      OLED_P8x16Str(72, 0, ">");
      OLED_P8x16Str(32, 2, "   ");
      OLED_P8x16Str(8, 4, "         ");
    }
    switch (InfUsedNum)
    {
    case 1: //连A
      OLED_P16x16Ch(8, 2, 34);
      OLED_P8x16Str(24, 2, "A");
      break;
    case 2: //连Y
      OLED_P16x16Ch(8, 2, 34);
      OLED_P8x16Str(24, 2, "Y");
      break;
    case 3: //刷瓦特
      OLED_P16x16Ch(8, 2, 27);
      OLED_P16x16Ch(24, 2, 32);
      OLED_P16x16Ch(40, 2, 33);
      break;
    case 4: //刷树果
      OLED_P16x16Ch(8, 2, 27);
      OLED_P16x16Ch(24, 2, 25);
      OLED_P16x16Ch(40, 2, 26);
      break;
    case 5: //刷头饰
      OLED_P16x16Ch(8, 2, 27);
      OLED_P16x16Ch(24, 2, 28);
      OLED_P16x16Ch(40, 2, 29);
      break;
    case 6: //售货郎
      OLED_P16x16Ch(8, 2, 56);
      OLED_P16x16Ch(24, 2, 57);
      OLED_P16x16Ch(40, 2, 58);
      break;
    case 7: //宝可帮帮忙
      OLED_P16x16Ch(8, 2, 35);
      OLED_P16x16Ch(24, 2, 36);
      OLED_P16x16Ch(40, 2, 37);
      OLED_P16x16Ch(56, 2, 37);
      OLED_P16x16Ch(72, 2, 38);
      break;
    case 8: //洛托姆抽奖
      OLED_P16x16Ch(8, 2, 39);
      OLED_P16x16Ch(24, 2, 40);
      OLED_P16x16Ch(40, 2, 41);
      OLED_P16x16Ch(56, 2, 23);
      OLED_P16x16Ch(72, 2, 24);
      break;
    default:
      break;
    }

    break;
  default:
    break;
  }
}

//操作状态
//State:
//1.功能
//2.周期
//3.箱
//4.帧
//5.跳帧秒
//6.开车秒
//7.密码
//8.其他功能
//9.最后帧
//10.锁定模式
//11.加好友
//12.过帧模式
//13.复制数量
//14.自动放生
void SwitchState()
{
  switch (ScriptNum)
  {
  case 1:
    if (State == 1)
    {
      State = 2;
      OLED_P8x16Str(0, 0, " ");
      OLED_P8x16Str(72, 0, " ");
      OLED_P8x16Str(0, 2, "<");
      OLED_P8x16Str(56, 2, ">");
    }
    else if (State == 2)
    {
      State = 3;
      OLED_P8x16Str(0, 2, " ");
      OLED_P8x16Str(56, 2, " ");
      OLED_P8x16Str(0, 4, "<");
      OLED_P8x16Str(40, 4, ">");
    }
    else
    {
      State = 1;
      OLED_P8x16Str(0, 0, "<");
      OLED_P8x16Str(72, 0, ">");
      OLED_P8x16Str(0, 4, " ");
      OLED_P8x16Str(40, 4, " ");
    }
    break;

  case 3:
    if (State == 1)
    {
      State = 2;
      OLED_P8x16Str(0, 0, " ");
      OLED_P8x16Str(40, 0, " ");
      OLED_P8x16Str(0, 2, "<");
      OLED_P8x16Str(56, 2, ">");
    }
    else if (State == 2)
    {
      State = 3;
      OLED_P8x16Str(0, 2, " ");
      OLED_P8x16Str(56, 2, " ");
      OLED_P8x16Str(0, 4, "<");
      OLED_P8x16Str(40, 4, ">");
    }
    else
    {
      State = 1;
      OLED_P8x16Str(0, 0, "<");
      OLED_P8x16Str(40, 0, ">");
      OLED_P8x16Str(0, 4, " ");
      OLED_P8x16Str(40, 4, " ");
    }
    break;

  case 2:
  case 4:
    if (State == 1)
    {
      State = 3;
      OLED_P8x16Str(0, 0, " ");
      OLED_P8x16Str(40, 0, " ");
      OLED_P8x16Str(0, 4, "<");
      OLED_P8x16Str(40, 4, ">");
    }
    else
    {
      State = 1;
      OLED_P8x16Str(0, 0, "<");
      OLED_P8x16Str(40, 0, ">");
      OLED_P8x16Str(0, 4, " ");
      OLED_P8x16Str(40, 4, " ");
    }
    break;

  case 5:
    if (State == 1)
    {
      State = 12;
      OLED_P8x16Str(0, 0, " ");
      OLED_P8x16Str(40, 0, " ");
      OLED_P8x16Str(0, 2, "<");
      OLED_P8x16Str(40, 2, ">");
    }
    else if (State == 12)
    {
      State = 4;
      OLED_P8x16Str(0, 4, "<");
      OLED_P8x16Str(64, 4, ">");
      OLED_P8x16Str(0, 2, " ");
      OLED_P8x16Str(40, 2, " ");
    }
    else
    {
      State = 1;
      OLED_P8x16Str(0, 0, "<");
      OLED_P8x16Str(40, 0, ">");
      OLED_P8x16Str(0, 4, " ");
      OLED_P8x16Str(64, 4, " ");
    }
    break;

  case 6:
    if (State == 1)
    {
      State = 5;
      OLED_P8x16Str(0, 0, " ");
      OLED_P8x16Str(64, 0, " ");
      OLED_P8x16Str(0, 2, "<");
      OLED_P8x16Str(72, 2, ">");
    }
    else if (State == 5)
    {
      State = 9;
      OLED_P8x16Str(0, 2, " ");
      OLED_P8x16Str(72, 2, " ");
      OLED_P8x16Str(0, 4, "<");
      OLED_P8x16Str(48, 4, ">");
    }
    else
    {
      State = 1;
      OLED_P8x16Str(0, 0, "<");
      OLED_P8x16Str(64, 0, ">");
      OLED_P8x16Str(0, 4, " ");
      OLED_P8x16Str(48, 4, " ");
    }
    break;

  case 7:
    switch (State)
    {
    case 1:
      State = 7;
      OLED_P8x16Str(0, 0, " ");
      OLED_P8x16Str(72, 0, " ");
      OLED_P8x16Str(0, 2, "<");
      OLED_P8x16Str(72, 2, ">");
      break;
    case 7:
      State = 6;
      OLED_P8x16Str(0, 2, " ");
      OLED_P8x16Str(72, 2, " ");
      OLED_P8x16Str(0, 4, "<");
      OLED_P8x16Str(80, 4, ">");
      break;
    case 6:
      State = 11;
      OLED_P8x16Str(8, 0, AddStr);
      OLED_P16x16Ch(16, 0, 31);
      OLED_P16x16Ch(32, 0, 30);
      OLED_P16x16Ch(48, 0, 50);
      OLED_P16x16Ch(64, 0, 51);

      OLED_P16x16Ch(8, 2, 55);
      OLED_P8x16Str(24, 2, LastFrameStr);
      OLED_P16x16Ch(32, 2, 10);
      OLED_P8x16Str(48, 2, "   ");

      if (LockMode)
        OLED_P16x16Ch(8, 4, 60);
      else
        OLED_P16x16Ch(8, 4, 59);
      OLED_P16x16Ch(24, 4, 18);
      OLED_P8x16Str(40, 4, "     ");

      OLED_P8x16Str(0, 4, " ");
      OLED_P8x16Str(80, 4, " ");
      OLED_P8x16Str(0, 0, "<");
      OLED_P8x16Str(80, 0, ">");
      break;
    case 11:
      State = 9;
      OLED_P8x16Str(0, 0, " ");
      OLED_P8x16Str(80, 0, " ");
      OLED_P8x16Str(0, 2, "<");
      OLED_P8x16Str(48, 2, ">");
      break;
    case 9:
      State = 10;
      OLED_P8x16Str(0, 2, " ");
      OLED_P8x16Str(48, 2, " ");
      OLED_P8x16Str(0, 4, "<");
      OLED_P8x16Str(40, 4, ">");
      break;
    case 10:
      State = 1;
      SwitchScript();
      OLED_P8x16Str(0, 4, " ");
      OLED_P8x16Str(80, 0, " ");
      break;

    default:
      break;
    }
    break;

  case 8:
    if (State == 1)
    {
      State = 13;
      OLED_P8x16Str(0, 0, " ");
      OLED_P8x16Str(72, 0, " ");
      OLED_P8x16Str(0, 2, "<");
      OLED_P8x16Str(48, 2, ">");
    }
    else if (State == 13)
    {
      State = 14;
      OLED_P8x16Str(0, 2, " ");
      OLED_P8x16Str(48, 2, " ");
      OLED_P8x16Str(0, 4, "<");
      OLED_P8x16Str(80, 4, ">");
    }
    else
    {
      State = 1;
      OLED_P8x16Str(0, 0, "<");
      OLED_P8x16Str(72, 0, ">");
      OLED_P8x16Str(0, 4, " ");
      OLED_P8x16Str(80, 4, " ");
    }
    break;

  case 9:
    if (State == 1)
    {
      State = 8;
      OLED_P8x16Str(0, 2, "<");
      OLED_P8x16Str(0, 0, " ");
      OLED_P8x16Str(72, 0, " ");
      switch (InfUsedNum)
      {
      case 1: //连A
      case 2: //连Y
        //OLED_P8x16Str(72, 0, " ");
        OLED_P8x16Str(32, 2, ">");
        break;
      case 3: //刷瓦特
      case 4: //刷树果
      case 5: //刷头饰
      case 6: //售货郎
        //OLED_P8x16Str(72, 0, " ");
        OLED_P8x16Str(56, 2, ">");
        break;
      case 7: //宝可帮帮忙
      case 8: //洛托姆抽奖
        //OLED_P8x16Str(72, 0, " ");
        OLED_P8x16Str(88, 2, ">");
        break;
      default:
        break;
      }
    }
    else
    {
      State = 1;
      OLED_P8x16Str(0, 0, "<");
      OLED_P8x16Str(0, 2, " ");
      OLED_P8x16Str(72, 0, ">");
      switch (InfUsedNum)
      {
      case 1: //连A
      case 2: //连Y
        //OLED_P8x16Str(72, 0, ">");
        OLED_P8x16Str(32, 2, " ");
        break;
      case 3: //刷瓦特
      case 4: //刷树果
      case 5: //刷头饰
      case 6: //售货郎
        //OLED_P8x16Str(72, 0, ">");
        OLED_P8x16Str(56, 2, " ");
        break;

      case 7: //宝可帮帮忙
      case 8: //洛托姆抽奖
        //OLED_P8x16Str(72, 0, ">");
        OLED_P8x16Str(88, 2, " ");
        break;
      default:
        break;
      }
    }

  default:
    break;
  }
}

//切换周期数
void SwitchCycle()
{
  if (PlusButton)
  {
    CycleNum += 5;
    if (CycleNum > 41)
      CycleNum = 6;
  }
  if (MinusButton)
  {
    CycleNum -= 5;
    if (CycleNum < 6)
      CycleNum = 41;
  }
  CycleStr[0] = CycleNum / 10 + 0x30;
  CycleStr[1] = CycleNum % 10 + 0x30;
}

//切换箱数
void SwitchBox()
{
  if (PlusButton)
  {
    BoxNum++;
    if (BoxNum > 32)
      BoxNum = 1;
  }
  if (MinusButton)
  {
    BoxNum--;
    if (BoxNum < 1)
      BoxNum = 32;
  }
  BoxStr[0] = BoxNum / 10 + 0x30;
  BoxStr[1] = BoxNum % 10 + 0x30;
}

//切换帧数
void SwitchFrame(char x)
{
  if (PlusButton)
  {
    FrameNum += x;
    if (FrameNum > 90000)
      FrameNum = 30;
  }
  if (MinusButton)
  {
    FrameNum -= x;
    if (FrameNum < 30)
      FrameNum = 90000;
  }
  FrameStr[0] = (FrameNum / 10000) % 10 + 0x30;
  FrameStr[1] = (FrameNum / 1000) % 10 + 0x30;
  FrameStr[2] = (FrameNum / 100) % 10 + 0x30;
  FrameStr[3] = (FrameNum / 10) % 10 + 0x30;
  FrameStr[4] = FrameNum % 10 + 0x30;
}

//切换过帧模式
void SwitchSpeed()
{
  if (PlusButton || MinusButton)
    SpeedUp = !SpeedUp;
  if (SpeedUp)
  {
    OLED_P16x16Ch(8, 2, 63);
    OLED_P16x16Ch(24, 2, 64);
  }
  else
  {
    OLED_P16x16Ch(8, 2, 61);
    OLED_P16x16Ch(24, 2, 62);
  }
}

//切换最后N帧
void SwitchLastFrame()
{
  if (PlusButton)
  {
    LastFrameNum++;
    if (LastFrameNum > 5)
      LastFrameNum = 0;
  }
  if (MinusButton)
  {
    LastFrameNum--;
    if (LastFrameNum < 0)
      LastFrameNum = 5;
  }
  LastFrameStr[0] = LastFrameNum % 10 + 0x30;
}

//切换N帧等待时间
void SwitchSkipWait()
{
  if (PlusButton)
  {
    SkipWaitNum += 5;
    if (SkipWaitNum > 90)
      SkipWaitNum = 0;
  }
  if (MinusButton)
  {
    SkipWaitNum -= 5;
    if (SkipWaitNum < 0)
      SkipWaitNum = 90;
  }
  SkipWaitStr[0] = (SkipWaitNum / 10) % 10 + 0x30;
  SkipWaitStr[1] = SkipWaitNum % 10 + 0x30;
}

//切换开车等待时间
void SwitchDriveWait()
{
  if (PlusButton)
  {
    DriveWaitNum += 30;
    if (DriveWaitNum > 180)
      DriveWaitNum = 0;
  }
  if (MinusButton)
  {
    DriveWaitNum -= 30;
    if (DriveWaitNum < 0)
      DriveWaitNum = 180;
  }
  DriveWaitStr[0] = (DriveWaitNum / 100) % 10 + 0x30;
  DriveWaitStr[1] = (DriveWaitNum / 10) % 10 + 0x30;
  DriveWaitStr[2] = DriveWaitNum % 10 + 0x30;
}

//切换密码
void SwitchPassword(char x)
{
  if (PlusButton)
  {
    PasswordNum += x;
    if (PasswordNum > 10001)
      PasswordNum = 0;
  }
  if (MinusButton)
  {
    PasswordNum -= x;
    if (PasswordNum < 0)
      PasswordNum = 10001;
  }
    PasswordStr[0] = (PasswordNum / 1000) % 10 + 0x30;
    PasswordStr[1] = (PasswordNum / 100) % 10 + 0x30;
    PasswordStr[2] = (PasswordNum / 10) % 10 + 0x30;
    PasswordStr[3] = PasswordNum % 10 + 0x30;
}

//切换锁定模式
void SwitchLockMode()
{
  if (PlusButton || MinusButton)
    LockMode = !LockMode;
  if (LockMode)
    OLED_P16x16Ch(8, 4, 60);
  else
    OLED_P16x16Ch(8, 4, 59);
  OLED_P16x16Ch(24, 4, 18);
}

//切换N车加好友
void SwitchAdd()
{
  if (PlusButton)
  {
    AddNum++;
    if (AddNum > 9)
      AddNum = 0;
  }
  if (MinusButton)
  {
    AddNum--;
    if (AddNum < 0)
      AddNum = 9;
  }
  AddStr[0] = AddNum % 10 + 0x30;
}

//切换道具复制数量
void SwitchCopy()
{
  if (PlusButton)
  {
    CopyNum++;
    if (CopyNum > 999)
      CopyNum = 1;
  }
  if (MinusButton)
  {
    CopyNum--;
    if (CopyNum < 1)
      CopyNum = 999;
  }
  CopyStr[0] = (CopyNum / 100) % 10 + 0x30;
  CopyStr[1] = (CopyNum / 10) % 10 + 0x30;
  CopyStr[2] = CopyNum % 10 + 0x30;
}

//切换自动放生
void SwitchAutoRelease()
{
  if (PlusButton)
  {
    AutoRelease++;
    if (AutoRelease > 2)
      AutoRelease = 0;
  }
  if (MinusButton)
  {
    AutoRelease--;
    if (AutoRelease < 0)
      AutoRelease = 2;
  }
  OLED_P16x16Ch(8, 4, 5);
  OLED_P16x16Ch(24, 4, 6);
  OLED_P8x16Str(40, 4, ":");
  if (AutoRelease == 1)
  {
    OLED_P16x16Ch(48, 4, 73);
    OLED_P16x16Ch(64, 4, 69);
  }
  else if (AutoRelease == 2)
  {
    OLED_P16x16Ch(48, 4, 73);
    OLED_P16x16Ch(64, 4, 9);
  }
  else
  {
    OLED_P16x16Ch(48, 4, 71);
    OLED_P16x16Ch(64, 4, 72);
  }
}

//切换不常用功能
void SwitchInfUsed()
{
  if (PlusButton)
  {
    if (InfUsedNum != 8)
      InfUsedNum++;
    else
      InfUsedNum = 1;
  }
  if (MinusButton)
  {
    if (InfUsedNum != 1)
      InfUsedNum--;
    else
      InfUsedNum = 8;
  }
  SwitchScript();
  switch (InfUsedNum)
  {
  case 1: //连A
  case 2: //连Y
    OLED_P8x16Str(32, 2, ">");
    OLED_P8x16Str(40, 2, "       ");
    break;
  case 3: //刷瓦特
  case 4: //刷树果
  case 5: //刷头饰
  case 6: //售货郎
    OLED_P8x16Str(56, 2, ">");
    OLED_P8x16Str(64, 2, "    ");
    break;
  case 7: //宝可帮帮忙
  case 8: //洛托姆抽奖
    OLED_P8x16Str(88, 2, ">");
    break;
  default:
    break;
  }
  /*
  switch (InfUsedNum)
  {
  case 1: //连A
    OLED_P16x16Ch(8, 2, 34);
    OLED_P8x16Str(24, 2, "A");
    OLED_P8x16Str(32, 2, ">");
    OLED_P8x16Str(40, 2, "       ");
    break;
    case 2: //连Y
    OLED_P16x16Ch(8, 2, 34);
    OLED_P8x16Str(24, 2, "Y");
    OLED_P8x16Str(32, 2, ">");
    OLED_P8x16Str(40, 2, "   ");
    break;
  case 3: //刷瓦特
    OLED_P16x16Ch(8, 2, 27);
    OLED_P16x16Ch(24, 2, 32);
    OLED_P16x16Ch(40, 2, 33);
    OLED_P8x16Str(56, 2, ">");
    break;
  case 4: //刷树果
    OLED_P16x16Ch(8, 2, 27);
    OLED_P16x16Ch(24, 2, 25);
    OLED_P16x16Ch(40, 2, 26);
    break;
  case 5: //刷头饰
    OLED_P16x16Ch(8, 2, 27);
    OLED_P16x16Ch(24, 2, 28);
    OLED_P16x16Ch(40, 2, 29);
    break;
  case 6: //售货郎
    OLED_P16x16Ch(8, 2, 56);
    OLED_P16x16Ch(24, 2, 57);
    OLED_P16x16Ch(40, 2, 58);
    OLED_P8x16Str(56, 2, ">");
    OLED_P8x16Str(64, 2, "    ");
    break;
  case 7: //宝可帮帮忙
    OLED_P16x16Ch(8, 2, 35);
    OLED_P16x16Ch(24, 2, 36);
    OLED_P16x16Ch(40, 2, 37);
    OLED_P16x16Ch(56, 2, 37);
    OLED_P16x16Ch(72, 2, 38);
    OLED_P8x16Str(88, 2, ">");
    break;
  case 8: //洛托姆抽奖
    OLED_P16x16Ch(8, 2, 39);
    OLED_P16x16Ch(24, 2, 40);
    OLED_P16x16Ch(40, 2, 41);
    OLED_P16x16Ch(56, 2, 23);
    OLED_P16x16Ch(72, 2, 24);
    OLED_P8x16Str(88, 2, ">");
    break;
  default:
    break;
  }
  */
}

void delay(int ms)
{
  for (; ms > 0; ms--)
  {
    _delay_ms(1);
  }
}

//设置引脚状态
void SetupButtons()
{
  //地
  set_bit(DDRF, 4);
  reset_bit(PORTF, 4);
  //减
  reset_bit(DDRF, 5);
  set_bit(PORTF, 5);
  //加
  reset_bit(DDRF, 6);
  set_bit(PORTF, 6);
  //切换
  reset_bit(DDRF, 7);
  set_bit(PORTF, 7);
  //启停
  reset_bit(DDRB, 1);
  set_bit(PORTB, 1);
  /*
  //地
  set_bit(DDRB, 1);
  reset_bit(PORTB, 1);
  //减
  reset_bit(DDRF, 5);
  set_bit(PORTF, 5);
  //加
  reset_bit(DDRF, 4);
  set_bit(PORTF, 4);
  //切换
  reset_bit(DDRF, 6);
  set_bit(PORTF, 6);
  //启停
  reset_bit(DDRF, 7);
  set_bit(PORTF, 7);
*/
}

//启停
void StopScript()
{
  STOP = !STOP;
  if (STOP)
  {
    OLED_P8x16Str(88, 5, " --");
    OLED_Set_Pos(11, 7);
    for (int i = 0; i < 100; i++)
      OLED_WrDat(0b10000001);
    OLED_Set_Pos(116, 7);
    OLED_WrDat(0b00111100);
    OLED_WrDat(0b00111100);
    OLED_WrDat(0b00111100);
    OLED_WrDat(0b00111100);
    //OLED_P8x16Str(117,7,"N");
  }
  else
  {
    OLED_P8x16Str(88, 5, " ");
    OLED_P8x16Str(96, 5, ProgressStr);
    OLED_Set_Pos(11, 7);
    for (int i = 0; i < 100; i++)
      OLED_WrDat(0b10000001);
    OLED_Set_Pos(116, 7);
    OLED_WrDat(0b11111110);
    OLED_WrDat(0b01111100);
    OLED_WrDat(0b00111000);
    OLED_WrDat(0b00010000);
    //OLED_P8x16Str(117,7,"Y");
    Stopping = 1;
  }
}

//按键切换
void SwitchButton(char button)
{
  OLED_P8x16Str(88, 5, " --");
  OLED_Set_Pos(11, 7);
  for (int i = 0; i < 100; i++)
    OLED_WrDat(0b10000001);
  switch (State)
  {
  case 1:
    for (;;)
    {
      if (read_bit(PINF, button))
      {
        SwitchScript();
        WriteEepData(250, ScriptNum);
        break;
      }
      delay(10);
    }
    break;
  case 2:
    for (;;)
    {
      if (read_bit(PINF, button))
      {
        SwitchCycle();
        OLED_P8x16Str(8, 2, CycleStr);
        WriteEepData(260, CycleNum);
        break;
      }
      delay(10);
    }
    break;
  case 3:
    for (int i = 0;; i++)
    {
      if (read_bit(PINF, button))
      {
        SwitchBox();
        OLED_P8x16Str(8, 4, BoxStr);
        WriteEepData(270, BoxNum);
        break;
      }
      if (i > 5)
      {
        SwitchBox();
        OLED_P8x16Str(8, 4, BoxStr);
      }
      delay(50);
    }
    break;

  case 4:
    for (int i = 0;; i++)
    {
      if (read_bit(PINF, button))
      {
        SwitchFrame(30);
        OLED_P8x16Str(8, 4, FrameStr);
        WriteEepData(280, FrameNum);
        break;
      }
      if (i > 14)
      {
        SwitchFrame(90);
        OLED_P8x16Str(8, 4, FrameStr);
      }
      delay(20);
    }
    break;
  case 5:
    for (int i = 0;; i++)
    {
      if (read_bit(PINF, button))
      {
        SwitchSkipWait();
        OLED_P8x16Str(40, 2, SkipWaitStr);
        WriteEepData(310, SkipWaitNum);
        break;
      }
      if (i > 2)
      {
        SwitchSkipWait();
        OLED_P8x16Str(40, 2, SkipWaitStr);
      }
      delay(100);
    }
    break;
  case 6:
    for (;;)
    {
      if (read_bit(PINF, button))
      {
        SwitchDriveWait();
        OLED_P8x16Str(40, 4, DriveWaitStr);
        WriteEepData(320, DriveWaitNum);
        break;
      }
      delay(10);
    }
    break;
  case 7:
    for (int i = 0;; i++)
    {
      if (read_bit(PINF, button))
      {
        SwitchPassword(1);
        if (PasswordNum == 10000)
          OLED_P8x16Str(40, 2, "----");
        else if (PasswordNum == 10001)
          OLED_P8x16Str(40, 2, "????");
        else
          OLED_P8x16Str(40, 2, PasswordStr);
        WriteEepData(330, PasswordNum);
        break;
      }
      if (i > 14)
      {
        SwitchPassword(10);
        if (PasswordNum == 10000)
          OLED_P8x16Str(40, 2, "----");
        else if (PasswordNum == 10001)
          OLED_P8x16Str(40, 2, "????");
        else
          OLED_P8x16Str(40, 2, PasswordStr);
      }
      delay(20);
    }
    break;
  case 8:
    for (;;)
    {
      if (read_bit(PINF, button))
      {
        SwitchInfUsed();
        WriteEepData(360, InfUsedNum);
        break;
      }
      delay(10);
    }
    break;
  case 9:
    for (;;)
    {
      if (read_bit(PINF, button))
      {
        SwitchLastFrame();
        if (ScriptNum == 6)
          OLED_P8x16Str(24, 4, LastFrameStr);
        else
          OLED_P8x16Str(24, 2, LastFrameStr);
        WriteEepData(300, LastFrameNum);
        break;
      }
      delay(10);
    }
    break;
  case 10:
    for (;;)
    {
      if (read_bit(PINF, button))
      {
        SwitchLockMode();
        WriteEepData(350, LockMode);
        break;
      }
      delay(10);
    }
    break;
  case 11:
    for (;;)
    {
      if (read_bit(PINF, button))
      {
        SwitchAdd();
        OLED_P8x16Str(8, 0, AddStr);
        WriteEepData(340, AddNum);
        break;
      }
      delay(10);
    }
    break;
  case 12:
    for (;;)
    {
      if (read_bit(PINF, button))
      {
        SwitchSpeed();
        WriteEepData(290, SpeedUp);
        break;
      }
      delay(10);
    }
    break;
  case 13:
    for (int i = 0;; i++)
    {
      if (read_bit(PINF, button))
      {
        SwitchCopy();
        OLED_P8x16Str(8, 2, CopyStr);
        WriteEepData(380, CopyNum);
        break;
      }
      if (i > 29)
      {
        SwitchCopy();
        OLED_P8x16Str(8, 2, CopyStr);
      }
      delay(10);
    }
    break;
  case 14:
    for (;;)
    {
      if (read_bit(PINF, button))
      {
        SwitchAutoRelease();
        WriteEepData(370, AutoRelease);
        break;
      }
      delay(10);
    }
    break;
  default:
    break;
  }
}

//按键检测
void PressButton()
{
  if (initialized)
  {
    //启停键
    if (!read_bit(PINB, 1))
    //if (!read_bit(PINF, 7))
    {
      delay(100);
      for (;;)
      {
        if (read_bit(PINB, 1))
        //if (!read_bit(PINF, 7))
        {
          StopScript();
          break;
        }
        delay(20);
      }
    }

    if (STOP)
    {
      //切换键
      if (!read_bit(PINF, 7))
      //if (!read_bit(PINF, 6))
      {
        delay(100);
        for (;;)
        {
          if (read_bit(PINF, 7))
          //if (!read_bit(PINF, 6))
          {
            SwitchState();
            break;
          }
          delay(20);
        }
      }

      //加号键
      if (!read_bit(PINF, 6))
      //if (!read_bit(PINF, 4))
      {
        delay(100);
        PlusButton = 1;
        SwitchButton(6);
        //SwitchButton(4);
        PlusButton = 0;
      }

      //减号键
      if (!read_bit(PINF, 5))
      {
        delay(100);
        MinusButton = 1;
        SwitchButton(5);
        MinusButton = 0;
      }
    }
  }
}

//切换LED
void SwitchLED()
{
  if (!STOP)
  {
    set_bit(DDRD, 5);
    reset_bit(PORTD, 5);
  }
  else
    reset_bit(DDRD, 5);
}

//刷新进度条
void RefreshProgress()
{
  ProgressNum = SizeofPgmNow * 100 / SizeofPgm;
  ProgressStr[0] = ProgressNum / 10 + 0x30;
  ProgressStr[1] = ProgressNum % 10 + 0x30;
  OLED_P8x16Str(96, 5, ProgressStr);
  if (ProgressNum != 0)
  {
    OLED_Set_Pos(10 + ProgressNum, 7);
    OLED_WrDat(0b10011001);
  }
  if (ScriptNum < 6 || ScriptNum == 8)
    SizeofPgmNow++;
}

//运行指令
void RunStep(Buttons_t button, uint16_t duration)
{
  if (Stopping)
    return;
  for (; duration > 0; duration--)
  {
    cli();
    SwitchLED();
    if (!STOP && initialized)
      RefreshProgress();
    PressButton();
    HID_Task(button);

    if (Stopping)
      break;
    USB_USBTask();
    if (!SkipMode)
      delay(20);
    delay(3);
    sei();
  }
}

//读取模块
void RunScript(const command script[], int times)
{
  if (Stopping)
    return;
  for (; times > 0; times--)
  {
    for (int i = 0;; i++)
    {
      if (pgm_read_byte(&script[i].button) == SCRIPT_END)
      {
        break;
      }
      RunStep(pgm_read_byte(&script[i].button), pgm_read_byte(&script[i].duration));
      if (Stopping)
        break;
    }
    if (Stopping)
      break;
  }
}

//程序结束
void PgmEnd()
{
  STOP = 1;
  OLED_P8x16Str(88, 5, "100");
  OLED_Set_Pos(110, 7);
  OLED_WrDat(0b10011001);
  OLED_Set_Pos(116, 7);
  OLED_WrDat(0b00111100);
  OLED_WrDat(0b00111100);
  OLED_WrDat(0b00111100);
  OLED_WrDat(0b00111100);
}

void SetupHardware(void)
{
  // We need to disable watchdog if enabled by bootloader/fuses.
  MCUSR &= ~(1 << WDRF);
  wdt_disable();

  // We need to disable clock division before initializing the USB hardware.
  clock_prescale_set(clock_div_1);
  // We can then initialize our hardware and peripherals, including the USB stack.
  SetupButtons();

  set_bit(PORTD, 1);
  set_bit(DDRD, 1);
  set_bit(DDRD, 0);
  set_bit(DDRD, 4);
  /*
  set_bit(PORTD, 1);
  set_bit(DDRD, 1);
  set_bit(DDRD, 0);
  set_bit(DDRD, 4);
*/

  USB_Init();

  OLED_Init();
}

// Fired to indicate that the device is enumerating.
void EVENT_USB_Device_Connect(void)
{
  // We can indicate that we're enumerating here (via status LEDs, sound, etc.).
}

// Fired to indicate that the device is no longer connected to a host.
void EVENT_USB_Device_Disconnect(void)
{
  // We can indicate that our device is not ready (via status LEDs, sound, etc.).
}

// Fired when the host set the current configuration of the USB device after enumeration.
void EVENT_USB_Device_ConfigurationChanged(void)
{
  bool ConfigSuccess = true;

  // We setup the HID report endpoints.
  ConfigSuccess &= Endpoint_ConfigureEndpoint(JOYSTICK_OUT_EPADDR, EP_TYPE_INTERRUPT, JOYSTICK_EPSIZE, 1);
  ConfigSuccess &= Endpoint_ConfigureEndpoint(JOYSTICK_IN_EPADDR, EP_TYPE_INTERRUPT, JOYSTICK_EPSIZE, 1);

  // We can read ConfigSuccess to indicate a success or failure at this point.
}

// Process control requests sent to the device from the USB host.
void EVENT_USB_Device_ControlRequest(void)
{
  // We can handle two control requests: a GetReport and a SetReport.

  // Not used here, it looks like we don't receive control request from the Switch.
}

// Process and deliver data from IN and OUT endpoints.
void HID_Task(Buttons_t button)
{

  // If the device isn't connected and properly configured, we can't do anything here.
  if (USB_DeviceState != DEVICE_STATE_Configured)
    return;

  // We'll start with the OUT endpoint.
  Endpoint_SelectEndpoint(JOYSTICK_OUT_EPADDR);
  // We'll check to see if we received something on the OUT endpoint.
  if (Endpoint_IsOUTReceived())
  {
    // If we did, and the packet has data, we'll react to it.
    if (Endpoint_IsReadWriteAllowed())
    {
      // We'll create a place to store our data received from the host.
      USB_JoystickReport_Output_t JoystickOutputData;
      // We'll then take in that data, setting it up in our storage.
      while (Endpoint_Read_Stream_LE(&JoystickOutputData, sizeof(JoystickOutputData), NULL) != ENDPOINT_RWSTREAM_NoError)
        ;
      // At this point, we can react to this data.

      // However, since we're not doing anything with this data, we abandon it.
    }
    // Regardless of whether we reacted to the data, we acknowledge an OUT packet on this endpoint.
    Endpoint_ClearOUT();
  }

  // We'll then move on to the IN endpoint.
  Endpoint_SelectEndpoint(JOYSTICK_IN_EPADDR);
  // We first check to see if the host is ready to accept data.
  if (Endpoint_IsINReady())
  {
    // We'll create an empty report.
    USB_JoystickReport_Input_t JoystickInputData;
    // We'll then populate this report with what we want to send to the host.
    GetNextReport(&JoystickInputData, button);
    // Once populated, we can output this data to the host. We do this by first writing the data to the control stream.
    while (Endpoint_Write_Stream_LE(&JoystickInputData, sizeof(JoystickInputData), NULL) != ENDPOINT_RWSTREAM_NoError)
      ;
    // We then send an IN packet on this endpoint.
    Endpoint_ClearIN();
  }
}

USB_JoystickReport_Input_t last_report;

int report_count = 0;
//int hold_LX = STICK_CENTER;
//int hold_LY = STICK_CENTER;
//int hold_RX = STICK_CENTER;

void GetNextReport(USB_JoystickReport_Input_t *const ReportData, Buttons_t button)
{
  //按键释放
  memset(ReportData, 0, sizeof(USB_JoystickReport_Input_t));
  ReportData->LX = STICK_CENTER;
  ReportData->LY = STICK_CENTER;
  ReportData->RX = STICK_CENTER;
  ReportData->RY = STICK_CENTER;
  ReportData->HAT = HAT_CENTER;

  //ReportData->LX = hold_LX;
  //ReportData->LY = hold_LY;
  //ReportData->RX = hold_RX;

  if (!STOP)
  {
    switch (button)
    {
    case UP:
      ReportData->LY = STICK_MIN;
      break;

    case LEFT:
      ReportData->LX = STICK_MIN;
      break;

    case DOWN:
      ReportData->LY = STICK_MAX;
      break;

    case RIGHT:
      ReportData->LX = STICK_MAX;
      break;

    case RLEFT:
      ReportData->RX = STICK_MIN;
      break;

    case RRIGHT:
      ReportData->RX = STICK_MAX;
      break;
      /*
    case HATLEFT:
      ReportData->HAT = HAT_LEFT;
      break;

    case HATRIGHT:
      ReportData->HAT = HAT_RIGHT;
      break;

    case HATCENTER:
      ReportData->HAT = HAT_CENTER;
      break;
*/
    case UPLEFT:
      ReportData->LY = STICK_MIN;
      ReportData->LX = STICK_MIN;
      break;

    case UPRIGHT:
      ReportData->LY = STICK_MIN;
      ReportData->LX = STICK_MAX;
      break;

    case DOWNLEFT:
      ReportData->LY = STICK_MAX;
      ReportData->LX = STICK_MIN;
      break;

    case DOWNRIGHT:
      ReportData->LY = STICK_MAX;
      ReportData->LX = STICK_MAX;
      break;

    case A:
      ReportData->Button |= SWITCH_A;
      break;

    case B:
      ReportData->Button |= SWITCH_B;
      break;

    case X:
      ReportData->Button |= SWITCH_X;
      break;

    case Y:
      ReportData->Button |= SWITCH_Y;
      break;

    case L:
      ReportData->Button |= SWITCH_L;
      break;

    case R:
      ReportData->Button |= SWITCH_R;
      break;

    case PLUS:
      ReportData->Button |= SWITCH_PLUS;
      break;

    case HOME:
      ReportData->Button |= SWITCH_HOME;
      break;

    case RCLICK:
      ReportData->Button |= SWITCH_RCLICK;
      break;

    default:
      break;
    }
  }

  memcpy(&last_report, ReportData, sizeof(USB_JoystickReport_Input_t));
}

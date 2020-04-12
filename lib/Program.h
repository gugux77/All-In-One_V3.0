//extern char AutoPause;
extern char ScriptNum;
extern signed char CycleNum;
extern int BoxNum;
extern char InfUsedNum;
extern long FrameNum;
extern signed char SkipWaitNum;
extern signed char LastFrameNum;
extern int DriveWaitNum;
extern int PasswordNum;
extern signed char AddNum;
extern char SkipMode;
extern char SpeedUp;
extern char LockMode;
extern char AutoRelease;
extern long CopyNum;
extern long SizeofSync;
extern long SizeofCollect;
extern long SizeofHatch;
//extern long SizeofHatch6;
//extern long SizeofHatch11;
//extern long SizeofHatch16;
//extern long SizeofHatch21;
//extern long SizeofHatch26;
//extern long SizeofHatch31;
//extern long SizeofHatch36;
//extern long SizeofHatch41;
extern long SizeofRelease;
//extern long SizeofSkip;
//extern long SizeofSkipFast;
extern long SizeofCopy;
extern long SizeofPgm;
extern long SizeofPgmNow;

void PgmStart(void);
void CollectAndHatch(void);
void Collecting(void);
void Hatching(void);
void HatchOperation(void);
void Releasing(void);
void ReleaseOperation(void);
void Skipping(void);
void SkipLastFrame(void);
void Driving(void);
//void SkipAndDrive(void);
//void DriveOpration(void);
void Copying(void);
void InfUsed(void);
void PressA(void);
void PressY(void);
void LuckDraw(void);
void CollectWatt(void);
void CollectBerry(void);
void AutoSalesman(void);
void HeadwearBattle(void);
void PokeJob(void);

/////////////////////////模块区/////////////////////////

//持续时间40约等于1秒

//打开盒子
static const command OpenBox[] PROGMEM = {
    {X, 2},
    {PAUSE, 50},
    {A, 2},
    {PAUSE, 80},
    {R, 2},
    {PAUSE, 100},
    {SCRIPT_END, 0},
};

//关闭盒子
static const command CloseBox[] PROGMEM = {
    {B, 2},
    {PAUSE, 80},
    {B, 2},
    {PAUSE, 80},
    {B, 2},
    {PAUSE, 80},
    {SCRIPT_END, 0},
};

//取蛋移动
static const command CollectMove[] PROGMEM = {
    {UPRIGHT, 2},
    {UPLEFT, 2},
    {LEFT, 60},
    {PAUSE, 5},
    {UPLEFT, 2},
    {UPRIGHT, 2},
    {RIGHT, 60},
    {PAUSE, 5},
    {SCRIPT_END, 0},
};

//取蛋对话
static const command GetEgg[] PROGMEM = {
    {UPRIGHT, 3},
    {PAUSE, 10},
    {A, 2},
    {PAUSE, 50},
    {A, 2},
    {PAUSE, 150},
    {B, 2},
    {PAUSE, 80},
    {B, 2},
    {PAUSE, 80},
    {B, 2},
    {PAUSE, 30},
    {SCRIPT_END, 0},
};

//取蛋孵蛋过渡
static const command CollectToHatch[] PROGMEM = {
    {DOWN, 10},
    {PAUSE, 5},
    {RIGHT, 200},
    {PAUSE, 5},
    {DOWNLEFT, 100},
    {PAUSE, 5},
    {X, 2},
    {PAUSE, 50},
    {A, 2},
    {PAUSE, 80},
    {R, 2},
    {PAUSE, 100},
    {LEFT, 2},
    {PAUSE, 5},
    {DOWN, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 30},
    {UP, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 30},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 60},
    {A, 2},
    {PAUSE, 50},
    {A, 2},
    {PAUSE, 30},
    {UP, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 30},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 60},
    {A, 2},
    {PAUSE, 50},
    {A, 2},
    {PAUSE, 30},
    {UP, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 30},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 60},
    {A, 2},
    {PAUSE, 50},
    {A, 2},
    {PAUSE, 30},
    {UP, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 30},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 60},
    {A, 2},
    {PAUSE, 50},
    {A, 2},
    {PAUSE, 30},
    {UP, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 30},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 60},
    {A, 2},
    {PAUSE, 50},
    {B, 2},
    {PAUSE, 80},
    {B, 2},
    {PAUSE, 80},
    {B, 2},
    {PAUSE, 80},
    {SCRIPT_END, 0},
};

//孵蛋复位
static const command HatchReset[] PROGMEM = {
    {DOWNLEFT, 10},
    {PAUSE, 5},
    {LEFT, 200},
    {LEFT, 200},
    {LEFT, 200},
    {PAUSE, 5},
    {SCRIPT_END, 0},
};

//孵蛋移动
static const command HatchMove[] PROGMEM = {
    {DOWNLEFT, 2},
    {DOWNRIGHT, 2},
    {RIGHT, 200},
    {RIGHT, 200},
    {RIGHT, 100},
    {PAUSE, 5},
    {DOWNRIGHT, 2},
    {DOWNLEFT, 2},
    {LEFT, 200},
    {LEFT, 200},
    {LEFT, 100},
    {PAUSE, 5},
    {SCRIPT_END, 0},
};

//孵蛋6周期最后一次移动
static const command LastMove6[] PROGMEM = {
    {DOWNLEFT, 2},
    {DOWNRIGHT, 2},
    {RIGHT, 200},
    {RIGHT, 200},
    {RIGHT, 100},
    {PAUSE, 5},
    {DOWNRIGHT, 2},
    {DOWNLEFT, 2},
    {LEFT, 200},
    {LEFT, 150},
    {PAUSE, 5},
    {SCRIPT_END, 0},
};

//孵蛋11周期最后一次移动
static const command LastMove11[] PROGMEM = {
    {DOWNLEFT, 2},
    {DOWNRIGHT, 2},
    {RIGHT, 200},
    {RIGHT, 200},
    {RIGHT, 100},
    {PAUSE, 5},
    {SCRIPT_END, 0},
};

//孵蛋16周期最后一次移动
static const command LastMove16[] PROGMEM = {
    {DOWNLEFT, 2},
    {DOWNRIGHT, 2},
    {RIGHT, 150},
    {PAUSE, 5},
    {SCRIPT_END, 0},
};

//孵蛋21周期最后一次移动
static const command LastMove21[] PROGMEM = {
    {DOWNLEFT, 2},
    {DOWNRIGHT, 2},
    {RIGHT, 200},
    {RIGHT, 200},
    {RIGHT, 100},
    {PAUSE, 5},
    {DOWNRIGHT, 2},
    {DOWNLEFT, 2},
    {LEFT, 200},
    {LEFT, 100},
    {PAUSE, 5},
    {SCRIPT_END, 0},
};

//孵蛋26周期最后一次移动
static const command LastMove26[] PROGMEM = {
    {DOWNLEFT, 2},
    {DOWNRIGHT, 2},
    {RIGHT, 200},
    {RIGHT, 200},
    {RIGHT, 100},
    {PAUSE, 5},
    {SCRIPT_END, 0},
};

//孵蛋31周期最后一次移动
static const command LastMove31[] PROGMEM = {
    {DOWNLEFT, 2},
    {DOWNRIGHT, 2},
    {RIGHT, 200},
    {PAUSE, 5},
    {SCRIPT_END, 0},
};

//孵蛋36周期最后一次移动
static const command LastMove36[] PROGMEM = {
    {DOWNLEFT, 2},
    {DOWNRIGHT, 2},
    {RIGHT, 200},
    {RIGHT, 200},
    {RIGHT, 100},
    {PAUSE, 5},
    {DOWNRIGHT, 2},
    {DOWNLEFT, 2},
    {LEFT, 200},
    {LEFT, 200},
    {PAUSE, 5},
    {SCRIPT_END, 0},
};

//孵蛋41周期最后一次移动
static const command LastMove41[] PROGMEM = {
    {DOWNLEFT, 2},
    {DOWNRIGHT, 2},
    {RIGHT, 200},
    {RIGHT, 200},
    {RIGHT, 100},
    {PAUSE, 5},
    {DOWNRIGHT, 2},
    {DOWNLEFT, 2},
    {LEFT, 100},
    {PAUSE, 5},
    {SCRIPT_END, 0},
};

//出蛋动画
static const command Hatched[] PROGMEM = {
    {DOWNRIGHT, 50},
    {PAUSE, 5},
    {B, 2},
    {PAUSE, 5},
    {B, 2},
    {PAUSE, 200},
    {PAUSE, 200},
    {PAUSE, 200},
    {PAUSE, 130},
    {B, 2},
    {PAUSE, 5},
    {B, 2},
    {PAUSE, 130},
    {SCRIPT_END, 0},
};

//盒子操作1
static const command BoxOperation1[] PROGMEM = {
    {Y, 2},
    {PAUSE, 5},
    {Y, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 10},
    {LEFT, 2},
    {PAUSE, 5},
    {DOWN, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 10},
    {SCRIPT_END, 0},
};

//盒子操作2
static const command BoxOperation2[] PROGMEM = {
    {LEFT, 2},
    {PAUSE, 5},
    {DOWN, 2},
    {PAUSE, 5},
    {Y, 2},
    {PAUSE, 5},
    {Y, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 10},
    {RIGHT, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 10},
    {RIGHT, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 10},
    {LEFT, 2},
    {PAUSE, 5},
    {LEFT, 2},
    {PAUSE, 5},
    {DOWN, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 10},
    {SCRIPT_END, 0},
};

//盒子操作3
static const command BoxOperation3[] PROGMEM = {
    {LEFT, 2},
    {PAUSE, 5},
    {DOWN, 2},
    {PAUSE, 5},
    {Y, 2},
    {PAUSE, 5},
    {Y, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 10},
    {RIGHT, 2},
    {PAUSE, 5},
    {RIGHT, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 10},
    {RIGHT, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 10},
    {LEFT, 2},
    {PAUSE, 5},
    {LEFT, 2},
    {PAUSE, 5},
    {LEFT, 2},
    {PAUSE, 5},
    {DOWN, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 10},
    {SCRIPT_END, 0},
};

//盒子操作4
static const command BoxOperation4[] PROGMEM = {
    {LEFT, 2},
    {PAUSE, 5},
    {DOWN, 2},
    {PAUSE, 5},
    {Y, 2},
    {PAUSE, 5},
    {Y, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 10},
    {RIGHT, 2},
    {PAUSE, 5},
    {RIGHT, 2},
    {PAUSE, 5},
    {RIGHT, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 10},
    {RIGHT, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 10},
    {RIGHT, 2},
    {PAUSE, 5},
    {RIGHT, 2},
    {PAUSE, 5},
    {RIGHT, 2},
    {PAUSE, 5},
    {DOWN, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 10},
    {SCRIPT_END, 0},
};

//盒子操作5
static const command BoxOperation5[] PROGMEM = {
    {LEFT, 2},
    {PAUSE, 5},
    {DOWN, 2},
    {PAUSE, 5},
    {Y, 2},
    {PAUSE, 5},
    {Y, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 10},
    {LEFT, 2},
    {PAUSE, 5},
    {LEFT, 2},
    {PAUSE, 5},
    {LEFT, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 10},
    {RIGHT, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 10},
    {RIGHT, 2},
    {PAUSE, 5},
    {RIGHT, 2},
    {PAUSE, 5},
    {DOWN, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 10},
    {SCRIPT_END, 0},
};

//盒子操作6
static const command BoxOperation6[] PROGMEM = {
    {LEFT, 2},
    {PAUSE, 5},
    {DOWN, 2},
    {PAUSE, 5},
    {Y, 2},
    {PAUSE, 5},
    {Y, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 10},
    {LEFT, 2},
    {PAUSE, 5},
    {LEFT, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 10},
    {RIGHT, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 10},
    {RIGHT, 2},
    {PAUSE, 5},
    {DOWN, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 10},
    {SCRIPT_END, 0},
};

//盒子操作7
static const command BoxOperation7[] PROGMEM = {
    {LEFT, 2},
    {PAUSE, 5},
    {DOWN, 2},
    {PAUSE, 5},
    {Y, 2},
    {PAUSE, 5},
    {Y, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 10},
    {LEFT, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 10},
    {R, 2},
    {PAUSE, 30},
    {SCRIPT_END, 0},
};

//放生并向下移动
static const command ReleaseDown[] PROGMEM = {
    {A, 2},
    {PAUSE, 20},
    {UP, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 30},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 60},
    {A, 2},
    {PAUSE, 20},
    {DOWN, 2},
    {PAUSE, 5},
    {SCRIPT_END, 0},
};

//放生并向上移动
static const command ReleaseUP[] PROGMEM = {
    {A, 2},
    {PAUSE, 20},
    {UP, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 30},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 60},
    {A, 2},
    {PAUSE, 20},
    {UP, 2},
    {PAUSE, 5},
    {SCRIPT_END, 0},
};

//放生并向右移动
static const command ReleaseRight[] PROGMEM = {
    {A, 2},
    {PAUSE, 20},
    {UP, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 30},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 60},
    {A, 2},
    {PAUSE, 20},
    {RIGHT, 2},
    {PAUSE, 5},
    {SCRIPT_END, 0},
};

//放生并切换下一箱
static const command ReleaseReset[] PROGMEM = {
    {A, 2},
    {PAUSE, 20},
    {UP, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 30},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 60},
    {A, 2},
    {PAUSE, 20},
    {LEFT, 2},
    {PAUSE, 5},
    {LEFT, 2},
    {PAUSE, 5},
    {LEFT, 2},
    {PAUSE, 5},
    {LEFT, 2},
    {PAUSE, 5},
    {LEFT, 2},
    {PAUSE, 5},
    {R, 2},
    {PAUSE, 30},
    {SCRIPT_END, 0},
};

//转到设置
static const command GotoSettings[] PROGMEM = {
    {HOME, 2},
    {PAUSE, 50},
    {DOWN, 2},
    {PAUSE, 5},
    {RIGHT, 2},
    {PAUSE, 5},
    {RIGHT, 2},
    {PAUSE, 5},
    {RIGHT, 2},
    {PAUSE, 5},
    {RIGHT, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 30},
    {DOWN, 60},
    {PAUSE, 5},
    {RIGHT, 2},
    {PAUSE, 5},
    {DOWN, 2},
    {PAUSE, 5},
    {DOWN, 2},
    {PAUSE, 5},
    {DOWN, 2},
    {PAUSE, 5},
    {DOWN, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 10},
    {DOWN, 2},
    {PAUSE, 5},
    {DOWN, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 5},
    {RIGHT, 2},
    {PAUSE, 5},
    {RIGHT, 2},
    {PAUSE, 5},
    {RIGHT, 2},
    {PAUSE, 5},
    {RIGHT, 2},
    {PAUSE, 5},
    {RIGHT, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 10},
    {SCRIPT_END, 0},
};

//跳回一帧
static const command SkipBack[] PROGMEM = {
    {A, 2},
    {PAUSE, 5},
    {LEFT, 2},
    {PAUSE, 1},
    {LEFT, 2},
    {PAUSE, 1},
    {LEFT, 2},
    {PAUSE, 1},
    {DOWN, 2},
    {PAUSE, 1},
    {RIGHT, 2},
    {PAUSE, 1},
    {RIGHT, 2},
    {PAUSE, 1},
    {RIGHT, 2},
    {PAUSE, 1},
    {A, 2},
    {PAUSE, 5},
    {SCRIPT_END, 0},
};

//跳帧
static const command Skip[] PROGMEM = {
    {A, 2},
    {PAUSE, 7},
    {RLEFT, 2},
    {PAUSE, 1},
    {LEFT, 2},
    {PAUSE, 1},
    {RLEFT, 2},
    {PAUSE, 1},
    {UP, 2},
    {PAUSE, 1},
    {RIGHT, 2},
    {PAUSE, 1},
    {RRIGHT, 2},
    {PAUSE, 1},
    {RIGHT, 2},
    {PAUSE, 1},
    {A, 2},
    {PAUSE, 7},
    {SCRIPT_END, 0},
};

//跳帧修复
static const command SkipFast[] PROGMEM = {
    {A, 10},
    {PAUSE, 30},
    {RLEFT, 10},
    {PAUSE, 1},
    {LEFT, 10},
    {PAUSE, 1},
    {RLEFT, 10},
    {PAUSE, 1},
    {UP, 10},
    {PAUSE, 1},
    {RRIGHT, 10},
    {PAUSE, 1},
    {RIGHT, 10},
    {PAUSE, 1},
    {RRIGHT, 10},
    {PAUSE, 1},
    {A, 10},
    {PAUSE, 30},
    {SCRIPT_END, 0},
};

//回到游戏
static const command GotoGame[] PROGMEM = {
    {HOME, 2},
    {PAUSE, 50},
    {A, 2},
    {PAUSE, 80},
    {SCRIPT_END, 0},
};

//重启游戏
static const command RestartGame[] PROGMEM = {
    {HOME, 2},
    {PAUSE, 50},
    {X, 2},
    {PAUSE, 30},
    {A, 2},
    {PAUSE, 150},
    {A, 2},
    {PAUSE, 80},
    {A, 2},
    {PAUSE, 200},
    {PAUSE, 200},
    {PAUSE, 200},
    {PAUSE, 100},
    {A, 2},
    {PAUSE, 200},
    {PAUSE, 200},
    {SCRIPT_END, 0},
};

//进招募界面
static const command Recruit[] PROGMEM = {
    {A, 2},
    {PAUSE, 50},
    {A, 2},
    {PAUSE, 120},
    {SCRIPT_END, 0},
};

//第二次招募
static const command NextRecruit[] PROGMEM = {
    {B, 2},
    {PAUSE, 30},
    {A, 2},
    {PAUSE, 200},
    {A, 2},
    {PAUSE, 30},
    {B, 2},
    {PAUSE, 30},
    {B, 2},
    {PAUSE, 50},
    {A, 2},
    {PAUSE, 120},
    {SCRIPT_END, 0},
};

//退出招募界面
static const command ExitRecruit[] PROGMEM = {
    {B, 2},
    {PAUSE, 30},
    {A, 2},
    {PAUSE, 200},
    {SCRIPT_END, 0},
};

//联网
static const command Connect[] PROGMEM = {
    {Y, 2},
    {PAUSE, 50},
    {PLUS, 2},
    {PAUSE, 200},
    {PAUSE, 200},
    {PAUSE, 200},
    {PAUSE, 200},
    {PAUSE, 200},
    {B, 2},
    {PAUSE, 30},
    {B, 2},
    {PAUSE, 50},
    {SCRIPT_END, 0},
};

//开车准备
static const command ReadyToDrive[] PROGMEM = {
    {A, 2},
    {PAUSE, 200},
    {PAUSE, 100},
    {PLUS, 2},
    {PAUSE, 80},
    {RIGHT, 2},
    {PAUSE, 5},
    {DOWN, 2},
    {PAUSE, 5},
    {SCRIPT_END, 0},
};

//密码0
static const command Password0[] PROGMEM = {
    {DOWN, 2},
    {PAUSE, 5},
    {DOWN, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {SCRIPT_END, 0},
};

//密码1
static const command Password1[] PROGMEM = {
    {LEFT, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 5},
    {DOWN, 2},
    {PAUSE, 5},
    {RIGHT, 2},
    {PAUSE, 5},
    {SCRIPT_END, 0},
};

//密码2
static const command Password2[] PROGMEM = {
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 5},
    {DOWN, 2},
    {PAUSE, 5},
    {SCRIPT_END, 0},
};

//密码3
static const command Password3[] PROGMEM = {
    {RIGHT, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 5},
    {DOWN, 2},
    {PAUSE, 5},
    {LEFT, 2},
    {PAUSE, 5},
    {SCRIPT_END, 0},
};

//密码4
static const command Password4[] PROGMEM = {
    {LEFT, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 5},
    {RIGHT, 2},
    {PAUSE, 5},
    {SCRIPT_END, 0},
};

//密码5
static const command Password5[] PROGMEM = {
    {A, 2},
    {PAUSE, 5},
    {SCRIPT_END, 0},
};

//密码6
static const command Password6[] PROGMEM = {
    {RIGHT, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 5},
    {LEFT, 2},
    {PAUSE, 5},
    {SCRIPT_END, 0},
};

//密码7
static const command Password7[] PROGMEM = {
    {LEFT, 2},
    {PAUSE, 5},
    {DOWN, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {RIGHT, 2},
    {PAUSE, 5},
    {SCRIPT_END, 0},
};

//密码8
static const command Password8[] PROGMEM = {
    {DOWN, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {SCRIPT_END, 0},
};

//密码9
static const command Password9[] PROGMEM = {
    {RIGHT, 2},
    {PAUSE, 5},
    {DOWN, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {LEFT, 2},
    {PAUSE, 5},
    {SCRIPT_END, 0},
};

//等待玩家
static const command DriveWait[] PROGMEM = {
    {PLUS, 2},
    {PAUSE, 60},
    {X, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 30},
    {A, 2},
    {PAUSE, 200},
    {SCRIPT_END, 0},
};

//开车
static const command StartDrive[] PROGMEM = {
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 200},
    {PAUSE, 200},
    {SCRIPT_END, 0},
};

//飞行模式
static const command AirplaneMode[] PROGMEM = {
    {PAUSE, 200},
    {PAUSE, 200},
    {PAUSE, 200},
    {PAUSE, 200},
    {HOME, 60},
    {PAUSE, 5},
    {DOWN, 2},
    {PAUSE, 5},
    {DOWN, 2},
    {PAUSE, 5},
    {DOWN, 2},
    {PAUSE, 5},
    {DOWN, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 30},
    {A, 2},
    {PAUSE, 30},
    {B, 2},
    {PAUSE, 30},
    {B, 2},
    {PAUSE, 30},
    {B, 2},
    {PAUSE, 30},
    {A, 2},
    {PAUSE, 30},
    {A, 2},
    {PAUSE, 30},
    {A, 2},
    {PAUSE, 30},
    {A, 2},
    {PAUSE, 30},
    {A, 2},
    {PAUSE, 200},
    {PAUSE, 200},
    {PAUSE, 200},
    {PAUSE, 200},
    {SCRIPT_END, 0},
};

//加好友
static const command AddFriends[] PROGMEM = {
    {HOME, 2},
    {PAUSE, 50},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 80},
    {A, 2},
    {PAUSE, 60},
    {DOWN, 60},
    {PAUSE, 5},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 5},
    {SCRIPT_END, 0},
};

//复制取蛋
static const command CopyGetEgg[] PROGMEM = {
    {UPRIGHT, 3},
    {PAUSE, 10},
    {A, 2},
    {PAUSE, 50},
    {A, 2},
    {PAUSE, 150},
    {B, 2},
    {PAUSE, 80},
    {A, 2},
    {PAUSE, 50},
    {B, 2},
    {PAUSE, 80},
    {A, 2},
    {PAUSE, 100},
    {B, 2},
    {PAUSE, 50},
    {B, 2},
    {PAUSE, 80},
    {B, 2},
    {PAUSE, 30},
    {SCRIPT_END, 0},
};

//复制放生
static const command CopyRelease[] PROGMEM = {
    {A, 2},
    {PAUSE, 20},
    {DOWN, 2},
    {PAUSE, 5},
    {DOWN, 2},
    {PAUSE, 5},
    {DOWN, 2},
    {PAUSE, 5},
    {DOWN, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 30},
    {UP, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 60},
    {A, 2},
    {PAUSE, 20},
    {SCRIPT_END, 0},
};

//领取瓦特
static const command GetWatt[] PROGMEM = {
    {A, 2},
    {PAUSE, 30},
    {B, 2},
    {PAUSE, 30},
    {B, 2},
    {PAUSE, 50},
    {B, 2},
    {PAUSE, 80},
    {SCRIPT_END, 0},
};

//宝可帮帮忙刷新
static const command RefreshJob[] PROGMEM = {
    {A, 2},
    {PAUSE, 30},
    {A, 2},
    {PAUSE, 30},
    {DOWN, 2},
    {PAUSE, 5},
    {DOWN, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 130},
    {B, 2},
    {PAUSE, 60},
    {B, 2},
    {PAUSE, 30},
    {SCRIPT_END, 0},
};

//进入任务
static const command StartJob[] PROGMEM = {
    {A, 2},
    {PAUSE, 30},
    {A, 2},
    {PAUSE, 30},
    {DOWN, 2},
    {PAUSE, 5},
    {DOWN, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 130},
    {A, 2},
    {PAUSE, 30},
    {A, 2},
    {PAUSE, 50},
    {A, 2},
    {PAUSE, 20},
    {A, 2},
    {PAUSE, 80},
    {X, 2},
    {PAUSE, 30},
    {B, 2},
    {PAUSE, 100},
    {A, 2},
    {PAUSE, 30},
    {A, 2},
    {PAUSE, 200},
    {PAUSE, 200},
    {B, 2},
    {PAUSE, 30},
    {B, 2},
    {PAUSE, 30},
    {B, 2},
    {PAUSE, 50},
    {B, 2},
    {PAUSE, 30},
    {SCRIPT_END, 0},
};

//结束任务
static const command EndJob[] PROGMEM = {
    {A, 2},
    {PAUSE, 30},
    {A, 2},
    {PAUSE, 30},
    {DOWN, 2},
    {PAUSE, 5},
    {DOWN, 2},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 120},
    {A, 2},
    {PAUSE, 30},
    {A, 2},
    {PAUSE, 200},
    {PAUSE, 200},
    {PAUSE, 100},
    {SCRIPT_END, 0},
};

//咖啡厅战斗
static const command Battle[] PROGMEM = {
    {A, 2},
    {PAUSE, 50},
    {B, 2},
    {PAUSE, 50},
    {B, 2},
    {PAUSE, 50},
    {A, 2},
    {PAUSE, 50},
    {DOWN, 2},
    {PAUSE, 30},
    {B, 2},
    {PAUSE, 50},
    {B, 2},
    {PAUSE, 150},
    {B, 2},
    {PAUSE, 200},
    {PAUSE, 200},
    {PAUSE, 200},
    {PAUSE, 200},
    {A, 2},
    {PAUSE, 30},
    {UP, 50},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 30},
    {UP, 50},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 30},
    {A, 2},
    {PAUSE, 30},
    {UP, 50},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 30},
    {UP, 50},
    {PAUSE, 5},
    {A, 2},
    {PAUSE, 30},
    //{UP, 50},
    //{PAUSE, 30},
    //{A, 2},
    //{PAUSE, 50},
    //{UP, 50},
    //{PAUSE, 30},
    //{A, 2},
    {PAUSE, 200},
    {PAUSE, 200},
    {PAUSE, 100},
    {B, 2},
    {PAUSE, 200},
    {PAUSE, 200},
    {PAUSE, 100},
    {B, 2},
    {PAUSE, 200},
    {B, 2},
    {PAUSE, 50},
    {B, 2},
    {PAUSE, 200},
    {B, 2},
    {PAUSE, 50},
    {B, 2},
    {PAUSE, 200},
    {SCRIPT_END, 0},
};

//宝可梦中心
static const command GotoCenter[] PROGMEM = {
    {DOWN, 80},
    {PAUSE, 120},
    {X, 2},
    {PAUSE, 50},
    {A, 2},
    {PAUSE, 120},
    {A, 2},
    {PAUSE, 50},
    {A, 2},
    {PAUSE, 200},
    {UP, 50},
    {PAUSE, 120},
    {UP, 80},
    {PAUSE, 30},
    {A, 2},
    {PAUSE, 30},
    {A, 2},
    {PAUSE, 30},
    {A, 2},
    {PAUSE, 30},
    {A, 2},
    {PAUSE, 200},
    {PAUSE, 200},
    {PAUSE, 100},
    {A, 2},
    {PAUSE, 60},
    {A, 2},
    {PAUSE, 30},
    {DOWN, 80},
    {PAUSE, 120},
    {SCRIPT_END, 0},
};

//回到餐厅
static const command GoBack[] PROGMEM = {
    {RIGHT, 30},
    {PAUSE, 30},
    {UP, 140},
    {PAUSE, 30},
    {LEFT, 60},
    {PAUSE, 10},
    {UP, 10},
    {PAUSE, 10},
    {LEFT, 10},
    {PAUSE, 120},
    {UP, 80},
    {PAUSE, 50},
    {SCRIPT_END, 0},
};

//树果
static const command Berry[] PROGMEM = {
    {A, 2},
    {PAUSE, 50},
    {A, 2},
    {PAUSE, 50},
    {A, 2},
    {PAUSE, 200},
    {SCRIPT_END, 0},
};

//售货郎
static const command Salesman[] PROGMEM = {
    {A, 2},
    {PAUSE, 50},
    {A, 2},
    {PAUSE, 30},
    {A, 2},
    {PAUSE, 50},
    {A, 2},
    {PAUSE, 30},
    {SCRIPT_END, 0},
};

//抽奖
static const command Rotomi[] PROGMEM = {
    {A, 2},
    {PAUSE, 30},
    {A, 2},
    {PAUSE, 30},
    {DOWN, 2},
    {PAUSE, 5},
    {SCRIPT_END, 0},
};

//等待5秒
static const command PAUSE5[] PROGMEM = {
    {PAUSE, 200},
    {SCRIPT_END, 0},
};

//同步
static const command Sync[] PROGMEM = {
    {RCLICK, 2},
    {PAUSE, 5},
    {SCRIPT_END, 0},
};

//A30
static const command A30[] PROGMEM = {
    {A, 2},
    {PAUSE, 30},
    {SCRIPT_END, 0},
};

//B30
static const command B30[] PROGMEM = {
    {B, 2},
    {PAUSE, 30},
    {SCRIPT_END, 0},
};

/////////////////////////程序区/////////////////////////

//RunScript(模块名,执行次数)
//RunStep(单个操作,持续时间) 持续时间40约等于一秒
//LOOP_START(X) LOOP_END 之间的代码循环X次后继续 X=0为无限循环
//PROGRAM_END 程序结束后自动停止 如果不写 结束后会重复执行下去

void PgmStart()
{
    Stopping = 0;
    SizeofPgmNow = 0;
    SkipMode = 0;
    switch (ScriptNum)
    {
    case 1:
        CollectAndHatch();
        break;
    case 2:
        Collecting();
        break;
    case 3:
        Hatching();
        break;
    case 4:
        Releasing();
        break;
    case 5:
        Skipping();
        break;
    case 6:
        SkipLastFrame();
        break;
    case 7:
        Driving();
        break;
    case 8:
        Copying();
        break;
    case 9:
        InfUsed();
        break;
    default:
        break;
    }
}

//取蛋并孵化
void CollectAndHatch()
{
    switch (CycleNum)
    {
    case 6:
        SizeofPgm = GetDuration(LastMove6) * BoxNum;
        break;
    case 11:
        SizeofPgm = (GetDuration(HatchMove) * 6 + GetDuration(LastMove11) * 6) * BoxNum;
        break;
    case 16:
        SizeofPgm = (GetDuration(HatchMove) * 12 + GetDuration(LastMove16) * 6) * BoxNum;
        break;
    case 21:
        SizeofPgm = (GetDuration(HatchMove) * 12 + GetDuration(LastMove21) * 6) * BoxNum;
        break;
    case 26:
        SizeofPgm = (GetDuration(HatchMove) * 18 + GetDuration(LastMove26) * 6) * BoxNum;
        break;
    case 31:
        SizeofPgm = (GetDuration(HatchMove) * 24 + GetDuration(LastMove31) * 6) * BoxNum;
        break;
    case 36:
        SizeofPgm = (GetDuration(HatchMove) * 24 + GetDuration(LastMove36) * 6) * BoxNum;
        break;
    case 41:
        SizeofPgm = (GetDuration(HatchMove) * 30 + GetDuration(LastMove41) * 6) * BoxNum;
        break;
    default:
        break;
    }
    SizeofPgm += (SizeofHatch + SizeofCollect * 43) * BoxNum + GetDuration(CollectToHatch) + 10;
    //取蛋 成功率约70%
    LOOP_START((BoxNum * 43))
    RunScript(CollectMove, 3);
    RunScript(GetEgg, 1);
    LOOP_END
    //过渡操作
    RunScript(CollectToHatch, 1);
    //孵蛋
    RunStep(DOWNLEFT, 10);
    LOOP_START(BoxNum)
    HatchOperation();
    LOOP_END
    PROGRAM_END
}

/*
//取蛋并孵化(420个左右&41周期)
void CollectAndHatch41()
{
LOOP_START(600)
  Collecting();
LOOP_END
RunScript(CollectToHatch,1);
RunScript(ReleaseDown,5);
RunStep(B,2);
RunStep(PAUSE,80);
RunStep(B,2);
RunStep(PAUSE,80);
RunStep(B,2);
RunStep(PAUSE,80);
LOOP_START(14)
  Hatching41();
LOOP_END
PROGRAM_END
}
*/

//取蛋
void Collecting()
{
    SizeofPgm = SizeofCollect * BoxNum * 43;
    LOOP_START((BoxNum * 43))
    RunScript(CollectMove, 3);
    RunScript(GetEgg, 1);
    LOOP_END
    PROGRAM_END
}

//孵蛋
void Hatching()
{
    switch (CycleNum)
    {
    case 6:
        SizeofPgm = GetDuration(LastMove6) * BoxNum;
        break;
    case 11:
        SizeofPgm = (GetDuration(HatchMove) * 6 + GetDuration(LastMove11) * 6) * BoxNum;
        break;
    case 16:
        SizeofPgm = (GetDuration(HatchMove) * 12 + GetDuration(LastMove16) * 6) * BoxNum;
        break;
    case 21:
        SizeofPgm = (GetDuration(HatchMove) * 12 + GetDuration(LastMove21) * 6) * BoxNum;
        break;
    case 26:
        SizeofPgm = (GetDuration(HatchMove) * 18 + GetDuration(LastMove26) * 6) * BoxNum;
        break;
    case 31:
        SizeofPgm = (GetDuration(HatchMove) * 24 + GetDuration(LastMove31) * 6) * BoxNum;
        break;
    case 36:
        SizeofPgm = (GetDuration(HatchMove) * 24 + GetDuration(LastMove36) * 6) * BoxNum;
        break;
    case 41:
        SizeofPgm = (GetDuration(HatchMove) * 30 + GetDuration(LastMove41) * 6) * BoxNum;
        break;
    default:
        break;
    }
    SizeofPgm += SizeofHatch * BoxNum + 10;
    RunStep(DOWNLEFT, 10);
    LOOP_START(BoxNum)
    HatchOperation();
    LOOP_END
    PROGRAM_END
}

//孵蛋操作
void HatchOperation()
{
    char num = 2;
    RunScript(OpenBox, 1);
    RunScript(BoxOperation1, 1);
    RunScript(CloseBox, 1);
    LOOP_START(6)
    switch (CycleNum)
    {
    case 6:
        RunScript(LastMove6, 1);
        break;
    case 11:
        RunScript(HatchMove, 1);
        RunScript(LastMove11, 1);
        break;
    case 16:
        RunScript(HatchMove, 2);
        RunScript(LastMove16, 1);
        break;
    case 21:
        RunScript(HatchMove, 2);
        RunScript(LastMove21, 1);
        break;
    case 26:
        RunScript(HatchMove, 3);
        RunScript(LastMove26, 1);
        break;
    case 31:
        RunScript(HatchMove, 4);
        RunScript(LastMove31, 1);
        break;
    case 36:
        RunScript(HatchMove, 4);
        RunScript(LastMove36, 1);
        break;
    case 41:
        RunScript(HatchMove, 5);
        RunScript(LastMove41, 1);
        break;
    default:
        break;
    }
    RunScript(Hatched, 5);
    RunScript(HatchReset, 1);
    RunScript(OpenBox, 1);
    switch (num)
    {
    case 2:
        RunScript(BoxOperation2, 1);
        break;
    case 3:
        RunScript(BoxOperation3, 1);
        break;
    case 4:
        RunScript(BoxOperation4, 1);
        break;
    case 5:
        RunScript(BoxOperation5, 1);
        break;
    case 6:
        RunScript(BoxOperation6, 1);
        break;
    case 7:
        RunScript(BoxOperation7, 1);
    default:
        break;
    }
    RunScript(CloseBox, 1);
    num++;
    LOOP_END
}

//放生
void Releasing()
{
    SizeofPgm = SizeofSync + SizeofRelease * BoxNum;
    RunScript(Sync, 5);
    LOOP_START(BoxNum)
    ReleaseOperation();
    LOOP_END
    PROGRAM_END
}

//放生操作
void ReleaseOperation()
{
    RunScript(ReleaseDown, 4);
    RunScript(ReleaseRight, 1);
    RunScript(ReleaseUP, 4);
    RunScript(ReleaseRight, 1);
    RunScript(ReleaseDown, 4);
    RunScript(ReleaseRight, 1);
    RunScript(ReleaseUP, 4);
    RunScript(ReleaseRight, 1);
    RunScript(ReleaseDown, 4);
    RunScript(ReleaseRight, 1);
    RunScript(ReleaseUP, 4);
    RunScript(ReleaseReset, 1);
}

//跳帧
void Skipping()
{
    if (SpeedUp)
        SizeofPgm = GetDuration(SkipFast) * 31 * FrameNum / 30;
    else
        SizeofPgm = GetDuration(Skip) * 31 * FrameNum / 30;
    SizeofPgm += SizeofSync + GetDuration(GotoSettings) + GetDuration(GotoGame);
    RunScript(Sync, 5);
    RunScript(GotoSettings, 1);
    LOOP_START((FrameNum / 30))
    if (SpeedUp)
    {
        SkipMode = 1;
        RunScript(SkipFast, 31);
        SkipMode = 0;
    }
    else
        RunScript(Skip, 31);
    LOOP_END
    RunScript(GotoGame, 1);
    PROGRAM_END
}

//跳最后N帧
void SkipLastFrame()
{
    RunScript(Sync, 5);
    LOOP_START(0)
    LOOP_START((30 / LastFrameNum))
    RunScript(Recruit, 1);
    RunScript(GotoSettings, 1);
    RunScript(Skip, 1);
    RunScript(GotoGame, 1);
    LOOP_START((LastFrameNum - 1))
    RunScript(NextRecruit, 1);
    RunScript(GotoSettings, 1);
    RunScript(Skip, 1);
    RunScript(GotoGame, 1);
    LOOP_END
    RunScript(NextRecruit, 1);
    RunScript(PAUSE5, SkipWaitNum / 5);
    RunScript(RestartGame, 1);
    LOOP_END
    RunScript(GotoSettings, 1);
    RunScript(Skip, 1);
    if (LastFrameNum == 4)
    {
        RunScript(Skip, 2);
    }
    RunScript(GotoGame, 1);
    LOOP_END
}

//自动驾驶
void Driving()
{
    RunScript(Sync, 5);
    LOOP_START(0)
    LOOP_START(AddNum)
    int num = 1000;
    int random = PasswordNum;
    if (LastFrameNum)
    {
        RunScript(Recruit, 1);
        RunScript(GotoSettings, 1);
        RunScript(Skip, 1);
        RunScript(GotoGame, 1);
        LOOP_START((LastFrameNum - 1))
        RunScript(NextRecruit, 1);
        RunScript(GotoSettings, 1);
        RunScript(Skip, 1);
        RunScript(GotoGame, 1);
        LOOP_END
        RunScript(ExitRecruit, 1);
        RunScript(GotoSettings, 1);
        RunScript(SkipBack, LastFrameNum);
        RunScript(GotoGame, 1);
        RunScript(GetWatt, 1);
    }
    RunScript(Connect, 1);
    RunScript(ReadyToDrive, 1);
    if (PasswordNum != 10000)
    {
        if (PasswordNum == 10001)
        {
            random = (int)rand();
        }
        LOOP_START(4)
        switch ((random / num) % 10)
        {
        case 0:
            RunScript(Password0, 1);
            break;
        case 1:
            RunScript(Password1, 1);
            break;
        case 2:
            RunScript(Password2, 1);
            break;
        case 3:
            RunScript(Password3, 1);
            break;
        case 4:
            RunScript(Password4, 1);
            break;
        case 5:
            RunScript(Password5, 1);
            break;
        case 6:
            RunScript(Password6, 1);
            break;
        case 7:
            RunScript(Password7, 1);
            break;
        case 8:
            RunScript(Password8, 1);
            break;
        case 9:
            RunScript(Password9, 1);
            break;
        default:
            break;
        }
        num /= 10;
        LOOP_END
    }
    RunScript(DriveWait, 1);
    RunScript(PAUSE5, DriveWaitNum / 5 - 2);
    RunScript(StartDrive, 1);
    RunScript(A30, 30);
    if (LockMode)
        RunScript(RestartGame, 1);
    else
        RunScript(AirplaneMode, 1);
    LOOP_END
    RunScript(AddFriends, 1);
    RunScript(A30, 60);
    RunScript(GotoGame, 1);
    LOOP_END
}

//复制道具
void Copying()
{
    if (AutoRelease == 1)
        SizeofPgm = (SizeofCopy + GetDuration(CopyRelease) + GetDuration(OpenBox) + GetDuration(CloseBox)) * (CopyNum * 43 / 30);
    else if (AutoRelease == 2)
        SizeofPgm = SizeofCopy * (CopyNum * 43 / 30) + (SizeofRelease + GetDuration(OpenBox) + GetDuration(CloseBox)) * (CopyNum * 43 / 30 / 86);
    else
        SizeofPgm = SizeofCopy * (CopyNum * 43 / 30);
    int num = 0;
    LOOP_START((CopyNum * 43 / 30))
    num++;
    RunScript(CollectMove, 3);
    RunScript(CopyGetEgg, 1);
    if (AutoRelease == 1)
    {
        RunScript(OpenBox, 1);
        RunScript(CopyRelease, 1);
        RunScript(CloseBox, 1);
    }
    if (AutoRelease == 2 && num >= 86)
    {
        RunScript(OpenBox, 1);
        ReleaseOperation();
        RunScript(CloseBox, 1);
        num = 0;
    }
    LOOP_END
    PROGRAM_END
}

//不常用功能
void InfUsed()
{
    RunScript(Sync, 5);
    switch (InfUsedNum)
    {
    case 1: //连A
        PressA();
        break;
    case 2: //连Y
        PressY();
        break;
    case 3: //刷瓦特
        CollectWatt();
        break;
    case 4: //刷树果
        CollectBerry();
        break;
    case 5: //刷头饰
        HeadwearBattle();
        break;
    case 6: //售货郎
        AutoSalesman();
        break;
    case 7: //宝可帮帮忙
        PokeJob();
        break;
    case 8: //洛托姆抽奖
        LuckDraw();
        break;
    default:
        break;
    }
}

//连A
void PressA()
{
    LOOP_START(0)
    RunStep(A, 2);
    RunStep(PAUSE, 5);
    LOOP_END
}

//连Y
void PressY()
{
    LOOP_START(0)
    RunStep(Y, 2);
    RunStep(PAUSE, 5);
    LOOP_END
}

//刷瓦特
void CollectWatt()
{
    LOOP_START(0)
    RunScript(GetWatt, 1);
    RunScript(GotoSettings, 1);
    RunScript(Skip, 1);
    RunScript(GotoGame, 1);
    LOOP_END
}

//刷树果
void CollectBerry()
{
    LOOP_START(0)
    RunScript(Berry, 1);
    RunScript(B30, 15);
    RunScript(GotoSettings, 1);
    RunScript(Skip, 1);
    RunScript(GotoGame, 1);
    LOOP_END
}

//刷头饰()
void HeadwearBattle()
{
    LOOP_START(0)
    LOOP_START(6)
    LOOP_START(5)
    RunScript(Battle, 1);
    RunScript(B30, 12);
    RunScript(GotoSettings, 1);
    RunScript(Skip, 1);
    RunScript(GotoGame, 1);
    LOOP_END
    RunScript(GotoCenter, 1);
    RunScript(GoBack, 1);
    LOOP_END
    RunScript(GotoSettings, 1);
    RunScript(Skip, 1);
    RunScript(GotoGame, 1);
    LOOP_END
}

//售货郎
void AutoSalesman()
{
    LOOP_START(0)
    RunScript(Salesman, 1);
    RunScript(B30, 12);
    RunScript(GotoSettings, 1);
    RunScript(Skip, 1);
    RunScript(GotoGame, 1);
    LOOP_END
}

//宝可帮帮忙
void PokeJob()
{
    RunScript(RefreshJob, 1);
    LOOP_START(0)
    LOOP_START(15)
    RunScript(StartJob, 1);
    RunScript(GotoSettings, 1);
    RunScript(Skip, 2);
    RunScript(GotoGame, 1);
    RunScript(EndJob, 1);
    RunScript(B30, 15);
    LOOP_END
    RunScript(GotoSettings, 1);
    RunScript(Skip, 1);
    RunScript(GotoGame, 1);
    LOOP_END
}

//洛托姆抽奖
void LuckDraw()
{
    LOOP_START(0)
    RunScript(Rotomi, 1);
    RunScript(A30, 6);
    RunScript(B30, 20);
    RunScript(GotoSettings, 1);
    RunScript(Skip, 1);
    RunScript(GotoGame, 1);
    LOOP_END
}

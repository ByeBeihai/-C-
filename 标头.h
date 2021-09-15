#define SIZE 15
#define BLACKtem 10
#define WHITEtem 11
#define BLACK 20
#define WHITE 21

extern int Board[SIZE][SIZE];//显示用的棋盘
extern int BoardCheck[SIZE][SIZE];//禁手检查用棋盘
extern  int Boardtest[SIZE][SIZE];//给AI打分和模拟使用的棋盘
extern int result;//判断棋局是否结束的变量
extern int dx[8];//方向向量扫描法
extern int dy[8];
extern  int HSD_point[4];
extern int Last_step[2];
extern double set_a, set_c,set_b, set_d, set_e;
extern double set_a1, set_c1, set_b1, set_d1;

void PVP();//双人对战模式
void PVE();//人机对战模式
void Train();//AI训练用的模式

void AI(int color,int q);//三步进攻型
int Step2(int color2, int score1,int last_score1);
int Step3(int color2, int score2, int last_score2);

void AInew(int color, int q);//三步保守型
int Step2new(int color, int score1, int last_score1);
int Step3new(int color2, int score2, int last_score2);

void AIB(int color, int q);//四步AI
int Step2B(int color, int score1, int last_score1);
int Step3B(int color2, int score2, int last_score2);
int Step4B(int color3, int score3, int last_score3);


void Airdrop(int x, int y, int color);//AI用于下棋的函数（接入Board数组）
int point(int x, int y, int color,int step);//AI打分函数（三步进攻型和四步共用）
int point2(int x, int y, int color, int step);//三步保守型的打分函数
void Playerpart(int color);//人机对战的人类
void InitBoardArray();  //初始化空棋盘//
void DisplayBoard();	//显示棋盘//
int ForbiddenCheck(char x2, int y2);//双人对弈的禁手判断 //
int ForbiddenCheck_forlive3(int x2, int y2);//检测禁手导致的伪活三
int ForbiddenCheck_Unit(int x, int y);

void SwitchSituation_WHITE();  //把WHITEtem转换成WHITE
void SwitchSituation_BLACK();  //把BLACKtem转换成BLACK
int WINorLOSE();  //判断胜负// //20201031简单版//

int HSD(int i, int j,int step);//详细说明见“棋盘态势感知.c”
int HSD2(int i, int j,int step);
int next(int i, int j);//判断周围是否有棋子
int next1(int x, int y);//判断的范围增大





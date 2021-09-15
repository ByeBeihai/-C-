#define SIZE 15
#define BLACKtem 10
#define WHITEtem 11
#define BLACK 20
#define WHITE 21

extern int Board[SIZE][SIZE];//��ʾ�õ�����
extern int BoardCheck[SIZE][SIZE];//���ּ��������
extern  int Boardtest[SIZE][SIZE];//��AI��ֺ�ģ��ʹ�õ�����
extern int result;//�ж�����Ƿ�����ı���
extern int dx[8];//��������ɨ�跨
extern int dy[8];
extern  int HSD_point[4];
extern int Last_step[2];
extern double set_a, set_c,set_b, set_d, set_e;
extern double set_a1, set_c1, set_b1, set_d1;

void PVP();//˫�˶�սģʽ
void PVE();//�˻���սģʽ
void Train();//AIѵ���õ�ģʽ

void AI(int color,int q);//����������
int Step2(int color2, int score1,int last_score1);
int Step3(int color2, int score2, int last_score2);

void AInew(int color, int q);//����������
int Step2new(int color, int score1, int last_score1);
int Step3new(int color2, int score2, int last_score2);

void AIB(int color, int q);//�Ĳ�AI
int Step2B(int color, int score1, int last_score1);
int Step3B(int color2, int score2, int last_score2);
int Step4B(int color3, int score3, int last_score3);


void Airdrop(int x, int y, int color);//AI��������ĺ���������Board���飩
int point(int x, int y, int color,int step);//AI��ֺ��������������ͺ��Ĳ����ã�
int point2(int x, int y, int color, int step);//���������͵Ĵ�ֺ���
void Playerpart(int color);//�˻���ս������
void InitBoardArray();  //��ʼ��������//
void DisplayBoard();	//��ʾ����//
int ForbiddenCheck(char x2, int y2);//˫�˶��ĵĽ����ж� //
int ForbiddenCheck_forlive3(int x2, int y2);//�����ֵ��µ�α����
int ForbiddenCheck_Unit(int x, int y);

void SwitchSituation_WHITE();  //��WHITEtemת����WHITE
void SwitchSituation_BLACK();  //��BLACKtemת����BLACK
int WINorLOSE();  //�ж�ʤ��// //20201031�򵥰�//

int HSD(int i, int j,int step);//��ϸ˵����������̬�Ƹ�֪.c��
int HSD2(int i, int j,int step);
int next(int i, int j);//�ж���Χ�Ƿ�������
int next1(int x, int y);//�жϵķ�Χ����





#define NUMBER '0'
#define SIN -30
#define COS -31
#define TAN -32
#define EXP -33
#define POW -34
#define ASG -35
#define VAR -36

void push(double);
double pop(void);

int getop(char []);

int getch(void);
void ungetch(int);
typedef struct INode{
	char data;
	struct INode* next;
}INode;

typedef struct stack{
	INode* top;
}stack;

typedef struct IINode{
	int data;
	struct IINode* next;
}IINode;

typedef struct stack2{
	IINode* top;
}stack2;

void init(stack* s);
void push(stack *s, char c);
char pop(stack* s);
int isOperator(char c);
int priority(char c);
char peek(stack* s);
char* inToPost(char* infix);

void init2(stack2* s);
void push2(stack2 *s, int c);
int pop2(stack2* s);
int evalPost(char* post);

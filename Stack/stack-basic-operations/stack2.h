typedef struct stack{
	char *A;
	int size;
	int top;
}stack;

void init(stack *s, int len);
void push(stack *s, char data);
int isFull(stack s) ;
int isEmpty(stack s);
char pop(stack *s);
void reverse(stack *s, char *str);
void decToBin(int dec);
int isOpen(char ch);
int isClose(char ch);
int match(char ch1, char ch2);
int isValid(char* str);

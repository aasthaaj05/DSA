typedef struct twoStacks{
    int *a;
    int size;
    int top1;
    int top2;
}twoStacks;

twoStacks* create(int n);
void push1(twoStacks* s, int x);
void push2(twoStacks* s, int x);
int pop1(twoStacks* s);
int pop2(twoStacks* s);
void display(twoStacks s);

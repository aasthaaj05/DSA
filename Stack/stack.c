#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<ctype.h>

char* reverse(char infix[]) {
    int len = strlen(infix);
    char* rev = (char*)malloc((len + 1) * sizeof(char));  
    int i, j = 0;
    for (i = len - 1; i >= 0; i--) {
        rev[j] = infix[i];
        if(rev[j]=='('){
        	rev[j]==')';
        }else if(rev[j]==')'){
		rev[j]=='(';        
        }
        j++;
    }
    rev[j] = '\0'; 
    return rev;
}

typedef struct Node {
    char data;
    struct Node* next;
} Node;

int isemp(Node* top) {
    return top == NULL;
}

Node* newN(char data) {
    Node* new = (Node*)malloc(sizeof(Node));
    new->data = data;
    new->next = NULL;
    return new;
}

Node* push(Node* top, char data) {
    Node* new = newN(data);
    new->next = top;
    top = new;
    printf("%c pushed to stack\n", data);
    return top; 
}

Node* pop(Node* top) {
    if (isemp(top)) {
        printf("Stack underflow\n");
        return NULL;
    }
    Node* temp = top;
    top = top->next;
    printf("%c popped from stack\n", temp->data);
    free(temp);
    return top;  
}

void printStack(Node* top) {
    if (isemp(top)) {
        printf("Stack is empty\n");
        return;
    }
    Node* temp = top;
    printf("Stack elements are:\n");
    while (temp != NULL) {
        printf("%c\n", temp->data);
        temp = temp->next;
    }
}

char peek(Node* top) {
    if (isemp(top)) {
        printf("Stack is empty\n");
        return '\0';  
    }
    return top->data;
}

int priority(char operator) {
    switch (operator) {
        case '^':
            return 4;
        case '/':
        case '*':
            return 3;
        case '+':
        case '-':
            return 2;
        case '(':
            return 1;
        case ')':
            return 0;
        default:
            return -1; 
    }
}

void inToPost(char* in, char* post) {
    int i = 0, j = 0;
    Node* top = NULL; 
    
    while (in[i] != '\0') {
        int val = priority(in[i]);
        
        if (val == -1) {
            post[j++] = in[i];
        } else if (val > 1) {
            while (!isemp(top) && priority(peek(top)) >= val && peek(top) != '(') {
                post[j++] = peek(top);
                top = pop(top);
            }
            top = push(top, in[i]);
        } else if (in[i] == '(') {
            top = push(top, in[i]);
        } else if (in[i] == ')') {
            while (!isemp(top) && peek(top) != '(') {
                post[j++] = peek(top);
                top = pop(top);
            }
            top = pop(top); 
        }
        
        i++;
    }
    while (!isemp(top)) {
        post[j++] = peek(top);
        top = pop(top);
    }

    post[j] = '\0'; 
}

int eval(char operator, int op1, int op2) {
    int result;
    switch (operator) {
        case '/':
            result = op1 / op2;
            break;
        case '*':
            result = op1 * op2;
            break;
        case '+':
            result = op1 + op2;
            break;
        case '-':
            result = op1 - op2;
            break;
        case '%':
        	result=op1%op2;
        	break;
        default:
            printf("Invalid operator\n");
            result = 0; 
    }
    return result;
}

int eval_post(char* post){
	int i,x;
	int op1, op2, result;
	
	Node* top=NULL;
	for(i=0;post[i]!='\0';i++){
		if(isalnum(post[i])){
			printf("Enter value for %c: ", post[i]);
			scanf("%d", &x);
			char conv=(char)x;
			top=push(top,conv);
		}else{
			op2=(int)peek(top);
			top=pop(top);
			op1=(int)peek(top);
			top=pop(top);
			result=eval(post[i],op1,op2);
			char conv=(char)result;
			top=push(top,conv);
		}
	}

	return result;
}

void inToPre(char in[], char* pre) {
    int i = 0, j = 0;
    Node* top = NULL; 
    char* revin=reverse(in);
    while (revin[i] != '\0') {
        int val = priority(revin[i]);
        
        if (val == -1) {
            pre[j++] =revin[i];
        } else if (val > 1) {
            while (!isemp(top) && priority(peek(top)) > val && peek(top) != '(') {
                pre[j++] = peek(top);
                top = pop(top);
            }
            top = push(top, in[i]);
        } else if (revin[i] == '(') {
            top = push(top, in[i]);
        } else if (revin[i] == ')') {
            while (!isemp(top) && peek(top) != '(') {
                pre[j++] = peek(top);
                top = pop(top);
            }
            top = pop(top); 
        }
        
        i++;
    }
    while (!isemp(top)) {
        pre[j++] = peek(top);
        top = pop(top);
    }

   pre=reverse(pre);
}

int main() {
    Node* top = NULL;

    top = push(top, '1');
    top = push(top, '2');
    top = push(top, '3');

    printf("Top element is %c\n", peek(top));

    top = pop(top);
    printf("Top element is %c\n", peek(top));

    printStack(top);

    char infix[100] = "a+(b-c)*d-e/f+g";
    char* postfix = (char*)malloc(strlen(infix) + 1); 

    inToPost(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    
    char* prefix = (char*)malloc(strlen(infix) + 1); 

    inToPre(infix, prefix);
    printf("Prefix expression: %s\n", prefix);

    int result=eval_post(postfix);
    printf("Result %d", result);

    free(postfix);
    return 0;
}


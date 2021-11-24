#define STACK_SIZE 100;

Typedef struct{
    SElemType *base_one, *base_two;//栈底指针
    ElemType *top_one, *top_two;//栈顶指针
    int stacksize;
}SqStack;

Status InitStack(SqStack &S){
    //初始化双向栈
    //第一个栈底和栈顶指向数组起点
    S.base_two = S.top_two = S.base_one + STACK_SIZE - 1;
    S.stacksize = STACK_SIZE;
    return OK;
}//InitStack

Status Push(SqStack &S, int i, SElemType e){
    //
    if(S.top_two < S.top_one){
        return OVERFLOW;//栈满，不考虑追加空间
    }
    if(i == 0){
        *S.top_one++ = e;//1号入栈
    }else{
        *S.top_two-- = e;//2号入栈
    }
    return OK;
}//Push

SElemType Pop(SqStack &S, int i){
    //出栈操作，i = 0 出1号栈，i = 1 出2号栈
    if(i == 0){
        if(S.top_one == S.base_one){
            return ERROR;
        }
        S.top_one--;
        e = *S.top_one;
    }else{
        if(S.top_two == S.base_two){
            return ERROR;
        }
        S.top_two++;
        e = *S.top_two;
    }
    return e;
}//Pop
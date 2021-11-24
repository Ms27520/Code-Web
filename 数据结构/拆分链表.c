void decompose(Linklist La, Linklist &Lb, Linklist &Lc){
    Linknode *p;
    Lc = (Linknode *)malloc(sizeof(Linknode));
    Lc->next = NULL;
    p = La->next;
    Lb = La;
    Lb->next = NULL;
    while(p){
        La = p->next;
        if(p->data > 0){
            p->next = Lc->next;
            Lc->next = p;
        }else{
            p->next = Lb->next;
            Lb->next = p;
        }
        p = La;
    }
 }
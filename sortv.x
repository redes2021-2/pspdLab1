struct numbers{
    int a[2000];
};

struct funcreturn{
    int a;
    int b;
};

program SORTV_PROG{
    version SORTV_VERS{
        funcreturn sort(numbers* a)=1; 
    }=1;
}=0x23451111;

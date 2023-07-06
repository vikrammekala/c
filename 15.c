//find structure base adress using structure member adress 
#include<stdio.h>
#define container(ptr,type,member) ((type*)((char*)ptr-(char*)&(((type*)0)->member)))
struct some_data{
    int d;
    float c;
    char z;
    int y;

};
struct some_data data;
void init(void)
{
    data.d=123;
    data.c=12.5;
    data.z='x';
    data.y=12345;

}
void get_cont(char *ptr)
{
#if 0
    int get;
    struct some_data tmp;
    // get=(int)(((char*)&tmp.z)-(char*)&tmp.d);
    get=(&(((struct some_data*)0)->z));
    printf("size=%d\n",sizeof(struct some_data));
    struct some_data a[2]={0};
    a[0]=&data;
    struct some_data*p1=NULL;
    struct some_data*p2=NULL;
    p1=&a[0];
    p2=&a[1];
    int g=(char*)p2-(char*)p1;
    printf("xxx=%d\n",g);
printf("data=%x\n",&data);
    printf("%x\n",ptr);
    struct some_data*v=NULL;//find sizeof structure without using sizeoff 
    ++v;

    printf("l=%d\n",v);
    // struct some_data*x=&tmp;
    // ++x;
    // printf("xx=%x\n",x);
    // x=x-(&data);
    // printf("x=%x\n",x);
   
    struct some_data*data1=(struct some_data*)(ptr-get);
    printf("ad=%x\n",data1);
    printf("d=%d",data1->d);
    printf("c=%f\n",data1->c);
    printf("c=%c\n",data1->z);
    printf("y=%d\n",data1->y);
    #endif

    

   
}
int  main()
{
    init();
   // printf("c=%x\n",(&(((struct some_data*)0)->c)));
    struct some_data*data1=container(&data.c,struct some_data,c);
 printf("ad=%x\n",data1);
 printf("mem=%x\n",&(data.c));
    printf("d=%d",data1->d);
    printf("c=%f\n",data1->c);
    printf("c=%c\n",data1->z);
    printf("y=%d\n",data1->y);
}

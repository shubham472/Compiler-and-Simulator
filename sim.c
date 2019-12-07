#include<stdio.h>
#include<stdlib.h>
#define MAX 50
int stack[MAX],top=-1;
void push();
int pop();
void display();

void main()
{
   int p,q,A[1000],B[1000],i=0;
   char fr[10],fw[10];
   FILE *fp;
   printf("Give filename for Input: ");
   scanf("%s",fr);
   fp=fopen(fr,"r");
   while(1){
     fscanf(fp,"%d",&p);
     if(p!=99){ B[i]=p;i++;}
     else break;
  }
  // printf("Give filename for Output: ");
   //scanf("%s",fw);
   //fp=fopen(fw,"w");
   A[23]=B[i-1];A[25]=1;
   while(1)
   {
       i=A[23];
       if(B[i]==30){ A[23]=A[23]+3; A[B[i+1]]=B[i+2];//unconditional mov immediate 
       }
       else if(B[i]==33){ A[23]=A[23]+3; A[B[i+1]]=A[B[i+2]];  }
       else if(B[i]==26){ A[23]=A[23]+4; A[B[i+1]]=A[B[i+2]]+A[B[i+3]];} 
       else if(B[i]==27)
       {
           A[23]=A[23]+4;
           A[B[i+1]]=A[B[i+2]]-A[B[i+3]]; 
           if(A[B[i+1]]<0){ A[25]=0;}
           else{ A[25]=1; }
       }
       else if(B[i]==28){ A[23]=A[23]+4; A[B[i+1]]=A[B[i+2]]*A[B[i+3]];}
       else if(B[i]==29){ A[23]=A[23]+4; if(B[i+3]!=0)A[B[i+1]]=A[B[i+2]]/A[B[i+3]];}
       else if(B[i]==31){ A[23]=A[23]+2; printf("%d\n",A[B[i+1]]); sleep(2);fflush(fp);}
       else if(B[i]==32){ A[23]=A[23]+2; printf("Give Input: "); scanf("%d",&A[B[i+1]]);}
       else if(B[i]==42){ A[23]=A[23]+2;  push(A[B[i+1]]); }
       else if(B[i]==43){ A[23]=A[23]+2; A[B[i+1]]=pop(); }
       else if(B[i]==44){ A[23]++; display(); }
       else if(B[i]==40){ A[23]++; break; }
       else if(B[i]==47){ A[23]++; push(A[1]); push(A[2]);push(A[3]);push(A[4]); }
       else if(B[i]==48){ A[23]++; A[4]=pop(); A[3]=pop(); A[2]=pop(); A[1]=pop(); }
       
  }
}
void push(int val)
{
   if(top==MAX-1){ printf("\nStack is full\n"); }
   else{ top=top+1; stack[top]=val;}
}
int pop()
{
  int val=stack[top];
  top=top-1;
  return val;
}
void display()
{
  int i;
  for(i=0;i<top;i++){ printf("\n%d ",stack[i]);}
}
      
   
   
   
   
   
   
   
  

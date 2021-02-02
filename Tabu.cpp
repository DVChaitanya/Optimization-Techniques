#include <iostream>
#include <list>
#include <iterator>
#include <climits>
using namespace std;
class tabu {
    int x;
    int x1=0,x2=0,x3=0,x4=0,x5=0;
    int currentbestsol;
    int test_res;
    int arr[5];
    int current_res;
    int a,b,c,d,e,a1,b1,c1,d1,e1,a2,b2,c2,d2,e2,a3,b3,c3,d3,e3,a4,b4,c4,d4,e4,a5,b5,c5,d5,e5;
    std::list <int> TS;
    list <int>::iterator it=TS.begin();
    public:
        void x_value(){
            x=a*16+b*8+c*4+d*2+e*1;
        }
        void x1_value(){
            x1=a1*16+b1*8+c1*4+d1*2+e1*1;
        }
        void x2_value(){
            x2=a2*16+b2*8+c2*4+d2*2+e2*1;
        }
        void x3_value(){
            x3=a3*16+b3*8+c3*4+d3*2+e3*1;
        }
        void x4_value(){
            x4=a4*16+b4*8+c4*4+d4*2+e4*1;
        }
        void x5_value(){
            x5=a5*16+b5*8+c5*4+d5*2+e5*1;
        }
        tabu (){
        
            cout<<"Enter the bits for initial value of x"<<endl;
            cin>>a>>b>>c>>d>>e;
            x_value();
            cout<<"The value of x is "<<x<<endl;
        }
        int fun_value(int x){
            return (x*x*x-60*x*x+900*x+100);
        }
        void change(int i)
        {
            if(i==1)
            {
                if(a==1)
                    a=0;
                else
                {
                    a=1;
                }  
            }
            if(i==2)
            {
                if(b==1)
                    b=0;
                else
                {
                    b=1;
                }  
            }
            if(i==3)
            {
                if(c==1){
                    c=0;}
                else
                {
                    c=1;
                }
            }
            if(i==4)
            {
                if(d==1)
                    d=0;
                else
                {
                    d=1;
                }  
            }
            if(i==5)
            {
                if(e==1)
                    e=0;
                else
                {
                    e=1;
                }  
            }

        }
        void renew(){
            it=TS.begin();
            it++;
            while (it!=TS.end()){
                if(*it>=100){
                    TS.erase(--it);
                    TS.erase(it);
                }
                else{
                   if(it!=--Ts.end())
                   	it++;
                   std::advance(it,2);
                }
            }
        }
        int tabu_check(){
            it=TS.begin();
            int count=0;
            int k=0;
            while(it !=--TS.end()){
                if(x1==*it){
                    x1=x;
                    count++;
                    arr[0]=INT_MIN;
                }
                if(x2==*it){
                    x2=x;
                    count++;
                    arr[1]=INT_MIN;
                }
                if(x3==*it){
                    x3=x;
                    count++;
                    arr[2]=INT_MIN;
                }
                if(x4==*it){
                    x4=x;
                    count++;
                    arr[3]=INT_MIN;
                }
                if(x5==*it){
                    x5=x;
                    count++;
                    arr[4]=INT_MIN;
                }
                it++;
                *it=*it+1;
                it++;
            }
            return count;
        }
        void Ts(){
                cout<<"Let the Tabu Search Begin:"<<endl;
                cout<<"Tabu Tenure is 100 "<<endl;
                int l,k;
                l=0;
                k=0;
                TS.push_back(x);
                TS.push_back(1);
                while(k<=500000){
                    a1=a2=a3=a4=a5=a;
                    b1=b2=b3=b4=b5=b;
                    c1=c2=c3=c4=c5=c;
                    d1=d2=d3=d4=d4=d;
                    e1=e2=e3=e4=e5=e;
                    k++;l=0;
                    change(1);
                    a1=a;b1=b;c1=c;d1=d;e1=e;
                    change(1);
                    change(2);
                    a2=a;b2=b;c2=c;d2=d;e2=e;
                    change(2);
                    change(3);
                    a3=a;b3=b,c3=c;d3=d;e3=e;
                    change(3);
                    change(4);
                    a4=a;b4=b,c4=c,d4=d;e4=e;
                    change(4);
                    change(5);
                    a5=a;b5=b;c5=c;d5=d;e5=e;
                    change(5);
                    x_value();
                    x1_value();
                    x2_value();
                    x3_value();
                    x4_value();
                    x5_value();
                    currentbestsol=x;
                    test_res=INT_MIN;
                    current_res=fun_value(x);
                    arr[0]=fun_value(x1);
                    arr[1]=fun_value(x2);
                    arr[2]=fun_value(x3);
                    arr[3]=fun_value(x4);
                    arr[4]=fun_value(x5);
                    l=tabu_check();
                    if(l==5){
                        change(k%2 + k%3 + 1);
                        if(fun_value(x)>fun_value(x1))
                            currentbestsol=x;
                    }
                    else
                    {
                        int flag;
                        for(int i=0;i<5;i++){
                            if(arr[i]>test_res){
                                test_res=arr[i];
                                flag=i;
                            }
                        }
                        if(flag==0){
                            if(fun_value(x)<=fun_value(x1))
                                currentbestsol=x1;
                            x=x1;
                        }
                        if(flag==1){
                            if(fun_value(x)<=fun_value(x2))
                                currentbestsol=x2;
                            x=x2;
                        }
                        if(flag==2){
                            if(fun_value(x)<=fun_value(x3))
                                currentbestsol=x3;
                            x=x3;
                        }
                        if(flag==3){
                            if(fun_value(x)<=fun_value(x4))
                                currentbestsol=x4;
                            x=x4;
                        }
                        if(flag==4){
                            if(fun_value(x)<=fun_value(x5))
                                currentbestsol=x5;
                            x=x5;
                        }
                    }
                    TS.push_back(x);
                    TS.push_back(1);
                    }
                    renew();
                }


        }
    
        
};
int main()
{
    tabu X;
    X.tabu1();
    X.Ts();
    return 0;
}

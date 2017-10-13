/*----------------------------------------------------------------
Copyright (c) 2017 Author: Jagadeesh Vasudevamurthy
file: ulongnum.cpp

-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has class definition
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "ulongnum.h"
/*----------------------------------------------------------------

Definition of routines of ulongnum class

WRITE ALL CODE HERE
-----------------------------------------------------------------*/

ulongnum::ulongnum(const int a,const bool verbose){
    char* c = num2string(a);
    _num=str(c,verbose);
}

ulongnum::ulongnum(const char* c,const bool verbose){
    _num=str(c,verbose);
}

ulongnum::ulongnum(const char c,const bool verbose){
    _num=str(c,verbose);
}

ulongnum::ulongnum(const str& s){
    _num=s;
}
/*----------------------------------------------------------------
 Helper: copy function
 -----------------------------------------------------------------*/
void ulongnum::_copy(const ulongnum & n){
    _num = n._num;
}
/*----------------------------------------------------------------
 Copy constructor
 -----------------------------------------------------------------*/
ulongnum::ulongnum(const ulongnum& n){
    _copy(n);
}

/*----------------------------------------------------------------
 Counting how many digits in a num
 -----------------------------------------------------------------*/
int ulongnum::numDigits(const int s)
{
    int count=0;
    int s1=(s>0)?s:s*(-1);
    while (s1!=0){
        s1=s1/10;
        count++;
    }
    return count;
}

/*----------------------------------------------------------------
 num to string
 -----------------------------------------------------------------*/

char* ulongnum::num2string(const int n){
    int r=n;
    char*ch = new char[20];
    int count =numDigits(r);
    for (int i=0;i<count;++i){
        ch[i]=(char)(r/pow(10,count-1-i)+48);
        r=r-(int)(r/pow(10,count-1-i))*pow(10,count-1-i);
    }
    ch[count]='\0';
    return ch;
}

/*----------------------------------------------------------------
 equal operator
 -----------------------------------------------------------------*/
ulongnum& ulongnum::operator=(const ulongnum& rhs){
    if(this!=&rhs){
        _copy(rhs);
    }
    return *this;
}

/*----------------------------------------------------------------
 cout operator
 -----------------------------------------------------------------*/
ostream& operator<<(ostream& o, const ulongnum& n){
    o<<n._num;
    return o;
}
/*----------------------------------------------------------------
 + operator overloading
 -----------------------------------------------------------------*/
ulongnum operator+(const ulongnum& n1,const ulongnum& n2){
    /*
    int len1 = n1.len()-1;
    int len2 = n2.len()-1;
    int c=0;
    char* s;
    int len3=0;
    for (;len1>=0 ||len2>=0;len1--,len2--,len3++){
        if(len1>=0 && len2>=0){
            s[len3] = ((n1.gt(len1)-'0')+(n2.gt(len2)-'0')+c)%10 + '0';
            c=((n1.gt(len1)-'0')+(n2.gt(len2)-'0')+c)/10;
        }
        else if(len1<0){
            s[len3] = (n2.gt(len2)-'0' + c)%10 +'0';
            c = (n2.gt(len2)-'0' + c)/10;
        } else {
            s[len3] = (n1.gt(len1)-'0' + c)%10 +'0';
            c = (n1.gt(len1)-'0' + c)/10;
        }
    }
    if(c) s[len3]='1';
    str s1(s,false);
    s1.reverse();
    ulongnum n3(s1);
     */
    ulongnum n3=n1;
    return n3;
}

ulongnum operator+(const ulongnum& n1,const int& n2){
//    char *s = n1.num2string(n2);
    ulongnum n3(n1);
    //sdf
    return n3;
}



int ulongnum::len(){
    return _num.len();
}
char ulongnum::gt(const int index){
    return _num.gt(index);
}

//EOF



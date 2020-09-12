#include <iostream>

/*
小英是药学专业大三的学生，暑假期间获得了去医院药房实习的机会。在药房实习期间，小英扎实的专业基础获得了医生的一致好评，得知小英在计算概论中取得过好成绩后，主任又额外交给她一项任务，解密抗战时期被加密过的一些伤员的名单。 经过研究，小英发现了如下加密规律（括号中是一个“原文 -> 密文”的例子）
1.  原文中所有的字符都在字母表中被循环左移了三个位置（dec  -> abz）
2.  逆序存储（abcd -> dcba ）
3.  大小写反转（abXY -> ABxy）
输入：
一个加密的字符串。（长度小于50且只包含大小写字母）
输出：
输出解密后的字符串。

样例输入：
GSOOWFASOq
样例输出：
Trvdizrrvj
关键任务：完成代码的编写，通过样例数据检测实现出的算法的正确性，自己设计三组其它输入样例并将实验结果写入到实验报告中。
*/
using namespace std;

string Decryption(const string& s)     //解密
{
    //首先转换大小写
    int i = 0;
    int j = s.size();
    string temp = s;
    //cout<<s;
    char* array = new char[j];
    for(i=0;i<j;i++)
    {
        array[i] = temp[i];
       // cout<<array[i];
    }
    for(i=0;i<j;i++)
    {
        if(array[i]>='A' && array[i]<='Z')
        {
            array[i] = array[i] + ('a'-'A');

        }
        else if(array[i]>='a' && array[i]<='z')
        {
            array[i] = array[i]-('z'-'Z');
        }
        //cout<<array[i];
    }
    //array数组就是大小写翻转了的
    //逆序操作
    char tempchar;
    int m=0,n=j-1;
    while(m<n)
    {
        tempchar = array[m];
        array[m] = array[n];
        array[n] = tempchar;
        m++;
        n--;
    }
    //解密  首先生成大小写两个数组
    char allchar[26] = {'A'};
    for(int z = 1; z < 26 ;z++)
    {
        allchar[z] = 'A' + z;       //大写数组
    }
    char allchar_2[26] = {'a'};
    for(int z = 1; z < 26 ;z++)
    {
        allchar_2[z] = 'a' + z;     //小写数组
    }
    for(i = 0; i<j;i++)
    {
        if(array[i]>='A' && array[i]<='Z')      //如果是大写
        {
            int number = array[i] - 'A';
            number =(number + 3) %26;
            array[i] = allchar[number];
        }
        else if(array[i]>='a' && array[i]<='z')     //如果是小写
        {
            int number2 = array[i] - 'a';
            number2 = (number2 + 3) %26;
            array[i] = allchar_2[number2];
        }
    }
    for(i=0;i<j;i++)
    {
        temp[i] = array[i];

    }
    return temp;
}





int main()
{
  //  cout << "Hello world!" << endl;
    string s;
    cout<<"输入字符串"<<endl;
    cin>>s;
    cout<<"结果："<<Decryption(s)<<endl;


    return 0;

}

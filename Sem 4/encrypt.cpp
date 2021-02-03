#include<iostream>
#include<fstream>

using namespace std;

int main()
{
    char ch;
    int key = 5;
    fstream enc1;
    enc1.open("filea.txt", ios::out);
    enc1<<"Message to be encrypted";
    enc1.close();

    fstream enc2,dec1;
    enc2.open("filea.txt", ios::in);
    dec1.open("fileb.txt", ios::out);

    while(!enc2.eof())
    {
        enc2.get(ch);
        if(ch >= 'a' && ch <= 'z')
        {
            ch += key;
            if(ch > 'z')
                ch -= 26;
        }

        if(ch >= 'A' && ch <= 'Z')
        {
            ch += key;
            if(ch > 'Z')
                ch -= 26;
        }
        dec1<<ch;
    }

    enc2.close();
    dec1.close();

    fstream dec2;
    dec2.open("fileb.txt", ios::in);
    while(!dec2.eof())
    {
        dec2.get(ch);
        cout<<ch;
    }
    dec2.close();

    return 0;
}
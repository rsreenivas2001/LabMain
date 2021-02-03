#include<iostream>
#include<fstream>

using namespace std;

int main()
{
    char ch;
    int key = 5;
    fstream enc1,dec1;

    enc1.open("filec.txt", ios::out);
    dec1.open("fileb.txt", ios::in);

    while(!dec1.eof())
    {
        dec1.get(ch);
        if(ch >= 'a' && ch <= 'z')
        {
            ch -= key;
            if(ch < 'a')
                ch += 26;
        }

        if(ch >= 'A' && ch <='Z')
        {
            ch -= key;
            if(ch < 'A')
                ch += 26;
        }
        enc1<<ch;
    }

    enc1.close();
    dec1.close();

    fstream enc2;
    enc2.open("filec.txt", ios::in);
    while(!enc2.eof())
    {
        enc2.get(ch);
        cout<<ch;
    }
    enc2.close();

    return 0;
}
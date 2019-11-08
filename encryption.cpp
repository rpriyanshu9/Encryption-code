#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int i,m,j;
    cout<<"Enter the message to encrypt."<<endl<<endl;      //input prompt
    char message[50];
    cin.getline(message,50);        //getting string from user
    int x=strlen(message);      // length of string
    for(i=0;i<x;i++)            // loop to remove white spaces
    {
        if(message[i]==' ')
        {
            for(j=i;j<x;j++)
            message[j]=message[j+1];
            x--;
        }
    }
    for(i=0;i<x;i++)      // loop for converting upper case to lower case
    {
        if(message[i]>'z'||message[i]<'a')
            message[i]+=32;
    }
    cout<<endl<<"Enter the no. of digits."<<endl; cin>>m;       // getting no. of digits from user
    char arr0[m],arr1[m],arr2[m],arr3[m];
    cout<<endl<<"Enter the four numbers."<<endl;        // getting four numbers from the user
    cin>>arr0;
    cin>>arr1;
    cin>>arr2;
    cin>>arr3;
    char pin[m];
    for(i=0;i<m;i++)        // loop for determining the PIN
    {
        int min=arr0[i];
        if(min>arr1[i])
            min=arr1[i];
        if (min>arr2[i])
            min=arr2[i];
        if (min>arr3[i])
            min=arr3[i];
        pin[i]=min;
    }
    cout<<endl<<"Pin is : ";        // displaying pin
    for(i=0;i<m;i++)
    cout<<pin[i];
    for(i=0;i<m;i++)        // loop for shifting characters according to the pin
    {
        for(j=i;message[j]!='\0';j+=m)
        {
            int y=(int)message[j]+(pin[i]-48);
            if(y>122)
            {
                int extra=y-123;
                 message[j]='a'+extra;
            }
            else
            message[j]+=(pin[i]-48);
        }
    }
    for(i=0;i<x;i++)        // loop for converting lower case to upper case
    {
            message[i]-=32;
    }
    cout<<endl<<endl<<"The encrypted message is "<<message<<endl;       // displaying encrypted message
    return 0;
}

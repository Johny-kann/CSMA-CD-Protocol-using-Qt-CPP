#include <QDebug>
#include <string>
#include <iostream>
#include "logics.h"

namespace testJohny
{

template <typename T>
bool messageToBuffer(T var, unsigned char* buf)
{
    int byte_length = sizeof(var)/8;
  //  qDebug()<<byte_length;

    std::string str = (std::string)var;

    for(int i=0;i<byte_length;i++)
    {
        buf[i]= ((str.at(i)) &0xFF);
    }

    return true;
}

std::string bufferToMessage(const unsigned char* buf, int length)
{
    std::string str;
    for(int i=0;i<length;i++)
    {
        str+=((char)buf[i]);
    }

    return str;
}

template <typename T>
int lengthFinder(T var)
{
    return sizeof(var)/8;
}



void test_run()
{

    Buffer buffer;
    //buffer.

    logics::convertMessageToBuffer("kell",buffer);


    Byte *b = buffer.getBuffer();


 //   {'h','e','l'};

    Byte tb;
 //   qDebug()<<sizeof(tb);
 //   qDebug()<<sizeof(b);

    Bit *bits = logics::convertByteToBits(b,buffer.getBuf_length());

   //  qDebug()<<sizeof(b);
    for(int i=0;i<buffer.getBuf_length()*8;i++)
    {
        if(bits[i])
            std::cout<<1;
        else
            std::cout<<0;
       // qDebug()<<bits[i];
    }

    Byte *cBytes = logics::convertBitsToBytes(bits,sizeof(b)*8);

    qDebug()<<"Buffer Length"<<buffer.getBuf_length();

    for(int i=0;i<(buffer.getBuf_length());i++)
    {
        qDebug()<<i<<(char)cBytes[i];
    }

}


}

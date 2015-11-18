#include <string>

#ifndef MODELS_H
#define MODELS_H

#include <QApplication>
//enum bitValue {Postive, Negative};

typedef std::string Message;

class ChannelMedium : public QObject
{
    Q_OBJECT
public:
    ChannelMedium();
    ~ChannelMedium();

    void setBit(int value);

public slots:
    void timeOut();
    void unsetBit();

signals:
    void done();

private:
    short bitValue;


};



#endif // MODELS_H

#ifndef SMALLOBJECTS_H
#define SMALLOBJECTS_H

class Buffer
{
public:
    Buffer();
    Buffer(int length);
    ~Buffer();

    int getBuf_length() const;
    void setBuf_length(int value);

    unsigned char *getBuffer() const;
    unsigned char *getBuffer();
    void setBuffer(unsigned char *value);
    void setBuffer(const Message message);

    int getStart_pos() const;
    void setStart_pos(int value);

    int getEnd_pos() const;
    void setEnd_pos(int value);

    bool initBufferLength(int length);

private:
    int buf_length, start_pos, end_pos;
    unsigned char *buffer;


};

#endif
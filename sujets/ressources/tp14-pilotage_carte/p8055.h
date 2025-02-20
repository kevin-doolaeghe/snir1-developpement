﻿#ifndef P8055_H
#define P8055_H

#include <QLibrary>
#include <QCoreApplication>
#include <QtCore>
#include <QMessageBox>

typedef long (*OpenDevice)(long CardAddress);
typedef void (*CloseDevice)(void);
typedef void (*SetDigitalChannel)(long Channel);
typedef void (*ClearDigitalChannel)(long Channel);
typedef void (*WriteAllDigital)(long Data);
typedef long (*ReadAllDigital)(void);
typedef long (*ReadDigitalChannel)(long Channel);
typedef void (*SetAnalogChannel)(long Channel);
typedef void (*ClearAnalogChannel)(long Channel);
typedef void (*OutputAnalogChannel)(long Channel, long Data);

class P8055
{
private:
    OpenDevice opendevice;
    CloseDevice closedevice;
    SetDigitalChannel setdigitalchannel;
    ClearDigitalChannel cleardigitalchannel;
    WriteAllDigital writealldigital;
    ReadAllDigital readalldigital;
    ReadDigitalChannel readdigitalchannel;
    SetAnalogChannel setanalogchannel;
    ClearAnalogChannel clearanalogchannel;
    OutputAnalogChannel outputanalogchannel;

    QLibrary lib;

public:
    P8055(int addcarte);
    ~P8055();

};

#endif // P8055_H

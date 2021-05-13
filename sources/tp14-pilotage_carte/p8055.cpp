#include "p8055.h"


//---------------------------------------------------------------------------

P8055::P8055(int addcarte)
{
    QLibrary lib( QDir(QCoreApplication::applicationDirPath()).filePath("K8055D.dll"));
    if(lib.load())
    {
        opendevice = (OpenDevice)lib.resolve("OpenDevice");
        closedevice = (CloseDevice)lib.resolve("CloseDevice");
        setdigitalchannel = (SetDigitalChannel)lib.resolve("SetDigitalChannel");
        cleardigitalchannel = (ClearDigitalChannel)lib.resolve("ClearDigitalChannel");
        writealldigital = (WriteAllDigital)lib.resolve("WriteAllDigital");
        readalldigital = (ReadAllDigital)lib.resolve("ReadAllDigital");
        readdigitalchannel = (ReadDigitalChannel)lib.resolve("ReadDigitalChannel");
        setanalogchannel = (SetAnalogChannel)lib.resolve("SetAnalogChannel");
        clearanalogchannel = (ClearAnalogChannel)lib.resolve("ClearAnalogChannel");
        outputanalogchannel = (OutputAnalogChannel)lib.resolve("OutputAnalogChannel");

        QMessageBox::information(NULL, "Chargement", "Chargement dll réussi");

        ncarte = opendevice(addcarte);
    }
    else
    {
        QMessageBox::information(NULL, "Chargement", "Chargement dll impossible");
    }
}

P8055::~P8055()
{

}

char P8055::P8055_present()
{

}

void P8055::setBit(unsigned char val)
{

}

void P8055::clearBit(unsigned char val)
{

}

void P8055::valOutput(unsigned char val)
{

}

unsigned char P8055::getOutput()
{

}

unsigned char P8055::getInput()
{

}

bool P8055::getBitInput(unsigned char val)
{

}

//----------------------------------------------------------------------------


#include "p8055.h"



//---------------------------------------------------------------------------
P8055::P8055(int addcarte)
{
    QLibrary lib( QDir(QCoreApplication::applicationDirPath()).filePath("K8055D.dll"));
    if (lib.load())
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
//----------------------------------------------------------------------------


#ifndef BF_COMMANDLINEPROGRAM
#define BF_COMMANDLINEPROGRAM

#define BF_COMMANDLINEPROGRAMVERSION "1.0.0"

#include <QObject>
#include <QDebug>
#include <QDir>
#include "BeaconExternalProgram.hpp"
#include "BeaconPlatformInfo.hpp"

class BeaconCommandlineProgram : public BeaconExternalProgram
{
    Q_OBJECT
public:
    explicit BeaconCommandlineProgram(QString platform=QString("auto"))
    {
        if(platform=="auto"){
        if(BeaconPlatformInfo::isWindows())platform=QString("windows");
        else if(BeaconPlatformInfo::isMacos())platform=QString("macos");
        else if(BeaconPlatformInfo::isLinux())platform=QString("linux");
        }
        if(platform=="windows"){
            //qDebug() << "Current Directory:" << QDir::
            if(QFile::exists("./ConEmu/ConEmu64.exe")){
                bashBased=true;
                setProgram("./ConEmu/ConEmu64.exe");
                prefixArgument << "-run";
            }
            setProgram("cmd");
            prefixArgument << "/k";
        }
        else if(platform=="macos"){
            setProgram("open");
        }
        else if(platform=="linux"){
            //yakuake&guake not supported
            //liri not supported
            if(QFile::exists("/usr/bin/konsole")){
                bashBased=true;
                setProgram("konsole");
                prefixArgument << "--noclose" << "-e" ;
                prefixArgument << "bash" << "-c";
            }
            else if(QFile::exists("/usr/bin/gnome-terminal")){
                bashBased=true;
                manualHalt=true;
                prefixArgument << "--" << "bash" << "-c";
                setProgram("gnome-terminal");
            }
            else if(QFile::exists("/usr/bin/mate-terminal")){
                bashBased=true;
                manualHalt=true;
                prefixArgument << "--" << "bash" << "-c";
                setProgram("mate-terminal");
            }
            else if(QFile::exists("/usr/bin/deepin-terminal")){
                bashBased=true;
                manualHalt=true;
                prefixArgument << "-e" << "bash" << "-c";
                setProgram("deepin-terminal");
            }
            else if(QFile::exists("/usr/bin/xfce4-terminal")){
                bashBased=true;
                manualHalt=true;
                prefixArgument << "-x" << "bash" << "-c";
                setProgram("xfce4-terminal");
            }
            else if(QFile::exists("/usr/bin/lxterminal")){
                bashBased=true;
                manualHalt=true;
                prefixArgument << "-e" << "bash" << "-c";
                setProgram("lxterminal");
            }
            else if(QFile::exists("/usr/bin/uxterm")){
                bashBased=true;
                manualHalt=true;
                prefixArgument << "-e" << "bash" << "-c";
                setProgram("uxterm");
            }
            else if(QFile::exists("/usr/bin/xterm")){
                bashBased=true;
                manualHalt=true;
                prefixArgument << "-e" << "bash" << "-c";
                setProgram("xterm");
            }
            //else
        }
    }
    void setArguments(QStringList arg)
    {
        QString t=arg.first();
        QStringList pathL=t.split("/");
        pathL.removeLast();
        QString path=pathL.join("/");
        this->program.setWorkingDirectory(path);
    
        QStringList arguments=prefixArgument;
        if(bashBased){
            QString mid;
            if(manualHalt)mid = QString("""%1;echo \"\n------Program Exited------\";sleep 2147483647""").arg(arg.first());
            else mid = QString("""%1;echo \"\n------Program Exited------\"").arg(arg.first());
            arguments.append(mid);
        }
        else arguments.append(arg);
        //arguments.append(suffixArgument);
        this->program.setArguments(arguments);
        }
    QStringList prefixArgument;
    QStringList suffixArgument;
    bool bashBased=false;
    bool manualHalt=false;
};

#endif // BF_COMMANDLINEPROGRAM

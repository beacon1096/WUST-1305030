#ifndef BF_FILEIO
#define BF_FILEIO

#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QDataStream>
#include <QUrl>
#include <QDebug>

class BeaconFileIO : public QObject
{
    Q_OBJECT
public:
    explicit BeaconFileIO(QObject *parent = nullptr){}
    static bool openFile(QFile& file,QString name,QChar IOMode){
        bool res=false;
        file.setFileName(name);
        if(IOMode=='r'){
            res=file.open(QIODevice::ReadOnly | QIODevice::Text);
        }
        if(IOMode=='w'){
            res=file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text);
        }
        return res;
    }
    static void bundleIO(QFile& file,QTextStream& str){
        str.setDevice(&file);
    }
    const static QString readTextFileContent(QString fileName){
        qDebug() << "BeaconFileIO::readFileContent:"<< fileName;
        QFile file(fileName);
        if(!openFile(file,fileName,'r'))return QStringLiteral("*/*Beaco File General Error*/*");
        QTextStream inputStream(&file);
        QString res;
        while(!inputStream.atEnd()){
            res.append(inputStream.readAll());
        }
        return res;
    }
    static QString readTextFileContent(QUrl target){
        return readTextFileContent(target.toLocalFile());
    }
    const static QByteArray readRawFileContent(QString fileName){
        qDebug() << "BeaconFileIO::readFileContent:"<< fileName;
        QFile file(fileName);
        if(!openFile(file,fileName,'r'))return QStringLiteral("*/*Beaco File General Error*/*").toUtf8();
        QByteArray res;
        res = file.readAll();
        return res;
    }
    static QString readRawFileContent(QUrl target){
        QString fileName = target.toLocalFile();
        return readRawFileContent(fileName);
    }
    static bool saveTextFileContent(QString fileName,QString content){
        QFile file(fileName);
        if(!openFile(file,fileName,'w'))return false;
        QTextStream outputStram(&file);
        outputStram<<content;
        file.close();
        return true;
    }
    static bool saveTextFileContent(QUrl target,QString content){
        return saveTextFileContent(target.toLocalFile(),content);
    }
    static bool saveRawFileContent(QString fileName,QByteArray content){
        QFile file(fileName);
        if(!openFile(file,fileName,'w'))return false;
        file.write(content);
        file.close();
        return true;
    }
    static bool saveRawFileContent(QUrl target,QByteArray content){
        return saveRawFileContent(target.toLocalFile(),content);
    }
    static bool fileExist(QString fileName){
        QFile file(fileName);
        return file.exists();
    }
};

#endif // BF_FILEIO

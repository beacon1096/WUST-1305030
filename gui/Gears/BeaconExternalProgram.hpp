#ifndef BF_EXTERNALPROGRAM
#define BF_EXTERNALPROGRAM

#define BF_EXTERNALPROGRAMVERSION "1.1.0"

#include <QObject>
#include <QFile>
#include <QProcess>
#include <QDebug>

class BeaconExternalProgram : public QObject
{
    Q_OBJECT
public:
    explicit BeaconExternalProgram(QObject *parent = nullptr)
    {
        connect(&program,SIGNAL(readyReadStandardOutput()),this,SLOT(programOutputUpdatedTriggered()));
        connect(&program,SIGNAL(readyReadStandardError()),this,SLOT(programErrorUpdatedTriggered()));
        connect(&program,SIGNAL(finished(int,QProcess::ExitStatus)),this,SLOT(sendProgramExited(int,QProcess::ExitStatus)));
    }
    QProcess program;
    QFile programFile;
    QString programPath;
    QStringList arguments;
    QByteArray standardOut,errorOut,logOut;
    QByteArray standardOutDelta,errorOutDelta,logOutDelta;
    qint64 pid(){
        return program.processId();
    }
    void addEnvironment(const QString &name, const QString &key){
        QProcessEnvironment env = program.processEnvironment();
        env.insert(name, key);
        program.setProcessEnvironment(env);
    }
    void setEnvironment(const QProcessEnvironment &environment){
        program.setProcessEnvironment(environment);
    }
    bool setProgram(QString path,QStringList argu=QString("").split('.'))
    {
        programPath=path;
        arguments=argu;
        program.setProgram(programPath);
        program.setArguments(arguments);
        programFile.setFileName(path);
        if(!programFile.exists())return false;
        return true;
    }
    void setArguments(QStringList arg)
    {
        program.setArguments(arg);
    }
    bool startProgram()
    {
        program.start();
        if (!program.waitForStarted()){
            return false;
        }
        return true;
    }
    bool startProgramDetached()
    {
        program.startDetached();
        if (!program.waitForStarted()){
            return false;
        }
        return true;
    }
    void clearLog()
    {
        this->logOut.clear();
        this->logOutDelta.clear();
        this->errorOut.clear();
        this->errorOutDelta.clear();
        this->standardOut.clear();
        this->standardOutDelta.clear();
    }
signals:
    void programOutputUpdated(QString content);
    void programErrorUpdated(QString content);
    void programLogUpdated(QString content);
    void programExited(int result,QProcess::ExitStatus);
public slots:
    void sendProgramExited(int result,QProcess::ExitStatus status)
    {
        emit programExited(result,status);
    }
    void programOutputUpdatedTriggered()
    {
        QByteArray ba = program.readAllStandardOutput();
        standardOut.append(ba);
        logOut.append(ba);
        standardOutDelta=ba;
        logOutDelta=ba;
        qDebug() << "[BEP]update:" << QString(ba);
        emit programOutputUpdated(ba);
        emit programLogUpdated(ba);
    }
    void programErrorUpdatedTriggered()
    {
        QByteArray ba = program.readAllStandardError();
        errorOut.append(ba);
        logOut.append(ba);
        errorOutDelta=ba;
        logOutDelta=ba;
        emit programErrorUpdated(ba);
        emit programLogUpdated(ba);
    }
};

#endif // BF_EXTERNALPROGRAM

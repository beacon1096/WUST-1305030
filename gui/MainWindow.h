#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>
#include <QProcess>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

enum Cipher{
    Caeser,
    Polybius,
    Railfence
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void changeCipher();
    void encrypt();
    void decrypt();
    void readClearTextFromFile();
    void writeClearTextToFile();
    void readCipherTextFromFile();
    void writeCipherTextToFile();

    void selectInput();
    void selectOutput();
    void encryptFile();
    void decryptFile();
    void fileReadStdio();
    void fileReadFile();
    void fileReadSelect();
    void fileWriteStdio();
    void fileWriteFile();
    void fileWriteSelect();

private:

private:
    Ui::MainWindow *ui;
    QMap<Cipher,QString> suites;
    QMap<QString,Cipher> ciphers;
    Cipher _currentCipher;
    bool fileReadFromFile;
    bool fileWriteToFile;
    bool checkKey(const QString &key);
};
#endif // MAINWINDOW_H

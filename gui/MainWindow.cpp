#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include "Gears/BeaconFileIO.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    suites.insert(Cipher::Caeser,"./caeser.exe");
    suites.insert(Cipher::Polybius,"./polybius.exe");
    suites.insert(Cipher::Railfence,"./railfence.exe");
    ciphers.insert("caeserRadioButton",Cipher::Caeser);
    ciphers.insert("polybiusRadioButton",Cipher::Polybius);
    ciphers.insert("railfenceRadioButton",Cipher::Railfence);

    ui->caeserRadioButton->click();
    _currentCipher = Cipher::Caeser;

    fileReadFromFile = false;
    fileWriteToFile = false;
    ui->fileReadStdio->click();
    ui->fileWriteStdio->click();

    connect(ui->caeserRadioButton,SIGNAL(clicked()),this,SLOT(changeCipher()));
    connect(ui->polybiusRadioButton,SIGNAL(clicked()),this,SLOT(changeCipher()));
    connect(ui->railfenceRadioButton,SIGNAL(clicked()),this,SLOT(changeCipher()));
    connect(ui->directEncryptButton,SIGNAL(clicked()),this,SLOT(encrypt()));
    connect(ui->directDecryptButton,SIGNAL(clicked()),this,SLOT(decrypt()));
    connect(ui->directClearTextReadButton,SIGNAL(clicked()),this,SLOT(readClearTextFromFile()));
    connect(ui->directClearTextWriteButton,SIGNAL(clicked()),this,SLOT(writeClearTextToFile()));
    connect(ui->directCipherTextReadButton,SIGNAL(clicked()),this,SLOT(readCipherTextFromFile()));
    connect(ui->directCipherTextWriteButton,SIGNAL(clicked()),this,SLOT(writeCipherTextToFile()));

    connect(ui->fileReadFile,SIGNAL(clicked()),this,SLOT(fileReadFile()));
    connect(ui->fileReadStdio,SIGNAL(clicked()),this,SLOT(fileReadStdio()));
    connect(ui->fileWriteFile,SIGNAL(clicked()),this,SLOT(fileWriteFile()));
    connect(ui->fileWriteStdio,SIGNAL(clicked()),this,SLOT(fileWriteStdio()));
    connect(ui->fileEncryptButton,SIGNAL(clicked()),this,SLOT(encryptFile()));
    connect(ui->fileDecryptButton,SIGNAL(clicked()),this,SLOT(decryptFile()));
    connect(ui->fileReadButton,SIGNAL(clicked()),this,SLOT(fileReadSelect()));
    connect(ui->fileWriteButton,SIGNAL(clicked()),this,SLOT(fileWriteSelect()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeCipher(){
    _currentCipher = ciphers[sender()->objectName()];
}

void MainWindow::encrypt(){
    QProcess p;
    p.setProgram(suites[_currentCipher]);
    QStringList args;
    args << "e";
    if(_currentCipher != Cipher::Polybius){
        if(!checkKey(ui->directKey->text())){
            QMessageBox::warning(this,tr("Warning"),tr("Invalid key provided."));
            return;
        }
        args << ui->directKey->text();
    }
    args << ui->directClearText->toPlainText();
    p.setArguments(args);
    p.start();
    qDebug() << p.errorString();
    p.waitForFinished();
    QByteArray result = p.readAllStandardOutput();
    ui->directCipherText->setPlainText(result);
}
void MainWindow::decrypt(){
    QProcess p;
    p.setProgram(suites[_currentCipher]);
    QStringList args;
    args << "d";
    if(_currentCipher != Cipher::Polybius){
        if(!checkKey(ui->directKey->text())){
            QMessageBox::warning(this,tr("Warning"),tr("Invalid key provided."));
            return;
        }
        args << ui->directKey->text();
    }
    args << ui->directCipherText->toPlainText();
    p.setArguments(args);
    p.start();
    qDebug() << p.errorString();
    p.waitForFinished();
    QByteArray result = p.readAllStandardOutput();
    ui->directClearText->setPlainText(result);
}
void MainWindow::readClearTextFromFile(){
    ui->directClearText->setPlainText(BeaconFileIO::readTextFileContent(QFileDialog::getOpenFileUrl()));
}
void MainWindow::writeClearTextToFile(){
    BeaconFileIO::saveTextFileContent(QFileDialog::getSaveFileUrl(),ui->directClearText->toPlainText());
}
void MainWindow::readCipherTextFromFile(){
    ui->directCipherText->setPlainText(BeaconFileIO::readTextFileContent(QFileDialog::getOpenFileUrl()));
}
void MainWindow::writeCipherTextToFile(){
    BeaconFileIO::saveTextFileContent(QFileDialog::getSaveFileUrl(),ui->directCipherText->toPlainText());
}

bool MainWindow::checkKey(const QString &key){
    bool success=0;
    key.toInt(&success);
    return success;
}

void MainWindow::selectInput(){
    ui->fileReadPath->setText(QFileDialog::getOpenFileUrl().toString());
}
void MainWindow::selectOutput(){
    ui->fileReadPath->setText(QFileDialog::getSaveFileUrl().toString());
}
void MainWindow::encryptFile(){
    QProcess p;
    p.setProgram(suites[_currentCipher]);
    QStringList args;
    if(fileReadFromFile){
        args << "-i" << ui->fileReadPath->text();
    }
    if(fileWriteToFile){
        args << "-o" << ui->fileWritePath->text();
    }
    args << "e";
    if(_currentCipher != Cipher::Polybius){
        if(!checkKey(ui->fileKey->text())){
            QMessageBox::warning(this,tr("Warning"),tr("Invalid key provided."));
            return;
        }
        args << ui->fileKey->text();
    }
    if(!fileReadFromFile){
        args << ui->fileReadArea->toPlainText();
    }
    p.setArguments(args);
    qDebug() << args;
    p.start();
    qDebug() << p.errorString();
    p.waitForFinished();
    if(!fileWriteToFile){
        QByteArray result = p.readAllStandardOutput();
        ui->fileWriteArea->setPlainText(result);
    }
    else {
        ui->fileWriteArea->setPlainText("success");
    }

}
void MainWindow::decryptFile(){
    QProcess p;
    p.setProgram(suites[_currentCipher]);
    QStringList args;
    if(fileReadFromFile){
        args << "-i" << ui->fileReadPath->text();
    }
    if(fileWriteToFile){
        args << "-o" << ui->fileWritePath->text();
    }
    args << "d";
    if(_currentCipher != Cipher::Polybius){
        if(!checkKey(ui->fileKey->text())){
            QMessageBox::warning(this,tr("Warning"),tr("Invalid key provided."));
            return;
        }
        args << ui->fileKey->text();
    }
    if(!fileReadFromFile){
        args << ui->fileReadArea->toPlainText();
    }
    p.setArguments(args);
    p.start();
    qDebug() << p.errorString();
    p.waitForFinished();
    if(!fileWriteToFile){
        QByteArray result = p.readAllStandardOutput();
        ui->fileWriteArea->setPlainText(result);
    }
    else {
        ui->fileWriteArea->setPlainText("success");
    }
}
void MainWindow::fileReadStdio(){
    fileReadFromFile = false;
}
void MainWindow::fileReadFile(){
    fileReadFromFile = true;
    fileReadSelect();
}
void MainWindow::fileWriteStdio(){
    fileWriteToFile = false;
}
void MainWindow::fileWriteFile(){
    fileWriteToFile = true;
    fileWriteSelect();
}
void MainWindow::fileReadSelect(){
    ui->fileReadPath->setText(QFileDialog::getOpenFileUrl().toLocalFile());
}
void MainWindow::fileWriteSelect(){
    ui->fileWritePath->setText(QFileDialog::getSaveFileUrl().toLocalFile());
}

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QCloseEvent>
#include <QMessageBox>
#include <QTextStream>
#include <QFileInfo>
#include <QFileDialog>
#include <QFontDialog>

MainWindow::MainWindow(const QString &fileName,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // actions
    connect(ui->actionClose,SIGNAL(triggered()),this,SLOT(close()));
    connect(ui->actionExit,SIGNAL(triggered()),qApp,SLOT(closeAllWindows()));
    connect(ui->actionSave,SIGNAL(triggered()),this,SLOT(saveFile()));
    connect(ui->actionSaveAs,SIGNAL(triggered()),this,SLOT(saveFileAs()));
    connect(ui->actionAboutQt,SIGNAL(triggered()),qApp,SLOT(aboutQt()));
    connect(ui->actionCut,SIGNAL(triggered()),ui->textEdit,SLOT(cut()));
    connect(ui->actionCopy,SIGNAL(triggered()),ui->textEdit,SLOT(copy()));
    connect(ui->actionPaste,SIGNAL(triggered()),ui->textEdit,SLOT(paste()));
    connect(ui->actionUndo,SIGNAL(triggered()),ui->textEdit,SLOT(undo()));
    connect(ui->actionRedo,SIGNAL(triggered()),ui->textEdit,SLOT(redo()));

    // textedit triggers
    connect(ui->textEdit,SIGNAL(copyAvailable(bool)),ui->actionCut,SLOT(setEnabled(bool)));
    connect(ui->textEdit,SIGNAL(copyAvailable(bool)),ui->actionCopy,SLOT(setEnabled(bool)));
    connect(ui->textEdit,SIGNAL(undoAvailable(bool)),ui->actionUndo,SLOT(setEnabled(bool)));
    connect(ui->textEdit,SIGNAL(redoAvailable(bool)),ui->actionRedo,SLOT(setEnabled(bool)));

    // document modified trigger
    connect(ui->textEdit, SIGNAL(textChanged()), this,SLOT(documentModified()));

    loadFile(fileName);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *e)
{
    bool isModified = this->isWindowModified();
    QMessageBox::StandardButton selected;
    QString msgBoxTitle = "Document Modified";
    QString msgBoxBody = "The document has been modified, Do you want to save your changes?\nYou will lose all your changes.";
    QMessageBox::StandardButtons msgBoxButtons = QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel;

    if(isModified){
        selected = QMessageBox::warning(this, msgBoxTitle,msgBoxBody, msgBoxButtons, QMessageBox::Cancel);
        switch(selected)
        {
        case QMessageBox::Yes:
            saveFile();
        case QMessageBox::No:
            e->accept();
            break;
        case QMessageBox::Cancel:
        default:
            e->ignore();
        }
    }else{
        e->accept();
    }
}

void MainWindow::loadFile(const QString &fileName)
{

    if(fileName.isEmpty()){
        setFileName(QString());
        return;
    }

    try {
        QFile f(fileName);
        f.open(QFile::ReadOnly|QIODevice::Text);
        QTextStream stream(&f);
        ui->textEdit->setText(stream.readAll());
        f.close();
        this->setWindowModified(false);
        setFileName(fileName);
    }  catch (...) {
        QMessageBox::warning(this,"Failed to open the file","The file cannot be opened!",QMessageBox::Ok);
        setFileName(QString());
        return;
    }

}

void MainWindow::setFileName(const QString &fileName){
    m_fileName = fileName;
    this->setWindowTitle(QString("%1[*] - %2").arg(m_fileName.isNull()?"untitled":QFileInfo(m_fileName).fileName(), QApplication::applicationName()));
}

// --- SLOTS ---

void MainWindow::on_actionNew_triggered()
{
    MainWindow *w = new MainWindow();
    w->show();
}

void MainWindow::documentModified()
{
    this->setWindowModified(true);
    // by default he save action will be disabled,
    // if user modified the file actions will be enabled
    ui->actionSave->setEnabled(true);
    ui->actionSaveAs->setEnabled(true);
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open document", QDir::currentPath(), "Text documents (*.txt)");

    if(fileName.isNull()) return;

    if(m_fileName.isNull() || !this->isWindowModified()) {
        loadFile(fileName);
    }
    else {
        MainWindow *w = new MainWindow(fileName);
        w->show();
    }
}

bool MainWindow::saveFile()
{

    // if file isn't saved, get a file name from user and save it
    if(m_fileName.isNull()) return saveFileAs();


    try {
        QFile f(m_fileName);
        f.open(QFile::WriteOnly|QIODevice::Text);
        QTextStream stream(&f);
        stream << ui->textEdit->toPlainText();
        f.close();
        this->setWindowModified(false);
        return true;
    }  catch (...) {
        QMessageBox::warning(this,"Failed to create the file","There was an error creating or writing to the file!",QMessageBox::Ok);
        setFileName(QString());
        return false;
    }

}

bool MainWindow::saveFileAs()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save document", m_fileName.isNull()?QDir::currentPath():m_fileName, "Text documents (*.txt)");
    if(fileName.isNull()) return false;

    setFileName(fileName);
    return saveFile();
}

void MainWindow::on_actionSelectFont_triggered()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, ui->textEdit->font(), this);
    if(ok) ui->textEdit->setFont(font);
}


void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this,"Simple QT Text Editor", "A simple text editor created using Qt framework for C++\n\nThank you...\n - BMC 😉");
}


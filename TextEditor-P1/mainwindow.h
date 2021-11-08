#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

protected:
    void closeEvent(QCloseEvent *e);

public:
    MainWindow(const QString &fileName=QString(), QWidget *parent=0);
    ~MainWindow();

private slots:
    void loadFile(const QString &fileName);
    void setFileName(const QString &fileName);

    void on_actionNew_triggered();
    void documentModified();
    void on_actionOpen_triggered();
    bool saveFile();
    bool saveFileAs();

private:
    QString m_fileName;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

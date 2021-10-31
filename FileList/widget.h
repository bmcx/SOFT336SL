#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_add_clicked();

    void on_remove_clicked();

    void on_clear_clicked();

    void on_save_clicked();

    void on_load_clicked();

    void enable_remove_btn();

    void toggle_actions();


private:
    Ui::Widget *ui;
};
#endif // WIDGET_H

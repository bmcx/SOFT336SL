#include "widget.h"
#include "ui_widget.h"
#include "qfile.h"
#include "qtextstream.h"

QString fileName = "FileList.txt";

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->list,SIGNAL(itemSelectionChanged()),this,SLOT(enable_remove_btn()));
    connect(ui->clear,SIGNAL(clicked()),this,SLOT(toggle_actions()));
    connect(ui->add,SIGNAL(clicked()),this,SLOT(toggle_actions()));
    connect(ui->remove,SIGNAL(clicked()),this,SLOT(toggle_actions()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::enable_remove_btn(){
    ui->remove->setEnabled(true);
}

void Widget::toggle_actions(){

    ui->clear->setEnabled(ui->list->count()>0);
    ui->save->setEnabled(ui->list->count()>0);
    if(ui->list->count()==0)
        ui->remove->setEnabled(false);
}


void Widget::on_add_clicked()
{
    // get trimmed input, so there are no leading or trailing spaces
    QString input = ui->input->text().trimmed();
    // if the input isn't empty,
    if(input != ""){
        // add it to list
        ui->list->addItem(input);
        // clear the input box
        ui->input->clear();
    }
    // move focus back to input box
    ui->input->setFocus();
}


void Widget::on_remove_clicked()
{
    // remove the selected item(s) from list
    foreach (QListWidgetItem *item, ui->list->selectedItems())
       delete item;
}


void Widget::on_clear_clicked()
{
    // delete all items from the list
    ui->list->clear();
    // TODO: add a confirmation before removing all
}


void Widget::on_save_clicked()
{
    QFile f(fileName);
    f.open(QFile::WriteOnly);
    QTextStream stream(&f);
    for (int i=0; i<ui->list->count(); i++)
    {
        stream << "item: " << ui->list->item(i)->text() << "\n";
    }
    f.close();
}


void Widget::on_load_clicked()
{
    // clear the list before loading from file
    ui->list->clear();

    QFile f(fileName);
    f.open(QFile::ReadOnly);
    QTextStream stream(&f);
    int i=0;
    while (!stream.atEnd())
    {
        QString line = stream.readLine();
        // remove item prefix from line
        line.replace("item: ","");
        // add the line to list widget
        ui->list->addItem(line);
        i++;
    }
    f.close();
}


#ifndef MYFIGURE_H
#define MYFIGURE_H

#include <QWidget>

class MyFigure : public QWidget
{
    Q_OBJECT
public:
    explicit MyFigure(int value, QWidget *parent = nullptr);
    int value() const;
    int heightForWidth(int) const;
    QSize sizeHint() const;
    virtual void drawMyFigure() = 0;

public slots:
    void setValue(int);

signals:
    void valueChanged(int);

protected:
    void paintEvent(QPaintEvent *);

private:
    int m_value;

};

#endif // MYFIGURE_H

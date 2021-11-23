#ifndef MYCIRCLE_H
#define MYCIRCLE_H

#include <QWidget>

class MyCircle : public QWidget
{
    Q_OBJECT
public:
    explicit MyCircle(int value, QWidget *parent = nullptr);

    int value() const;
    int heightForWidth(int) const;
    QSize sizeHint() const;

public slots:
    void setValue(int);

signals:
    void valueChanged(int);

protected:
    void paintEvent(QPaintEvent *);

private:
    int m_value;
    void drawMyFigure();


};

#endif // MYCIRCLE_H

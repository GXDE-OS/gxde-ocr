#ifndef CONTROLWIDGET_H
#define CONTROLWIDGET_H

#include <DMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>

DWIDGET_USE_NAMESPACE

class ControlWidget : public DMainWindow
{
    Q_OBJECT
public:
    explicit ControlWidget(QWidget *parent = nullptr);

signals:

public slots:


private :
    QPushButton *m_openImageBtn = nullptr;
    QLabel *m_iconLabel = nullptr;
};

#endif // CONTROLWIDGET_H

#ifndef CONTROLWIDGET_H
#define CONTROLWIDGET_H

#include <dtk2/DWidget/DMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>

using namespace Dtk::Widget;

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

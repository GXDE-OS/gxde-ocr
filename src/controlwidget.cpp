#include "controlwidget.h"
#include <QFileDialog>
#include "ocrapplication.h"
#include <DTitlebar>

ControlWidget::ControlWidget(QWidget *parent) : DMainWindow(parent)
{
    // 设置标题
    titlebar()->setTitle(tr("GXDE OCR"));
    titlebar()->setIcon(QIcon(":/assets/gxde-ocr.svg"));

    QVBoxLayout *layout =new QVBoxLayout(this);

    m_iconLabel = new QLabel("<p align='center'><img width='256' src=':/assets/gxde-ocr.svg'></p>");
    m_openImageBtn = new QPushButton(tr("Open Image"));
    //layout->addWidget(m_iconLabel);
    layout->addWidget(m_openImageBtn);
    connect(m_openImageBtn,&QPushButton::clicked,this,[=]{
        QString path = QFileDialog::getOpenFileName();
        OcrApplication::instance()->openFile(path);
    });
    QWidget *widget = new QWidget();
    widget->setLayout(layout);
    this->setCentralWidget(widget);
}

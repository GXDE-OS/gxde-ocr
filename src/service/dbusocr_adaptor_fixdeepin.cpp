/*
* Copyright (C) 2020 ~ 2021 Deepin Technology Co., Ltd.
*
* Author: He MingYang Hao<hemingyang@uniontech.com>
*
* Maintainer: He MingYang <hemingyang@uniontech.com>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program. If not, see <http://www.gnu.org/licenses/>.
*/


#include "dbusocr_adaptor_fixdeepin.h"
#include <QtCore/QMetaObject>
#include <QtCore/QByteArray>
#include <QtCore/QList>
#include <QtCore/QMap>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>
#include <QWidget>
#include <QDebug>

DbusOcrAdaptorFixDeepin::DbusOcrAdaptorFixDeepin(QObject *parent)
    : QDBusAbstractAdaptor(parent)
{
    // constructor
    setAutoRelaySignals(true);
}

DbusOcrAdaptorFixDeepin::~DbusOcrAdaptorFixDeepin()
{
    // destructor
}


bool DbusOcrAdaptorFixDeepin::openFile(QString filePath)
{
    qDebug() << __FUNCTION__ << __LINE__;
    QMetaObject::invokeMethod(parent(), "openFile", Q_ARG(QString, filePath));
    return true;
}

void DbusOcrAdaptorFixDeepin::openImageAndName(QByteArray images,QString imageName)
{
    qDebug() << __FUNCTION__ << __LINE__;
    QByteArray data = images;
    QString tmp_data = QString::fromLatin1(data.data(), data.size());
    QByteArray srcData = QByteArray::fromBase64(tmp_data.toLatin1());
    data = qUncompress(srcData);
    QImage image;
    image.loadFromData(data);
    QMetaObject::invokeMethod(parent(), "openImageAndName", Q_ARG(QImage, image), Q_ARG(QString, imageName));
}
void DbusOcrAdaptorFixDeepin::openImage(QByteArray images)
{
    qDebug() << __FUNCTION__ << __LINE__;
    QByteArray data = images;
    QString tmp_data = QString::fromLatin1(data.data(), data.size());
    QByteArray srcData = QByteArray::fromBase64(tmp_data.toLatin1());
    data = qUncompress(srcData);
    QImage image;
    image.loadFromData(data);
    QMetaObject::invokeMethod(parent(), "openImage", Q_ARG(QImage, image));
}


/****************************************************************************
**
** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names
**     of its contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QtGui>
#include <QtSvg>
#include <QTextCodec>
#include "window.h"
#include "QColorGroup"
#include "svgtextobject.h"

Window::Window()
{
	m_nCount = 0;
	//;setStyleSheet("background-image:url(:/files/ss.png)")
    setupGui();
    setupTextObject();
	//setStyleSheet("background-image:url(:/files/ss.png)");
	//setStyleSheet("background-color:rgb(199,237,204)");
	//setWindowOpacity(1); 
	
	//setStyleSheet("background-color:yellow;");
	//setWindowFlags(Qt::FramelessWindowHint| Qt::Dialog);
	//setAttribute(Qt::WA_TranslucentBackground, true);

	palette2.setBrush(QPalette::Background, QColor(176,196,222));

	this->setPalette(palette2);
	this->setAutoFillBackground(true);
	

    setWindowTitle("留取丹心照我心");
	setWindowIcon(QIcon(":/files/heartDan.ico"));
}

//![1]
void Window::insertTextObject()
{
    QString fileName = fileNameLineEdit->text();
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this, tr("Error Opening File"),
                             tr("Could not open '%1'").arg(fileName));
    }

    QByteArray svgData = file.readAll();
//![1]

//![2]
    QTextCharFormat svgCharFormat;
    svgCharFormat.setObjectType(SvgTextFormat);
    QSvgRenderer renderer(svgData);

    QImage svgBufferImage(renderer.defaultSize(), QImage::Format_ARGB32);
    QPainter painter(&svgBufferImage);
    renderer.render(&painter, svgBufferImage.rect());

    svgCharFormat.setProperty(SvgData, svgBufferImage);

    QTextCursor cursor = textEdit->textCursor();
   // cursor.insertText(QString(QChar::ObjectReplacementCharacter), svgCharFormat);
	QImage dandan(":/files/heartDanDan.ico");
	cursor.insertImage(dandan);
    textEdit->setTextCursor(cursor);

	m_nCount++;
	m_HeartLable->setText( QString("%1").arg(m_nCount));

	QFont font;
	font.setPointSize(25);
	font.setBold(true);
	font.setItalic(true);
	m_HeartLable->setFont(font);
	m_HeartLable->setAlignment(Qt::AlignCenter);
}
//![2]

//![3]
void Window::setupTextObject()
{
    QObject *svgInterface = new SvgTextObject;
    textEdit->document()->documentLayout()->registerHandler(SvgTextFormat, svgInterface);
}
//![3]

void Window::setupGui()
{
	QTextCodec::setCodecForTr(QTextCodec::codecForName("system"));
	QTextCodec::setCodecForCStrings(QTextCodec::codecForName("system"));
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("system"));

    fileNameLabel = new QLabel(tr("Svg File Name:"));
	m_HeartCount = new QLabel();
	m_HeartLable = new QLabel();
	m_HeartLable->setStyleSheet("background-color: rgb(176,196,222);");
	m_HeartCount->setStyleSheet("background-color: rgb(176,196,222);");

	QPixmap scaledPixmap = QPixmap(":/files/heartDanDan.ico");/*.scaled(18,25, Qt::IgnoreAspectRatio);*/
	m_HeartCount->setPixmap(scaledPixmap);
	m_HeartCount->setScaledContents(true);
	fileNameLabel->hide();
    fileNameLineEdit = new QLineEdit;
    insertTextObjectButton = new QPushButton(tr("我  心"));


	QFont font;
	font.setPointSize(16);
	font.setBold(true);
	font.setItalic(true);
	insertTextObjectButton->setFont(font);

	palette1=insertTextObjectButton->palette();
	palette1.setBrush(QPalette::ButtonText,QColor(255,0,0));
	insertTextObjectButton->setStyleSheet("background-color: rgb(255,228,181);");
	insertTextObjectButton->setPalette(palette1);
	insertTextObjectButton->setAutoFillBackground(true);

    fileNameLineEdit->setText(":/files/heart.svg");
	fileNameLineEdit->hide();
    connect(insertTextObjectButton, SIGNAL(clicked()),
            this, SLOT(insertTextObject()));

    QHBoxLayout *bottomLayout = new QHBoxLayout;
	QHBoxLayout *heartLayout = new QHBoxLayout;
	QHBoxLayout *comLayout = new QHBoxLayout;
   // bottomLayout->addWidget(fileNameLabel);
   // bottomLayout->addWidget(fileNameLineEdit);
	heartLayout->addWidget(m_HeartLable);
	heartLayout->addWidget(m_HeartCount);
    bottomLayout->addWidget(insertTextObjectButton);
	comLayout->addLayout(heartLayout);
	comLayout->addLayout(bottomLayout);
	comLayout->setStretchFactor(heartLayout,60);
	comLayout->setStretchFactor(bottomLayout,60);
	//bottomLayout->setSpacing(50);
    textEdit = new QTextEdit;
	palette=textEdit->palette();
	QImage dan=QImage(":/files/danheart.jpg").scaled(400, 550, Qt::IgnoreAspectRatio, Qt::SmoothTransformation); 
	palette.setBrush(QPalette::Base,QBrush(dan));

	textEdit->setPalette(palette);
	textEdit->setAutoFillBackground(true);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(textEdit);
    mainLayout->addLayout(comLayout);

    setLayout(mainLayout);
}

void Window::mousePressEvent(QMouseEvent *event){                                                                                                          
	this->windowPos = this->pos();   
	this->mousePos = event->globalPos();  
	this->dPos = mousePos - windowPos;  
}  
void Window::mouseMoveEvent(QMouseEvent *event){   
	this->move(event->globalPos() - this->dPos);  
}  
#pragma once
#include <QtGui>
#include <QPushButton>
class CMyButton: public QPushButton
{
	Q_OBJECT  
private:  
	QIcon m_NormalIcon;  
	QIcon m_FocusIcon;  
	QIcon m_PressedIcon;  
	QImage image;
protected:  
	void paintEvent(QPaintEvent *event);
	void enterEvent(QEvent *event);  
	void leaveEvent(QEvent *event);  
	void mousePressEvent(QMouseEvent *event);  
	void mouseReleaseEvent(QMouseEvent *event);  
	
public:  
	CMyButton(QWidget *parent = 0);  
	virtual ~CMyButton();  
	void SetButtonIcons( );  
};


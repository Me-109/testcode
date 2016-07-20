#include "MyButton.h"

CMyButton::CMyButton(QWidget *parent)  
	: QPushButton(parent)  
{  
	//为了让图标看起来自然一点而设置了这两个操作  
	setDown(false);  
	setFocusPolicy(Qt::NoFocus);  
	SetButtonIcons();
}  

CMyButton::~CMyButton()  
{  

}  

//重载“进入”和“离开”事件，进入时切换为另一个图标，离开时还原  
void CMyButton::enterEvent(QEvent *event)  
{  
	if( isEnabled() && !m_FocusIcon.isNull() )  
		//setIcon(m_FocusIcon);  
	image.load(":/new/prefix1/Resources/buttonTwo.png");
}  

void CMyButton::leaveEvent(QEvent *event)  
{  
	if( isEnabled() )  
		//setIcon(m_NormalIcon);  
	image.load(":/new/prefix1/Resources/buttonFour.png");
}  

//重载鼠标事件  
void CMyButton::mousePressEvent(QMouseEvent *event)  
{  
	if( isEnabled() && !m_PressedIcon.isNull() ) 
		image.load(":/new/prefix1/Resources/buttonOne.png");
		//setIcon(m_PressedIcon);  
	QPushButton::mousePressEvent(event);  
}  

void CMyButton::mouseReleaseEvent(QMouseEvent *event)  
{  
	if( isEnabled() && m_FocusIcon.isNull() )  
		setIcon(m_FocusIcon);  
	QPushButton::mouseReleaseEvent(event);  
}  

void CMyButton::SetButtonIcons()  
{  
	m_NormalIcon = QIcon(":/new/prefix1/Resources/buttonOne.png");  
	m_FocusIcon = QIcon(":/new/prefix1/Resources/buttonTwo.png");  
	m_PressedIcon = QIcon(":/new/prefix1/Resources/buttonFour.png");  
	//setIcon(m_NormalIcon);  
	image.load(":/new/prefix1/Resources/buttonThree.png");
}  
 
void CMyButton::paintEvent(QPaintEvent *event)
{
	
	//QPainter painter(&image); //创建painter
	QPainter draw(this);        //创建QPainter，将指针传入该设备

	QRect rect(0,0,this->width(),this->height());  //创建绘图区域

	draw.drawImage(rect,image);                    //绘图，drawImage有很多重载函数，可根据自己的需要调用相应函数    
	//painter.setRenderHint(QPainter::Antialiasing, true); //消除锯齿效果

	//构造painterpath
	/*QPainterPath path;
	path.moveTo(0, 0);
	path.lineTo(20, 0);
	path.lineTo(20/2, 20);
	path.lineTo(0, 0);*/

	//path->setFillRule(Qt::WindingFill);
	//设置无画笔，避免边框出现一条黑线
	//painter.setPen(Qt::NoPen);
	//设置画刷
	//painter.setBrush(QBrush(QColor(36,169,225), Qt::SolidPattern));
	//绘制背景
	//painter.drawPath(path);
	//painter.drawEllipse(10,3,20,20);

	//painter.drawImage();
	//event->accept();//不再向父类传递消息
}